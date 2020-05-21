#include"Dictionary_Header.h"

Dictionary::Dictionary(int numd,int numi,int len) :num_def{numd} {
	this->Def = new Definition * [num_def];
	for (auto i = 0; i < num_def; i++) {
		if(num_def!=1 || len!=1)
			Def[i] = new Definition(numi,len);
		else
			Def[i] = new Definition();
	}
}
//------------------------------------------------------------------
void Dictionary::AlphaBet() {
	for(auto i=0;i<this->num_def;(i+=2))
		if (*(this->Def[i]->word->GetStr()) > *(this->Def[i + 1]->word->GetStr())) {
			Definition help{* this->Def[i] };
			this->Def[i] = this->Def[i + 1];
			this->Def[i + 1] = &help;
		}
}
//------------------------------------------------------------------
void Dictionary::ShowIntersection() {
	Dictionary temp{ *this };
	for (auto i = 0; i < this->num_def; i++) {
		for (auto j = 0; j < this->num_def; j++)
			for (auto k = i+1; k < this->num_def; k++)
				if (*(this->Def[i]->Def_Word[j] )== *(this->Def[k]->Def_Word[j])) {
					cout << *(this->Def[i]->word) << ", " << *(this->Def[k]);
					/*temp -=Def[i];
					temp -= Def[k];*/
					
				}
	}
}
//--------------------------------------------------------------------------------------------
void Dictionary::AddDefinition(const Definition* obj) {
	Definition* temp=NULL;
	for(auto i=0;i<this->num_def;i++){
		if (*(this->Def[i]->word )== *(obj->word))
			temp = this->Def[i];
		}
	if (temp == NULL) {
		temp = new Definition(*obj);
		*this += temp;
		//**this->Def += temp;
	}
	else {
		*temp += obj;
	}
}
//------------------------------------------------------------------
void Dictionary::SearchWord(const String* ptr) {
	for (auto i = 0; i < this->num_def; i++) {
		if (*(this->Def[i]->word) == *ptr) {
			cout << **(this->Def[i]->Def_Word);
			return;
		}

			
	}
	cout << "Word not in this dictionary." << endl;
}
//----------------------------------------------------------
Dictionary::Dictionary(const Dictionary& other) :num_def{other.num_def} {
	this->Def = new Definition * [num_def];
	for (auto i = 0; i < this->num_def; i++)
		this->Def[i] = other.Def[i];
}
//-------------------------------------------------------------------
Dictionary::~Dictionary() {
	for (auto i = 0; i < this->num_def; i++) {
		delete this->Def[i];
	}
	delete[] Def; 
}
//-------------------------------------------------------------------
Dictionary& Dictionary::operator=(const Dictionary& D) {
	if (this != &D) {
		/*if (this->Def)
			delete[]Def;*/
		this->num_def = D.num_def;
		this->Def = new Definition * [num_def];
		for (auto i = 0; i < this->num_def; i++)
			this->Def[i] = D.Def[i];
	}
	else
		cout << "Self assignment!" << endl;
	return *this;
}
//---------------------------------------------------------------
bool Dictionary::operator == (const Dictionary& D)const {
	if (this->num_def != D.num_def)
		return false;
	for (auto i = 0; i < D.num_def; i++) {
		if (this->Def[i] != D.Def[i])
			return false;
	}
	return true;
}
//---------------------------------------------------
ostream& operator << (ostream& os, const Dictionary& D) {
	for (auto i = 0; i < D.num_def; i++)
		os << *(D.Def[i]) << " ";
	os << endl;
	return os;
}
//-------------------------------------------------------
int Dictionary::GetNumDef() {
	return this->num_def;
}
//------------------------------------------------------
Dictionary& Dictionary::operator+= (const Definition* D) {
	Dictionary temp(*this);
	this->num_def++;
	this->Def = new Definition* [num_def];
	for (auto i = 0; i < num_def-1; i++) {
		this->Def[i] = temp.Def[i];
	}
	Definition temp1{ *D };
	this->Def[num_def -1] =&temp1;
	return *this;
}
//------------------------------------------------------
Dictionary& Dictionary::operator-= (const Definition* S){
	String** temp;
	int j{ 0 };
	for (auto i = 0; i < this->num_def; i++) {
		temp = this->Def[i]->Def_Word;
		if (this->Def[i]->Def_Word != S->Def_Word) {
			this->Def[i]->Def_Word[j] = *temp;
			j++;
		}
	}
	return *this;
}
//---------------------------------------------------------
Definition Dictionary::operator[](int index) {
	if (index >= 0 && index < this->num_def) 
		return *this->Def[index];
	else {
		cout << "Out of boundary of the array: " << endl;
		exit(1);
	}
}
//------------------------------------------------------------------