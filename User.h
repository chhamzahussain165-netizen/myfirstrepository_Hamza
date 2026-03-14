#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Book.h"

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

    User();
    User(int id, const std::string &name);

    void display() const;
    void borrowBook(int bookId);
    void returnBook(int bookId);
};

#endif // USER_H
