#include<iostream>
#include<vector>
using namespace std;

class media {
protected:
    string title, publicationdate, uniqueid, publisher;
    bool ischeckedout;
public:
    media(string t, string date, string id, string pub): title(t), publicationdate(date), uniqueid(id), publisher(pub), ischeckedout(false) {}

    virtual void displayinfo() {
        cout<< "Title: " << title << endl;
		cout<< "Publication Date: " << publicationdate << endl;
        cout<< "ID: " << uniqueid << endl;
		cout<< "Publisher: " << publisher << endl;
    }

    void checkout() {
        if (ischeckedout)
            cout<< title << " is already checked out.\n";
        else {
            ischeckedout = true;
            cout<< title << " has been checked out.\n";
        }
    }

    void returnitem() {
        if (!ischeckedout)
            cout<< title << " was not checked out.\n";
        else {
            ischeckedout = false;
            cout<< title << " has been returned.\n";
        }
    }
    
    virtual ~media() {}
};

class book : public media {
private:
    string author, ISBN;
    int numberofpages;
public:
    book(string t, string date, string id, string pub, string auth, string isbn, int pages) : media(t, date, id, pub), author(auth), ISBN(isbn), numberofpages(pages) {}

    void displayinfo() override {
        media::displayinfo();
        cout<< "Author: " << author << endl;
		cout<< "ISBN: " << ISBN << endl;
		cout<< "Pages: " << numberofpages << endl;
    }
};

class DVD : public media {
private:
    string director;
    double duration;
    double rating;
public:
    DVD(string t, string date, string id, string pub, string dir, double dur, double rat) : media(t, date, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayinfo() override {
        media::displayinfo();
        cout<< "Director: " << director << endl;
		cout<< "Duration: " << duration << endl;
		cout<< " hours\nRating: " << rating << "/10" << endl;
    }
};

class CD : public media {
private:
    string artist, genre;
    int numberoftracks;
public:
    CD(string t, string date, string id, string pub, string art, int tracks, string gen) : media(t, date, id, pub), artist(art), numberoftracks(tracks), genre(gen) {}

    void displayinfo() override {
        media::displayinfo();
        cout<< "Artist: " << artist << endl;
		cout<< "Tracks: " << numberoftracks << endl;
		cout<< "Genre: " << genre << endl;
    }
};

class magazine : public media {
private:
    string editor, genre;
    int issuenumber;
public:
    magazine(string t, string date, string id, string pub, string edit, int issue, string gen) : media(t, date, id, pub), editor(edit), issuenumber(issue), genre(gen) {}

    void displayinfo() override {
        media::displayinfo();
        cout<< "Editor: " << editor << endl;
		cout<< "Issue Number: " << issuenumber << endl;
		cout<< "Genre: " << genre << endl;
    }
};

int main() {
    book b1("C++ Programming", "2020", "B101", "Tech Press", "Bjarne Stroustrup", "978-0321563842", 350);
    DVD d1("The Matrix", "1999", "D204", "Warner Bros", "Lana & Lilly Wachowski", 2.3, 8.7);
    CD c1("Back in Black", "1980", "C304", "Atlantic Records", "AC/DC", 10, "Hard Rock");
    magazine m1("Time", "2022", "M406", "Time USA LLC", "Edward Felsenthal", 100, "News");  
    cout << "--- book Info ---\n";
    b1.displayinfo();
    b1.checkout();
    b1.returnitem();    
    cout << "\n--- DVD Info ---\n";
    d1.displayinfo();
    d1.checkout();    
    cout << "\n--- CD Info ---\n";
    c1.displayinfo(); 
    cout << "\n--- magazine Info ---\n";
    m1.displayinfo();   
    return 0;
}
