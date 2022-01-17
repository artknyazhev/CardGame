#include<iostream>
#include<vector>
#include<string>
#include<Windows.h>
#include<time.h>

using namespace std;



class Card
{
public:
	Card(int v,int m) {
		val = v;
		type = mast[m];
	}
	void ShowC() {
		if (val == 11)
			cout << "J(" << type<<") | ";
		else if (val == 12)
			cout << "Q(" << type << ") | ";
		else if (val == 13)
			cout << "K(" << type << ") | ";
		else if (val == 14)
			cout << "A(" << type << ") | ";
		else 
			cout << val << "(" << type << ") | ";
	}
	int GetV() {
		return val;
	}
	~Card()=default;

private:
	int val;
	char mast[4] = { char(3),char(4),char(5),char(6) };
	char type;
};

vector<Card> c = { Card(6,0),Card(6,1),Card(6,2),Card(6,3),
	Card(7,0),Card(7,1),Card(7,2),Card(7,3),
	Card(8,0),Card(8,1),Card(8,2),Card(8,3),
	Card(9,0),Card(9,1),Card(9,2),Card(9,3),
	Card(10,0),Card(10,1),Card(10,2),Card(10,3),
	Card(11,0),Card(11,1),Card(11,2),Card(11,3),
	Card(12,0),Card(12,1),Card(12,2),Card(12,3),
	Card(13,0),Card(13,1),Card(13,2),Card(13,3),
	Card(14,0),Card(14,1),Card(14,2),Card(14,3) };


class Player
{
public:
	Player(int _n) {
		
		win = false;
		num = _n;
		
	};
	void SetPlayer() {
		srand(time(NULL));
		for (size_t i = 0; i < 18; i++)
		{
			int n = 0 + rand() % c.size();
			card.push_back(c[n]);
			c.erase(c.begin() + n);


			Sleep(100);
		}
	}
	int ChooseCard() {
		int rnd = 0 + rand() % card.size();
		cn = rnd;
		cout << "\nPlayer " << num << " pick: "; card[rnd].ShowC(); cout << endl;
		return card[rnd].GetV();
	}
	Card GiveCard() {
		return card[cn];
	}
	void EraseCard() {
		card.erase(card.begin() + cn);
	}
	void PushCard(Card c1) {
		cout << "\nPlayer " << num << " takes in hand: "; c1.ShowC();cout << endl;
		card.push_back(c1);
	}
	bool IsLose() {
		if (card.empty() == true)
			return true;
		else
			return false;
	}
	int getPl() {
		return num;
	}
	void Show() {
		cout << "\t\tPlayer " << num << " hand:\n";
		for (size_t i = 0; i < card.size(); i++)
		{
			if (i == card.size() / 2)
				cout << endl;
			card[i].ShowC();
		}
		cout << "\n";
	}
	~Player()=default;

protected:
	vector<Card> card;
	bool win;
	int num;
	int cn;
};



int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Player p1(1);
	p1.SetPlayer();
	Player p2(2);
	p2.SetPlayer();
	do {
		Sleep(250);
		system("cls");
		p1.Show();
		p2.Show();
		int s1, s2;
		s1 = p1.ChooseCard();
		s2 = p2.ChooseCard();
		if (s1 < s2) {
			p1.PushCard(p2.GiveCard());
			p2.EraseCard();

		}
		else if (s2 < s1) {
			p1.PushCard(p2.GiveCard());
			p2.EraseCard();
		}
		else if (s1 == s2) {
			cout << "\nPlayers pick single cards\n";
		}


	} while (p1.IsLose() != true || p2.IsLose() != true);
	if (p1.IsLose())
		cout << "\n\nPlayer " << p1.getPl() << " win!\n\n";
	else if(p2.IsLose())
		cout << "\n\nPlayer " << p2.getPl() << " win!\n\n";

	return 0;
}