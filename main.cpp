#include <iostream>
#include <string>
#include <limits>
#include "LibrarySystem.h"

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

int main() {
    LibrarySystem lib;
    bool running = true;
    while (running) {
        std::cout << "================ Smart Library System ================\n";
        std::cout << "1. Book Management\n";
        std::cout << "2. User Management\n";
        std::cout << "3. Transactions (borrow/return)\n";
        std::cout << "4. Reservations\n";
        std::cout << "5. Analytics\n";
        std::cout << "6. Recommendations\n";
        std::cout << "7. Undo last operation\n";
        std::cout << "8. Exit\n";
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
                std::cout << "6. Auto-suggest titles\n";
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
                    std::cout << "Prefix: "; std::cin.ignore();
                    std::string pref;
                    std::getline(std::cin, pref);
                    lib.autoSuggest(pref);
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
            std::cout << "1. Most Borrowed\n";
            std::cout << "2. Active Users\n";
            std::cout << "3. Overdue Detection\n";
            std::cout << "4. Waiting Line Simulation\n";
            std::cout << "Choice: ";
            int c = readInt();
            if (c == 1) lib.showMostBorrowed();
            else if (c == 2) lib.showActiveUsers();
            else if (c == 3) lib.detectOverdue();
            else if (c == 4) lib.simulateWaitingLine();
            else std::cout << "Invalid.\n";
            break;
        }
        case 6: {
            std::cout << "User ID: "; int uid = readInt();
            auto recs = lib.recommendBooks(uid);
            std::cout << "Recommendations: ";
            for (int id : recs) std::cout << id << " ";
            std::cout << "\n";
            break;
        }
        case 7: {
            if (lib.undoLast()) std::cout << "Undo success.\n";
            else std::cout << "Nothing to undo.\n";
            break;
        }
        case 8: running = false; break;
        default:
            std::cout << "Invalid option\n";
            break;
        }
        std::cout << "\n";
    }
    std::cout << "Goodbye!\n";
    return 0;
}
