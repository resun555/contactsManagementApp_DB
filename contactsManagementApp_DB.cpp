// contactsManagementApp_DB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "contactsManagementApp_DB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			Person **personInfo = new Person*[PERSON_SIZE];
			for (size_t i = 0; i < PERSON_SIZE; i++)
			{
				personInfo[i] = new Person("defaultPersonName", "defaultPersonPost", "defaultPersonTitle", "000-0000000", "someone@example.com");
			}
		loop_main:
			system("cls");
			cout << "Contacts Management App (Development Branch)" << endl;
			cout << "Version: 10.0.16170.1000\n" << endl;
			size_t personCapacity = personInfo[0]->getPersonCapacity(personInfo);
			personInfo[0]->displayPerson(personInfo);
			cout << "\n" << endl;
			cout << "\t1. New contacts" << endl;
			cout << "\t2. Delete contacts" << endl;
			cout << "\t3. Edit contacts" << endl;
			cout << "\t4. Sort by..." << endl;
			cout << "\t5. Search anything" << endl;
			cout << "\t0. Exit the program" << endl;
			cout << "\n" << endl;
			cout << "Please choose an option and press Enter:" << endl;
			char getOption = '1';
			cin >> getOption;
			string randomSearchSyntax = "defaultRandomSearchSyntax";
			Person **searchPerson = new Person*[PERSON_SIZE];
			for (size_t i = 0; i < PERSON_SIZE; i++)
			{
				searchPerson[i] = new Person(personInfo[i]);
			}
			size_t personIndex = 0;
			string inputPersonName = "defaultPersonName";
			string inputPersonPost = "defaultPersonPost";
			string inputPersonTitle = "defaultPersonTitle";
			string inputPersonMobile = "000-0000000";
			string inputPersonEmail = "someone@example.com";
			switch (getOption)
			{
			case '0':
				goto done_main;
				break;
			case '1':
				cout << "Please enter information of a new contact:" << endl;
				cout << "Name:" << endl;
				cin >> inputPersonName;
				personInfo[personCapacity]->setPersonName(inputPersonName);
				cout << "Post:" << endl;
				cin >> inputPersonPost;
				personInfo[personCapacity]->setPersonPost(inputPersonPost);
				cout << "Title:" << endl;
				cin >> inputPersonTitle;
				personInfo[personCapacity]->setPersonTitle(inputPersonTitle);
				cout << "Mobile:" << endl;
				cin >> inputPersonMobile;
				personInfo[personCapacity]->setPersonMobile(inputPersonMobile);
				cout << "Email:" << endl;
				cin >> inputPersonEmail;
				personInfo[personCapacity]->setPersonEmail(inputPersonEmail);
				personInfo[0]->sortByName(personInfo, true);
				goto loop_main;
				break;
			case '2':
				searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
				cout << "Please type anything you want to delete:" << endl;
				cin >> randomSearchSyntax;
				searchPerson = personInfo[0]->searchAnything(searchPerson, personInfo, randomSearchSyntax);
				if (searchPerson[0]->getPersonName() == "defaultPersonName")
				{
					cout << "No such contacts were found" << endl;
				}
				else
				{
					searchPerson[0]->displayPerson(searchPerson);
					if (searchPerson[1]->getPersonName() == "defaultPersonName")
					{
						for (size_t i = 0; personInfo[i]->getPersonName() != "defaultPersonName"; i++)
						{
							if (searchPerson[0]->getPersonMobile() == personInfo[i]->getPersonMobile())
							{
								searchPerson[0]->setPersonName("defaultPersonName");
								personInfo[i]->setPersonName("defaultPersonName");
								searchPerson[0]->setPersonPost("defaultPersonPost");
								personInfo[i]->setPersonPost("defaultPersonPost");
								searchPerson[0]->setPersonTitle("defaultPersonTitle");
								personInfo[i]->setPersonTitle("defaultPersonTitle");
								searchPerson[0]->setPersonMobile("000-0000000");
								personInfo[i]->setPersonMobile("000-0000000");
								searchPerson[0]->setPersonEmail("someone@example.com");
								personInfo[i]->setPersonEmail("someone@example.com");
								break;
							}
						}
					}
					else
					{
						cout << "Please choose one you want to delete:" << endl;
						string getPersonName = "defaultPersonName";
						cin >> getPersonName;
						for (size_t i = 0; searchPerson[i]->getPersonName() != "defaultPersonName"; i++)
						{
							if (getPersonName == searchPerson[i]->getPersonName())
							{
								for (size_t j = 0; personInfo[j]->getPersonName() != "defaultPersonName"; j++)
								{
									if (searchPerson[i]->getPersonMobile() == personInfo[j]->getPersonMobile())
									{
										searchPerson[i]->setPersonName("defaultPersonName");
										personInfo[j]->setPersonName("defaultPersonName");
										searchPerson[i]->setPersonPost("defaultPersonPost");
										personInfo[j]->setPersonPost("defaultPersonPost");
										searchPerson[i]->setPersonTitle("defaultPersonTitle");
										personInfo[j]->setPersonTitle("defaultPersonTitle");
										searchPerson[i]->setPersonMobile("000-0000000");
										personInfo[j]->setPersonMobile("000-0000000");
										searchPerson[i]->setPersonEmail("someone@example.com");
										personInfo[j]->setPersonEmail("someone@example.com");
										break;
									}
								}
								break;
							}
						}
					}
				}
				personInfo[0]->sortByName(personInfo, true);
				goto loop_main;
				break;
			case '3':
				searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
				cout << "Please type anything you want to edit:" << endl;
				cin >> randomSearchSyntax;
				searchPerson = personInfo[0]->searchAnything(searchPerson, personInfo, randomSearchSyntax);
				if (searchPerson[0]->getPersonName() == "defaultPersonName")
				{
					cout << "No such contacts were found" << endl;
				}
				else
				{
					searchPerson[0]->displayPerson(searchPerson);
					if (searchPerson[1]->getPersonName() == "defaultPersonName")
					{
						for (size_t i = 0; personInfo[i]->getPersonName() != "defaultPersonName"; i++)
						{
							if (searchPerson[0]->getPersonMobile() == personInfo[i]->getPersonMobile())
							{
							loop_edit_single:
								cout << "Please choose a property identifier to modify:" << endl;
								cout << "\tChoose \'0\' to modify \"Name\"" << endl;
								cout << "\tChoose \'1\' to modify \"Post\"" << endl;
								cout << "\tChoose \'2\' to modify \"Title\"" << endl;
								cout << "\tChoose \'3\' to modify \"Mobile\"" << endl;
								cout << "\tChoose \'4\' to modify \"Email\"" << endl;
								cout << "\tChoose \'5\' to break this session" << endl;
								cin >> getOption;
								switch (getOption)
								{
								case '0':
									cout << "Please enter a new name of the contact:" << endl;
									cin >> inputPersonName;
									searchPerson[0]->setPersonName(inputPersonName);
									personInfo[i]->setPersonName(searchPerson[i]->getPersonName());
									break;
								case '1':
									cout << "Please enter a new post of the contact:" << endl;
									cin >> inputPersonPost;
									searchPerson[0]->setPersonPost(inputPersonPost);
									personInfo[i]->setPersonPost(searchPerson[i]->getPersonPost());
									break;
								case '2':
									cout << "Please enter a new title of the contact:" << endl;
									cin >> inputPersonTitle;
									searchPerson[0]->setPersonTitle(inputPersonTitle);
									personInfo[i]->setPersonTitle(searchPerson[i]->getPersonTitle());
									break;
								case '3':
									cout << "Please enter a new mobile of the contact:" << endl;
									cin >> inputPersonMobile;
									searchPerson[0]->setPersonMobile(inputPersonMobile);
									personInfo[i]->setPersonMobile(searchPerson[i]->getPersonMobile());
									break;
								case '4':
									cout << "Please enter a new email of the contact:" << endl;
									cin >> inputPersonEmail;
									searchPerson[0]->setPersonEmail(inputPersonEmail);
									personInfo[i]->setPersonEmail(searchPerson[i]->getPersonEmail());
									break;
								case '5':
									goto done_edit_single;
									break;
								default:
									cout << "Please enter a correct number from 0 to 5" << endl;
									break;
								}
								goto loop_edit_single;
							done_edit_single:
								break;
							}
						}
					}
					else
					{
						cout << "Please choose one you want to edit:" << endl;
						string getPersonName = "defaultPersonName";
						cin >> getPersonName;
						for (size_t i = 0; searchPerson[i]->getPersonName() != "defaultPersonName"; i++)
						{
							if (getPersonName == searchPerson[i]->getPersonName())
							{
								for (size_t j = 0; personInfo[j]->getPersonName() != "defaultPersonName"; j++)
								{
									if (searchPerson[i]->getPersonMobile() == personInfo[j]->getPersonMobile())
									{
									loop_edit_multiple:
										cout << "Please choose a property identifier to modify:" << endl;
										cout << "\tChoose \'0\' to modify \"Name\"" << endl;
										cout << "\tChoose \'1\' to modify \"Post\"" << endl;
										cout << "\tChoose \'2\' to modify \"Title\"" << endl;
										cout << "\tChoose \'3\' to modify \"Mobile\"" << endl;
										cout << "\tChoose \'4\' to modify \"Email\"" << endl;
										cout << "\tChoose \'5\' to break this session" << endl;
										cin >> getOption;
										switch (getOption)
										{
										case '0':
											cout << "Please enter a new name of the contact:" << endl;
											cin >> inputPersonName;
											searchPerson[i]->setPersonName(inputPersonName);
											personInfo[j]->setPersonName(searchPerson[i]->getPersonName());
											break;
										case '1':
											cout << "Please enter a new post of the contact:" << endl;
											cin >> inputPersonPost;
											searchPerson[i]->setPersonPost(inputPersonPost);
											personInfo[j]->setPersonPost(searchPerson[i]->getPersonPost());
											break;
										case '2':
											cout << "Please enter a new title of the contact:" << endl;
											cin >> inputPersonTitle;
											searchPerson[i]->setPersonTitle(inputPersonTitle);
											personInfo[j]->setPersonTitle(searchPerson[i]->getPersonTitle());
											break;
										case '3':
											cout << "Please enter a new mobile of the contact:" << endl;
											cin >> inputPersonMobile;
											searchPerson[i]->setPersonMobile(inputPersonMobile);
											personInfo[j]->setPersonMobile(searchPerson[i]->getPersonMobile());
											break;
										case '4':
											cout << "Please enter a new email of the contact:" << endl;
											cin >> inputPersonEmail;
											searchPerson[i]->setPersonEmail(inputPersonEmail);
											personInfo[j]->setPersonEmail(searchPerson[i]->getPersonEmail());
											break;
										case '5':
											goto done_edit_multiple;
											break;
										default:
											cout << "Please enter a correct number from 0 to 5" << endl;
											break;
										}
										goto loop_edit_multiple;
									done_edit_multiple:
										break;
									}
								}
								break;
							}
						}
					}
				}
				personInfo[0]->sortByName(personInfo, true);
				goto loop_main;
				break;
			case '4':
				searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
				for (size_t i = 0; i < PERSON_SIZE; i++)
				{
					if (personInfo[i]->getPersonName() != "defaultPersonName" || personInfo[i]->getPersonPost() != "defaultPersonPost" || personInfo[i]->getPersonTitle() != "defaultPersonTitle" || personInfo[i]->getPersonMobile() != "000-0000000" || personInfo[i]->getPersonEmail() != "someone@example.com")
					{
						*searchPerson[personIndex] = *personInfo[i];
						personIndex++;
					}
				}
				personInfo[0]->setPersonInfoDefault(personInfo, PERSON_SIZE);
				for (size_t i = 0; searchPerson[i]->getPersonName() != "defaultPersonName"; i++)
				{
					*personInfo[i] = *searchPerson[i];
				}
				personCapacity = searchPerson[0]->getPersonCapacity(searchPerson);
				cout << "Please choose which property to sort by as the first priority:" << endl;
				cout << "\tChoose \'0\' to sort by \"Name\"" << endl;
				cout << "\tChoose \'1\' to sort by \"Post\"" << endl;
				cout << "\tChoose \'2\' to sort by \"Title\"" << endl;
				cout << "\tChoose \'3\' to sort by \"Mobile\"" << endl;
				cout << "\tChoose \'4\' to sort by \"Email\"" << endl;
				cin >> getOption;
				switch (getOption)
				{
				case '0':
					cout << "Please choose sort ascending or descending:" << endl;
					cout << "\tChoose \'0\' to sort descending" << endl;
					cout << "\tChoose \'1\' to sort ascending" << endl;
					cin >> getOption;
					switch (getOption)
					{
					case '0':
						searchPerson[0]->sortByName(searchPerson, false);
						break;
					case '1':
						searchPerson[0]->sortByName(searchPerson, true);
						break;
					default:
						break;
					}
					break;
				case '1':
					cout << "Please choose sort ascending or descending:" << endl;
					cout << "\tChoose \'0\' to sort descending" << endl;
					cout << "\tChoose \'1\' to sort ascending" << endl;
					cin >> getOption;
					switch (getOption)
					{
					case '0':
						searchPerson[0]->sortByPost(searchPerson, false);
						break;
					case '1':
						searchPerson[0]->sortByPost(searchPerson, true);
						break;
					default:
						break;
					}
					break;
				case '2':
					cout << "Please choose sort ascending or descending:" << endl;
					cout << "\tChoose \'0\' to sort descending" << endl;
					cout << "\tChoose \'1\' to sort ascending" << endl;
					cin >> getOption;
					switch (getOption)
					{
					case '0':
						searchPerson[0]->sortByTitle(searchPerson, false);
						break;
					case '1':
						searchPerson[0]->sortByTitle(searchPerson, true);
						break;
					default:
						break;
					}
					break;
				case '3':
					cout << "Please choose sort ascending or descending:" << endl;
					cout << "\tChoose \'0\' to sort descending" << endl;
					cout << "\tChoose \'1\' to sort ascending" << endl;
					cin >> getOption;
					switch (getOption)
					{
					case '0':
						searchPerson[0]->sortByMobile(searchPerson, false);
						break;
					case '1':
						searchPerson[0]->sortByMobile(searchPerson, true);
						break;
					default:
						break;
					}
					break;
				case '4':
					cout << "Please choose sort ascending or descending:" << endl;
					cout << "\tChoose \'0\' to sort descending" << endl;
					cout << "\tChoose \'1\' to sort ascending" << endl;
					cin >> getOption;
					switch (getOption)
					{
					case '0':
						searchPerson[0]->sortByEmail(searchPerson, false);
						break;
					case '1':
						searchPerson[0]->sortByEmail(searchPerson, true);
						break;
					default:
						break;
					}
					break;
				default:
					cout << "Please enter a correct number from 0 to 4" << endl;
					break;
				}
				personCapacity = searchPerson[0]->getPersonCapacity(searchPerson);
				searchPerson[0]->displayPerson(searchPerson);
				cout << "Enter any character and press enter to return to the main menu" << endl;
				cin >> getOption;
				goto loop_main;
				break;
			case '5':
				searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
				cout << "Please type anything you want to search:" << endl;
				cin >> randomSearchSyntax;
				searchPerson = personInfo[0]->searchAnything(searchPerson, personInfo, randomSearchSyntax);
				if (searchPerson[0]->getPersonName() == "defaultPersonName")
				{
					cout << "No such contacts were found" << endl;
				}
				else
				{
					searchPerson[0]->displayPerson(searchPerson);
				}
				cout << "Enter any character and press enter to return to the main menu" << endl;
				cin >> getOption;
				goto loop_main;
				break;
			default:
				cout << "Please enter a correct number from 0 to 5" << endl;
				cout << "Enter any character and press enter to return to the main menu" << endl;
				cin >> getOption;
				goto loop_main;
				break;
			}
		done_main:
			for (size_t i = 0; i < PERSON_SIZE; i++)
			{
				delete searchPerson[i];
			}
			delete[] searchPerson;
			for (size_t i = 0; i < PERSON_SIZE; i++)
			{
				delete personInfo[i];
			}
			delete[] personInfo;
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}


