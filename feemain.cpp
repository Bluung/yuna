#include "Fee.h"
#include "feefunc.h"
#include <iostream>

using namespace std;

Fee* studArr[10];

void menu2()
{
	ShowMenu2();
	int num2; // �޴�2 ����
	cout << "�޴��� �����ϼ���. : ";
	cin >> num2;
	cout << endl;
	switch (num2)
	{
	case 1:
		all_fee(studArr);
		menu2();
		break;
	case 2:
		all_TranFee(studArr);
		menu2();
		break;
	case 3:
		all_FoodFee(studArr);
		menu2();
		break;
	case 4:
		all_ExFee(studArr);
		menu2();
		break;
	case 5:
		end_fee(studArr);
		break;
	default:
		cout << "�߸��� ��ȣ�Դϴ�." << endl;
	}
}

void menu1()
{
	int num1; // �޴�1 ����

	while (1)
	{
		ShowMenu1();
		cout << "�޴��� �����ϼ���. : ";
		cin >> num1;
		cout << endl;
		switch (num1)
		{
		case 1:
			AddStud(studArr);
			break;
		case 2:
			SearchStud(studArr);
			menu2();
			break;
		default:
			cout << "�߸��� ��ȣ�Դϴ�." << endl;
		}
	}
}

int main(void)
{
	menu1();

	return 0;
}