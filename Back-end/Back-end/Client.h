#ifndef Client_h
#define Client_h



#pragma once
#include <string>
#include <vector>
#include <iostream>
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


	std::string hash_password(const std::string& password)
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