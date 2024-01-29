#pragma once







void start() { 
#pragma region datas 
	Database db;

	Admin* admin = new Admin("admin", "admin");
	db.admins.addadmin(admin);
	Admin* admin1 = new Admin("admin1", "admin23"); 
	db.admins.addadmin(admin1);  
	Admin* admin2 = new Admin("admin2", "admin24"); 
	db.admins.addadmin(admin2); 





	string menuOne = R"(
				[1] => As Gusest
				[2] => As Admin
				[0] => Exit
		)";

	string menuAdmin = R"(
				[1] =>  Create Quiz
				[2] =>  Start Quiz
				[3] =>  Leader Board(Top 10)
				[4] =>  Add admin :)
				[0] =>  Exit )";
	string menuplayer = R"(
				[1] => Start Quiz
				[2] => Submit
				[0] => Exit 
)";
	string menusual = R"(
				[1] => Pass
				[2] =>Submit
				)";
	string menuquiz = R"(
				[1] =>  new
				[2] =>  back
				[3] => Submit)";
	string menuquizcavabi = R"(
				[Answer 1] => A
				[Answer 2] => B
				[Answer 3 ] => C
				[Answer 4 ] => Pass				)";


	//Sual* s1 = new Sual( "Azrap","Pasterin-adi-nedir?", "A.Ilqar B.Samxal C.Perviz ", "C.Perviz");
	//db.suals.addsual(s1);
