
#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Client
{
private:
	
	std::string login;
	std::string password;
	std::vector<Card> cards;

public:

	Client(std::string login, std::string password);
	~Client();
	void addCard(Card new_card);


};

