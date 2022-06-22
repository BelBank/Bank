//#include "Card.h"
//
//
//Card::Card(std::string card_number, long double balance, int pin, int validity, int CVV_code)
//	: card_number(card_number), balance(balance), pin(pin), validity(validity), CVV_code(CVV_code) 
//{
//	if (card_number[0] == '4')
//	{
//		payment_system = "Visa";
//	}
//	else if (card_number[0] == '5')
//	{
//		payment_system = "MasterCard";
//	}
//	else if (card_number[0] == '3')
//	{
//		payment_system = "ÌÈÐ";
//	}
//	else
//	{
//		payment_system = "OPS"; // Own Payment System
//	}
//}
//
//Card::~Card() {}
//
//std::string Card::getCardNumber() const {
//	return card_number;
//}
//
//long long Card::getBalance() const {
//	return balance;
//}
//
//long double Card::makePayment(int pin, long double amount)
//{
//	if (this->pin != pin)
//	{
//		throw("PIN-code doesn't match!");
//		return 0;
//	}
//	if (amount > balance)
//	{
//		throw("Not enough money!");
//		return 0;
//	}
//	balance -= amount;
//	return balance;
//}
//
//long double Card::moneyTransfer(long double amount, Card other_card, int pin)
//{
//	if (this->pin != pin)
//	{
//		throw("PIN-code doesn't match!");
//		return 0;
//	}
//	if (amount > balance)
//	{
//		throw("Not enough money!");
//		return 0;
//	}
//	balance -= amount;
//	other_card.balance += amount;
//	return balance;
//}
//
