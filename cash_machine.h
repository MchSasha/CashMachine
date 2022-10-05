#pragma once
using namespace std;
#include <string>
#include <vector>



class account
{
private:
	double sum;
	int accounts_number[16];
public:
	void setAccountsNumber(int* num);
	void setAccountsSum(int sum);

};

class PIN
{
private:
	int pin[4];
public:
	void setPIN(int *pin);
};

class card
{
private:
	account cards_account;
	int cards_number[16];
	PIN cards_pin;
public:
	void setCardsAccount(account account);
	void setCardsNumber(int* num);
	void setCardsPIN(PIN pin);
};

class client
{
private:
	string FIO;
	card clients_card;
public:
	void setFIO(string fio);
	void setClientsCard(card card);
};

class session : public client
{
private:
	bool state = true;

};

class Bank
{
private:
	vector <client> client_info;
	vector <session> sessions_history;
public: 
	void buildBankBase();
	void setFIO_info();
	void setCardNumber_info();
	void setCardPIN_info();
	void setCardSum_info();
	
};

class cash_machine : public Bank
{
public:
	
};