#pragma once

class Guest {
	string fullname;
	string connected_date; //tarix saat
public:
	Guest(string fullname, string date)
	{
		this->setFullname(fullname);
		this->setDate(date);
	}

	// Copy Constructor
	Guest(const Guest& guest)
	{
		this->setFullname(guest.getFullname());
		this->setDate(guest.getDate());
	}


	void setFullname(string fullname) {
		this->fullname = fullname;
	}

	void setDate(string date) {
		this->connected_date = date;
	}

	string getFullname() const {
		return this->fullname;
	}

	string getDate() const {
		return this->connected_date;
	}
};

class Admin {
	string username;
	string password;
public:

	Admin(string username, string password) {
		this->SetUsername(username);
		this->SetPassword(password);
	}

	// Copy Constructor
	Admin(const Admin& admin) {
		this->SetUsername(admin.GetUsername());
		this->SetPassword(admin.GetPassword());
	}

	void SetUsername(string username) {
		this->username = username;
	}

	void SetPassword(string password) {
		this->password = password;
	}

	string GetUsername() const {
		return this->username;
	}

	string GetPassword()const {
		return this->password;
	}

};

class Sual {
	//
	string _sual; 
	vector<string> _variants; 
	string _duzguncavab;
	string _quizname;

public:
	Sual() {}; 
	Sual(string quizname, string sual, const vector<string>& variants, string duzgun)
		: _sual(sual), _variants(variants), _duzguncavab(duzgun), _quizname(quizname) {}

	string Getsual() const {
		return _sual;
	}

	string Getcorrect() const {
		return _duzguncavab;
	}

	vector<string> Getvariants() const {
		return _variants;
	}

	bool checkcorrect(string cavab) const {
		return (cavab == _duzguncavab);
	}
	



};

class Result {
	int Correct = 0; 
	int InCorrect = 0; 
	int Pass = 0; 
	int result=0; 
public: 
	void increasecorrect() { 
		Correct++; 

	}void increaseincorrect() { 
		InCorrect++;

	}void increasepass() {
		Pass++;

	}void increaseresult() {
		result+=10;

	}
	int Getcorrect() {
		return Correct;

	}int Getresult() {
		return result;

	}int Getincorrect() {
		return InCorrect;

	}int Getpass() {
		return Pass;

	}

};

template<typename T>
class DbSet {
	T** items = nullptr;
	int count = 0;
public:
	void addsual(const T* item)
	{


		T** nItems = new T * [count + 1];
		for (size_t i = 0; i < count; i++)
			nItems[i] = items[i];


		nItems[count] = new T(*item);
		delete[] items;
		items = nItems;
		count++;

		

	}

	

	void addguest(const T* item)
	{

		if (items == nullptr)
		{
			items = new T * [++count];
			items[0] = new T(*item);
		}
		else
		{
			T** nItems = new T * [count + 1];
			for (size_t i = 0; i < count; i++)
				nItems[i] = items[i];


			nItems[count] = new T(*item);
			delete[] items;
			items = nItems;
			count++;
		}
	}
	void addadmin(const T* item)
	{

		if (items == nullptr)
		{
			items = new T * [++count];
			items[0] = new T(*item);
		}
		else
		{
			T** nItems = new T * [count + 1];
			for (size_t i = 0; i < count; i++)
				nItems[i] = items[i];


			nItems[count] = new T(*item);
			delete[] items;
			items = nItems;
			count++;
		}
	}

	bool checkId(const int& id)
	{
		for (size_t i = 0; i < count; i++)
			if (items[i]->getId() == id)
				return true;
		return false;

	}

	void deleteByid(const int& id)
	{
		if (checkId(id))
		{
			T** nItems = new T * [count - 1];
			int index = 0;

			for (size_t i = 0; i < count; i++)
			{
				if (items[i]->getId() != id)
					nItems[index++] = items[i];
				else
					delete items[i];
			}
			delete[] items;
			items = nItems;
			count--;
		}
	}



	T* getItem(const int& id)
	{
		if (checkId(id))
			for (size_t i = 0; i < count; i++)
				if (items[i]->getId() == id)
					return items[i];
		return nullptr;
	}
	

	int getCount() const
	{
		return count;
	}



	void leadboard() {
		//leader leri yazrsan burda file ni acmaq lazim olacaq
		for (size_t i = 0; i < count; i++)
		{
			cout << "name of guest =>   " << items[i]->getFullname() << endl;
			cout << "conecctiondate of guest => " << items[i]->getDate() << endl;
		}
	}

	T** getItems() const
	{
		return items;
	}

