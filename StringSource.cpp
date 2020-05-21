#include"StringHeader.h"

String::String(int len){
	this->leng = len;
	if (this->leng <= 1) {
		str = new char[1];
		this->str[0] = '\0';
	}
	else{
		str = new char[len+1];
		cout << "Enter word:" << endl;
		cin.getline(str, SIZE);
	}
}
//--------------------------------------------------------------------
String::String(const String& other) :leng{other.leng} {
	str = new char[leng+1];
	strcpy_s(str,strlen(other.str), other.str);
}
//-------------------------------------------------------------------
String::~String() {
	delete str;
}
//-------------------------------------------------------------------
String& String::operator=(const String& S) {
	this->leng = S.leng;
	str = new char[leng + 1];
	strcpy_s(str,strlen(S.str), S.str);
	return *this;
}
//------------------------------------------------------------------
bool String::operator == (const String& S)const {
	if (strcmp(this->str, S.str) == 0)
		return true;
	return false;
}
//-------------------------------------------------------------------
char* String::GetStr() {
	return this->str;
}
//--------------------------------------------------------------------
ostream& operator << (ostream& os, const String& S) {
	os << "The sentance/word is:" << endl;
	os <<S.str << endl;
	return os;
}
//------------------------------------------------------------------
istream& operator >> (istream& is, String& S) {
	cout << "Enter sentence/word:" << endl;
	is >> S.str;
	return is;
}
//-------------------------------------------------------------------
String& String::operator+= (const String& S) {
	char temp[SIZE];
	strcpy_s(temp, this->str);
	this->leng++;
	this->str = new char[this->leng];
	for (auto i = 0; i < this->leng; i++) {
		this->str[i] = temp[i];
		if (i == (this->leng - 1))
			this->str[i] = (*S.str);
	}
	return *this;
}
//-------------------------------------------------------------------
String& String::operator-= (const String& S) {
	char temp[SIZE];
	strcpy_s(temp, this->str);
	this->leng--;
	this->str = new char[this->leng];
	for (auto i = 0; i < this->leng; i++) {
		this->str[i] = temp[i];
	}
	return *this;
}
//-------------------------------------------------------------------
char String::operator[](int index) {
	if (index >= 0 && index < this->leng)
		return this->str[index];
	else {
		cout << "Out of boundaries.Wrong index." << endl;
		exit(1);
	}
}
//---------------------------------------------------------------------
void String::SetStr(char* st) {
	strcpy_s(this->str,strlen(st), st);
}
//-------------------------------------------------------------------
void String::UpperLower() {
	if (isupper(this->str[0]) == 0)
		str[0]=toupper(str[0]);
}
//-------------------------------------------------------------------
void String::Spaces() {
	char temp[SIZE];
	strcpy_s(temp, this->str);
	int i = 0, j = 0;
	while (this->str[i]!='\0') {
		this->str[j] = temp[i];
		if(this->str[i]== ' ')
			///skip extra spaces
			while (this->str[i + 1] == ' ') {
				i++;
			}
		i++;
		j++;
	}
	this->str[j] = '\0';
}
//-------------------------------------------------------------------