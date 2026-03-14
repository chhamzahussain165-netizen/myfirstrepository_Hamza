#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <chrono>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    std::string category;
    int totalCopies;
    int availableCopies;

    Book();
    Book(int id, const std::string &title, const std::string &author,
         const std::string &category, int copies);

    void display() const;
};

#endif // BOOK_H
