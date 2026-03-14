#include "Book.h"
#include <iostream>

Book::Book()
    : id(0), title(""), author(""), category(""), totalCopies(0), availableCopies(0) {}

Book::Book(int id, const std::string &title, const std::string &author,
           const std::string &category, int copies)
    : id(id), title(title), author(author), category(category),
      totalCopies(copies), availableCopies(copies) {}

void Book::display() const {
    std::cout << "ID: " << id << " | " << title << " | " << author
              << " | " << category << " | Copies: " << availableCopies
              << "/" << totalCopies << "\n";
}
