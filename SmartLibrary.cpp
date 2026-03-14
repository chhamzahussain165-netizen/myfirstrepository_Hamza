#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <functional>
#include <memory>
#include <chrono>
#include <set>
#include <algorithm>
#include <limits>

// ---------------- Book ----------------
class Book {
public:
    int id;
    std::string title;
    std::string author;
    std::string category;
    int totalCopies;
    int availableCopies;

    Book()
        : id(0), title(""), author(""), category(""), totalCopies(0), availableCopies(0) {}

    Book(int id, const std::string &title, const std::string &author,
         const std::string &category, int copies)
        : id(id), title(title), author(author), category(category),
          totalCopies(copies), availableCopies(copies) {}

    void display() const {
        std::cout << "ID: " << id << " | " << title << " | " << author
                  << " | " << category << " | Copies: " << availableCopies
                  << "/" << totalCopies << "\n";
    }
};

// ---------------- User ----------------
struct BorrowRecord {
    int bookId;
    std::chrono::system_clock::time_point borrowDate;
    std::chrono::system_clock::time_point returnDate;
    bool returned;
};

class User {
public:
    int id;
    std::string name;
    std::vector<BorrowRecord> history;

    User() : id(0), name("") {}
    User(int id, const std::string &name) : id(id), name(name) {}

    void display() const {
        std::cout << "User ID: " << id << " | Name: " << name << "\n";
    }

    void borrowBook(int bookId) {
        BorrowRecord rec;
        rec.bookId = bookId;
        rec.borrowDate = std::chrono::system_clock::now();
        rec.returnDate = rec.borrowDate;
        rec.returned = false;
        history.push_back(rec);
    }

    void returnBook(int bookId) {
        for (auto &rec : history) {
            if (rec.bookId == bookId && !rec.returned) {
                rec.returnDate = std::chrono::system_clock::now();
                rec.returned = true;
                break;
            }
        }
    }
};

// ---------------- Generic BST ----------------
template <typename T>
class BST {
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(const T &d) : data(d), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;
    std::function<bool(const T &, const T &)> comp;

public:
    BST(std::function<bool(const T &, const T &)> comparator)
        : root(nullptr), comp(comparator) {}

    void insert(const T &value) {
        root = insertRec(std::move(root), value);
    }

    void remove(const T &value) {
        root = removeRec(std::move(root), value);
    }

    T *search(const T &value) {
        Node *curr = root.get();
        while (curr) {
            if (comp(value, curr->data)) {
                curr = curr->left.get();
            } else if (comp(curr->data, value)) {
                curr = curr->right.get();
            } else {
                return &curr->data;
            }
        }
        return nullptr;
    }

    void inOrder(std::vector<T> &vec) {
        inOrderRec(root.get(), vec);
    }

private:
    std::unique_ptr<Node> insertRec(std::unique_ptr<Node> node,
                                    const T &value) {
        if (!node) return std::make_unique<Node>(value);
        if (comp(value, node->data))
            node->left = insertRec(std::move(node->left), value);
        else
            node->right = insertRec(std::move(node->right), value);
        return node;
    }

    std::unique_ptr<Node> removeRec(std::unique_ptr<Node> node,
                                    const T &value) {
        if (!node) return node;
        if (comp(value, node->data)) {
            node->left = removeRec(std::move(node->left), value);
        } else if (comp(node->data, value)) {
            node->right = removeRec(std::move(node->right), value);
        } else {
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);
            Node *minNode = findMin(node->right.get());
            node->data = minNode->data;
            node->right = removeRec(std::move(node->right), minNode->data);
        }
        return node;
    }

    Node *findMin(Node *node) {
        while (node && node->left) node = node->left.get();
        return node;
    }

    void inOrderRec(Node *node, std::vector<T> &vec) {
        if (!node) return;
        inOrderRec(node->left.get(), vec);
        vec.push_back(node->data);
        inOrderRec(node->right.get(), vec);
    }
};

