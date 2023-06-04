#pragma once
#include <string>
#include "Role.h"
#include "Date.h"
#include "Permission.h"

class User : Role , Permission{
private:
	int user_id;
	int user_role_id;
	std::string user_name;
	std::string user_email;
	Date user_dob;
	std::string user_address;
public:
	void addUser();
	void editUser();
	void deleteUser();
	void searchUser();
};