#pragma once
#include <string>
#include "db_pool.hpp"


class Card {


protected:

public:
	std::string owner_name;
	std::string card_number; // "#143 #### #### ####", 143 - BelBank numbers
	std::string payment_system;
	double balance;
	std::string pin;
	//int validity; // number of days before expiration (calculate with QDate)
	int CVV_code;


	Card(std::string card_number, long double balance, std::string pin, int CVV_code);
	~Card();
	std::string getCardNumber() const;
	long long getBalance() const;
	long double makePayment(std::string pin, long double amount);
	long double moneyTransfer(long double amount, Card other_card, std::string pin);
}; 



namespace soci {

	template<> struct type_conversion<Card> {
		typedef values base_type;

		static void from_base(values const& v, indicator ind, Card& p) {
			if (ind == i_null) return;
			try {
				p.owner_name = v.get<std::string>("owner_name", {});
				p.card_number = v.get<std::string>("card_number", {});
			p.balance = v.get<double>("balance", 0);
				p.pin = v.get<std::string>("pin", {});
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
		}

		static void to_base(const Card& p, values& v, indicator& ind) {
			try {
				v.set("owner_name", p.owner_name);
				v.set("card_number", p.card_number);
				v.set("balance", p.balance);
				v.set("pin", p.pin);
				ind = i_ok;
				return;
			}
			catch (std::exception const& e) { std::cerr << e.what() << std::endl; }
			ind = i_null;
		}

	};
}
