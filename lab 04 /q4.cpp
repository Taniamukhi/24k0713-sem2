#include <iostream>
#include <string>
using namespace std;

class Books {
public:
    string title;
    string author;
    double price;
    string publisher;
    int stock;
    Books(string t, string a, double p, string pub, int s) {
        title = t;
        author = a;
        price = p;
        publisher = pub;
        stock = s;
    }
    void displayBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Available: " << stock << " copies" << endl;
    }
    void purchaseBook(int copies) {
        if (copies <= stock) {
            cout << "Total Cost: $" << (copies * price) << endl;
            stock -= copies;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    }
};

int main() {
    Books book("1984", "George Orwell", 8.99, "Secker & Warburg", 3);
    
    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter book author: ";
    getline(cin, searchAuthor);
    
    if (searchTitle == book.title && searchAuthor == book.author) {
        book.displayBook();
        int copies;
        cout << "Enter number of copies required: ";
        cin >> copies;
        book.purchaseBook(copies);
    } else {
        cout << "Book not available" << endl;
    }
    return 0;
}