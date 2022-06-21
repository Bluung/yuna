# E-oN 마지막 과제
# 202112338 김유나

import TrainListDB
import mytrainDB

class Train:

    def Menu(self):
        menu = int(input("1. 빠른시간 기차 검색 및 예매 2. 전체 기차 리스트 출력 3. 나의 예매 현황 출력 및 예매 취소 4. 프로그램 종료\n"))
        while(1):
            if menu == 1:
                a = input("메뉴로 돌아가기 y/n : ")
                if a == 'y':
                    t.Menu()
                elif a == 'n':
                    t.search_train()
                t.Menu()
            elif menu == 2:
                a = input("메뉴로 돌아가기 y/n : ")
                if a == 'y':
                    y.Menu()
                elif a == 'n':
                    t.show_train()
                t.Menu()
            elif menu == 3:
                a = input("메뉴로 돌아가기 y/n : ")
                if a == 'y':
                    t.Menu()
                elif a == 'n':
                    t.my_train()
                t.Menu()
            elif menu == 4:
                t.save_train()
                break

    def search_train(self):
        print("예매하고 싶은 기차 시간대와 출발/도착역, 종류를 입력하세요.\n")
        h = int(input("시를 입력하세요. (ex. 06, 12, 18) : "))
        m = int(input("분을 입력하세요. (ex. 00, 05, 30) : "))
        start = input("출발역을 입력하세요. (ex. 서울, 영등포, 부산) : ")
        arrive = input("도착역을 입력하세요. (ex. 서울, 부산, 광주) : ")
        train = input("기차 종류를 입력하세요. (ex. KTX, 새마을호) : ")
        a_arr = ["%d:%d"% (h, m), start, "->", arrive, train] # 원하는 기차 정보 리스트 생성
        a_time = a_arr[0].split(':') # [시, 분]
        a_time = list(map(int, a_time)) # 정수형으로
            
        print(' '.join(a_arr))
        print("\n입력하신 시간대와 가장 가까운 시간의 기차 리스트입니다.\n")

        t_arr = []
        t_time = []
        for i in range(1, len(TrainListDB.lines)): # 1~21
            t_info = TrainListDB.lines[i].split() # [시간, 출발, 도착, 종류, 잔여좌석수]
            t_arr.append(t_info) # [[시간, 출발, 도착, 종류, 잔여좌석수]] 2차원 배열 
            arr = t_arr[i-1][0].split(':')
            t_time.append(arr) # [[시, 분], [시, 분]] 2차원 배열

        for i in range(0, len(TrainListDB.lines)-1): # 0~20
            t_time[i] = list(map(int, t_time[i])) # 정수형으로

        r_arr = []
        for i in range(0, len(TrainListDB.lines)-1): # 0~20
            if abs(a_time[0] - t_time[i][0]) <= 1: # 앞뒤로 1시간 30분 내에 있는 시간대
                if abs(a_time[1] - t_time[i][1]) <= 30:
                    if start in t_arr[i]:
                        if arrive in t_arr[i]:
                            if train in t_arr[i]:
                                r_arr.append(t_arr[i])
                                print(' '.join(t_arr[i]))

        num = int(input("\n예매할 기차의 줄 번호를 입력하세요. (1부터) : "))
        a1 = r_arr[num-1]
        a2 = r_arr[num-1]
        seat_num = int(a1[5])
        if seat_num == 0:
            print("해당 기차는 매진입니다.")
        elif seat_num != 0:
            seat_num -= 1
            a1[5] = str(seat_num)
            print("\n예매 완료\n")
            print(' '.join(a1) + '\n')
            mytrainDB.lines.append(' '.join(a1)+'\n') # 예매 현황 리스트 요소 추가
            t.save_mytrain()

            for i in range(1, len(TrainListDB.lines)):
                db = TrainListDB.lines[i].split()
                for j in range(0, 6):
                    if db[j] == a2[j]:
                        db[5] = str(int(db[5])-1)
                        t.save_train()

    def show_train(self):
        with open("C:\python\TrainList.txt", "r") as f:
            lines = f.readlines()
            for line in lines:
                line = line.strip() 
                print(line)

    def save_train(self):
        with open("C:\python\TrainList.txt", "w") as f:
            for line in TrainListDB.lines:
                f.write(line)

    def save_mytrain(self):
        with open("C:\python\mytrain.txt", "w") as file:
            for t in mytrainDB.lines:
                file.write(t)

    def my_train(self):
        print("\n<나의 예매 현황>\n")
        with open("C:\python\mytrain.txt", "r") as file:
            lines = file.readlines()
            for line in lines:
                line = line.strip()
                print(line)

        a = input("예매 취소 y/n : ")
        if a == 'y':
            b = int(input("취소할 예매표의 줄 번호를 입력하세요. (1부터) : "))
            for i in range(0, len(mytrainDB.lines)+1):
                if b == i:
                    mytrainDB.lines.pop(b-1)
                    t.save_mytrain()
                    print("예매 취소 완료")
        elif a == 'n':
            t.Menu()
        
t = Train()

t.Menu()
