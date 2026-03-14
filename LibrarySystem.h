#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include "Book.h"
#include "User.h"
#include "BST.h"
#include "PriorityQueue.h"
#include "GraphManager.h"

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
    std::unordered_map<int, int> borrowCount; // bookId -> times borrowed

public:
    LibrarySystem();

    // book management
    bool addBook(const Book &book);
    bool removeBook(int bookId);
    bool updateBook(int bookId, const Book &updated);
    Book *searchBook(int bookId);
    std::vector<Book> listAllBooks();

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

    // analytics
    void showMostBorrowed();
    void showActiveUsers();

    // recommendations
    std::vector<int> recommendBooks(int userId);

    // misc
    void simulateWaitingLine();
    void autoSuggest(const std::string &prefix);
    void detectOverdue();
};

#endif // LIBRARYSYSTEM_H