// TODO: public get method definitions
string Person::getPersonName(void)
{
	return personName;
}


string Person::getPersonPost(void)
{
	return personPost;
}


string Person::getPersonTitle(void)
{
	return personTitle;
}


string Person::getPersonMobile(void)
{
	return personMobile;
}


string Person::getPersonEmail(void)
{
	return personEmail;
}


string* Person::getSearchWhichProperty(void)
{
	return searchWhichProperty;
}

// TODO: public set method definitions
void Person::setPersonName(string getPersonName)
{
	personName = getPersonName;
	return;
}


void Person::setPersonPost(string getPersonPost)
{
	personPost = getPersonPost;
	return;
}


void Person::setPersonTitle(string getPersonTitle)
{
	personTitle = getPersonTitle;
	return;
}


void Person::setPersonMobile(string getPersonMobile)
{
	personMobile = getPersonMobile;
	return;
}


void Person::setPersonEmail(string getPersonEmail)
{
	personEmail = getPersonEmail;
	return;
}


void Person::setSearchWhichProperty(string* getSearchWhichProperty)
{
	searchWhichProperty = getSearchWhichProperty;
	return;
}


void Person::setPersonInfoDefault(Person** searchPerson, size_t personLength)
{
	for (size_t i = 0; i < personLength; i++)
	{
		searchPerson[i]->personName = "defaultPersonName";
		searchPerson[i]->personPost = "defaultPersonPost";
		searchPerson[i]->personTitle = "defaultPersonTitle";
		searchPerson[i]->personMobile = "000-0000000";
		searchPerson[i]->personEmail = "someone@example.com";
		searchPerson[i]->searchWhichProperty = &personName;
	}
	return;
}


