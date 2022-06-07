#pragma once

class Fee
{
private:
	char* StudName; // 회원 이름
	int StudBirth; // 회원 생년월일
	int Tranfee;
	int Foodfee;
	int Exfee;

public:
	Fee();
	Fee(char* name, int birth, int tran, int food, int ex); // 생성자
	Fee(const Fee& ref); // 복사 생성자
	void ShowStudInfor() const; // 회원정보 출력
	const char* GetStudName() const;
	int GetStudBirth() const;
	int GetTranfee() const;
	int GetFoodfee() const;
	int GetExfee() const;
	~Fee(); // 소멸자
};