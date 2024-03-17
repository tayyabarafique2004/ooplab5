#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book {
private:
	string title;
	string author;
	int pulishedYear;
public:
	Book(string title, string author, int	publishedYear) {

		this->title = title;
		this->author = author;
		this->pulishedYear = publishedYear;
	}
	string getTitle() {
		return title;
	}

	string getAuthor() {
		return author;


	}
	int getYear() {
		return pulishedYear;

	}
};
class Library {
	vector<Book> books;
public:
	void addBook(string title, string author,int publishedYear) {

		books.push_back(Book(title, author, publishedYear));
		cout << endl;


	}
	void listBooks() {
		for (int i = 0; i < books.size(); i++) {

			cout << "Book title:  " << books[i].getTitle() << endl;
			cout << "Book author:  " << books[i].getAuthor() << endl;
			cout << "Book published year:  " << books[i].getYear() << endl;
		}





	}
	void removeBooks(string title, string author, int publishedYear) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].getTitle() == title && books[i].getAuthor() == author && books[i].getYear() == publishedYear) {
			
				books.erase(books.begin() + i);
				break;
			
			}
		
		}

	}


};
void userInterface(Library& mylib) {
	cout << endl;
	string command;
	cout << "Welcome to our library!" << endl; 
	cout << "enter: add to add books"<<endl<<"remove to remove books"<<endl<<"list to display list of books"<<endl;
	getline(cin, command);
	if (command == "add") {
		string title, author;
		int year;
		cout << "Enter title: ";
		getline(cin, title);
		cout << endl;
		cout << "Enter author: ";
		getline(cin, author);
		cout << endl;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		mylib.addBook(title, author, year);
		userInterface(mylib);
	}
	else if (command == "list") {
		mylib.listBooks();
		userInterface(mylib);
	}
	else if (command == "remove") {
		string title, author;
		int year;
		cout << "Enter title: ";
		getline(cin, title);		cout << endl;
		cout << "Enter author: ";
		getline(cin, author);
		cout << endl;
		cout << "Enter year: ";
		cin >> year;
		cout << endl;
		mylib.removeBooks(title, author, year);
		userInterface(mylib);
	}
	else if (command == "exit") {
		cout << "Thank you for using our library!" << endl;
	}
	else {
		cout << "Invalid command. Please try again." << endl;
		userInterface(mylib);
	}
}




int main() {







	Library mylib;
	userInterface(mylib);
	/*mylib.addBook("C++ with tayyaba", "Tayyaba", 2000);
	mylib.addBook("java with samreen", "samreen", 2004);

	mylib.addBook("oop hacks", "umama", 2005);
	mylib.listBooks();
	mylib.removeBooks("C++ with tayyaba", "Tayyaba", 2000);*/

	return 0;
}