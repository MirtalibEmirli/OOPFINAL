#pragma once
void start() {
#pragma region datas 
	Database db;

	Admin* admin = new Admin("admin", "admin");
	db.admins.addadmin(admin);

	string menuOne = R"(
				[1] => As Gusest
				[2] => As Admin
				[0] => Exit
		)";

	string menuAdmin = R"(
				[1] =>  Create Quiz
				[2] =>  Start Quiz
				[3] =>  Leader Board(min to max)
				[4] =>  Add admin :)
				[5] =>  Show all admins ^!^
				[0] =>  Exit )";
	string menuplayer = R"(
				[1] => Start Quiz
				[0] => Exit 
)";
	string menusual = R"(
				[1] => Pass
				[2] =>Submit
				)";




#pragma endregion 

	while (true)
	{
		cout << CYAN << menuOne << WHITE << endl;

#pragma region enter  

		cout << "Menudan secim edin => ";


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
				while (true)
				{
					if (a == 1)
					{

						cin.ignore();


						fstream file1("quizler.txt");
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
							cout << "file doesnt open PLease re enter" << endl;
							Sleep(500);
							system("cls");
							break;
						}


						string question;
						vector<string> questions;
						while (getline(quiz1, question)) {
							questions.push_back(question);

						}

						cout << endl;
						cout << CYAN << questions[0] << WHITE << endl;

						Result r11;
						int sans = 3;



						for (size_t i = 1; i < 4; i++)
						{
							int questionend = questions[i].find("^");
							string question = questions[i].substr(0, questionend);
							cout << question << " " << endl;
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
							cout << endl;



							char cavabs;
							int chch;
							cout << menusual << endl;
							cout << endl;
							for (size_t i = 3; i > 0; i--)
							{
								cout << CYAN << "enter your choice  :)" << WHITE << endl;
								cin >> chch;
								if (chch == 2) {
									cin.ignore();
									cout << endl;
									cout << "Enter your answer => ";
									cin >> cavabs;
									if (cavabs == correct) {
										r11.increasecorrect();
										r11.increaseresult();
										break;

									}
									else if (cavabs != correct)
										r11.increaseincorrect();
									break;
								}
								else if (chch == 1) {
									r11.increasepass();
									break;
								}

								else {
									if (sans == 0) {
										cout << RED << "Duzgun secim edin!! sizin " << CYAN << sans << WHITE << RED" sansiniz qaldi" << WHITE << endl;

										break;
									}
									cout << RED << "Duzgun secim edin!! sizin " << CYAN << --sans << WHITE << RED" sansiniz qaldi" << WHITE << endl;
									///2 1 
								}


							}
							if (sans == 0)
								break;

						}

						if (sans == 0) {
							Sleep(500);
							system("cls");

							cout << endl << GREEN << "Sizin oyun bitdi ve oyundan qovuldunuz ^_^ " << WHITE << endl;

							Sleep(100);
							cout << ".";
							Sleep(100);
							cout << ".";

							Sleep(100);
							cout << ". ";

							Sleep(1200000);
							system("cls");

							break;
						}




						cout << endl;
						cout << BOLDCYAN << "Duz => " << r11.Getcorrect() << endl;
						cout << "Sehv => " << r11.Getincorrect() << endl;
						cout << "Pass =>" << r11.Getpass() << endl;
						cout << "Point =>" << r11.Getresult() << WHITE << endl;

						ofstream ress("results.txt", ios::app);
						ress << guest->getFullname() << "/" << r11.Getresult() << endl;
						ress.close();


						Sleep(1900);

						system("cls");

						break;
					}


					else if (a == 0) {
						cout << MAGENTA << "You return to first menu baby :)" << WHITE << endl;

						Sleep(1000);

						system("cls");

						break;
					}
			
				}

				break;

			}

		}



		else if (select == 2)
		
		
		{


			cin.ignore();

			string username, password;

			cout << "username: ";

			cin >> username;

			cout << "password: ";

			

			Admin* adminnezaret = new Admin(username, password);
			cin >> password;
			fstream admns("admins.txt");
			admns << username << "/" << password << endl; 
			admns.close();
			Sleep(100);

			system("cls");

			if (db.checkAdmin(username))
			{

				if (db.adminLogin( password))
				{

					while (true)
					{
						cout << menuAdmin << endl;
						int v;
						cout << RED << "secim edin => " << WHITE;
						cin >> v;



						

						if (v == 1) {
							cin.ignore();
							db.createquiz();
						}
						else if (v == 2) {
							
							//players fayln ac elave ed oyuncunu sildin


							Sleep(500);
							system("cls");


							while (true)
							{

									fstream file1("quizler.txt");
									if (!file1.is_open()) {
										cout << "File açılamadı!" << std::endl;
									}


									string quizname;

									while (getline(file1, quizname)) {

										cout << CYAN << quizname << "\n" << WHITE << endl;
									}
									file1.close();

									cout << endl;
									cin.ignore();

									string name;
									cout << RED << "Enter quizname " << WHITE;
									cin >> name;
									Sleep(400);
									system("cls");
									fstream quiz1(name + ".txt");
									if (!quiz1) {
										cout << "file doesnt open PLease re enter" << endl;
										Sleep(500);
										system("cls");
										break;
									}







									string question;
									vector<string> questions;
									while (getline(quiz1, question)) {
										questions.push_back(question);

									}

									cout << endl;
									cout << CYAN << questions[0] << WHITE << endl;

									Result r11;
									int sans = 3;



									for (size_t i = 1; i < 4; i++)
									{
										int questionend = questions[i].find("^");
										string question = questions[i].substr(0, questionend);
										cout << question << " " << endl;
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
										cout << endl;



										char cavabs;
										int chch;
										cout << menusual << endl;
										cout << endl;
										for (size_t i = 3; i > 0; i--)
										{
											cout << CYAN << "enter your choice  :)" << WHITE << endl;
											cin >> chch;
											if (chch == 2) {
												cin.ignore();
												cout << endl;
												cout << "Enter your answer => ";
												cin >> cavabs;
												if (cavabs == correct) {
													r11.increasecorrect();
													r11.increaseresult();
													break;

												}
												else if (cavabs != correct)
													r11.increaseincorrect();
												break;
											}
											else if (chch == 1) {
												r11.increasepass();
												break;
											}

											else {
												if (sans == 0) {
													cout << RED << "Duzgun secim edin!! sizin " << CYAN << sans << WHITE << RED" sansiniz qaldi" << WHITE << endl;

													break;
												}
												cout << RED << "Duzgun secim edin!! sizin " << CYAN << --sans << WHITE << RED" sansiniz qaldi" << WHITE << endl;
												///2 1 
											}


										}
										if (sans == 0)
											break;

									}





									if (sans == 0) {
										Sleep(500);
										system("cls");

										cout << endl << GREEN << "Sizin oyun bitdi ve oyundan qovuldunuz ^_^ " << WHITE << endl;

										Sleep(100);
										cout << ".";
										Sleep(100);
										cout << ".";

										Sleep(100);
										cout << ". ";

										Sleep(1200000);
										system("cls");

										break;
									}



									cout << endl;
									cout << BOLDCYAN << "Duz => " << r11.Getcorrect() << endl;
									cout << "Sehv => " << r11.Getincorrect() << endl;
									cout << "Pass =>" << r11.Getpass() << endl;
									cout << "Point =>" << r11.Getresult() << WHITE << endl;

									ofstream ress("results.txt", ios::app); 
									ress << adminnezaret->GetUsername() << " " << r11.Getresult() << endl; 
									ress.close();


									Sleep(1900);

									system("cls");

									break;
								
							}


							break;

						}

						else if (v == 3) {
							fstream result("results.txt");

							vector<pair<int, string>> reslts;

							string rsltln;
							while (getline(result, rsltln)) {
								string name = rsltln.substr(0, rsltln.find("/"));
								string t = rsltln.substr(rsltln.find("/") + 1, rsltln.length() - rsltln.find("/"));
								int point = stoi(t);
								reslts.push_back(make_pair(point, name));
							}




							multiset<pair<int, string >> a;
							for (auto& pair : reslts)
							{
								a.insert(pair);

							}
							for (auto& entry : a) {
								cout<<BOLDCYAN << "player =>" << entry.second << "  point => " << entry.first <<WHITE << endl;
							}

							result.close();
							Sleep(2500);
							system("cls");

							break;

						}
						else if (v == 5) { 

							Sleep(800);

							system("cls");
							fstream amin455("admins.txt"); 
							string adm55; 
							vector<string> admeen;
							while (getline(amin455, adm55)) { 
								admeen.push_back(adm55);  
							}

							amin455.close(); 


							for (size_t i = 0; i < admeen.size(); i++) 
							{
								cout<<BOLDCYAN<<i<<" => " << admeen[i] <<WHITE << endl << endl; 
							}

							Sleep(2600);
							system("cls");
						}
						else if (v == 4) {
							Sleep(800);

							system("cls");
							cin.ignore();
							string namegg;
							cout<<BOLDYELLOW << "Enter name of admin "<<WHITE;
							getline(cin, namegg);

							cout << MAGENTA << "Enter parol of admin " << WHITE; 

							string parol;  
							getline(cin, parol); 

							Admin* adminnew = new Admin(namegg, parol);   


							fstream admins("admins.txt", ios::app);  
							admins << adminnew->GetUsername() << " " << adminnew->GetPassword() << endl;
							admins.close();

							db.admins.addadmin(adminnew); 
						}



						else if (v == 0) { 

							cout << MAGENTA << "You return to first menu  :)" << WHITE << endl; 

							Sleep(1000); 
							 
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
