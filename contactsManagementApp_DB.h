#pragma once

#include "resource.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef PERSON_SIZE
#define PERSON_SIZE 100
#endif
#ifndef SPACE_MAX_LENGTH
#define SPACE_MAX_LENGTH 256 
#endif


using namespace std;


class Person
{
public:
	Person(string personNameConstructor = "defaultPersonName", string personPostConstructor = "defaultPersonPost", string personTitleConstructor = "defaultPersonTitle", string personMobileConstructor = "000-0000000", string personEmailConstructor = "someone@example.com") : personName(personNameConstructor), personPost(personPostConstructor), personTitle(personTitleConstructor), personMobile(personMobileConstructor), personEmail(personEmailConstructor)
	{
	}
	Person(Person*& personConstructor) : personName(personConstructor->personName), personPost(personConstructor->personPost), personTitle(personConstructor->personTitle), personMobile(personConstructor->personMobile), personEmail(personConstructor->personEmail), searchWhichProperty(personConstructor->searchWhichProperty)
	{
	}
	~Person()
	{
		personName = "defaultPersonName";
		personPost = "defaultPersonPost";
		personTitle = "defaultPersonTitle";
		personMobile = "defaultPersonMobile";
		personEmail = "defaultPersonEmail";
		searchWhichProperty = &personName;
	}
	string getPersonName(void);
	string getPersonPost(void);
	string getPersonTitle(void);
	string getPersonMobile(void);
	string getPersonEmail(void);
	string* getSearchWhichProperty(void);
	void setPersonName(string);
	void setPersonPost(string);
	void setPersonTitle(string);
	void setPersonMobile(string);
	void setPersonEmail(string);
	void setSearchWhichProperty(string*);
	void setPersonInfoDefault(Person**, size_t);
	size_t getPersonCapacity(Person **);
	void displayPerson(Person **);
	virtual void sortByName(Person**, bool);
	virtual void sortByPost(Person**, bool);
	virtual void sortByTitle(Person**, bool);
	virtual void sortByMobile(Person**, bool);
	virtual void sortByEmail(Person**, bool);
	virtual Person** searchAnything(Person**, Person**, string);
	virtual Person** searchEachProperty(Person**, size_t&, string, Person**, string);

private:
	string personName = "defaultPersonName";
	string personPost = "defaultPersonPost";
	string personTitle = "defaultPersonTitle";
	string personMobile = "000-0000000";
	string personEmail = "someone@example.com";
	string* searchWhichProperty = &personName;

};


class sortBy : protected Person
{
public:
	virtual void sortByName(Person**, bool);
	virtual void sortByPost(Person**, bool);
	virtual void sortByTitle(Person**, bool);
	virtual void sortByMobile(Person**, bool);
	virtual void sortByEmail(Person**, bool);
	friend string Person::getPersonName(void);
	friend string Person::getPersonPost(void);
	friend string Person::getPersonTitle(void);
	friend string Person::getPersonMobile(void);
	friend string Person::getPersonEmail(void);
	friend string* Person::getSearchWhichProperty(void);
	friend void Person::setPersonName(string);
	friend void Person::setPersonPost(string);
	friend void Person::setPersonTitle(string);
	friend void Person::setPersonMobile(string);
	friend void Person::setPersonEmail(string);
	friend void Person::setSearchWhichProperty(string*);
	friend size_t Person::getPersonCapacity(Person **);
	friend void Person::displayPerson(Person **);

private:

};


class searchWhat : protected Person
{
public:
	Person** searchAnything(Person**, Person**, string);
	Person** searchEachProperty(Person**, size_t&, string, Person**, string);
	friend void Person::setPersonInfoDefault(Person**, size_t);

private:

};

