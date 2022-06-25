#include "Client.h"


std::string Client::hash_password(const std::string& password)
{
	unsigned int hash = 0;
	unsigned int a = 63689;
	unsigned int b = 378551;
	for (int i = 0; i < password.length(); i++)
	{
		hash = hash * a + password[i];
		a = a * b;
	}
	char hash_string[255];
	sprintf(hash_string, "%X", hash);
	return std::string(hash_string);
}

void Client::clear() {
	id = 0;
	login = "";
	password = "";
	name = "";
}

