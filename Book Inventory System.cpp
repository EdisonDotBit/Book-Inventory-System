// BOOK INVENTORY SYSTEM BY GROUP 5

// Headers used
#include <iostream> 
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h> // new header used to change the font color of the system 

#pragma warning(disable: 4996) // to ignore warnings in getch 
// could also be solved by using _getch instead of getch 
// getch works in old compilers but not on VS Code.		

using namespace std;

struct Book {
private:
	string id, title, author, edition, publication, date; //private variables
public:
	//setters - assigning user value to private variables
	void setid(string a) { id = a; }
	void setTitle(string b) { title = b; }
	void setAuthor(string c) { author = c; }
	void setEdition(string d) { edition = d; }
	void setPublication(string e) { publication = e; }
	void setDate(string f) { date = f; }
	//getters - getting the values from private variables
	string getid() { return id; }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	string getEdition() { return edition; }
	string getPublication() { return publication; }
	string getDate() { return date; }
};

// inputting functions with counter as parameter
void addBook(unsigned int counter);
void deleteBook(unsigned int counter);
void editBook(unsigned int counter);
void searchBook(unsigned int counter);
void viewAllBooks(unsigned int counter);
void quit();

// counter for Book array
unsigned int counter = 0;

// function for incrementing counter
void increment(unsigned int a) {
	a++;
	counter = a;
}

// function for decrementing counter
void decrement(unsigned int a) {
	a--;
	counter = a;
}

//Book class array initialization
Book books[1000]{};

// save book function 
bool save(Book obj[], unsigned int length) {
	bool result = false;
	std::ofstream outFile;
	outFile.open("data.txt");
	if (outFile.good()) {
		outFile << length << std::endl;
		for (unsigned int x = 0; x < length; x++) {
			outFile << obj[x].getid() << std::endl;
			outFile << obj[x].getTitle() << std::endl;
			outFile << obj[x].getAuthor() << std::endl;
			outFile << obj[x].getEdition() << std::endl;
			outFile << obj[x].getPublication() << std::endl;
			outFile << obj[x].getDate() << std::endl;
			outFile << std::endl;
		}
		result = true;
	}
	outFile.close();
	return result;
}

// load book function 
bool load(Book obj[], unsigned int& length)
{
	bool result = false;
	std::ifstream inFile;
	inFile.open("data.txt");
	std::string tmp;
	unsigned int count = 0;
	if (inFile.good()) {
		tmp.clear();
		getline(inFile, tmp);
		count = atoi(tmp.c_str());
		for (unsigned int x = 0; x < count; x++) {
			tmp.clear();
			getline(inFile, tmp);
			obj[x].setid(tmp);

			tmp.clear();
			getline(inFile, tmp);
			obj[x].setTitle(tmp);

			tmp.clear();
			getline(inFile, tmp);
			obj[x].setAuthor(tmp);

			tmp.clear();
			getline(inFile, tmp);
			obj[x].setEdition(tmp);

			tmp.clear();
			getline(inFile, tmp);
			obj[x].setPublication(tmp);

			tmp.clear();
			getline(inFile, tmp);
			obj[x].setDate(tmp);

			tmp.clear();
			getline(inFile, tmp);

		}
		length = count;
		result = true;
	}
	inFile.close();
	return result;
}

void mainMenu() {

	string choice;
	unsigned int loadsave;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	//Main Menu;
	system("CLS");
	SetConsoleTextAttribute(h, 11); cout << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); cout << "					  BOOK INVENTORY SYSTEM" << endl;
	SetConsoleTextAttribute(h, 11); cout << "=====================================================================================================================" << endl;
	//std:: left and setw(10) 
	//or set width to the left, to keep the text in the right even when fullscreened
	SetConsoleTextAttribute(h, 14);
	std::cout << std::left << std::setw(10) << "[1]ADD BOOK" << endl;
	std::cout << std::left << std::setw(10) << "[2]EDIT BOOK" << endl;
	std::cout << std::left << std::setw(10) << "[3]SEARCH BOOK" << endl;
	std::cout << std::left << std::setw(10) << "[4]VIEW ALL BOOKS" << endl;
	std::cout << std::left << std::setw(10) << "[5]DELETE BOOKS" << endl;
	std::cout << std::left << std::setw(10) << "[6]SAVE BOOKS" << endl;
	std::cout << std::left << std::setw(10) << "[7]LOAD BOOKS" << endl;
	std::cout << std::left << std::setw(10) << "[8]QUIT" << endl;

	cout << endl; // space 

	cout << "ENTER CHOICE: ";
	cin >> loadsave;
	system("CLS");

	// Switch case statements for function calls. Use switch case statements when your declared variable is char or int. 
	// Use switch statements to make your code simplier and easier to understand. 
	switch (loadsave) {
	case 1:
		cin.ignore();
		addBook(counter); //function call
		break;
	case 2:
		cin.ignore();
		editBook(counter); //function call
		break;
	case 3:
		cin.ignore();
		searchBook(counter);//function call
		break;
	case 4:
		cin.ignore();
		viewAllBooks(counter); //function call	
		break;
	case 5:
		cin.ignore();
		deleteBook(counter); //function call	
		break;
	case 6:
		save(books, counter); //function call
		mainMenu();
		break;
	case 7:
		load(books, counter); //function call
		mainMenu();
		break;
	case 8:
		quit();	 //function call //quit button 
	default:
		mainMenu();
	}
	_getch();
}

