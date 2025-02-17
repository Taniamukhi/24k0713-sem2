#include <iostream>
#include <string>
using namespace std;

class Invoice {
public:
    string part_number;
    string part_description;
    int quantity;
    double priceperitem;
    Invoice(string partnum, string partdes, int qua, double price) {
        part_number = partnum;
        part_description = partdes;
        quantity = (qua > 0) ? qua : 0;
        priceperitem = (price > 0.0) ? price : 0.0;
    }

    double getinvoiceamount()  {
        return quantity * priceperitem;
    }
};

int main() {
    Invoice item("C789", "Wrench", 2, 5.0);
    cout << "Invoice Details for Item:" << endl;
    cout << "Part Number: " << item.part_number << endl;
    cout << "Part Description: " << item.part_description << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Price Per Item: $" << item.priceperitem << endl;
    cout << "Total Invoice Amount: $" << item.getinvoiceamount() << endl;
    return 0;
}