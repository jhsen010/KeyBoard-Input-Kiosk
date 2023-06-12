#include"key.h"
using namespace std;
int index = 0; // index는 전역변수로 구조체배열 하나당 메뉴 하나를 설정
void Hamberger::hambergur_order(Order* ORDER, string a, int n)
{
	int food_count = 0;
	char yorn;
	string reorder;
	while (1)
	{
		if (food.find(a) != food.end()) { // map의 find함수는 데이터를 끝까지 찾지 못했을 경우, iterator는 end()를 반환합니다.
										  // 즉, 찾았을 경우 end함수를 반환하지 않는다
			for (int i = 0; i <= index; i++)
			{
				if (a != ORDER[i].foodname) // 입력된 메뉴가 주문표에 없을경우 주문표에 추가
				{
					ORDER[index].foodname = a;
					ORDER[index].price = food[a];
					ORDER[index].count = n;
				}
			}
			index++;
			cout <<a<<" 주문이 완료되었습니다. 추가로 주문하시겠습니까?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder>>food_count;
				for (int i = 0; i < index; i++) 
				{
					if (reorder == ORDER[i].foodname)//재주문시 주문표에 같은 음식이 있을경우 구조체배열을 더 추가하지 않고 인덱스를 찾아서 갯수만 늘려준다.
					{
						ORDER[i].count+=food_count;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout<<"-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = food[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn=='n')
				return;
			else { cout << "잘못된 입력입니다" << endl; }
		}
		else {
			cout << "찾으시는 음식이 없습니다.다시 주문하시겠습니까?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder >> food_count;
				if (food.find(reorder) != food.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " 주문이 완료되었습니다.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = food[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " 주문이 완료되었습니다.\n";
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
void Hamberger::side_order(Order* ORDER, string a, int n)//똑같은 음식 추가 주문, 
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
			cout << a << " 주문이 완료되었습니다. 추가로 주문하시겠습니까?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder >> food_count;
				for (int i = 0; i < index; i++)
				{
					if (reorder == ORDER[i].foodname)
					{
						ORDER[i].count += food_count;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = side[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn == 'n')
				return;
		}
		else {
			cout << "찾으시는 음식이 없습니다.다시 주문하시겠습니까?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder >> food_count;
				if (side.find(reorder) != side.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " 주문이 완료되었습니다.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = side[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " 주문이 완료되었습니다.\n";
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
void Hamberger::drink_order(Order* ORDER, string a, int n)//똑같은 음식 추가 주문, 
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
			cout << a << " 주문이 완료되었습니다. 추가로 주문하시겠습니까?(y/n)";
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			else if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder >> food_count;
				for (int i = 0; i < index; i++)
				{
					if (reorder == ORDER[i].foodname)
					{
						ORDER[i].count += food_count;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
					else {
						ORDER[index].foodname = reorder;
						ORDER[index].price = drink[reorder];
						ORDER[index].count = food_count;
						index++;
						cout << reorder << " 주문이 완료되었습니다.\n";
						cout << "-----------------------------------------------------------------------------" << endl;;
						return;
					}
				}
			}
			else if (yorn == 'n')
				return;
		}
		else {
			cout << "찾으시는 음식이 없습니다.다시 주문하시겠습니까?(y/n)" << endl;
			cin >> yorn;
			if (yorn != 'y' && yorn != 'n')
			{
				return;
			}
			if (yorn == 'y')
			{
				cout << "주문할 음식과 수량을 입력해주세요->";
				cin >> reorder >> food_count;
				if (drink.find(reorder) != drink.end()) {
					for (int i = 0; i < index; i++)
					{
						if (reorder == ORDER[i].foodname)
						{
							ORDER[i].count += food_count;
							cout << reorder << " 주문이 완료되었습니다.\n";
							cout << "-----------------------------------------------------------------------------" << endl;;
							return;
						}
						else {
							ORDER[index].foodname = reorder;
							ORDER[index].price = drink[reorder];
							ORDER[index].count = food_count;
							index++;
							cout << reorder << " 주문이 완료되었습니다.\n";
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
