#pragma once

class Fee;

void ShowMenu1(void); // �޴� 1
void AddStud(Fee* studArr[]); // ȸ�� ���, ���� ���� �Է�(1��~7�� �ѹ��� �Է�)
void SearchStud(Fee* studArr[]); // ȸ�� �˻�

void ShowMenu2(void); // �޴� 2 (ȸ�� ������ ����)
void show_date(Fee* studArr[]); // ��¥�� ���� ���� ��� (1~7�� ���)
void all_fee(Fee* studArr[]); // �����ϵ��� �� �� �ݾ� ���
void all_TranFee(Fee* studArr[]); // �����ϵ��� �� �� �����
void all_FoodFee(Fee* studArr[]); // �����ϵ��� �� �� �ĺ�
void all_ExFee(Fee* studArr[]); // �����ϵ��� �� �� ��Ÿ��
void end_fee(Fee* studArr[]); // �ʱ�ȭ �� ���α׷� ����