#pragma endregion 

	while (true)
	{
		cout << CYAN << menuOne << WHITE << endl;

		cout << "Menudan secim edin => ";

			#pragma region enter  

		int select;

		cin >> select;

		if (select == 1)
		{
			cin.ignore();

			string nameg;

			cout << "enter name ";

			getline(cin, nameg);

			cout << CYAN << "    " << WHITE << endl;

			string date;
			cout << "Enter date => ";
			getline(cin, date);



			Guest* guest = new Guest(nameg, date);

			db.guest.addguest(guest);
			fstream players("players.txt", ios::app);
			players << guest->getFullname() << "\n";
			Sleep(500);
			players.close();
			system("CLS");

			cout << endl;

			cout << endl;


			cout << endl;

			int a;

			cout << CYAN << menuplayer << WHITE << endl;


			cout << endl;

			cout << endl;

			cout << "Enter your choice => ";

			cin >> a;

			cout << endl;

			cout << endl;
			#pragma endregion
			while (true)
			{
				if (a == 1)
				{
					
					cin.ignore();


					fstream file1("quizler.txt") ; 
					if (!file1.is_open()) { 
						cout << "File açılamadı!" << std::endl; 
					}
					 
					string quizname;  

					while (getline(file1, quizname)) {  

						cout << CYAN << quizname << "\n" << WHITE << endl; 
					}
					file1.close(); 

					cout << endl;
					
					string name;
					cout << RED << "Enter quizname " << WHITE;
					cin >> name;
					Sleep(400);
					system("cls");
					fstream quiz1(name + ".txt");
					if (!quiz1) {
						cout << "file doesnt open" << endl;
					}

					/*string sual; 
					string variant1;
					string variant2; 
					string variant3;
					string correct;*/
					




					string question;
					vector<string> questions;
					while (getline(quiz1, question)) {
						questions.push_back(question);

					}
					
					cout << endl;
					cout<<CYAN << questions[0]<<WHITE << endl; 

					///1ci sual basdyr
					Result r11; 

					for (size_t i = 1; i < 4; i++)
					{
						
						int questionend = questions[i].find("^");
						string question = questions[i].substr(0, questionend);
						cout << question<<" " << endl; 
						cout << endl;

						int end2 = questions[i].find("*");
						string variants = questions[i].substr(questionend + 1, questions[i].length());

						char correct = questions[i].back();
						string lazim;
						int nomre = 0;
						for (size_t j = 0; j < variants.size(); j++) 
						{
							if (variants[j] != ' ') lazim += variants[j]; 

							else {
								if (nomre == 0) cout << "A => " << lazim << endl;
								if (nomre == 1) cout << "B => " << lazim << endl;
								if (nomre == 2) cout << "C => " << lazim << endl;
								nomre++;
								lazim = "";
							}
						}
						cout << endl;

						char cavabs;
						int chch;
						cout << menusual << endl;
						cout << endl;


						cout << CYAN << "enter your choice  :)" << WHITE << endl;
						cin >> chch;
						if (chch == 2) {
							cin.ignore();
							cout << "Enter your answer => ";
							cin >> cavabs;
							if (cavabs == correct) {
								r11.increasecorrect();
							}
							else
								r11.increaseincorrect();

						}
						else if (chch == 1) {
							r11.increasepass();
						}
					}

					
					cout << r11.Getcorrect()<<"\n";
					cout << r11.Getincorrect() << endl;
					cout << r11.Getpass() << endl;



					Sleep(1200000);

					system("cls");

					break;

				}

				else if (a == 2) {
				/*	R"(
				[1] => Start Quiz
				[2] => Submit
				[0] => Exit 
)";*/
					/*cin.ignore();
					string */

					//netice gostermelidi
					//save edmelidi file yazmaq lazmdi
					/*cout << CYAN << "RESULT :)" << WHITE << endl;
					cout << "Corrects => "<< r1.Getcorrect() << endl;
					cout << "InCorrects => " << r1.Getincreaseincorrect() << endl;
					cout << "Passed => "<< r1.Getpass() << endl;

					fstream results("results.txt");
					results << r1.Getcorrect() << " " << r1.Getincreaseincorrect() << r1.Getpass() << " " << endl;

					results.close()*/;
					Sleep(3200);

					system("cls");

					break;

				}
				else if (a == 0) {
					//save zad edmr bra bele qalsin
					cout << BOLDYELLOW << "You return to first menu baby :)" << WHITE << endl;

					Sleep(1000);

					system("cls");

					break;
				}


			}

		}

		else if (select == 2)
		{
			cin.ignore();

			string username, password;

			cout << "username: ";

			cin >> username;

			cout << "password: ";

			cin >> password;

			Sleep(100);

			system("cls");

			if (db.checkAdmin(username))
			{

				if (db.adminLogin(username, password))
				{

					while (true)
					{
						cout << menuAdmin << endl;
						int a;
						cout << RED << "secim edin => " << WHITE;
						cin >> a;


						/*
							[2] = > Start Quiz
							[3] = > Leader Board(Top 10)
							[0] = > Exit )";*/

						if (a == 1) {
							Sleep(600);
							system("cls");
							cin.ignore();
							db.createquiz();

							 
							 
							 
							 
						} 
						else if (a == 2) { 
							cin.ignore();
							Sleep(800); 
							 
							system("cls");

							/*ifstream file1("quizler.txt");
							if (!file1.is_open()) {
								cout << "File açılamadı!" << std::endl;
							}
							string quizname; 

							
							 while (getline(file1, quizname)) {
							
								cout<<CYAN << quizname<<"\n" << WHITE << endl;
							} 
							 file1.close(); 

							cout << endl; 
							string name;
							cout<<RED<< "Enter quizname " << WHITE; 
							cin >>  name;  
							
							fstream quiz1(name + ".txt");
							if (!quiz1) {
								cout << "file doesnt open" << endl;
							}
							string data; 
							vector<string> datas;
							while (getline(quiz1, data)) {
								datas.push_back(data);
								
							}*/
						}
						else if (a == 3) {

							Sleep(800);

							system("cls");



						}
						else if (a == 4) {
							Sleep(800);

							system("cls");
							/*cout << endl;
							db.guest.*/
						}

						else if (a == 0) {

							Sleep(100);

							system("cls");

							break;
						}




					}

				}
				else
				{
					cout << RED << "Password is incorrect. Login proses is not Accessible" << WHITE << endl;
					Sleep(800);
					system("CLS");
				}
			}
			else
			{
				cout << RED << "Admin Not found" << WHITE << endl;
				Sleep(600);
				system("cls");
			}
		}

		else if (select == 0)
		{
			Sleep(900);

			cout << "END";

			Sleep(400);

			cout << CYAN << ".";

			Sleep(100);

			cout << ".";

			Sleep(400);

			cout << ".";

			Sleep(400);

			cout << "." << WHITE;

			cout << endl;

			cout << endl;

			break;

		}

		else
		{
			cout << RED << "Birinci Menudan Duzgun secim edilmedi." << WHITE << endl;
			Sleep(800);
			system("CLS");
			cout << endl;

		}

	}
}
