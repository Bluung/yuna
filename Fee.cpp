#define _CRT_SECURE_NO_WARNINGS
#include "Fee.h"
#include <iostream>
#include <cstring>
using namespace std;

Fee::Fee()
{
}

Fee::Fee(char* name, int birth, int tran, int food, int ex)
	: StudBirth(birth), Tranfee(tran), Foodfee(food), Exfee(ex)
{
	int len = strlen(name) + 1;
	StudName = new char[len];
	strcpy_s(StudName, len, name);
}

Fee::Fee(const Fee& ref)
	: StudBirth(ref.StudBirth), Tranfee(ref.Tranfee), Foodfee(ref.Foodfee), Exfee(ref.Exfee)
{
	int len = strlen(ref.StudName) + 1;
	StudName = new char[len];
	strcpy_s(StudName, len, ref.StudName);
}

void Fee::ShowStudInfor() const
{
	cout << "회원 이름 : " << StudName << endl;
	cout << "회원 생년월일 : " << StudBirth << endl;
}

const char* Fee::GetStudName() const
{
	return StudName;
}

int Fee::GetStudBirth() const
{
	return StudBirth;
}

int Fee::GetTranfee() const
{
	return Tranfee;
}

int Fee::GetFoodfee() const
{
	return Foodfee;
}

int Fee::GetExfee() const
{
	return Exfee;
}

Fee::~Fee()
{
	delete[] StudName;
}