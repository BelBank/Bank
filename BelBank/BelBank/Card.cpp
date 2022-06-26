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

#include "Card.h"


Card::Card(std::string card_number, long double balance, std::string pin, int CVV_code)
	: card_number(card_number), balance(balance), pin(pin), CVV_code(CVV_code)
{
	if (card_number[0] == '4')
	{
		payment_system = "Visa";
	}
	else if (card_number[0] == '5')
	{
		payment_system = "MasterCard";
	}
	else if (card_number[0] == '3')
	{
		payment_system = "MIR";
	}
}

Card::~Card() {}

std::string Card::getCardNumber() const {
	return card_number;
}

long long Card::getBalance() const {
	return balance;
}
long double Card::makePayment(std::string pin, long double amount)
{
	if (this->pin != pin)
	{
		throw("PIN-code doesn't match!");
		return 0;
	}
	if (amount > balance)
	{
		throw("Not enough money!");
		return 0;
	}
	balance -= amount;
	return balance;
}

long double Card::moneyTransfer(long double amount, Card other_card, std::string pin)
{
	if (this->pin != pin)
	{
		throw("PIN-code doesn't match!");
		return 0;
	}
	if (amount > balance)
	{
		throw("Not enough money!");
		return 0;
	}
	balance -= amount;
	other_card.balance += amount;
	return balance;
}

