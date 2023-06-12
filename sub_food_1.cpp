#include "key.h"

using namespace std;

void list_sort(Order* orders);

void Hamberger::sub_food(Order* orders) 
{
	char wf; //�ܹ��� ���̵� �帵ũ�� �����ϴ� ����
	int i;
	char choice;
	string name;

	cout << "�ܹ���, ���̵�, �帵ũ �� �����Ͻ� �׸��� �����ϼ���.(h: �ܹ���, s: ���̵�, d: �帵ũ) : ";
	cin >> wf;

	switch (wf)
	{
	case 'h': //�ܹ��Ÿ� �����Ϸ��� �Ҷ�
		choice = '\0';
		cout << "������ �ܹ��� �̸�:";
		cin >> name;
		if (food.find(name) != food.end()) //�����Ϸ��� �ϴ� ��� ���� �޴� �׸��� �����ϴ��� Ȯ��
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name) //�����Ϸ��� �ϴ� �׸��� �ֹ�����Ʈ�� �����ϴ��� Ȯ��
				{
					cout << name << " (��)�� �ֹ��׸񿡼� �����Ͻðڽ��ϱ�?\n(y �Ǵ� n �Է�)";

					break;
				}
			}
		}
		else
		{
			cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
			return;
		}

		while (1)
		{
			cin >> choice;

			if (choice == 'y')
			{
				orders[i].foodname = "";
				orders[i].count = 0;
				list_sort(orders);
			}
			else if (choice == 'n')
			{
				return;
			}
			else
			{
				cout << "�߸��� �Է°��Դϴ�. �ٽ��Է��ϼ���." << endl;
				continue;
			}
		}
		break;
	case 's': //���̵� �޴��� ������ ��
		choice = '\0';
		cout << "������ ���̵� �̸�:";
		cin >> name;
		if (side.find(name) != side.end())
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name)
				{
					cout << name << " (��)�� �ֹ��׸񿡼� �����Ͻðڽ��ϱ�?\n(y �Ǵ� n �Է�)";

					break;
				}
			}
		}
		else
		{
			cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
			return;
		}

		while (1)
		{
			cin >> choice;

			if (choice == 'y')
			{
				orders[i].foodname = "";
				orders[i].count = 0;
				list_sort(orders);
			}
			else if (choice == 'n')
			{
				return;
			}
			else
			{
				cout << "�߸��� �Է°��Դϴ�. �ٽ��Է��ϼ���." << endl;
				continue;
			}
		}
	case 'd': //�帵ũ �޴��� ������ ��
		i = 0;
		choice = '\0';
		cout << "������ �帵ũ �̸�:";
		cin >> name;
		if (drink.find(name) != drink.end())
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name)
				{
					cout << name << " (��)�� �ֹ��׸񿡼� �����Ͻðڽ��ϱ�?\n(y �Ǵ� n �Է�)";

					break;
				}
			}
		}
		else
		{
			cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���." << endl;
			return;
		}

		while (1)
		{
			cin >> choice;

			if (choice == 'y')
			{
				orders[i].foodname = "";
				orders[i].count = 0;
				list_sort(orders);
			}
			else if (choice == 'n')
			{
				return;
			}
			else
			{
				cout << "�߸��� �Է°��Դϴ�. �ٽ��Է��ϼ���." << endl;
				continue;
			}
		}
	default :
		cout << "�߸��� �Է��Դϴ�. �ٽ��Է��ϼ���." << endl;
		break;
	}
}

void list_sort(Order* orders) //�迭�� �ֹ� ������� �������ִ� �Լ�
{
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		if (orders[i].foodname == "")
			if (orders[i + 1].foodname != "")
			{
				orders[i].foodname = orders[i + 1].foodname;
				orders[i].count = orders[i + 1].count;
				orders[i + 1].foodname = "";
				orders[i + 1].count = 0;
			}
	}
}