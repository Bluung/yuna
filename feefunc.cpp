#define _CRT_SECURE_NO_WARNINGS
#include "Fee.h"
#include "feefunc.h"
#include <iostream>
#include <cstring>

using namespace std;

Fee f1;
int arrFee[7][3];
int d;

void ShowMenu1()
{
	cout << "< ����� ���� ���α׷� >" << endl;
	cout << "1. ȸ����� 2. �α��� \n" << endl;
}

void AddStud(Fee* studArr[])
{
	char name[10];
	int birth;
	cout << "ȸ�� �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << endl;
	cout << "ȸ�� ��������� �Է��ϼ���(8�ڸ�) : ";
	cin >> birth;
	cout << endl;

	int tran;
	int food;
	int ex;
	for (d = 0; d < 7; d++)
	{
		cout << "< " << d+1 << "�� >" << endl;
		cout << "����� : ";
		cin >> tran;
		cout << "�ĺ� : ";
		cin >> food;
		cout << "��Ÿ : ";
		cin >> ex;
		cout << endl;

		arrFee[d][0] = tran;
		arrFee[d][1] = food;
		arrFee[d][2] = ex;

		studArr[d] = new Fee(name, birth, tran, food, ex);
	}
}

void SearchStud(Fee* studArr[])
{
	char name[10];
	int birth;
	int i;
	cout << "����� ȸ�� �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << endl;
	cout << "����� ȸ�� ��������� �Է��ϼ���(8�ڸ�) : ";
	cin >> birth;
	cout << endl;

	for (d = 0; d < 7; d++)
	{
		if (strcmp(studArr[d]->GetStudName(), name) == 0)
		{
			if (studArr[d]->GetStudBirth() == birth)
			{
				studArr[d]->ShowStudInfor();
				show_date(studArr);
			}
			else
			{
				cout << "��ġ�ϴ� ȸ�� ������ �����ϴ�.\n" << endl;
			}
		}
		else
		{
			cout << "��ġ�ϴ� ȸ�� ������ �����ϴ�.\n" << endl;
		}
	}
}

void show_date(Fee* studArr[])
{
	cout << "< ��¥�� ���� ���� >" << endl;
	for (d = 0; d < 7; d++)
	{
			cout << "< " << d + 1 << "�� ���� ���� >" << endl;
			cout << "����� : " << studArr[d]->GetTranfee() << endl;
			cout << "�ĺ� : " << studArr[d]->GetFoodfee() << endl;
			cout << "��Ÿ : " << studArr[d]->GetExfee() << endl;
			cout << "\n" << endl;
	}
}

void all_fee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetTranfee() + studArr[d]->GetFoodfee() + studArr[d]->GetExfee();
	}
	cout << "< 7�� �� �� ���� �ݾ�>" << endl;
	cout << all << " ��\n" << endl;
}

void all_TranFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetTranfee();
	}
	cout << "< 7�� �� �� ����� ���� �ݾ� >" << endl;
	cout << all << " ��\n" << endl;
}

void all_FoodFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetFoodfee();
	}
	cout << "< 7�� �� �� �ĺ� ���� �ݾ� >" << endl;
	cout << all << " ��\n" << endl;
}

void all_ExFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetExfee();
	}
	cout << "< 7�� �� �� ��Ÿ ���� �ݾ� >" << endl;
	cout << all << " ��\n" << endl;
}

void end_fee(Fee* studArr[])
{
	for (int i = 0; i < 7; i++)
	{
		delete studArr[i];
	}
}

void ShowMenu2(void)
{
	cout << "< ȸ�� ���� �޴� >" << endl;
	cout << "1. ������ �� ����" << endl;
	cout << "2. ������ �� �����" << endl;
	cout << "3. ������ �� �ĺ�" << endl;
	cout << "4. ������ �� ��Ÿ��" << endl;
	cout << "5. ���α׷� ����" << endl;
}