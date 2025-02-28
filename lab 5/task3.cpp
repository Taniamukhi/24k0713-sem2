#include <iostream>
#include <vector>
using namespace std;

class Catalog {
private:
    vector<pair<string, string>> book_index;
public:
    void addbook(const string& isbn, const string& location) {
        book_index.push_back({isbn, location});
    }
    string findbooklocation(const string& isbn) {
        for (const auto& entry : book_index) {
            if (entry.first == isbn) {
                return entry.second;
            }
        }
        return "Not found!";
    }
    void displaycatalog() {
        cout << "Catalog Entries: \n";
        for (const auto& entry : book_index) {
            cout << "ISBN: " << entry.first << " Location: " << entry.second << endl;
        }
    }
};
class Library {
private:
    string name;
    string address;
    Catalog catalog;
    vector<class Book*> books;  
public:
    Library(string n, string a) : name(n), address(a) {}

    string getname() { return name; }
    string getaddress() { return address; }

    void addbook(class Book* book, const string& location);
    void removebook(const string& isbn);
    void findbook(const string& isbn);
    void displaybooks();
    void displaycatalog();
};
class Book {
private:
    string title;
    string author;
    string isbn;
    vector<Library*> libraries;
public:
    Book(string t, string a, string ib) : title(t), author(a), isbn(ib) {}

    string gettitle() { return title; }
    string getauthor() { return author; }
    string getisbn() { return isbn; }

    void associatewithlibrary(Library* library) {
        libraries.push_back(library);
    }

    void display() {
        cout << "Title: " << title << " Author: " << author << " ISBN: " << isbn << endl;
        cout << "Available in libraries: ";
        for (Library* lib : libraries) {
            cout << lib->getname() << " ";  
        }
        cout << endl;
    }
};
void Library::addbook(Book* book, const string& location) {
    books.push_back(book);
    catalog.addbook(book->getisbn(), location);
    book->associatewithlibrary(this);
}
void Library::removebook(const string& isbn) {
    for (size_t i = 0; i < books.size(); i++) {
        if (books[i]->getisbn() == isbn) {
            books.erase(books.begin() + i);
            cout << "Book with ISBN " << isbn << " removed from " << name << endl;
            return;
        }
    }
    cout << "Book not found in " << name << endl;
}
void Library::findbook(const string& isbn) {
    string location = catalog.findbooklocation(isbn);
    cout << "Book Location: " << location << endl;
}
void Library::displaybooks() {  
    cout << "Books in " << name << ":\n";
    for (Book* book : books) {
        book->display();
    }
}
void Library::displaycatalog() {
    catalog.displaycatalog();
}
int main() {
    Library libr1("Oxford Library", "123 Library St.");
    Library libr2("National Library", "789 City St.");
    Book* book1 = new Book("Expository Writing", "Dr. Abdul", "12345");
    Book* book2 = new Book("Digital Logic", "Dr. Rehman", "34567");
    libr1.addbook(book1, "Shelf B3");
    libr2.addbook(book1, "Shelf A6");
    libr1.addbook(book2, "Shelf C1");
    libr1.displaybooks();
    libr2.displaybooks();
    libr1.displaycatalog();
    libr2.displaycatalog();
    libr1.findbook("12345");
    libr2.findbook("34567");
    libr1.removebook("12345");
    libr1.displaybooks();
    delete book1;
    delete book2;
    return 0;
}