// ---------------- Reservation priority queue ----------------
struct Reservation {
    int userId;
    int bookId;
    int priority; // lower means earlier
};
struct ReservationCompare {
    bool operator()(const Reservation &a, const Reservation &b) const {
        return a.priority > b.priority;
    }
};
using ReservationQueue = std::priority_queue<Reservation,
                                            std::vector<Reservation>,
                                            ReservationCompare>;

// ---------------- GraphManager ----------------
class GraphManager {
    std::unordered_map<int, std::set<int>> adj;
public:
    void addEdge(int a, int b) {
        adj[a].insert(b);
        adj[b].insert(a);
    }
    std::vector<int> getRelated(int bookId) const {
        std::vector<int> res;
        auto it = adj.find(bookId);
        if (it != adj.end()) {
            for (int n : it->second) res.push_back(n);
        }
        return res;
    }
};

// ---------------- LibrarySystem ----------------
enum class OperationType { AddBook, RemoveBook, UpdateBook, Borrow, Return, Reserve };
struct Transaction {
    OperationType type;
    int bookId;
    int userId;
    Book oldBookState;
};

class LibrarySystem {
    BST<Book> bookTree;
    std::vector<User> users;
    ReservationQueue reservations;
    GraphManager graph;
    std::queue<int> waitingLine;
    std::stack<Transaction> undoStack;
    std::unordered_map<int, int> borrowCount;

public:
    LibrarySystem();

    // book management
    bool addBook(const Book &book);
    bool removeBook(int bookId);
    bool updateBook(int bookId, const Book &updated);
    Book *searchBook(int bookId);
    std::vector<Book> listAllBooks();
    void displayIssuedBooks();

    // user management
    bool addUser(const User &user);
    User *searchUser(int userId);
    std::vector<User> listAllUsers();

    // borrow/return
    bool borrowBook(int userId, int bookId);
    bool returnBook(int userId, int bookId);

    // reservations
    void reserveBook(int userId, int bookId);
    void processReservations();

    // undo
    bool undoLast();

    // recommendations
    std::vector<int> recommendBooks(int userId);

    // misc (no analytics remaining)
};

// constructor with sample data
LibrarySystem::LibrarySystem()
    : bookTree([](const Book &a, const Book &b) { return a.id < b.id; }) {
    // sample users
    users.emplace_back(1, "Alice");
    users.emplace_back(2, "Bob");
    users.emplace_back(3, "Carol");
    users.emplace_back(4, "David");
    users.emplace_back(5, "Eve");

    // sample books
    std::vector<Book> samples = {
        {101, "The C++ Programming Language", "Bjarne Stroustrup", "Programming", 3},
        {102, "Effective Modern C++", "Scott Meyers", "Programming", 2},
        {103, "Clean Code", "Robert C. Martin", "Software Engineering", 4},
        {104, "Design Patterns", "Erich Gamma", "Software Engineering", 2},
        {105, "Introduction to Algorithms", "Cormen et al.", "Algorithms", 3},
        {106, "The Pragmatic Programmer", "Andrew Hunt", "Software Engineering", 2},
        {107, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 5},
        {108, "The Lord of the Rings", "J.R.R. Tolkien", "Fantasy", 3},
        {109, "A Game of Thrones", "George R.R. Martin", "Fantasy", 2},
        {110, "To Kill a Mockingbird", "Harper Lee", "Fiction", 4},
        {111, "1984", "George Orwell", "Dystopian", 4},
        {112, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 3},
        {113, "The Catcher in the Rye", "J.D. Salinger", "Fiction", 2},
        {114, "The Art of Computer Programming", "Donald Knuth", "Programming", 1},
        {115, "Algorithms Unlocked", "Thomas Cormen", "Algorithms", 2}
    };
    for (auto &b : samples) {
        bookTree.insert(b);
    }
    // build similarity graph
    auto all = listAllBooks();
    for (size_t i = 0; i < all.size(); ++i) {
        for (size_t j = i + 1; j < all.size(); ++j) {
            if (all[i].category == all[j].category || all[i].author == all[j].author) {
                graph.addEdge(all[i].id, all[j].id);
            }
        }
    }

    // some pre-issued books
    borrowBook(1, 101);
    borrowBook(2, 107);
    borrowBook(3, 108);
    // artificially make Alice's loan overdue
    User *u1 = searchUser(1);
    if (u1 && !u1->history.empty()) {
        u1->history[0].borrowDate -= std::chrono::hours(24 * 20);
    }

    // some reservations
    reserveBook(4, 102);
    reserveBook(5, 105);

    // flush undo stack so initial operations cannot be undone
    while (!undoStack.empty()) undoStack.pop();
}

