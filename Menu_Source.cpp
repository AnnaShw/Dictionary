#include"Menu_Header5476yu5.h"

Menu::Menu(int numdef, int numinter) {
	this->ptr = new Dictionary(numdef, numinter);
}
//------------------------------------------------------------------
Menu::Menu(const Menu& other) {
	(*this->ptr) = (*other.ptr);
}
//---------------------------------------------------------------------
Menu::~Menu() {
	delete ptr;
}
//---------------------------------------------------------------------
void Menu::MainMenu() {
	int choice{ 0 }, def{ 0 }, inter{ 0 }, choice2{0};
	cout << "Hello!This is dictionary!" << endl;
	cout << "Here you options:" << endl;
	while (choice != 6) {
	cout << "Press 1-for creating dictionary." << endl;
	cout << "Press 2-for insert new definition to the dictionary." << endl;
	cout << "Press 3-for add new interpritation for already existing definiton." << endl;
	cout << "Press 4-for searching defination in the dictionary." << endl;
	cout << "Press 5-for presentation all definitions that had at least 1 shared intarpritation." << endl;
	cout << "Press 6-for exit." << endl;
	cin >> choice;
	getchar();
	if (choice2 != choice || choice2 == 0) {
		if (choice == 1) {
			cout << "Enter how many definitions you want there:" << endl;
			cin >> def;
			getchar();
			cout << "Enter how many interpritation you want there:" << endl;
			cin >> inter;
			getchar();
			ptr =new Dictionary(def,inter,SIZE);
			//ptr->AlphaBet();
		}
	}
	else {
		cout << "You already made a dictionary.So chose another option:" << endl;
		cin >> choice;
	}
		if(choice == 2) {
			Definition* temp = new Definition(1, SIZE);
			(*ptr) += temp;
		}
		else if (choice == 3) {
			Definition* t = new Definition(1,SIZE);
			ptr->AddDefinition(t);
		}
		else if (choice == 4) {
			cout << "Now you will enter word that you want to find:" << endl;
			String temp(SIZE);
			ptr->SearchWord(&temp);
		}
		else if (choice == 5) {
			this->ptr->ShowIntersection();
		}
		else if (choice == 6) {
			cout << "Have a good day!" << endl;
			this->ptr = NULL;
		}
		choice2 = choice;
	}

}