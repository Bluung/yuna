# E-oN 5주차 과제

arr1 = list(map(int, input("수를 여러 개 입력하세요 : ").split())) # 배열 arr1에 정수 요소 입력

print(arr1)

commands = [ 0, 0, 0 ]
for x in range(3):
    commands[x] = list(map(int, input("i, j, k번째 수를 입력 : ").split())) # 2차원 배열 commands 요소 입력

print(commands)

def solution():
    for y in range(3):
        arr2 = arr1[(commands[y][0])-1 : commands[y][1]] # i번째부터 j번째까지 슬라이싱
        arr2.sort() # 요소 오름차순 정렬 후 arr2에 저장
        print("정렬된 배열 : ", arr2)
        print(arr2[commands[y][2]-1]) # k번째 수 출력
        
solution()
