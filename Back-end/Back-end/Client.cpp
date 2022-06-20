#include "Client.h"


Client::Client(std::string login, std::string password)
{
	this->login = login;
	this->password = password;
}

Client::~Client(){}

void Client::addCard(Card new_card)
{
	this->cards.push_back(new_card);
}