#pragma once
#include"StringHeader.h"

class Dictionary;

class Definition {
	int interpetation;
	String* word;//word
	String** Def_Word;//definitions if the word
public:
	Definition(int in = 1,int len=1);//default+parametrs Ctor
	Definition(const Definition& D);//Copy Ctor
	~Definition();

	Definition& operator=(const Definition& D);
	bool operator == (const Definition& D)const;
	friend ostream& operator << (ostream& os, const Definition&);
	friend istream& operator >> (istream& is, Definition&);
	Definition& operator+= (const Definition* D);//Add 1 interpetation
	Definition& operator-= (const Definition* S);// remove 1 interpetation
	String& operator[](int index);
	int GerInterpetation();
	friend class Dictionary;
};