//#pragma once
//#include <vector>
//
//Sual* createquiz() {
//	string quizname;
//	string question;
//	string variant1;
//	string variant2;
//	string variant3;
//	string correct;
//
//	vector<string> variants;
//
//	cout <<RED<< "Enter quiz name => "<<WHITE ;
//	cin >> quizname;
//
//	cout << endl;
//
//	cout << RED << "Enter first question => " << WHITE;
//	cin >> question;
//	cout << endl;
//
//	cout << RED << "Enter four variants => " << WHITE ;
//	cout << endl;
//	cout << "A.";
//	cin >> variant1;
//	cout << endl;
//	cout << "B.";
//	cin >> variant2;
//	cout << endl;
//	cout << "C.";
//	cin >> variant3;
//	cout << endl;
//	cout << "correct answer =>";
//	cin >> correct;
//
//
//	///file ac apppend eed kec ve sual klasindan isdfade ed
//	variants.push_back(variant1); 
//	variants.push_back(variant2);
//	variants.push_back(variant3);
//
//	Sual* sual1 = new Sual(quizname, question, variants, correct);  
//
//
//
//
//
//	ofstream file(quizname+".txt", ios::app);
//	if (file.is_open())
//		file << quizname << "\n" << sual1->Getsual() << " " << variant1 << " " << variant2 << " " << variant3 << endl;
//	else
//		cout << "Fayl aclmadi" << endl;
//
//	cout << endl;
//	cout << endl;
//
//
//	return sual1;
//
//
//
//}
