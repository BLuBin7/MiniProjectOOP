#pragma once
#include <string>
class Permission {
protected:
	int permission_id;
	int permission_role_id;
	std::string permission_title;
	std::string permission_module;
	std::string permission_description;
public:
	void addPermission();
	void editPermission();
	void deletepermission();
	void searvh
};
