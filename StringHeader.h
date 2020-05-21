#pragma once
#include<iostream>
#include<string.h>
#include <stdio.h>
#include <ctype.h>
#define SIZE 50
#define _CRT_OBSOLETE_NO_WARNINGS
using namespace std;

class String {
	int leng;
	char* str;
public:
	String(int len = 1);//default+parametrs Ctor
	String(const String& other);//Copy Ctor
	~String();//Dctor

	String& operator=(const String& S);
	bool operator == (const String& S)const;
	friend ostream& operator << (ostream& os, const String&);
	friend istream& operator >> (istream& is, String&);
	String& operator+= (const String& S);//Add 1 letter
	String& operator-= (const String& S);// remove 1 letter
	char operator[](int index);
	void UpperLower();//making letter upper case if neded
	void Spaces();//function will make sure that there is one space betwen words
	char* GetStr();
	void SetStr(char*);
};