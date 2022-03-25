# E-oN 4주차 과제
# 오름차순 정렬

values = list(input("수를 여러 개 입력하세요 : ").split()) # 정수 입력
values = [int(value) for value in values] # 문자열로 입력된 변수를 정수형으로 변경

x = len(values) # 리스트 요소의 개수 대입

for i in range(0, x): # i를 0부터 x-1까지, k를 i부터 x-1까지 반복하여 모든 요소 대소 비교
    for k in range(i, x):
        if values[i] > values[k]:
            values[i], values[k] = values[k], values[i]
            
print(values)