void isRegister() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("CLS");
	int ch;
	int choice;
	string username, password, pin;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); cout << "					  REGISTER" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "Enter username: ";
	cin >> username;
	cout << "\nReminder: Password must be into 8 - 16 characters." << endl;
	cout << "Enter password: ";
	ch = _getch();

	while (ch != 13) { // to make inputted password into asterisk 
		password.push_back(ch);
		cout << '*';
		ch = getch();
	}

	if ((password.length() < 8) || (password.length() > 16)) { // In order for the user to enter password that is into 8 - 16 characters
		cout << "\n\nERROR! Password does not meet the requirement." << endl;
		cout << "Registration failed!\n" << endl;
		cout << "Do you want to continue? ([1]Yes / [2]No): ";
		cin >> choice;
		if (choice == 1) {
			isRegister();
		}
		else if (choice == 2) {
			cout << "Operation cancelled." << endl;
			system("PAUSE");
		}
		else {
			cout << "Not in the choices. Operation cancelled." << endl;
			system("PAUSE");
		}
	}
	else {
		cout << "\n";

		cout << "Enter PIN Recovery: ";  // for account recovery 
		cin >> pin;

		// Database for register 
		ofstream file; // in order to store username and password into the file 
		file.open(username + ".txt");
		file << username << endl;
		file << password << endl;
		file << pin << endl;
		file.close();
		cout << "\nAccount registered successfully" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);
		system("PAUSE");
	}

}

bool isLoggedIn() { // Login page part 1 

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	string username, password, un, pw;
	int ch;

	system("CLS");
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); cout << "					  LOGIN" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	ch = _getch();

	while (ch != 13) { // to make inputted password into asterisk 
		password.push_back(ch);
		cout << '*';
		ch = getch();
	}

	cout << "\n";

	// single account database 
	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) { // to determine if username and password matches the data
		cout << "\nWelcome! " << username;
		return true;
	}
	else {
		return false;
	}
}

void login() { // Login page part 2

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int choice;
	bool status = isLoggedIn(); // calls the isLoggedIn function 

	if (!status) { // If the inputted credentials didn't matched the data
		SetConsoleTextAttribute(h, 14);
		cout << "\nLogin error!" << endl;
		cout << "Wrong username or password" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "Do you want to continue? ([1]Yes / [2]No): ";
		cin >> choice;
		if (choice == 1) {
			login();
		}
		else if (choice == 2) {
			cout << "Operation cancelled." << endl;
			system("PAUSE");
		}
		else {
			cout << "Not in the choices. Operation cancelled." << endl;
			system("PAUSE");
		}
	}
	else { // If the inputted credentials matched the data 
		SetConsoleTextAttribute(h, 14);
		cout << "\nSuccessfully logged in!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);
		system("PAUSE");
		mainMenu(); // Proceeds to mainMenu function 
	}
}

void isForgot() {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	string username, password, pin, un, pw, pn;
	int ch;

	system("CLS");
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	cout << "					  ACCOUNT RECOVERY" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;

	SetConsoleTextAttribute(h, 14);
	cout << "\nEnter username: ";
	cin >> username;

	// single account database 
	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);
	getline(read, pn);

	if (un == username) { // To search the username
		SetConsoleTextAttribute(h, 14);
		cout << "\nAccount Founded: " << username << endl; // Proceeds to detect the username 
		cout << "Enter PIN Recovery: ";  // Then requires to enter a pin recovery for that acc in order to recover the lost password 
		cin >> pin;
		if (pn == pin) { // When correct pin recovery is inputted
			cout << "\nPassword recovered successfully " << endl; // It will show the password of that account 
			cout << "Password: " << pw << endl << endl;
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14);
			system("PAUSE");
		}
		else {
			SetConsoleTextAttribute(h, 14);
			cout << "Wrong PIN recovery!" << endl; // If the inputted pin is wrong
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14);
			system("PAUSE");
		}
	}
	else {
		SetConsoleTextAttribute(h, 14);
		cout << "\nAccount not founded" << endl; // If the program does not identify the username 
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);
		system("PAUSE");
	}
}

