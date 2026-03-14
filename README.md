# Smart Library System

This C++ project implements a simple command-line library management system with
advanced features such as book/user management, borrowing/returning, reservations,
undo functionality, analytics, and recommendations.  It uses several data
structures like a binary search tree, priority queue, graph representation, and
standard containers to demonstrate algorithmic concepts.

---

## 🗂️ Project Structure

```
DS_Project/
├── Book.cpp          // Implementation of Book class
├── Book.h            // Book data model
├── BST.h             // Generic binary search tree template
├── GraphManager.cpp  // Graph utilities (similarity links)
├── GraphManager.h    // GraphManager class definition
├── LibrarySystem.cpp // Core system logic and operations
├── LibrarySystem.h   // System interface + data members
├── main.cpp          // User interface and menu-driven driver
├── PriorityQueue.h   // Reservation priority queue alias
├── SmartLibrary.cpp  // Alternate single-file version with sample data
├── User.cpp          // Implementation of User class
├── User.h            // User data model
└── README.md         // This documentation file
```

> The `SmartLibrary.cpp` file contains an all-in-one implementation used for
> testing and demonstration; `main.cpp` along with the other cpp files form the
> modular version used in normal builds.

---

## 🚀 Features

1. **Book Management**
   - Add, remove, update, search and list books
   - Auto-suggest titles by prefix (in the modular build)
   - Display currently issued books
   - Books stored in a generic BST keyed by `id` for efficient inserts and lookups

2. **User Management**
   - Add and search users
   - Keep borrowing history per user
   - List all registered users

3. **Transactions**
   - Borrow and return books with availability tracking
   - Unsuccessful borrow attempts are queued in a waiting line

4. **Reservations**
   - Priority queue-based reservation system
   - Process reservations automatically when copies become available

5. **Undo Support**
   - Undo the last operation (add, remove, update, borrow, return)
   - Implemented using a stack of `Transaction` records

6. **Analytics** *(modular version)*
   - Show most-borrowed books
   - Show most active users
   - Detect overdue loans (threshold: 14 days)
   - Simulate and inspect waiting line

7. **Recommendations**
   - Build a simple graph where nodes are books linked by shared author or
     category
   - Suggest related books based on a user's borrowing history

8. **Miscellaneous Utilities**
   - Waiting-line simulation and book title auto-suggestion
   - Graph management for similarity relationships

---

## 🧠 Key Components

### Book
Defined in `Book.h`/`Book.cpp`.  Contains metadata and counters for copies.

### User
Defined in `User.h`/`User.cpp`.  Tracks borrowing history with timestamps.

### BST (Generic)
Template in `BST.h` supporting insert, remove, search, and in-order traversal.
Used by `LibrarySystem` to store `Book` objects.

### ReservationQueue
Alias in `PriorityQueue.h` built on `std::priority_queue` with a custom
`ReservationCompare` functor.

### GraphManager
Simple adjacency-list representation of a book similarity graph used for
recommendations.

### LibrarySystem
The heart of the application (**LibrarySystem.h / LibrarySystem.cpp**).  It
aggregates all functionality: data structures, core operations, and undo
handling.  The class exposes public methods invoked by `main.cpp`.

### main.cpp
Menu-driven command‑line interface that interacts with `LibrarySystem`.
Provides basic input validation and user prompts.

### SmartLibrary.cpp
A standalone monolithic version combining all classes and sample data for
rapid testing and demonstration.  Can be compiled independently.

---

## 🛠️ Build Instructions

Requires a C++17–compatible compiler such as `g++` or `clang++`.

1. **Modular build** (recommended):

   ```sh
   cd "c:/Users/user/OneDrive/Desktop/DS_Project"
   g++ -std=c++17 -Wall -O2 \
       main.cpp LibrarySystem.cpp Book.cpp User.cpp GraphManager.cpp -o SmartLibrary
   ```

2. **Single-file build** (quick demo):

   ```sh
   g++ -std=c++17 -Wall -O2 SmartLibrary.cpp -o SmartLibraryDemo
   ```

3. **Run**:

   ```sh
   ./SmartLibrary          # or SmartLibrary.exe on Windows
   ```

> You can also open the project in an IDE like Visual Studio or Code::Blocks,
> and add the source files to a new project following the same compilation
> order.

---

## 📌 Usage Notes

- IDs for books and users must be unique integers.
- Borrowing fails when no copies are available; the user is queued instead.
- Reservations are processed explicitly via the menu but can also be triggered
  automatically after returns.
- Undo only affects the most recent eligible operation.
- The recommendation engine is naive; it simply returns distinct neighbors of
  previously borrowed books.

---

## 📝 Extending the Project

Suggestions for further work:

- Persist data to disk (e.g. using JSON or binary serialization).
- Add a graphical user interface or web front end.
- Enhance recommendation using collaborative filtering.
- Implement user authentication and roles (admin vs. borrower).
- Track due dates and fines more accurately.
- Integrate unit tests using a framework like Google Test.

---

## 🧾 License

This code is intended for educational purposes. Feel free to modify and reuse
it in personal projects.

---

Enjoy building and improving your smart library! 👩‍💻📚
