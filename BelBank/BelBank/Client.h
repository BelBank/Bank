
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
