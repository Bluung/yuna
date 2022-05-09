# 도서 DB

with open("C:\python\input.txt", "r") as file: # 초기 도서목록 불러오기
            lines = file.readlines() # 각 줄이 리스트 요소
            for line in lines:
                line = line.strip() # \n 제거
                print(line)
