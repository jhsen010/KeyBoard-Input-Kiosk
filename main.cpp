#include "key.h"


extern int index;

void first_view_menu()
{
	cout << "================================================================================" << endl;
	cout << "\t\t\t 1. �޴� �߰� �Ǵ� ����" << endl;
	cout << "\t\t\t 2. ��꼭 ����" << endl;
	cout << "\t\t\t 3. ����ϱ�" << endl;
	cout << "\t\t\t q,Q. �ֹ����" << endl;
	cout << "================================================================================" << endl;
}


void main() {
	Hamberger ham;

	char jumun;
	char st;
	string hamname;

	while (1){
		Order* user = new Order[SIZE];
		size_set(80, 10); // size_set �ܼ�â ������ ���� 
		system("cls"); // �ܼ�â Ŭ����
		goto_point(31, 3); // �ܼ�â Ŀ�� ��ġ ����
		cout << "�ֹ��Ͻðڽ��ϱ�?(y/n) : ";
		cin >> jumun;
		if (jumun == 'y'){
			size_set(80, 55);
			while (1){
				system("cls");
				first_view_menu(); // �ʱ�ȭ�� ���
				ham.showmenu();
				cout << "       �Է� : ";
				cin >> st;
				if (st == '1'){
					ham.select(user); // �޴����� �Լ�
					Sleep(1500); // �ܼ�â ������
				}
				else if (st == '2'){
					ham.select_showmenu(user, index); // ���ֹ�ǥ ��¹� �ѱݾ� ��� �Լ�
					Sleep(5000);
				}
				else if(st=='3') {
					
					ham.select_showmenu(user, index);
					if (ham.card_cash(user)) // ����, ī���� ���ù� �ܵ����
					{
						delete[] user;
						index = 0;
						Sleep(5000);
						break;
					}
				}
				else if (st == 'q'){
					cout << "�ֹ��� ����մϴ�." << endl;
					delete[] user;
					Sleep(1500);
					break;
				}
				else if (st == 'Q'){
					cout << "�ֹ��� ����մϴ�." << endl;
					delete[] user;
					Sleep(1500);
					break;
				}
				else
					cout << "�߸��� �Է��Դϴ�." << endl;
			}
		}
		else{
			system("cls");
			goto_point(32, 3);
			cout << "�����մϴ�." << endl << endl;
			return;
		}
	}
}
