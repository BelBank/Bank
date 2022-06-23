#ifndef Client_h
#define Client_h



#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Card.h"
#include "db_pool.hpp"


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
		login = "";
		password = "";
	}

	Client(std::string login, std::string password)
	{
		this->login = login;
		this->password = password;
	}

	~Client() {}
	//void addCard(Card new_card);
};


namespace soci {

	template<> struct type_conversion<Client> {
		typedef values base_type;

		static void from_base(values const& v, indicator ind, Client& p) {
			if (ind == i_null) return;
			try {
				p.id = v.get<int>("id", 0);
				p.login = v.get<std::string>("login", {});
				p.password = v.get<std::string>("password", {});
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
		}

		static void to_base(const Client& p, values& v, indicator& ind) {
			try {
				v.set("id", p.id);

				v.set("login", p.login);
				v.set("password", p.password);

				ind = i_ok;
				return;
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
			ind = i_null;
		}

	};
}

#endif