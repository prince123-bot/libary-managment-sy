#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ==================== Book Class ====================
class Book {
private:
    int id;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isAvailable = true;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getAvailability() { return isAvailable; }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully!\n";
        } else {
            cout << "Sorry, this book is already borrowed.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book returned successfully!\n";
        } else {
            cout << "This book was not borrowed.\n";
        }
    }

    void displayBook() {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

// ==================== Library Class ====================
class Library {
private:
    vector<Book> books;
    int nextId;

public:
    Library() {
        nextId = 1; // book IDs start from 1
    }

    void addBook(string title, string author) {
        books.push_back(Book(nextId, title, author));
        cout << "Book added successfully with ID: " << nextId << "\n";
        nextId++;
    }

    void showAllBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "\n===== Library Books =====\n";
        for (auto &book : books) {
            book.displayBook();
        }
    }

    void searchBook(string keyword) {
        bool found = false;
        for (auto &book : books) {
            if (book.getTitle().find(keyword) != string::npos ||
                book.getAuthor().find(keyword) != string::npos) {
                book.displayBook();
                found = true;
            }
        }
        if (!found)
            cout << "No book found with keyword: " << keyword << "\n";
    }

    void borrowBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto &book : books) {
            if (book.getId() == id) {
                book.returnBook();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

// ==================== Main Program ====================
int main() {
    Library library;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title, author;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
        } 
        else if (choice == 2) {
            library.showAllBooks();
        } 
        else if (choice == 3) {
            string keyword;
            cout << "Enter title/author keyword: ";
            getline(cin, keyword);
            library.searchBook(keyword);
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter book ID to borrow: ";
            cin >> id;
            library.borrowBook(id);
        } 
        else if (choice == 5) {
            int id;
            cout << "Enter book ID to return: ";
            cin >> id;
            library.returnBook(id);
        } 
        else if (choice == 6) {
            cout << "Exiting Library Management System. Goodbye!\n";
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}