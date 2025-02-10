#include<iostream>
using namespace std;

class book{
	private:
		string book_name;
		string isbn;
		string author;
		string publisher;
		
		public:
			book(string book_name, string isbn, string author, string publisher){
				this->book_name = book_name;
				this->isbn= isbn;
				this->author = author;
				this->publisher = publisher;
			}
			
			string getbook_name()
			{
				return this->book_name;
			}
			
			string getisbn()
			{
				return this->isbn;
			}
			
			string getauthor()
			{
				return this->author;
			}
			
			string getpublisher()
			{
				return this->publisher;
			}
			
			string getbookinfo()
			{
				return "Book name= " + this->book_name + "\nisbn= " + this->isbn + "\nAuthor= " + this->author +  "\nPublisher= " + this->publisher + "\n";
			}
};

int main()
{
	int i;
	book Book[5]= {
		book("ACCIDENTS DO NOT HAPPEN", "978-81-933904-8-1", "Dr Sankar Rajeev", "Rabia Mukhtar"),
		book("PROPAGATION OF GLORY LILY", "978-81-933904-6-7", "Dr. S. ANANDHI", "Gloriosa superba L"),
		book("Faulkner’s Treatment of Women", "978-81-933904-1-2", "Dr.Vibha Manoj Sharma", "Ch Hari Prasad"),
		book("SANSRITI", "978-81-933904-0-5", "Dr.Vibha Manoj Sharma", "Shaik Akbar"),
		book("BIG SCREEN BHAJANS", "978-81-933904-2-9", "JIGYASA HASIJA", "A.P. Senthil Kumar"),
	};
		cout<< "BOOK COLLECTION: \n"<< endl;
		for(i=0; i<5; i++)
		{
			cout<< "Book " << i+1 << " details: "<< endl;
			cout<< Book[i].getbookinfo() << endl;
		}
	
}
