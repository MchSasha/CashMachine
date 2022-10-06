#pragma once
using namespace std;
#include <string>
#include <vector>
#include <iostream>



class account
{
private:
	double sum;
	int accounts_number[16];
public:
	void setAccountsNumber(const int* num);
	void setAccountsSum(const int &sum);

};

class PIN
{
private:
	int pin[4];
public:
	void setPIN(const int *pin);
};

class card
{
private:
	account cards_account;
	int cards_number[16];
	PIN cards_pin;
public:
	card(string cardName);
	card();
	void setCardsAccount(const account &account);
	void setCardsNumber(const int* num);
	void setCardsPIN(const PIN &pin);
	const account getCardsAccount();
	const int* getCardsNumber();
	const PIN getCardsPIN();


	void insertCard();

};

class client
{
private:
	string FIO;
	card clients_card;
public:
	client();
	void setFIO(const string& fio);
	void setClientsCard(const card& card);

	const string getFIO();
	const card getClientsCard();
};





class Bank
{
protected:
	vector <client> client_info;
	
private:	
	vector <vector<string>> sessions_history;
public: 
	Bank();
	Bank(string BankName); //void buildBankBase(); 	//void setFIO_info();  //void setCardNumber_info(); //void setCardPIN_info(); //void setCardSum_info();
	
};

class session : public Bank
{
public:
	session();
	session(client& user);
private:
	vector<string> user_history;

};

class BaseWindow : public session
{
public:
	BaseWindow();
	void ChooseLanguage();
	void EnterPIN();
};

class cash_machine
{
private:

public:
	cash_machine();
	void startSession(const card &card);
	
};