size_t Person::getPersonCapacity(Person **personInfo)
{
	size_t i;
	for (i = 0; i < PERSON_SIZE; i++)
	{
		if (personInfo[i]->personName == "defaultPersonName")
		{
			if (i == 0)
			{
				cout << "No contacts in the list\n" << endl;
			}
			else
			{
				cout << "In the list are " << i << " contacts\n" << endl;
			}
			break;
		}
	}
	return i;
}


void Person::displayPerson(Person **personInfo)
{
	size_t personNameLengthMax = personInfo[0]->personName.length();
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		if (personNameLengthMax < personInfo[i]->personName.length())
		{
			personNameLengthMax = personInfo[i]->personName.length();
		}
	}
	size_t personPostLengthMax = personInfo[0]->personPost.length();
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		if (personPostLengthMax < personInfo[i]->personPost.length())
		{
			personPostLengthMax = personInfo[i]->personPost.length();
		}
	}
	size_t personTitleLengthMax = personInfo[0]->personTitle.length();
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		if (personTitleLengthMax < personInfo[i]->personTitle.length())
		{
			personTitleLengthMax = personInfo[i]->personTitle.length();
		}
	}
	size_t personMobileLengthMax = personInfo[0]->personMobile.length();
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		if (personMobileLengthMax < personInfo[i]->personMobile.length())
		{
			personMobileLengthMax = personInfo[i]->personMobile.length();
		}
	}
	size_t personEmailLengthMax = personInfo[0]->personEmail.length();
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		if (personEmailLengthMax < personInfo[i]->personEmail.length())
		{
			personEmailLengthMax = personInfo[i]->personEmail.length();
		}
	}
	char(*spaces)[SPACE_MAX_LENGTH] = new char[5][SPACE_MAX_LENGTH];
	string name = "Name";
	string post = "Post";
	string title = "Title";
	string mobile = "Mobile";
	string email = "Email";
	if (personNameLengthMax < name.length())
	{
		memset(spaces[0], ' ', 2);
		spaces[0][2] = NULL;
	}
	else
	{
		memset(spaces[0], ' ', personNameLengthMax - name.length() + 2);
		spaces[0][personNameLengthMax - name.length() + 2] = NULL;
	}
	if (personPostLengthMax < post.length())
	{
		memset(spaces[1], ' ', 2);
		spaces[1][2] = NULL;
	}
	else
	{
		memset(spaces[1], ' ', personPostLengthMax - post.length() + 2);
		spaces[1][personPostLengthMax - post.length() + 2] = NULL;
	}
	if (personTitleLengthMax < title.length())
	{
		memset(spaces[2], ' ', 2);
		spaces[2][2] = NULL;
	}
	else
	{
		memset(spaces[2], ' ', personTitleLengthMax - title.length() + 2);
		spaces[2][personTitleLengthMax - title.length() + 2] = NULL;
	}
	if (personMobileLengthMax < mobile.length())
	{
		memset(spaces[3], ' ', 2);
		spaces[3][2] = NULL;
	}
	else
	{
		memset(spaces[3], ' ', personMobileLengthMax - mobile.length() + 2);
		spaces[3][personMobileLengthMax - mobile.length() + 2] = NULL;
	}
	if (personEmailLengthMax < email.length())
	{
		memset(spaces[4], ' ', 2);
		spaces[4][2] = NULL;
	}
	else
	{
		memset(spaces[4], ' ', personEmailLengthMax - email.length() + 2);
		spaces[4][personEmailLengthMax - email.length() + 2] = NULL;
	}
	if (personInfo[0]->personName != "defaultPersonName")
	{
		cout << "Name" << spaces[0] << "Post" << spaces[1] << "Title" << spaces[2] << "Mobile" << spaces[3] << "Email" << spaces[4] << endl;
	}
	if (personNameLengthMax < name.length())
	{
		memset(spaces[0], ' ', name.length() - personNameLengthMax + 2);
		spaces[0][name.length() - personNameLengthMax + 2] = NULL;
	}
	else
	{
		memset(spaces[0], ' ', 2);
		spaces[0][2] = NULL;
	}
	if (personPostLengthMax < post.length())
	{
		memset(spaces[1], ' ', post.length() - personPostLengthMax + 2);
		spaces[1][post.length() - personPostLengthMax + 2] = NULL;
	}
	else
	{
		memset(spaces[1], ' ', 2);
		spaces[1][2] = NULL;
	}
	if (personTitleLengthMax < title.length())
	{
		memset(spaces[2], ' ', title.length() - personTitleLengthMax + 2);
		spaces[2][title.length() - personTitleLengthMax + 2] = NULL;
	}
	else
	{
		memset(spaces[2], ' ', 2);
		spaces[2][2] = NULL;
	}
	if (personMobileLengthMax < mobile.length())
	{
		memset(spaces[3], ' ', mobile.length() - personMobileLengthMax + 2);
		spaces[3][mobile.length() - personMobileLengthMax + 2] = NULL;
	}
	else
	{
		memset(spaces[3], ' ', 2);
		spaces[3][2] = NULL;
	}
	if (personEmailLengthMax < email.length())
	{
		memset(spaces[4], ' ', email.length() - personEmailLengthMax + 2);
		spaces[4][email.length() - personEmailLengthMax + 2] = NULL;
	}
	else
	{
		memset(spaces[4], ' ', 2);
		spaces[4][2] = NULL;
	}
	for (size_t i = 0; personInfo[i]->personName != "defaultPersonName"; i++)
	{
		cout << personInfo[i]->personName << spaces[0] << personInfo[i]->personPost << spaces[1] << personInfo[i]->personTitle << spaces[2] << personInfo[i]->personMobile << spaces[3] << personInfo[i]->personEmail << spaces[4] << endl;
	}
	return;
}


