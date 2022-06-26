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


#ifndef Client_h
#define Client_h



#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Card.h"


class Client
{

public:
	int id;
	std::string login, password, name;
	//std::vector<Card> cards;

	Client() : id(0), login(), password(), name() {}

	Client(std::string login, std::string password, std::string name) : login(login), password(password), name(name) {}

	~Client() {}

	std::string hash_password(const std::string& password);

	void clear();

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
				p.name = v.get<std::string>("name", {});
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
		}

		static void to_base(const Client& p, values& v, indicator& ind) {
			try {
				v.set("id", p.id);

				v.set("login", p.login);
				v.set("password", p.password);
				v.set("name", p.name);
				ind = i_ok;
				return;
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
			ind = i_null;
		}

	};
}

#endif
