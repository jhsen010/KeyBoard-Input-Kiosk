#include"key.h"
using namespace std;
int index = 0; // index�� ���������� ����ü�迭 �ϳ��� �޴� �ϳ��� ����
void Hamberger::hambergur_order(Order* ORDER, string a, int n)
{
	int food_count = 0;
	char yorn;
	string reorder;
	while (1)
	{
		if (food.find(a) != food.end()) { // map�� find�Լ��� �����͸� ������ ã�� ������ ���, iterator�� end()�� ��ȯ�մϴ�.
										  // ��, ã���� ��� end�Լ��� ��ȯ���� �ʴ´�
			for (int i = 0; i <= index; i++)
			{
				if (a != ORDER[i].foodname) // �Էµ� �޴��� �ֹ�ǥ�� ������� �ֹ�ǥ�� �߰�
				{
					ORDER[index].foodname = a;
					ORDER[index].price = food[a];
					ORDER[index].count = n;
				}
			}
			index++;
			cout <<a<<" �ֹ��� �Ϸ�Ǿ����ϴ�. �߰��� �ֹ��Ͻðڽ��ϱ�?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder>>food_count;
				for (int i = 0; i < index; i++) 
				{
					if (reorder == ORDER[i].foodname)//���ֹ��� �ֹ�ǥ�� ���� ������ ������� ����ü�迭�� �� �߰����� �ʰ� �ε����� ã�Ƽ� ������ �÷��ش�.
					{
						ORDER[i].count+=food_count;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout<<"-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = food[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn=='n')
				return;
			else { cout << "�߸��� �Է��Դϴ�" << endl; }
		}
		else {
			cout << "ã���ô� ������ �����ϴ�.�ٽ� �ֹ��Ͻðڽ��ϱ�?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder >> food_count;
				if (food.find(reorder) != food.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = food[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
						}
					}
				}
			}
			else if(yorn == 'n')
			{
				return;
			}
			
		}
	}
}
void Hamberger::side_order(Order* ORDER, string a, int n)//�Ȱ��� ���� �߰� �ֹ�, 
{
	int food_count = 0;
	char yorn;
	string reorder;
	while (1)
	{
		if (side.find(a) != side.end()) {
			for (int i = 0; i <= index; i++)
			{
				if (a != ORDER[i].foodname)
				{
					ORDER[index].foodname = a;
					ORDER[index].price = side[a];
					ORDER[index].count = n;
				}
			}
			index++;
			cout << a << " �ֹ��� �Ϸ�Ǿ����ϴ�. �߰��� �ֹ��Ͻðڽ��ϱ�?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder >> food_count;
				for (int i = 0; i < index; i++)
				{
					if (reorder == ORDER[i].foodname)
					{
						ORDER[i].count += food_count;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = side[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn == 'n')
				return;
		}
		else {
			cout << "ã���ô� ������ �����ϴ�.�ٽ� �ֹ��Ͻðڽ��ϱ�?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder >> food_count;
				if (side.find(reorder) != side.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = side[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
					}
				}
			}
			else if (yorn == 'n')
			{
				return;
			}

		}
	}
}
void Hamberger::drink_order(Order* ORDER, string a, int n)//�Ȱ��� ���� �߰� �ֹ�, 
{
	int food_count = 0;
	char yorn;
	string reorder;
	while (1)
	{
		if (drink.find(a) != drink.end()) {
			for (int i = 0; i <= index; i++)
			{
				if (a != ORDER[i].foodname)
				{
					ORDER[index].foodname = a;
					ORDER[index].price = drink[a];
					ORDER[index].count = n;
				}
			}
			index++;
			cout << a << " �ֹ��� �Ϸ�Ǿ����ϴ�. �߰��� �ֹ��Ͻðڽ��ϱ�?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder >> food_count;
				for (int i = 0; i < index; i++)
				{
					if (reorder == ORDER[i].foodname)
					{
						ORDER[i].count += food_count;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = drink[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn == 'n')
				return;
		}
		else {
			cout << "ã���ô� ������ �����ϴ�.�ٽ� �ֹ��Ͻðڽ��ϱ�?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "�ֹ��� ���İ� ������ �Է����ּ���->";
				cin >> reorder >> food_count;
				if (drink.find(reorder) != drink.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = drink[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " �ֹ��� �Ϸ�Ǿ����ϴ�.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
					}
				}
			}
			else if (yorn == 'n')
			{
				return;
			}

		}
	}
}