bool LibrarySystem::addBook(const Book &book) {
    if (searchBook(book.id)) return false;
    bookTree.insert(book);
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

void LibrarySystem::displayIssuedBooks() {
    std::cout << "Issued books:\n";
    for (auto &b : listAllBooks()) {
        if (b.availableCopies < b.totalCopies) {
            b.display();
        }
    }
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


std::vector<int> LibrarySystem::recommendBooks(int userId) {
    std::vector<int> recs;
    User *u = searchUser(userId);
    if (!u) return recs;
    std::set<int> seen;
    for (auto &r : u->history) {
        auto related = graph.getRelated(r.bookId);
        for (int id : related) {
            if (seen.insert(id).second) recs.push_back(id);
        }
    }
    return recs;
}


// ---------------- utility ----------------
void clearScreen() {
    std::cout << std::string(50, '\n');
}

int readInt() {
    int x;
    while (!(std::cin >> x)) {
        std::cout << "Invalid input. Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return x;
}

// ---------------- main menu ----------------
int main() {
    LibrarySystem lib;
    bool running = true;
    while (running) {
        std::cout << "================ Smart Library System ================\n";
        std::cout << "1. Book Management\n";
        std::cout << "2. User Management\n";
        std::cout << "3. Transactions (borrow/return)\n";
        std::cout << "4. Reservations\n";
        std::cout << "5. Undo last operation\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        int choice = readInt();
        switch (choice) {
        case 1: {
            bool bkmenu = true;
            while (bkmenu) {
                std::cout << "-- Book Management --\n";
                std::cout << "1. Add Book\n";
                std::cout << "2. Remove Book\n";
                std::cout << "3. Update Book\n";
                std::cout << "4. Search Book\n";
                std::cout << "5. List All Books\n";
                std::cout << "6. Display Issued Books\n";
                std::cout << "7. Back\n";
                std::cout << "Choice: ";
                int c = readInt();
                switch (c) {
                case 1: {
                    Book b;
                    std::cout << "ID: "; b.id = readInt();
                    std::cout << "Title: "; std::cin.ignore();
                    std::getline(std::cin, b.title);
                    std::cout << "Author: ";
                    std::getline(std::cin, b.author);
                    std::cout << "Category: ";
                    std::getline(std::cin, b.category);
                    std::cout << "Copies: "; b.totalCopies = readInt();
                    b.availableCopies = b.totalCopies;
                    if (lib.addBook(b))
                        std::cout << "Book added.\n";
                    else
                        std::cout << "Book exists.\n";
                    break;
                }
                case 2: {
                    std::cout << "Book ID: ";
                    int id = readInt();
                    if (lib.removeBook(id))
                        std::cout << "Removed.\n";
                    else
                        std::cout << "Not found.\n";
                    break;
                }
                case 3: {
                    std::cout << "Book ID to update: ";
                    int id = readInt();
                    Book *b = lib.searchBook(id);
                    if (b) {
                        Book nb = *b;
                        std::cout << "New title (enter to keep): "; std::cin.ignore();
                        std::string s;
                        std::getline(std::cin, s);
                        if (!s.empty()) nb.title = s;
                        std::cout << "New author: ";
                        std::getline(std::cin, s);
                        if (!s.empty()) nb.author = s;
                        std::cout << "New category: ";
                        std::getline(std::cin, s);
                        if (!s.empty()) nb.category = s;
                        std::cout << "New copies: ";
                        int cpy = readInt();
                        if (cpy > 0) {
                            nb.totalCopies = cpy;
                            nb.availableCopies = cpy;
                        }
                        lib.updateBook(id, nb);
                        std::cout << "Updated.\n";
                    } else {
                        std::cout << "Not found.\n";
                    }
                    break;
                }
                case 4: {
                    std::cout << "Book ID: ";
                    int id = readInt();
                    Book *b = lib.searchBook(id);
                    if (b) b->display();
                    else std::cout << "Not found.\n";
                    break;
                }
                case 5: {
                    auto all = lib.listAllBooks();
                    for (auto &b : all) b.display();
                    break;
                }
                case 6: {
                    lib.displayIssuedBooks();
                    break;
                }
                case 7: bkmenu = false; break;
                default: std::cout << "Invalid.\n"; break;
                }
            }
            break;
        }
        case 2: {
            bool umenu = true;
            while (umenu) {
                std::cout << "-- User Management --\n";
                std::cout << "1. Add User\n";
                std::cout << "2. Search User\n";
                std::cout << "3. List All Users\n";
                std::cout << "4. Back\n";
                std::cout << "Choice: ";
                int c = readInt();
                switch (c) {
                case 1: {
                    User u;
                    std::cout << "ID: "; u.id = readInt();
                    std::cout << "Name: "; std::cin.ignore();
                    std::getline(std::cin, u.name);
                    if (lib.addUser(u)) std::cout << "Added.\n";
                    else std::cout << "Exists.\n";
                    break;
                }
                case 2: {
                    std::cout << "User ID: ";
                    int id = readInt();
                    User *u = lib.searchUser(id);
                    if (u) u->display();
                    else std::cout << "Not found.\n";
                    break;
                }
                case 3: {
                    auto all = lib.listAllUsers();
                    for (auto &u : all) u.display();
                    break;
                }
                case 4: umenu = false; break;
                default: std::cout << "Invalid.\n"; break;
                }
            }
            break;
        }
        case 3: {
            std::cout << "1. Borrow Book\n";
            std::cout << "2. Return Book\n";
            std::cout << "Choice: ";
            int c = readInt();
            if (c == 1) {
                std::cout << "User ID: "; int uid = readInt();
                std::cout << "Book ID: "; int bid = readInt();
                if (lib.borrowBook(uid, bid))
                    std::cout << "Borrowed.\n";
                else
                    std::cout << "Cannot borrow now. Added to waiting queue.\n";
            } else if (c == 2) {
                std::cout << "User ID: "; int uid = readInt();
                std::cout << "Book ID: "; int bid = readInt();
                if (lib.returnBook(uid, bid))
                    std::cout << "Returned.\n";
                else
                    std::cout << "Error.\n";
            } else {
                std::cout << "Invalid.\n";
            }
            break;
        }
        case 4: {
            std::cout << "1. Reserve Book\n";
            std::cout << "2. Process Reservations\n";
            std::cout << "Choice: ";
            int c = readInt();
            if (c == 1) {
                std::cout << "User ID: "; int uid = readInt();
                std::cout << "Book ID: "; int bid = readInt();
                lib.reserveBook(uid, bid);
                std::cout << "Reserved.\n";
            } else if (c == 2) {
                lib.processReservations();
                std::cout << "Processed.\n";
            } else {
                std::cout << "Invalid.\n";
            }
            break;
        }
        case 5: {
            if (lib.undoLast()) std::cout << "Undo success.\n";
            else std::cout << "Nothing to undo.\n";
            break;
        }
        case 6: running = false; break;
        default:
            std::cout << "Invalid option\n";
            break;
        }
        std::cout << "\n";
    }
    std::cout << "Goodbye!\n";
    return 0;
}
