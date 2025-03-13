#include <iostream>
#include <string>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {
	}
    virtual void displaydetail() const = 0;

    virtual ~Books() {}
};

class mysterybook : public Books {
private:
    string title;
    string author;
public:
    mysterybook(string t, string a) : Books("Mystery"), title(t), author(a) {}

    void displaydetail() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n" << endl;
    }
};

class novelbook : public Books {
private:
    string title;
    string author;
public:
    novelbook(string t, string a) : Books("Novel"), title(t), author(a) {}

    void displaydetail() const override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << "\n" << endl;
    }
};

int main() {
    mysterybook book1("Gone Girl", "Gillian Flynn");
    novelbook book2("To Kill a Mockingbird", "Harper Lee");
    book1.displaydetail();
    book2.displaydetail();
    return 0;
}
