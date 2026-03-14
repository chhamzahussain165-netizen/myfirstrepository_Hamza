#include "User.h"
#include <iostream>

User::User() : id(0), name("") {}
User::User(int id, const std::string &name) : id(id), name(name) {}

void User::display() const {
    std::cout << "User ID: " << id << " | Name: " << name << "\n";
}

void User::borrowBook(int bookId) {
    BorrowRecord rec;
    rec.bookId = bookId;
    rec.borrowDate = std::chrono::system_clock::now();
    rec.returnDate = rec.borrowDate;
    rec.returned = false;
    history.push_back(rec);
}

void User::returnBook(int bookId) {
    for (auto &rec : history) {
        if (rec.bookId == bookId && !rec.returned) {
            rec.returnDate = std::chrono::system_clock::now();
            rec.returned = true;
            break;
        }
    }
}
