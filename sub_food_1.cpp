#include "key.h"

using namespace std;

void list_sort(Order* orders);

void Hamberger::sub_food(Order* orders) 
{
	char wf; //햄버거 사이드 드링크를 결정하는 변수
	int i;
	char choice;
	string name;

	cout << "햄버거, 사이드, 드링크 중 삭제하실 항목을 결정하세요.(h: 햄버거, s: 사이드, d: 드링크) : ";
	cin >> wf;

	switch (wf)
	{
	case 'h': //햄버거를 삭제하려고 할때
		choice = '\0';
		cout << "삭제할 햄버거 이름:";
		cin >> name;
		if (food.find(name) != food.end()) //삭제하려고 하는 모든 음식 메뉴 항목이 존재하는지 확인
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name) //삭제하려고 하는 항목이 주문리스트에 존재하는지 확인
				{
					cout << name << " (을)를 주문항목에서 삭제하시겠습니까?\n(y 또는 n 입력)";

					break;
				}
			}
		}
		else
		{
			cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
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
				cout << "잘못된 입력값입니다. 다시입력하세요." << endl;
				continue;
			}
		}
		break;
	case 's': //사이드 메뉴를 삭제할 때
		choice = '\0';
		cout << "삭제할 사이드 이름:";
		cin >> name;
		if (side.find(name) != side.end())
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name)
				{
					cout << name << " (을)를 주문항목에서 삭제하시겠습니까?\n(y 또는 n 입력)";

					break;
				}
			}
		}
		else
		{
			cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
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
				cout << "잘못된 입력값입니다. 다시입력하세요." << endl;
				continue;
			}
		}
	case 'd': //드링크 메뉴를 삭제할 때
		i = 0;
		choice = '\0';
		cout << "삭제할 드링크 이름:";
		cin >> name;
		if (drink.find(name) != drink.end())
		{
			for (i = 0; orders[i].foodname != ""; i++)
			{
				if (orders[i].foodname == name)
				{
					cout << name << " (을)를 주문항목에서 삭제하시겠습니까?\n(y 또는 n 입력)";

					break;
				}
			}
		}
		else
		{
			cout << "잘못된 선택입니다. 다시 시도해주세요." << endl;
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
				cout << "잘못된 입력값입니다. 다시입력하세요." << endl;
				continue;
			}
		}
	default :
		cout << "잘못된 입력입니다. 다시입력하세요." << endl;
		break;
	}
}

void list_sort(Order* orders) //배열을 주문 순서대로 정렬해주는 함수
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