#pragma once
#include"Dictionary_Header.h"

class Menu {
	Dictionary* ptr;
public:
	Menu(int numdef=1,int numinter=1);//Ctor
	Menu(const Menu& other);//Copy Ctor
	~Menu();//Dctor
	void MainMenu();
};