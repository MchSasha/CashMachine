#include "cash_machine.h"
#include <sstream>
#include <fstream>
#include <math.h>
void Bank::buildBankBase()
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
}



void card::setCardsAccount(account account)
{
	this->cards_account = account;
};
void card::setCardsNumber(int *num)
{
	for (int i = 0; i < 16; i++)
		this->cards_number[i] = num[i];
};
void card::setCardsPIN(PIN pin)
{
	this->cards_pin = pin;
};



void PIN::setPIN(int* pin)
{
	for (int i = 0; i < 4; i++)
		this->pin[i] = pin[i];
};



void account::setAccountsNumber(int* num)
{
	for (int i = 0; i < 16; i++)
		this->accounts_number[i] = num[i];
};
void account::setAccountsSum(int sum)
{
	this->sum = sum;
};



void client::setFIO(string fio)
{
	this->FIO = fio;
};
void client::setClientsCard(card card)
{
	this->clients_card = card;

};



void setFIO_info() {

};
void setCardNumber_info();
void setCardPIN_info();
void setCardSum_info();