#include "key.h"
using namespace std;

Hamberger::Hamberger() { // 전체메뉴 데이터
	total = 0, pay = 0, change = 0;

	// 햄버거메뉴
	food["트리플콰트로머쉬룸스테이크버거세트"] = 9000;
	food["트러플콰트로머쉬룸와퍼세트"] = 8000;
	food["통새우와퍼주니어세트"] = 6600;
	food["통새우스테이크버거세트"] = 9700;
	food["통새우와퍼세트"] = 8600;
	food["와퍼"] = 7700;
	food["불고기와퍼"] = 7700;
	food["콰트로치즈와퍼"] = 8500;
	food["치즈와퍼"] = 8300;
	food["와퍼주니어"] = 6000;
	food["불고기와퍼주니어"] = 6000;
	food["콰트로치즈와퍼주니어"] = 6600;
	food["치즈와퍼주니어"] = 6300;

	// 사이드 메뉴
	side["치즈스틱"] = 1500;
	side["코코넛쉬림프 3조각"] = 2800;
	side["코코넛쉬림프 6조각"] = 5600;
	side["코코넛쉬림프 9조각"] = 8300;
	side["텐더킹 2조각"] = 2000;
	side["텐더킹 4조각"] = 3900;
	side["텐더킹 6조각"] = 5700;
	side["치즈프라이"] = 2500;
	side["프렌치프라이"] = 1600;
	side["어니언링"] = 2000;
	side["너겟킹 4조각"] = 2000;
	side["너겟킹 6조각"] = 3000;
	side["너겟킹 10조각"] = 5000;
	side["바닐라선데"] = 600;
	side["딸기선데"] = 1500;
	side["초코선데"] = 1500;
	side["콘샐러드"] = 1600;

	// 음료
	drink["아메리카노"] = 1500;
	drink["카페라떼"] = 2500;
	drink["코카콜라"] = 1700;
	drink["코카콜라(제로)"] = 1500;
	drink["아메리카노"] = 1500;
	drink["아메리카노"] = 1500;
	drink["아메리카노"] = 1500;
}

void Hamberger::showmenu() { // 전체 메뉴 출력
	// 햄버거의 모든 데이터 출력
	for (auto iter = food.begin(); iter != food.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;

	// 사이드의 모든 데이터 출력
	for (auto iter = side.begin(); iter != side.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;

	// 음료의 모든 데이터 출력
	for (auto iter = drink.begin(); iter != drink.end(); iter++)
	{
		cout << "* " << iter->first << ": " << iter->second << endl;
	}
	cout << "-----------------------------------------------------------------------------" << endl;;


}

void Hamberger::set_total(int t) { // 총금액 저장
	total = t;
}

int Hamberger::get_total() { // 총금액 값 반환
	return total;
}

void Hamberger::set_change(int t, int c) { // 잔돈 저장
	change = c - t;
}

int Hamberger::get_change() { // 잔돈 반환
	return change;
}

void Hamberger::select_showmenu(Order* user, int index) {
	int total = 0;

	// 총 주문표 출력
	cout << "-------총 주문표-------" << endl;
	for (int i = 0; i < index; i++) {
		cout << "메뉴: " << user[i].foodname << ", 가격: " << user[i].price <<
			", 갯수: " << user[i].count << "개" << endl;
	}

	//총금액 계산
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

	// 총금액 출력
	cout << "총 금액: " << get_total() << endl;
}

bool Hamberger::card_cash(Order* user) {


	char choice, card;
	int cash;
	string name;
	cout << "계산하시겠습니까? 또는 메뉴 제거 또는 추가하시겠습니까?" << endl;
	cout << "계산 y, 메뉴 추가 및 제거==n 입력: ";
	cin >> choice;

	
	switch (choice) {
	case 'y': // 지불방법 선택
		cout << "카드==c, 현금==s 입력: ";
		cin >> card;
		switch (card) {
		case 'c':
			cout << "카드를 선택하였습니다." << endl;
			cout << "결제완료" << endl;
			cout << "감사합니다 안녕히가세요~";
			break;
		case 's':
			cout << "현금를 선택하였습니다.";
			cin >> cash;
			set_change(get_total(), cash);
			cout << "잔돈: " << get_change() << endl;
			cout << "결제완료" << endl;
			cout << "감사합니다 안녕히가세요~";
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
		
	//메뉴 추가및 제거 선택
		cout << "추가및 제거선택(추가는 a 제거는 s):";
		cin >> choice1;
		switch (choice1) {
		case 'a':
			cout << "햄버거: h, 사이드: s, 음료: d   "; // 햄버거, 사이드, 음료중 선택
			cin >> choice2;
			switch (choice2) {
			case 'h': // 햄버거 추가
				cout << "추가할 햄버거 이름 : ";
				cin >> name;
				cout << "추가할 수량: ";
				cin >> n;
				hambergur_order(user, name, n);
				break;
			case 's': // 사이드 추가
				cout << "추가할 사이드 이름: ";
				cin >> name;
				cout << "추가할 수량: ";
				cin >> n;
				side_order(user, name, n);
				break;
			case 'd': // 음료 추가
				cout << "추가할 음료 이름: ";
				cin >> name;
				cout << "추가할 수량: ";
				cin >> n;
				drink_order(user, name, n);
				break;
			}
			break;
		case 's': // 메뉴 삭제
			sub_food(user);
			}
		
}