// main function
int main() {

	int choice;
	int ch;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("CLS");
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); cout << "					  LOGIN PAGE" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "[1]REGISTER" << endl;
	cout << "[2]LOGIN" << endl;
	cout << "[3]FORGOT PASSWORD" << endl;
	cout << "[4]EXIT" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		cin.ignore();
		isRegister();
		main();
		break;
	case 2:
		cin.ignore();
		login();
		main();
		break;
	case 3:
		cin.ignore();
		isForgot();
		main();
		break;
	case 4:
		exit(0);
	default:
		main();
	}

	return 0;
}

// addBook function
void addBook(unsigned int counter) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // To change the color of the text

	string id, title, author, edition, publication, date;
	std::cout << std::left << std::setw(10) << "ADD BOOK" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "======================================================================================================================" << endl;
	if (counter < 1000) {
		SetConsoleTextAttribute(h, 14);
		std::cout << std::left << std::setw(10) << "Enter Book ID: "; // ISBN or id is the same, I only prefer ID so that people would know what to input
		getline(cin, id); // getline - just like cin but includes white spaces
		for (unsigned int i = 0; i < counter; i++) {
			// to know if the ID already exist or not
			if (books[i].getid() == id) {
				SetConsoleTextAttribute(h, 11);	std::cout << std::left << std::setw(10) << "========================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK ALREADY EXIST\n\n";
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "========================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue..." << endl;
				_getch();
				mainMenu();
			}
		} // will proceed to enter title and the other if there is no existing ID yet
		SetConsoleTextAttribute(h, 14);
		std::cout << std::left << std::setw(10) << "Enter Title: ";
		getline(cin, title);
		std::cout << std::left << std::setw(10) << "Enter Author: ";
		getline(cin, author);
		std::cout << std::left << std::setw(10) << "Enter Edition: ";
		getline(cin, edition);
		std::cout << std::left << std::setw(10) << "Enter Publication: ";
		getline(cin, publication);
		std::cout << std::left << std::setw(10) << "Enter Date Inputted: ";
		getline(cin, date);
		books[counter].setid(id); // assigning the values entered to book object
		books[counter].setTitle(title);
		books[counter].setAuthor(author);
		books[counter].setEdition(edition);
		books[counter].setPublication(publication);
		books[counter].setDate(date);
		increment(counter);	// calling function to increment counter
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK ADDED SUCCESSFULLY!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
		_getch();
		mainMenu();
	}
	else {
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TO BE ADDED!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		cout << endl; // space
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
		_getch();
		mainMenu();
	}
}

// editBook function 
void editBook(unsigned int counter) {
	system("CLS");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // To change the color of the text

	string editid, choice;
	string id, title, author, edition, publication, date;

	SetConsoleTextAttribute(h, 14); cout << "\nEDIT BOOK\n\n";
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	// if there is no book added in the program yet 
	if (counter == 0) {
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "THERE IS NO BOOK TO EDIT!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
		_getch();
		mainMenu();
	}
	SetConsoleTextAttribute(h, 14); cout << "Enter Book ID: ";
	getline(cin, editid);
	// finding a match using for loop
	for (unsigned int i = 0; i < counter; i++) {
		if (books[i].getid() == editid) {
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK FOUND!\n\n";
			SetConsoleTextAttribute(h, 11); cout << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14);
			cout << "Book ID: " << books[i].getid() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "AUTHOR: " << books[i].getAuthor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl;
			cout << "DATE INPUTTED: " << books[i].getDate() << endl;
			SetConsoleTextAttribute(h, 11);	std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nDo you want to edit?\n[1]Yes\n[2]No" << endl;
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nEnter choice : ";
			getline(cin, choice);
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			if (choice == "1") {
				SetConsoleTextAttribute(h, 14);
				// re-entering values
				std::cout << std::left << std::setw(10) << "Enter Title: ";
				getline(cin, title);
				std::cout << std::left << std::setw(10) << "Enter Author: ";
				getline(cin, author);
				std::cout << std::left << std::setw(10) << "Enter Edition: ";
				getline(cin, edition);
				std::cout << std::left << std::setw(10) << "Enter Publication: ";
				getline(cin, publication);
				std::cout << std::left << std::setw(10) << "Enter Date Inputted: ";
				getline(cin, date);
				books[i].setTitle(title);
				books[i].setAuthor(author);
				books[i].setEdition(edition);
				books[i].setPublication(publication);
				books[i].setDate(date);
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK EDITED SUCCESSFULLY!" << endl;
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
				_getch();
				mainMenu();
			}
			else {
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nOPERATION CANCELLED" << endl;
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
				_getch();
				mainMenu();
			}
		}
	} // if the system did not found any id that the user wants to edit 
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nNO BOOK FOUNDED!" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
	_getch();
	mainMenu();
}

