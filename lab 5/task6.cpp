#include<iostream>
#include<string>
using namespace std;

struct menuitem{
	string name;
	string type;
	double price;
};

class coffeeshop{
	private:
		string order[10];
		int menu_size;
		int order_count;
	public:
		const string name;
		menuitem menu[10];
		int i,j;
		
		coffeeshop(string shopname, menuitem menu_item[], int size) : name(shopname), menu_size(size), order_count(0){
			for(i=0; i<size; i++)
			{
				menu[i] = menu_item[i];
			}
		}
		
		string addorder(string itemname)
		{
			for(i=0; i<menu_size; i++)
			{
				if(menu[i].name == itemname)
				{
					if(order_count < 10)
					{
						order[order_count++] = itemname;
						return "Order Added...";
					}
					return "Order list is full.";
				}
			}
			return "This item is currently unavailable!";
		}
		
		string fulfillorder()
		{
			if(order_count > 0)
			{
				string item = order[0];
				for(i=1; i<order_count; i++)
				{
					order[i-1] = order[i];
				}
				order_count-- ;
				return "The" + item + "is ready.";
			}
			return "All orders are fulfilled.";
		}
		
		string* listorder()
		{
			if(order_count == 0)
			{
				return NULL;
			}
			return order;
		}
		
		double dueamount()
		{
			double total = 0.0;
			 for(i=0; i<order_count; i++)
			 {
			 	for(j=0; j<menu_size; j++)
			 	{
			 		if(order[i] == menu[j].name)
			 		{
			 			total += menu[j].price;
			 			break;
					 }
				 }
			 }
			 return total;
		}
		
		string cheapestitem()
		{
			if(menu_size == 0)
			{
				return "";
			}
			menuitem cheapest = menu[0];
			for(i=0; i<menu_size; i++)
			{
				if(menu[i].price < cheapest.price)
				{
					cheapest = menu[i];
				}
			}
			return cheapest.name;
		}
		
		string* drinkonly(int& count) 
		{
        static string drink[10];
        count = 0;
        for (i=0; i<menu_size; i++) {
            if (menu[i].type == "drink") {
                drink[count++] = menu[i].name;
            }
        }
        return drink;
    }
    
    string* foodonly(int& count) 
	 {
        static string food[10];
        count = 0;
        for (i=0; i<menu_size; i++) 
		{
            if (menu[i].type == "food")
			 {
                food[count++] = menu[i].name;
            }
        }
        return food;
    }
};

int main()
{
	menuitem menu[] = {
		{"Americano", "drink", 2.00},
        {"Mocha", "drink", 3.75},
        {"Flat White", "drink", 3.25},
        {"Bagel", "food", 4.00},
        {"Croissant", "food", 3.50}
	};
	
	coffeeshop shop("Real cafe", menu, 5);
	cout << shop.addorder("Mocha") << endl;
    cout << shop.addorder("Pancakes") << endl;
    cout << "Due amount: $" << shop.dueamount() << endl;
    cout << shop.fulfillorder() << endl;
    cout << shop.fulfillorder() << endl;
    cout << "Cheapest item: " << shop.cheapestitem() << endl;
    int drinkcount;
	int  foodcount;
	int i;
    string* drink = shop.drinkonly(drinkcount);
    cout << "Drinks: ";
    for (i=0; i<drinkcount; i++)
	cout << drink[i] << " ";
    cout << endl;
    string* food = shop.foodonly(foodcount);
    cout << "Foods: ";
    for (i=0; i<foodcount; i++) 
	cout << food[i] << " ";
    cout << endl;
    return 0;
}
