#include"DefHeader.h"

Definition::Definition(int in,int len) :interpetation{ in } {
	if (len == 1) {
		this->word = new String();
		this->Def_Word = new String * [interpetation];
	}
	else {
		this->word = new String(SIZE);
		this->word->Spaces();
		this->word->UpperLower();
		this->Def_Word = new String * [interpetation];
		for (auto i = 0; i < this->interpetation; i++) {
			cout << "Her interpritation" << endl;
			this->Def_Word[i] = new String(SIZE);
			this->Def_Word[i]->Spaces();
			this->Def_Word[i]->UpperLower();
		}
	}
}
//------------------------------------------------------------------
Definition::Definition(const Definition& D) :interpetation{D.interpetation} {
	this->Def_Word = new String * [interpetation];
	String * help{ D.word };
	this->word = help;
	for (auto i = 0; i < interpetation; i++) {
		this->Def_Word[i] = D.Def_Word[i];
	}
}
//--------------------------------------------------------------------
Definition::~Definition() {
	for (auto i = 0;i< this->interpetation; i++)
		delete this->Def_Word[i];
	delete[] this->Def_Word;
	delete this->word;
}
//-------------------------------------------------------------------
Definition& Definition::operator=(const Definition& D) {
	if(this!=&D)
		if (this->interpetation != D.interpetation) {
			/*delete[]this->Def_Word;*/
			this->interpetation = D.interpetation;
			this->word = D.word;
			for (auto i = 0; i < this->interpetation; i++)
				this->Def_Word[i] = D.Def_Word[i];
		}
	return *this;
}
//--------------------------------------------------------------------
bool Definition::operator == (const Definition& D)const {
	if (this->word == D.word)
		return true;
	return false;
}
//-------------------------------------------------------------------
int Definition::GerInterpetation() {
	return this->interpetation;
}
//------------------------------------------------------------------
ostream& operator << (ostream& os, const Definition& D) {
	os << "The word is: " << *(D.word) << endl;
	os << "Number of interpetation is:" << D.interpetation << endl;
	for (auto i = 0; i < D.interpetation; i++) {
		os << i + 1 << ")" << *(D.Def_Word[i]) << endl;
	}
	return os;
}
//--------------------------------------------------------------------
istream& operator >> (istream& is, Definition& D) {
	cout << "Enter a definition for the word:" << endl;
	for (auto i = 0; i < D.interpetation; i++)
		is >> *D.Def_Word[i];
		return is;
}
//-------------------------------------------------------------------
Definition& Definition::operator+= (const Definition* D) {
		this->interpetation++;
		String** temp;
		temp = this->Def_Word;
		this->Def_Word = new String * [this->interpetation];
		for (auto i = 0; i < this->interpetation-1; i++)
			this->Def_Word[i] = temp[i];

		this->Def_Word[this->interpetation - 1] = *D->Def_Word;
	/*else
		cout << "Word not found." << endl;*/
	return *this;
}
//--------------------------------------------------------------------
Definition& Definition::operator-= (const Definition* S) {
	int i{ 0 }, j{ 0 };
	String** temp;
	temp = this->Def_Word;
	this->interpetation--;
	this->Def_Word = new String * [this->interpetation];
	while (j < this->interpetation) {
		if (temp[i] == *S->Def_Word)
			i++;
		else {
			this->Def_Word[j] = temp[i];
			j++;
			i++;
		}
	}
	return *this;
}

String& Definition::operator[](int index) {
	if (index <0 && index >=this->interpetation)
		cout << "Out of boundaries.Wrong index." << endl;
	return *(this->Def_Word[index]);
}
//--------------------------------------------------------------------