// searchBook function 
void searchBook(unsigned int counter) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // To change the color of the text

	string id;
	unsigned int choice;
	bool print = false; // boolean expression to decide which to print
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "SEARCH BOOK\n\n";
	if (counter == 0) {
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "THERE IS NO BOOK TO SEARCH!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
		_getch();
		mainMenu();
	}
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Enter Book ID: ";
	getline(cin, id);
	for (unsigned int i = 0; i < counter; i++) {
		// finding a match using for loop
		if (books[i].getid() == id) {
			SetConsoleTextAttribute(h, 11);	std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14);
			std::cout << std::left << std::setw(10) << "\nBOOK FOUND!\n\n";
			cout << "Book ID: " << books[i].getid() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "AUTHOR: " << books[i].getAuthor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl;
			cout << "DATE INPUTTED: " << books[i].getDate() << endl;
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			print = true;
		}
	}
	if (print) {
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\n\nPress any key to continue . . .";
		_getch();
		mainMenu();
	}
	else { // If there is no book found
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);	std::cout << std::left << std::setw(10) << "\nBOOK NOT FOUND!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
		_getch();
		mainMenu();
	}
}

// viewAllBoooks function 
void viewAllBooks(unsigned int counter) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // To change the color of the text

	// display all the values on the library using book array
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "VIEW ALL BOOKS\n\n";
	for (unsigned int i = 0; i < counter; i++) {
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14);
		cout << "Book ID: " << books[i].getid() << endl;
		cout << "TITLE: " << books[i].getTitle() << endl;
		cout << "AUTHOR: " << books[i].getAuthor() << endl;
		cout << "EDITION: " << books[i].getEdition() << endl;
		cout << "PUBLICATION: " << books[i].getPublication() << endl;
		cout << "DATE INPUTTED: " << books[i].getDate() << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	}
	cout << endl; // space
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . .";
	_getch();
	mainMenu();
}

// deleteBook function
void deleteBook(unsigned int counter) {

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // To change the color of the text

	string id;
	unsigned int choice;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "DELETE BOOK\n\n";
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	// if there is no any book added yet 
	if (counter == 0) {
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "THERE IS NO BOOK TO DELETE!" << endl;
		SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
		SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . .";
		_getch();
		mainMenu();
	}
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Enter Book ID: ";
	getline(cin, id);
	// finding a match using for loop
	for (unsigned int i = 0; i < counter; i++) {
		if (books[i].getid() == id) {
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "======================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14);
			std::cout << std::left << std::setw(10) << "\nBOOK FOUNDED!\n\n";
			cout << "Book ID: " << books[i].getid() << endl;
			cout << "TITLE: " << books[i].getTitle() << endl;
			cout << "AUTHOR: " << books[i].getAuthor() << endl;
			cout << "EDITION: " << books[i].getEdition() << endl;
			cout << "PUBLICATION: " << books[i].getPublication() << endl;
			cout << "DATE INPUTTED: " << books[i].getDate() << endl;
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Do you want to delete?\n[1]Yes\n[2]No" << endl;
			SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
			SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Enter Choice : ";
			cin >> choice;
			if (choice == 1) {
				books[i].setid(""); // setting the value to none
				books[i].setTitle("");
				books[i].setAuthor("");
				books[i].setEdition("");
				books[i].setPublication("");
				books[i].setDate("");
				for (int a = i; a < counter; a++) {
					// adjusting the values after deletion of data eg. data from book[4] copied to book[3]
					books[a] = books[a + 1];
				}
				books[999].setid(""); // adjustment if the inventory is full(1000 books)
				books[999].setTitle("");
				books[999].setAuthor("");
				books[999].setEdition("");
				books[999].setPublication("");
				books[999].setDate("");
				decrement(counter); // calling function to decrement counter
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK SUCCESSFULLY DELETED!" << endl;
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nPress any key to continue . . ." << endl;
				_getch();
				mainMenu();
			}
			else {
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nOPERATION CANCELLED" << endl;
				SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
				SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
				getch();
				mainMenu();
			}
		}
	} // if theres no book founded
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "\nBOOK NOT FOUND!" << endl;
	SetConsoleTextAttribute(h, 11); std::cout << std::left << std::setw(10) << "=====================================================================================================================" << endl;
	SetConsoleTextAttribute(h, 14); std::cout << std::left << std::setw(10) << "Press any key to continue . . ." << endl;
	_getch();
	mainMenu();
}

void quit() {
	// quit functions
	_exit(1);
}