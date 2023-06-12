#include "key.h"


extern int index;

void first_view_menu()
{
	cout << "================================================================================" << endl;
	cout << "\t\t\t 1. 메뉴 추가 또는 삭제" << endl;
	cout << "\t\t\t 2. 계산서 보기" << endl;
	cout << "\t\t\t 3. 계산하기" << endl;
	cout << "\t\t\t q,Q. 주문취소" << endl;
	cout << "================================================================================" << endl;
}


void main() {
	Hamberger ham;

	char jumun;
	char st;
	string hamname;

	while (1){
		Order* user = new Order[SIZE];
		size_set(80, 10); // size_set 콘솔창 사이즈 제어 
		system("cls"); // 콘솔창 클리어
		goto_point(31, 3); // 콘솔창 커서 위치 변경
		cout << "주문하시겠습니까?(y/n) : ";
		cin >> jumun;
		if (jumun == 'y'){
			size_set(80, 55);
			while (1){
				system("cls");
				first_view_menu(); // 초기화면 출력
				ham.showmenu();
				cout << "       입력 : ";
				cin >> st;
				if (st == '1'){
					ham.select(user); // 메뉴선택 함수
					Sleep(1500); // 콘솔창 딜레이
				}
				else if (st == '2'){
					ham.select_showmenu(user, index); // 총주문표 출력및 총금액 계산 함수
					Sleep(5000);
				}
				else if(st=='3') {
					
					ham.select_showmenu(user, index);
					if (ham.card_cash(user)) // 현금, 카드계산 선택및 잔돈계산
					{
						delete[] user;
						index = 0;
						Sleep(5000);
						break;
					}
				}
				else if (st == 'q'){
					cout << "주문을 취소합니다." << endl;
					delete[] user;
					Sleep(1500);
					break;
				}
				else if (st == 'Q'){
					cout << "주문을 취소합니다." << endl;
					delete[] user;
					Sleep(1500);
					break;
				}
				else
					cout << "잘못된 입력입니다." << endl;
			}
		}
		else{
			system("cls");
			goto_point(32, 3);
			cout << "종료합니다." << endl << endl;
			return;
		}
	}
}
