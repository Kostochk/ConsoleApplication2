#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
	string name;
	int age;
public:
	User() {
		name = "Boryslav";
		age = 222;
	}
	User(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void WriteUserToFile() {
		ofstream outFile("users.txt", ios::app);
		outFile << "Username: " << this->name << " - Age: " << this->age << endl;
		outFile.close();
	}

};

class Group {
	User* users;
	int amountOfUsers;
public:
	Group() {
		amountOfUsers = 1;
		users = new User[amountOfUsers];
	}
	void ReadAllUsersToFile() {
		ifstream inFile("users.txt");
		string line;
		while (getline(inFile, line)) {
			cout << line << endl;
		}
		inFile.close();
	}
};
int main()
{
	User obj;
	obj.WriteUserToFile();
	Group obj1;
	obj1.ReadAllUsersToFile();

}