#include "key.h"
using namespace std;

Hamberger::Hamberger() { // ��ü�޴� ������
	total = 0, pay = 0, change = 0;

	// �ܹ��Ÿ޴�
	food["Ʈ������Ʈ�θӽ��뽺����ũ���ż�Ʈ"] = 9000;
	food["Ʈ������Ʈ�θӽ�����ۼ�Ʈ"] = 8000;
	food["���������ִϾƮ"] = 6600;
	food["����콺����ũ���ż�Ʈ"] = 9700;
	food["�������ۼ�Ʈ"] = 8600;
	food["����"] = 7700;
	food["�Ұ�����"] = 7700;
	food["��Ʈ��ġ�����"] = 8500;
	food["ġ�����"] = 8300;
	food["�����ִϾ�"] = 6000;
	food["�Ұ������ִϾ�"] = 6000;
	food["��Ʈ��ġ������ִϾ�"] = 6600;
	food["ġ������ִϾ�"] = 6300;

	// ���̵� �޴�
	side["ġ�ƽ"] = 1500;
	side["���ڳӽ����� 3����"] = 2800;
	side["���ڳӽ����� 6����"] = 5600;
	side["���ڳӽ����� 9����"] = 8300;
	side["�ٴ�ŷ 2����"] = 2000;
	side["�ٴ�ŷ 4����"] = 3900;
	side["�ٴ�ŷ 6����"] = 5700;
	side["ġ��������"] = 2500;
	side["����ġ������"] = 1600;
	side["��Ͼ�"] = 2000;
	side["�ʰ�ŷ 4����"] = 2000;
	side["�ʰ�ŷ 6����"] = 3000;
	side["�ʰ�ŷ 10����"] = 5000;
	side["�ٴҶ󼱵�"] = 600;
	side["���⼱��"] = 1500;
	side["���ڼ���"] = 1500;
	side["�ܻ�����"] = 1600;

	// ����
	drink["�Ƹ޸�ī��"] = 1500;
	drink["ī���"] = 2500;
	drink["��ī�ݶ�"] = 1700;
	drink["��ī�ݶ�(����)"] = 1500;
	drink["�Ƹ޸�ī��"] = 1500;
	drink["�Ƹ޸�ī��"] = 1500;
	drink["�Ƹ޸�ī��"] = 1500;
}

void Hamberger::showmenu() { // ��ü �޴� ���
	// �ܹ����� ��� ������ ���
	for (auto iter = food.begin(); iter != food.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;

	// ���̵��� ��� ������ ���
	for (auto iter = side.begin(); iter != side.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;

	// ������ ��� ������ ���
	for (auto iter = drink.begin(); iter != drink.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;


}

void Hamberger::set_total(int t) { // �ѱݾ� ����
	total = t;
}

int Hamberger::get_total() { // �ѱݾ� �� ��ȯ
	return total;
}

void Hamberger::set_change(int t, int c) { // �ܵ� ����
	change = c - t;
}

int Hamberger::get_change() { // �ܵ� ��ȯ
	return change;
}

void Hamberger::select_showmenu(Order* user, int index) {
	int total = 0;

	// �� �ֹ�ǥ ���
	cout << "-------�� �ֹ�ǥ-------" << endl;
	for (int i = 0; i < index; i++) {
		cout << "�޴�: " << user[i].foodname << ", ����: " << user[i].price <<
			", ����: " << user[i].count << "��" << endl;
	}

	//�ѱݾ� ���
	for (int i = 0; i < 17; i++) {
		if (food.find(user[i].foodname) != food.end()) {
			total += (user[i].price * user[i].count);
		}
		if (side.find(user[i].foodname) != side.end()) {
			total += (user[i].price * user[i].count);
		}
		if (drink.find(user[i].foodname) != drink.end()) {
			total += (user[i].price * user[i].count);
		}
	}
	set_total(total);

	// �ѱݾ� ���
	cout << "�� �ݾ�: " << get_total() << endl;
}

bool Hamberger::card_cash(Order* user) {


	char choice, card;
	int cash;
	string name;
	cout << "����Ͻðڽ��ϱ�? �Ǵ� �޴� ���� �Ǵ� �߰��Ͻðڽ��ϱ�?" << endl;
	cout << "��� y, �޴� �߰� �� ����==n �Է�: ";
	cin >> choice;

	
	switch (choice) {
	case 'y': // ���ҹ�� ����
		cout << "ī��==c, ����==s �Է�: ";
		cin >> card;
		switch (card) {
		case 'c':
			cout << "ī�带 �����Ͽ����ϴ�." << endl;
			cout << "�����Ϸ�" << endl;
			cout << "�����մϴ� �ȳ���������~";
			break;
		case 's':
			cout << "���ݸ� �����Ͽ����ϴ�.";
			cin >> cash;
			set_change(get_total(), cash);
			cout << "�ܵ�: " << get_change() << endl;
			cout << "�����Ϸ�" << endl;
			cout << "�����մϴ� �ȳ���������~";
			break;
		}
		return true;
	case 'n':
		select(user);		
		return false;
	}
}

void Hamberger::select(Order *user) {
	char choice1, choice2;
	string name;
	int n;
		
	//�޴� �߰��� ���� ����
		cout << "�߰��� ���ż���(�߰��� a ���Ŵ� s):";
		cin >> choice1;
		switch (choice1) {
		case 'a':
			cout << "�ܹ���: h, ���̵�: s, ����: d   "; // �ܹ���, ���̵�, ������ ����
			cin >> choice2;
			switch (choice2) {
			case 'h': // �ܹ��� �߰�
				cout << "�߰��� �ܹ��� �̸� : ";
				cin >> name;
				cout << "�߰��� ����: ";
				cin >> n;
				hambergur_order(user, name, n);
				break;
			case 's': // ���̵� �߰�
				cout << "�߰��� ���̵� �̸�: ";
				cin >> name;
				cout << "�߰��� ����: ";
				cin >> n;
				side_order(user, name, n);
				break;
			case 'd': // ���� �߰�
				cout << "�߰��� ���� �̸�: ";
				cin >> name;
				cout << "�߰��� ����: ";
				cin >> n;
				drink_order(user, name, n);
				break;
			}
			break;
		case 's': // �޴� ����
			sub_food(user);
			}
		
}
