//    That's an example of an internet banking system and this is a practice project
//    Copyright(C) 2022 Shchirov P.D, Skvortsov A. V, Kosmin P. M.
//
//    This program is free software : you can redistribute it and /or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//    GNU General Public License for more details.


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