	void suallar() {
		for (size_t i = 0; i < count; i++)
		{
			cout << items[i]->Getsual();
		}
	}
	/*void variants(string name) {
		for (size_t i = 0; i < count; i++)
		{
			items[i].
		}
	}*/
	~DbSet()
	{
		if (items != nullptr)
		{
			for (size_t i = 0; i < count; i++)
				if (items[i] != nullptr)
					delete items[i];
			delete[] items;
		}
	}

};

class Database {
public:
	
	DbSet<Admin>admins;
	DbSet<Guest>guest;
	DbSet<Sual> suals;

	bool checkAdmin(string username)
	{
		for (size_t i = 0; i < admins.getCount(); i++)

			if (admins.getItems()[i]->GetUsername() == username)
				return true;
		return false;
	}

	bool adminLogin(string username, string password)
	{
		for (size_t i = 0; i < admins.getCount(); i++)
			if (admins.getItems()[i]->GetUsername() == username && admins.getItems()[i]->GetPassword() == password)
				return true;
		return false;
	}

	void createquiz()noexcept { 

		string quizname; 
		string question;  
		string variant1; 
		string variant2; 
		string variant3; 
		string correct; 
		 
		vector<string> variants; 

		cout << RED << "Enter quiz name => " << WHITE;
		getline(cin, quizname); 

		cout << endl;

		cout << RED << "Enter first question => " << WHITE;
		getline(cin, question);
		cout << endl;

		cout << RED << "Enter four variants => " << WHITE;
		cout << endl;
		cout << "A.";
		getline(cin, variant1);
		cout << endl;
		cout << "B.";
		getline(cin, variant2);
		cout << endl;
		cout << "C.";
		getline(cin, variant3);
		cout << endl;
		cout << "correct answer =>";
		getline(cin, correct);


		///file ac apppend eed kec ve sual klasindan isdfade ed
		variants.push_back(variant1);
		variants.push_back(variant2);
		variants.push_back(variant3);

		Sual* sual1 = new Sual(quizname, question, variants, correct);

		suals.addsual(sual1);

		fstream filename("quizler.txt", ios::app);
		filename << quizname<<"\n";
		filename.close();

		fstream file(quizname + ".txt", ios::app);
		if (file.is_open())
			file << quizname << "\n" << sual1->Getsual() << "^" << variant1 << " " << variant2 << " " << variant3<<"*"<<correct << endl;
		else
			cout << "Fayl aclmadi" << endl;

		cout << endl;
		cout << endl;

		file.close();

		
		 
		

		cout << RED << "Enter second question => " << WHITE;
		getline(cin, question);
		cout << endl;

		cout << RED << "Enter four variants => " << WHITE;
		cout << endl;
		cout << "A.";
		getline(cin, variant1);
		cout << endl;
		cout << "B.";
		getline(cin, variant2);
		cout << endl;
		cout << "C.";
		getline(cin, variant3);
		cout << endl;
		cout << "correct answer =>";
		getline(cin, correct);

		variants.clear();
		variants.push_back(variant1); 
		variants.push_back(variant2); 
		variants.push_back(variant3); 

		Sual* sual2=new Sual(quizname, question, variants, correct);



		suals.addsual(sual2);

		fstream file2(quizname + ".txt", ios::app); 


		if (file2.is_open())
			file2 << sual2->Getsual() << "^" << variant1 << " " << variant2 << " " << variant3 << "*" << correct << endl;      

		else
			cout << "File aclmadi" << endl; 

		cout << endl;
		cout << endl;
		file2.close();

		cout << RED << "Enter thrid question => " << WHITE;
		getline(cin, question);
		cout << endl;

		cout << RED << "Enter four variants => " << WHITE;
		cout << endl;
		cout << "A.";
		getline(cin, variant1);
		cout << endl;
		cout << "B.";
		getline(cin, variant2);
		cout << endl;
		cout << "C.";
		getline(cin, variant3);
		cout << endl;
		cout << "correct answer =>";
		getline(cin, correct);


		variants.clear();
		variants.push_back(variant1);
		variants.push_back(variant2);
		variants.push_back(variant3);

		Sual* sual3 = new Sual(quizname, question, variants, correct);

		suals.addsual(sual3);
		fstream file3(quizname + ".txt", ios::app); 

		   



		if (file3.is_open())
			file3 << sual3->Getsual() << "^" << variant1 << " " << variant2 << " " << variant3 << "*" << correct << endl;
		else
			cout << "File aclmadi" << endl;


		file3.close();


		cout << endl;
		cout << endl;

		



	}

};

