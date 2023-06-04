#pragma once
#include <string>
class Role {
protected:
	int role_id;
	std::string role_title;
	std::string role_description;
public:
	void addRole();
	void editRole();
	void deleteRole();
	void searchRole();
	void assignRole();
};