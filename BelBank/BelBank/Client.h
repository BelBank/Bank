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


#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include <iostream>
//#include "db_pool.hpp"


class Client
{

public:
	int id;
	std::string login, password;



	//std::vector<Card> cards;

	Client() : id(0), login(), password() {}

	void print() {
		std::cout << "id: " << id << std::endl;
		std::cout << "login: " << login << std::endl;
		std::cout << "password: " << password << std::endl;
	}

	void clear() {
		id = 0;
		login = password = "";
	}

	Client(std::string login, std::string password);
	~Client();
	//void addCard(Card new_card);


};

#pragma once
