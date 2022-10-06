#include "cash_machine.h"
#include <sstream>
#include <fstream>
#include <math.h>
Bank::Bank()
{
	;
}
Bank::Bank(string BankName)
{
	ifstream getBankBase(BankName);/*"BankBase.txt"*/
	string in;
	while (getline(getBankBase, in))
	{
		stringstream info(in);
		string fo;
		client new_client;
		card new_card;
		account new_acc;
		int score = 0;
		while (getline(info, fo, ' '))
		{
			if (!score)
				new_client.setFIO(fo);
			if (score == 1) { // счет
				int num[16];
				for (int i = 0; i < 16; i++)
					num[i] = fo[i] - '0';
				new_acc.setAccountsNumber(num);
			}
			if (score == 2) {//карта
				int num[16];
				for (int i = 0; i < 16; i++)
					num[i] = fo[i] - '0';
				new_card.setCardsNumber(num);
			}
			if (score == 3) {
				int num[4];
				for (int i = 0; i < 4; i++)
					num[i] = fo[i] - '0';
				PIN pin;
				pin.setPIN(num);
				new_card.setCardsPIN(pin);
			}
			if (score == 4) {
				new_acc.setAccountsSum(stoi(fo));

				new_card.setCardsAccount(new_acc);
				new_client.setClientsCard(new_card);
				this->client_info.push_back(new_client);
			}
			score++;
		}


	}
}

/*void Bank::buildBankBase()
{
	ifstream getBankBase("BankBase.txt");
	string in;
	while (getline(getBankBase, in))
	{
		stringstream info(in);
		string fo;
		client new_client; 
		card new_card;
		account new_acc;
		int score = 0;
		while (getline(info, fo, ' '))
		{
			if (!score)
				new_client.setFIO(fo);
			if (score == 1) { // счет
				int num[16];
				for (int i = 0 ; i < 16; i++)
					num[i] = fo[i] - '0';
				new_acc.setAccountsNumber(num);
			}
			if (score == 2) {//карта
				int num[16];
				for (int i = 0; i < 16; i++)
					num[i] = fo[i] - '0';
				new_card.setCardsNumber(num);
			}
			if (score == 3) {
				int num[4];
				for (int i = 0; i < 4; i++)
					num[i] = fo[i] - '0';
				PIN pin;
				pin.setPIN(num);
				new_card.setCardsPIN(pin);
			}
			if (score == 4) {
				new_acc.setAccountsSum(stoi(fo));
				
				new_card.setCardsAccount(new_acc);
				new_client.setClientsCard(new_card);
				this->client_info.push_back(new_client);
			}
			score++;
		}

		
	}
}*/



void card::setCardsAccount(const account &account)
{
	this->cards_account = account;
};
void card::setCardsNumber(const int *num)
{
	for (int i = 0; i < 16; i++)
		this->cards_number[i] = num[i];
};
void card::setCardsPIN(const PIN &pin)
{
	this->cards_pin = pin;
};
card::card()
{
};


void PIN::setPIN(const int* pin)
{
	for (int i = 0; i < 4; i++)
		this->pin[i] = pin[i];
};



void account::setAccountsNumber(const int* num)
{
	for (int i = 0; i < 16; i++)
		this->accounts_number[i] = num[i];
};
void account::setAccountsSum(const int &sum)
{
	this->sum = sum;
};



void client::setFIO(const string& fio)
{
	this->FIO = fio;
};
void client::setClientsCard(const card& card)
{
	this->clients_card = card;

};
const string client::getFIO()
{
	return this->FIO;
};
const card client::getClientsCard()
{
	return this->clients_card;
};
client::client()
{

};



BaseWindow::BaseWindow()
{
	system("cls");
	cout << "Please, insert your card \n";
	string place_to_find_card; cin >> place_to_find_card;
	card card(place_to_find_card);
};
void BaseWindow::ChooseLanguage()
{

};
void BaseWindow::EnterPIN()
{

};

cash_machine::cash_machine()
{
	BaseWindow win;
};
card::card(string cardName)
{
	ifstream getCard(cardName);/*"BankBase.txt"*/
	string in; int score = 0;
	client new_client;
	card new_card;
	while (getline(getCard, in))
	{
		stringstream info(in);
		string fo;
		while (getline(info, fo, ' '))
			if (score)
			{
				int num[16];
				for (int i = 0; i < 16; i++)
					num[i] = fo[i] - '0';
				new_card.setCardsNumber(num);
			}
			else {
				new_client.setFIO(fo);
				score++;
			}
		new_client.setClientsCard(new_card);
	}
	session session(new_client);
};

const int* card::getCardsNumber()
{
	return this->cards_number;
};
const account card::getCardsAccount()
{
	return this->cards_account;
};
const PIN card::getCardsPIN()
{
	return this->cards_pin;
};

session::session()
{
	;
}
session::session(client& user)
{
	int expected_PIN[4];
	for (client i : client_info)
		if (user.getFIO() == i.getFIO())
		{
			card users_card = user.getClientsCard();
			card card_from_BankBAse = i.getClientsCard();

			if (users_card.getCardsNumber() == card_from_BankBAse.getCardsNumber())
			{
				users_card.setCardsAccount(card_from_BankBAse.getCardsAccount());
				users_card.setCardsPIN(card_from_BankBAse.getCardsPIN());
			}
		}

};










