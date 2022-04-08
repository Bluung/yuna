# E-oN 6주차 과제

import math

n = int(input("피자의 조각 수를 입력하세요 : "))

if n % 2 == 0: # 피자의 조각 수가 짝수일 때
    k = 1 + (n-1) + 1 # 1로만 분할했을 때, 2가 하나일 때, 2로만 분할했을 때
    for i in range(2, (n//2)): # 2가 2개 이상일 때 조합을 이용
        k = k + (math.factorial(n-i)//(math.factorial(i) * math.factorial(n-i-i)))

    print("1조각, 2조각씩 나누는 방법은 ", k, "가지 입니다.")

elif n % 2 == 1: # 피자의 조각 수가 홀수일 때
    k = 1 + (n-1) # 1로만 분할했을 때, 2가 하나일 때
    for i in range(2, (n//2+1)): # 2가 2개 이상일 때 조합을 이용
        k = k + (math.factorial(n-i)//(math.factorial(i) * math.factorial(n-i-i)))

    print("1조각, 2조각씩 나누는 방법은 ", k, "가지 입니다.")