void Person::sortByName(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->personName != "defaultPersonName"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->personName != "defaultPersonName"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->personName > searchPerson[j]->personName)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personName == searchPerson[j]->personName)
				{
					if (searchPerson[i]->personMobile > searchPerson[j]->personMobile)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
				}
				break;
			case false:
				if (searchPerson[i]->personName < searchPerson[j]->personName)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personName == searchPerson[j]->personName)
				{
					if (searchPerson[i]->personMobile < searchPerson[j]->personMobile)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void sortBy::sortByName(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->getPersonName() != "defaultPersonName()"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->getPersonName() != "defaultPersonName()"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->getPersonName() > searchPerson[j]->getPersonName())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
				{
					if (searchPerson[i]->getPersonMobile() > searchPerson[j]->getPersonMobile())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
				}
				break;
			case false:
				if (searchPerson[i]->getPersonName() < searchPerson[j]->getPersonName())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
				{
					if (searchPerson[i]->getPersonMobile() < searchPerson[j]->getPersonMobile())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void Person::sortByPost(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->personPost != "defaultPersonPost"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->personPost != "defaultPersonPost"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->personPost > searchPerson[j]->personPost)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personPost == searchPerson[j]->personPost)
				{
					if (searchPerson[i]->personName > searchPerson[j]->personName)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->personName == searchPerson[j]->personName)
					{
						if (searchPerson[i]->personMobile > searchPerson[j]->personMobile)
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			case false:
				if (searchPerson[i]->personPost < searchPerson[j]->personPost)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personPost == searchPerson[j]->personPost)
				{
					if (searchPerson[i]->personName < searchPerson[j]->personName)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->personName == searchPerson[j]->personName)
					{
						if (searchPerson[i]->personMobile < searchPerson[j]->personMobile)
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void sortBy::sortByPost(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->getPersonPost() != "defaultPersonPost()"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->getPersonPost() != "defaultPersonPost()"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->getPersonPost() > searchPerson[j]->getPersonPost())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonPost() == searchPerson[j]->getPersonPost())
				{
					if (searchPerson[i]->getPersonName() > searchPerson[j]->getPersonName())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
					{
						if (searchPerson[i]->getPersonMobile() > searchPerson[j]->getPersonMobile())
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			case false:
				if (searchPerson[i]->getPersonPost() < searchPerson[j]->getPersonPost())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonPost() == searchPerson[j]->getPersonPost())
				{
					if (searchPerson[i]->getPersonName() < searchPerson[j]->getPersonName())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
					{
						if (searchPerson[i]->getPersonMobile() < searchPerson[j]->getPersonMobile())
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void Person::sortByTitle(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->personTitle != "defaultPersonTitle"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->personTitle != "defaultPersonTitle"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->personTitle > searchPerson[j]->personTitle)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personTitle == searchPerson[j]->personTitle)
				{
					if (searchPerson[i]->personName > searchPerson[j]->personName)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->personName == searchPerson[j]->personName)
					{
						if (searchPerson[i]->personMobile > searchPerson[j]->personMobile)
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			case false:
				if (searchPerson[i]->personTitle < searchPerson[j]->personTitle)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->personTitle == searchPerson[j]->personTitle)
				{
					if (searchPerson[i]->personName < searchPerson[j]->personName)
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->personName == searchPerson[j]->personName)
					{
						if (searchPerson[i]->personMobile < searchPerson[j]->personMobile)
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void sortBy::sortByTitle(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->getPersonTitle() != "defaultPersonTitle()"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->getPersonTitle() != "defaultPersonTitle()"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->getPersonTitle() > searchPerson[j]->getPersonTitle())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonTitle() == searchPerson[j]->getPersonTitle())
				{
					if (searchPerson[i]->getPersonName() > searchPerson[j]->getPersonName())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
					{
						if (searchPerson[i]->getPersonMobile() > searchPerson[j]->getPersonMobile())
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			case false:
				if (searchPerson[i]->getPersonTitle() < searchPerson[j]->getPersonTitle())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				else if (searchPerson[i]->getPersonTitle() == searchPerson[j]->getPersonTitle())
				{
					if (searchPerson[i]->getPersonName() < searchPerson[j]->getPersonName())
					{
						*tempPerson = *searchPerson[i];
						*searchPerson[i] = *searchPerson[j];
						*searchPerson[j] = *tempPerson;
					}
					else if (searchPerson[i]->getPersonName() == searchPerson[j]->getPersonName())
					{
						if (searchPerson[i]->getPersonMobile() < searchPerson[j]->getPersonMobile())
						{
							*tempPerson = *searchPerson[i];
							*searchPerson[i] = *searchPerson[j];
							*searchPerson[j] = *tempPerson;
						}
					}
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void Person::sortByMobile(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->personMobile != "defaultPersonMobile"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->personMobile != "defaultPersonMobile"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->personMobile > searchPerson[j]->personMobile)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			case false:
				if (searchPerson[i]->personMobile < searchPerson[j]->personMobile)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void sortBy::sortByMobile(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->getPersonMobile() != "defaultPersonMobile()"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->getPersonMobile() != "defaultPersonMobile()"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->getPersonMobile() > searchPerson[j]->getPersonMobile())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			case false:
				if (searchPerson[i]->getPersonMobile() < searchPerson[j]->getPersonMobile())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void Person::sortByEmail(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->personEmail != "defaultPersonEmail"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->personEmail != "defaultPersonEmail"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->personEmail > searchPerson[j]->personEmail)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			case false:
				if (searchPerson[i]->personEmail < searchPerson[j]->personEmail)
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


void sortBy::sortByEmail(Person** searchPerson, bool isAscending)
{
	Person* tempPerson = new Person(searchPerson[0]);
	for (size_t i = 0; searchPerson[i + 1]->getPersonEmail() != "defaultPersonEmail()"; i++)
	{
		for (size_t j = i + 1; searchPerson[j]->getPersonEmail() != "defaultPersonEmail()"; j++)
		{
			switch (isAscending)
			{
			case true:
				if (searchPerson[i]->getPersonEmail() > searchPerson[j]->getPersonEmail())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			case false:
				if (searchPerson[i]->getPersonEmail() < searchPerson[j]->getPersonEmail())
				{
					*tempPerson = *searchPerson[i];
					*searchPerson[i] = *searchPerson[j];
					*searchPerson[j] = *tempPerson;
				}
				break;
			}
		}
	}
	delete tempPerson;
	return;
}


Person** Person::searchAnything(Person** searchPerson, Person** personInfo, string searchSyntax)
{
	searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
	size_t personIndex = 0;
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->searchWhichProperty = &personInfo[i]->personName;
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonName", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->searchWhichProperty = &personInfo[i]->personPost;
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonPost", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->searchWhichProperty = &personInfo[i]->personTitle;
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonTitle", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->searchWhichProperty = &personInfo[i]->personMobile;
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "000-0000000", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->searchWhichProperty = &personInfo[i]->personEmail;
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "someone@example.com", personInfo, searchSyntax);
	return searchPerson;
}


Person** searchWhat::searchAnything(Person** searchPerson, Person** personInfo, string searchSyntax)
{
	searchPerson[0]->setPersonInfoDefault(searchPerson, PERSON_SIZE);
	size_t personIndex = 0;
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->setSearchWhichProperty(&personInfo[i]->getPersonName());
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonName", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->setSearchWhichProperty(&personInfo[i]->getPersonPost());
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonPost", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->setSearchWhichProperty(&personInfo[i]->getPersonTitle());
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "defaultPersonTitle", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->setSearchWhichProperty(&personInfo[i]->getPersonMobile());
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "000-0000000", personInfo, searchSyntax);
	for (size_t i = 0; i < PERSON_SIZE; i++)
	{
		personInfo[i]->setSearchWhichProperty(&personInfo[i]->getPersonEmail());
	}
	personInfo[0]->searchEachProperty(searchPerson, personIndex, "someone@example.com", personInfo, searchSyntax);
	return searchPerson;
}


Person** Person::searchEachProperty(Person** searchPerson, size_t& personIndex, string defaultPropertySyntax, Person** personInfo, string searchSyntax)
{
	for (size_t i = 0; *personInfo[i]->searchWhichProperty != defaultPropertySyntax; i++)
	{
		if (searchSyntax == *personInfo[i]->searchWhichProperty)
		{
			*searchPerson[personIndex] = *personInfo[i];
			personIndex++;
		}
		else
		{
			for (size_t j = 0; j < personInfo[i]->searchWhichProperty->length(); j++)
			{
				for (size_t k = 0; k < personInfo[i]->searchWhichProperty->length() - j; k++)
				{
					if (searchSyntax == personInfo[i]->searchWhichProperty->substr(j, k))
					{
						*searchPerson[personIndex] = *personInfo[i];
						personIndex++;
					}
				}
			}
		}
	}
	return searchPerson;
}


Person** searchWhat::searchEachProperty(Person** searchPerson, size_t& personIndex, string defaultPropertySyntax, Person** personInfo, string searchSyntax)
{
	for (size_t i = 0; *personInfo[i]->getSearchWhichProperty() != defaultPropertySyntax; i++)
	{
		if (searchSyntax == *personInfo[i]->getSearchWhichProperty())
		{
			*searchPerson[personIndex] = *personInfo[i];
			personIndex++;
		}
		else
		{
			for (size_t j = 0; j < personInfo[i]->getSearchWhichProperty()->length(); j++)
			{
				for (size_t k = 0; k < personInfo[i]->getSearchWhichProperty()->length() - j; k++)
				{
					if (searchSyntax == personInfo[i]->getSearchWhichProperty()->substr(j, k))
					{
						*searchPerson[personIndex] = *personInfo[i];
						personIndex++;
					}
				}
			}
		}
	}
	return searchPerson;
}

