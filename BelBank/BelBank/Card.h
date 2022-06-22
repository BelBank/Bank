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


class Card {


protected:

	std::string card_number; // "#143 #### #### ####", 143 - BelBank numbers
	std::string payment_system;
	long double balance;
	int pin;
	int validity; // number of days before expiration (calculate with QDate)
	int CVV_code;

public:

	Card(std::string card_number, long double balance, int pin, int validity, int CVV_code);
	~Card();
	std::string getCardNumber() const;
	long long getBalance() const;
	long double makePayment(int pin, long double amount);
	long double moneyTransfer(long double amount, Card other_card, int pin);
}; 
