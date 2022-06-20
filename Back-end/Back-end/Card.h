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