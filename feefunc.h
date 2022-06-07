#pragma once

class Fee;

void ShowMenu1(void); // 메뉴 1
void AddStud(Fee* studArr[]); // 회원 등록, 지출 내역 입력(1일~7일 한번에 입력)
void SearchStud(Fee* studArr[]); // 회원 검색

void ShowMenu2(void); // 메뉴 2 (회원 페이지 느낌)
void show_date(Fee* studArr[]); // 날짜별 지출 내역 출력 (1~7일 모두)
void all_fee(Fee* studArr[]); // 일주일동안 쓴 총 금액 출력
void all_TranFee(Fee* studArr[]); // 일주일동안 쓴 총 교통비
void all_FoodFee(Fee* studArr[]); // 일주일동안 쓴 총 식비
void all_ExFee(Fee* studArr[]); // 일주일동안 쓴 총 기타비
void end_fee(Fee* studArr[]); // 초기화 후 프로그램 종료