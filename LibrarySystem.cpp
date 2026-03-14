#include "LibrarySystem.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

LibrarySystem::LibrarySystem()
    : bookTree([](const Book &a, const Book &b) { return a.id < b.id; }) {}

bool LibrarySystem::addBook(const Book &book) {
    if (searchBook(book.id)) return false;
    
    // insert and create similarity links
    bookTree.insert(book);
    // whenever a new book is added, connect it to others with same category or author
    auto all = listAllBooks();
    for (auto &b : all) {
        if (b.id == book.id) continue;
        if (b.category == book.category || b.author == book.author) {
            graph.addEdge(b.id, book.id);
        }
    }

    Transaction t{OperationType::AddBook, book.id, 0, book};
    undoStack.push(t);
    return true;
}

bool LibrarySystem::removeBook(int bookId) {
    Book key(bookId, "", "", "", 0);
    Book *found = searchBook(bookId);
    if (!found) return false;
    Book old = *found;
    bookTree.remove(*found);
    Transaction t{OperationType::RemoveBook, bookId, 0, old};
    undoStack.push(t);
    return true;
}

bool LibrarySystem::updateBook(int bookId, const Book &updated) {
    Book *found = searchBook(bookId);
    if (!found) return false;
    Book old = *found;
    *found = updated;
    Transaction t{OperationType::UpdateBook, bookId, 0, old};
    undoStack.push(t);
    return true;
}

Book *LibrarySystem::searchBook(int bookId) {
    Book key(bookId, "", "", "", 0);
    return bookTree.search(key);
}

std::vector<Book> LibrarySystem::listAllBooks() {
    std::vector<Book> vec;
    bookTree.inOrder(vec);
    return vec;
}

bool LibrarySystem::addUser(const User &user) {
    if (searchUser(user.id)) return false;
    users.push_back(user);
    return true;
}

User *LibrarySystem::searchUser(int userId) {
    for (auto &u : users) {
        if (u.id == userId) return &u;
    }
    return nullptr;
}

std::vector<User> LibrarySystem::listAllUsers() {
    return users;
}

bool LibrarySystem::borrowBook(int userId, int bookId) {
    User *u = searchUser(userId);
    Book *b = searchBook(bookId);
    if (!u || !b || b->availableCopies <= 0) {
        waitingLine.push(userId);
        return false;
    }
    u->borrowBook(bookId);
    b->availableCopies--;
    borrowCount[bookId]++;
    Transaction t{OperationType::Borrow, bookId, userId, *b};
    undoStack.push(t);
    return true;
}

bool LibrarySystem::returnBook(int userId, int bookId) {
    User *u = searchUser(userId);
    Book *b = searchBook(bookId);
    if (!u || !b) return false;
    u->returnBook(bookId);
    b->availableCopies++;
    Transaction t{OperationType::Return, bookId, userId, *b};
    undoStack.push(t);
    return true;
}

void LibrarySystem::reserveBook(int userId, int bookId) {
    static int counter = 0;
    reservations.push({userId, bookId, counter++});
}

void LibrarySystem::processReservations() {
    while (!reservations.empty()) {
        Reservation r = reservations.top();
        reservations.pop();
        if (!borrowBook(r.userId, r.bookId)) {
            // if still not available, push back
            // to avoid infinite loop we check copies
            Book *b = searchBook(r.bookId);
            if (b && b->availableCopies > 0) {
                borrowBook(r.userId, r.bookId);
            }
        }
    }
}

bool LibrarySystem::undoLast() {
    if (undoStack.empty()) return false;
    Transaction t = undoStack.top();
    undoStack.pop();
    switch (t.type) {
    case OperationType::AddBook:
        bookTree.remove(t.oldBookState);
        break;
    case OperationType::RemoveBook:
        bookTree.insert(t.oldBookState);
        break;
    case OperationType::UpdateBook:
        {
            Book *b = searchBook(t.bookId);
            if (b) *b = t.oldBookState;
        }
        break;
    case OperationType::Borrow:
        {
            Book *b = searchBook(t.bookId);
            User *u = searchUser(t.userId);
            if (b && u) {
                b->availableCopies++;
                u->returnBook(t.bookId);
            }
        }
        break;
    case OperationType::Return:
        {
            Book *b = searchBook(t.bookId);
            User *u = searchUser(t.userId);
            if (b && u) {
                if (b->availableCopies>0) b->availableCopies--;
                u->borrowBook(t.bookId);
            }
        }
        break;
    default:
        break;
    }
    return true;
}

void LibrarySystem::showMostBorrowed() {
    std::vector<std::pair<int, int>> vec;
    for (auto &p : borrowCount) vec.push_back(p);
    std::sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    std::cout << "Most borrowed books (ID:count):\n";
    for (auto &p : vec) std::cout << p.first << ":" << p.second << " ";
    std::cout << "\n";
}

void LibrarySystem::showActiveUsers() {
    std::vector<std::pair<int, int>> vec;
    for (auto &u : users) {
        vec.emplace_back(u.id, u.history.size());
    }
    std::sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });
    std::cout << "Active users (ID:transactions):\n";
    for (auto &p : vec) std::cout << p.first << ":" << p.second << " ";
    std::cout << "\n";
}

std::vector<int> LibrarySystem::recommendBooks(int userId) {
    std::vector<int> recs;
    User *u = searchUser(userId);
    if (!u) return recs;
    // simple algorithm: for each book borrowed, get related from graph
    std::set<int> seen;
    for (auto &r : u->history) {
        auto related = graph.getRelated(r.bookId);
        for (int id : related) {
            if (seen.insert(id).second) recs.push_back(id);
        }
    }
    return recs;
}

void LibrarySystem::simulateWaitingLine() {
    std::cout << "Simulating waiting line processing...\n";
    while (!waitingLine.empty()) {
        std::cout << "User " << waitingLine.front() << " is waiting\n";
        waitingLine.pop();
    }
}

void LibrarySystem::autoSuggest(const std::string &prefix) {
    std::vector<Book> all = listAllBooks();
    std::cout << "Suggestions for \"" << prefix << "\":\n";
    for (auto &b : all) {
        if (b.title.rfind(prefix, 0) == 0) {
            b.display();
        }
    }
}

void LibrarySystem::detectOverdue() {
    using namespace std::chrono;
    auto now = system_clock::now();
    std::cout << "Overdue records:\n";
    for (auto &u : users) {
        for (auto &r : u.history) {
            if (!r.returned) {
                auto days = duration_cast<hours>(now - r.borrowDate).count() / 24;
                if (days > 14) { // overdue threshold
                    std::cout << "User " << u.id << " has book " << r.bookId
                              << " overdue by " << (days - 14) << " days\n";
                }
            }
        }
    }
}
