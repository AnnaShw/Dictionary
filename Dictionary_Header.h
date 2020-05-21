#pragma once
#include"DefHeader.h"
#include<stdlib.h>


class Dictionary {

	int num_def;
	Definition** Def;
public:
	Dictionary(int numd=1,int numi=1,int len=1);
	Dictionary(const Dictionary& other);
	~Dictionary();

	Dictionary& operator=(const Dictionary& D);
	bool operator == (const Dictionary& D)const;
	friend ostream& operator << (ostream& os, const Dictionary&);
	//friend istream& operator >> (istream& is, Definition&);
	Dictionary& operator+= (const Definition* D);//Add 1 interpetation
	Dictionary& operator-= (const Definition* S);// remove 1 interpetation
	Definition operator[](int index);
	int GetNumDef();
	void AlphaBet();
	void AddDefinition(const Definition *);
	void SearchWord(const String* ptr);
	void ShowIntersection();
};