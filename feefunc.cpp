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
	cout << "< 가계부 정리 프로그램 >" << endl;
	cout << "1. 회원등록 2. 로그인 \n" << endl;
}

void AddStud(Fee* studArr[])
{
	char name[10];
	int birth;
	cout << "회원 이름을 입력하세요 : ";
	cin >> name;
	cout << endl;
	cout << "회원 생년월일을 입력하세요(8자리) : ";
	cin >> birth;
	cout << endl;

	int tran;
	int food;
	int ex;
	for (d = 0; d < 7; d++)
	{
		cout << "< " << d+1 << "일 >" << endl;
		cout << "교통비 : ";
		cin >> tran;
		cout << "식비 : ";
		cin >> food;
		cout << "기타 : ";
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
	cout << "등록한 회원 이름을 입력하세요 : ";
	cin >> name;
	cout << endl;
	cout << "등록한 회원 생년월일을 입력하세요(8자리) : ";
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
				cout << "일치하는 회원 정보가 없습니다.\n" << endl;
			}
		}
		else
		{
			cout << "일치하는 회원 정보가 없습니다.\n" << endl;
		}
	}
}

void show_date(Fee* studArr[])
{
	cout << "< 날짜별 지출 내역 >" << endl;
	for (d = 0; d < 7; d++)
	{
			cout << "< " << d + 1 << "일 지출 내역 >" << endl;
			cout << "교통비 : " << studArr[d]->GetTranfee() << endl;
			cout << "식비 : " << studArr[d]->GetFoodfee() << endl;
			cout << "기타 : " << studArr[d]->GetExfee() << endl;
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
	cout << "< 7일 간 총 지출 금액>" << endl;
	cout << all << " 원\n" << endl;
}

void all_TranFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetTranfee();
	}
	cout << "< 7일 간 총 교통비 지출 금액 >" << endl;
	cout << all << " 원\n" << endl;
}

void all_FoodFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetFoodfee();
	}
	cout << "< 7일 간 총 식비 지출 금액 >" << endl;
	cout << all << " 원\n" << endl;
}

void all_ExFee(Fee* studArr[])
{
	int all = 0;
	for (d = 0; d < 7; d++)
	{
			all += studArr[d]->GetExfee();
	}
	cout << "< 7일 간 총 기타 지출 금액 >" << endl;
	cout << all << " 원\n" << endl;
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
	cout << "< 회원 세부 메뉴 >" << endl;
	cout << "1. 일주일 총 지출" << endl;
	cout << "2. 일주일 총 교통비" << endl;
	cout << "3. 일주일 총 식비" << endl;
	cout << "4. 일주일 총 기타비" << endl;
	cout << "5. 프로그램 종료" << endl;
}