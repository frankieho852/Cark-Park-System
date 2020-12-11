#include<iostream>
#include<string>
#include<sstream>
#include"user.h"
using namespace std;

//to setting the data in user
void user::inputUser(string nName, string nUserName, int lastID, string nRole) {
	name = nName;
	userName = nUserName;
	role = nRole;
	userID = lastID;
}

//thoes get function
string user::getName()
{
	return name;
}

string user::getUserName()
{
	return userName;
}

string user::getRole()
{
	return role;
}

int user::getUserID()
{
	return userID;
}

//those set function
void user::setName(string x)
{
	name = x;
}

void user::setUserName(string x)
{
	userName = x;
}

void user::setRole(string x)
{
	role = x;
}

void user::setUserID(int x)
{
	userID = x;
}



