#pragma once

class Fee
{
private:
	char* StudName; // ȸ�� �̸�
	int StudBirth; // ȸ�� �������
	int Tranfee;
	int Foodfee;
	int Exfee;

public:
	Fee();
	Fee(char* name, int birth, int tran, int food, int ex); // ������
	Fee(const Fee& ref); // ���� ������
	void ShowStudInfor() const; // ȸ������ ���
	const char* GetStudName() const;
	int GetStudBirth() const;
	int GetTranfee() const;
	int GetFoodfee() const;
	int GetExfee() const;
	~Fee(); // �Ҹ���
};