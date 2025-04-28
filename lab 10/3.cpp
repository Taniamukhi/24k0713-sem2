#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

const int MAX_RECORDS = 100;

struct User {
    string user_id;
    string first_name;
    string last_name;
    string address;
    string email;
};

struct Product {
    string product_id;
    string product_name;
    string description;
    int price;
};

struct Order {
    string order_id;
    string user_id;
    string product_ordered;
    int total_paid;
};

string tolowercase(string str) {
    for (int i=0; i<str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

void createdummydata() {
    ofstream userFile("users.txt");
    userFile << "1,Linus,Torvalds,Finland,linus@linux.com\n";
    userFile << "2,Ali,Lovelace,London,ada@math.com\n";
    userFile << "3,Aslam,Turing,England,alan@math.com\n";
    userFile.close();
    ofstream productFile("products.txt");
    productFile << "1,Laptop,High performance laptop,1000\n";
    productFile << "2,Smartphone,Latest smartphone,700\n";
    productFile << "3,Tablet,Portable tablet,400\n";
    productFile.close();
    ofstream orderFile("orders.txt");
    orderFile << "1,1,1,1000\n"; 
    orderFile << "2,2,2,700\n";  
    orderFile << "3,1,3,400\n";  
    orderFile.close();
}

int loadusers(User users[]) {
    ifstream fin("users.txt");
    if (!fin) {
        cout<< "Error opening users.txt\n";
        return 0;
    }
    int count = 0;
    string line;
    while (getline(fin, line) && count < MAX_RECORDS) {
        stringstream ss(line);
        getline(ss, users[count].user_id, ',');
        getline(ss, users[count].first_name, ',');
        getline(ss, users[count].last_name, ',');
        getline(ss, users[count].address, ',');
        getline(ss, users[count].email, ',');
        count++;
    }
    fin.close();
    return count;
}

int loadproducts(Product products[]) {
    ifstream fin("products.txt");
    if (!fin) {
        cout<< "Error opening products.txt\n";
        return 0;
    }

    int count = 0;
    string line;
    while (getline(fin, line) && count < MAX_RECORDS) {
        stringstream ss(line);
        getline(ss, products[count].product_id, ',');
        getline(ss, products[count].product_name, ',');
        getline(ss, products[count].description, ',');
        string priceStr;
        getline(ss, priceStr, ',');
        products[count].price = stoi(priceStr);
        count++;
    }
    fin.close();
    return count;
}

int loadorders(Order orders[]) {
    ifstream fin("orders.txt");
    if (!fin) {
        cout<< "Error opening orders.txt\n";
        return 0;
    }

    int count = 0;
    string line;
    while (getline(fin, line) && count < MAX_RECORDS) {
        stringstream ss(line);
        getline(ss, orders[count].order_id, ',');
        getline(ss, orders[count].user_id, ',');
        getline(ss, orders[count].product_ordered, ',');
        string totalPaidStr;
        getline(ss, totalPaidStr, ',');
        orders[count].total_paid = stoi(totalPaidStr);
        count++;
    }
    fin.close();
    return count;
}

void fetchproductsforLinus() {
    User users[MAX_RECORDS];
    Product products[MAX_RECORDS];
    Order orders[MAX_RECORDS];
    int usercount = loadusers(users);
    int productCount = loadproducts(products);
    int orderCount = loadorders(orders);
    string linus_user_id = "";
    for (int i=0; i<usercount; i++) {
        if (tolowercase(users[i].first_name) == "linus") {
            linus_user_id = users[i].user_id;
            break;
        }
    }
    if (linus_user_id == "") {
        cout<< "User Linus not found.\n";
        return;
    }
    cout<< "\nProducts ordered by Linus:\n";
    bool found = false;
    for (int i=0; i<orderCount; i++) {
        if (orders[i].user_id == linus_user_id) {
            for (int j=0; j<productCount; j++) {
                if (products[j].product_id == orders[i].product_ordered) {
                    cout<< "- " << products[j].product_name << endl;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout<< "No products found for Linus.\n";
    }
}

int main() {
    createdummydata();  
    fetchproductsforLinus();
    return 0;
}
