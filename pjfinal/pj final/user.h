#ifndef USER_H
#define USER_H
#include<string>
using namespace std;

class user{
private:
	int userID;
	string name;
	string userName;
	string role;
public:
	//the default constarter
	user() { userID = 1; };

	//to setting the data in user
	void inputUser(string nName, string nUserName, int lastID, string nRole);

	//those get and set function
	string getName();
	string getUserName();
	string getRole();
	int getUserID();
	void setName(string x);
	void setUserName(string x);
	void setRole(string x);
	void setUserID(int x);

};
#endif
