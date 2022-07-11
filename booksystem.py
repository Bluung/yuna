# E-oN 7번째 과제
# 202112338 김유나

import bookDB

class Book:

    def menu(self): # 메뉴 선택
        menu = int(input("1. 도서 추가 2. 도서 검색 3. 도서 정보 수정 4. 도서 삭제 5. 현재 총 도서 목록 출력 6. 저장 7. 프로그램 나가기"))
        while(1):
            if menu == 1:
                myBook.add_book()
                myBook.menu()
            elif menu == 2:
                myBook.search_book()
                myBook.menu()
            elif menu == 3:
                myBook.modify_book()
                myBook.menu()
            elif menu == 4:
                myBook.delete_book()
                myBook.menu()
            elif menu == 5:
                myBook.show_book()
                myBook.menu()
            elif menu == 6:
                myBook.save_book()
                myBook.menu()
            elif menu == 7: # 자동 저장
                myBook.save_book()
                break
            else:
                print("번호를 다시 입력하세요.")
                myBook.menu()
                
    def add_book(self): # 도서 등록
        print(bookDB.lines)
        print("등록할 도서의 정보를 입력하세요.")
        name = input("도서명 : ")
        author = input("저자 : ")
        year = (input("출판연도 : "))
        publisher = input("출판사명 : ")
        genre = input("장르 : ")
        list_book = [name, author, year, publisher, genre, '\n']
        str_book = " ".join(list_book) # 리스트를 문자열로 결합
        bookDB.lines.append(str_book) # bookDB.lines 리스트에 요소 추가
        print("등록되었습니다.")
        myBook.save_book()

    def search_book(self): # 도서 검색
        a = []
        for i in range(0, len(bookDB.lines)):
            book = bookDB.lines[i].split() # 공백을 기준으로 [도서명, 저자, 출판연도, 출판사명, 장르] 리스트 만들기
            a.append(book) # 2차원 리스트
            
        print("검색할 도서의 카테고리를 고르세요.")
        category = int(input("1. 도서명 2. 저자 3. 출판연도 4. 출판사명 5. 장르"))
        if category == 1:
                book_n = input("도서명 : ")
                for i in range(0, len(bookDB.lines)):
                    if book_n in a[i]:
                        print(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4])
        elif category == 2:
                book_a = input("저자 : ")
                for i in range(0, len(bookDB.lines)):
                    if book_a in a[i]:
                        print(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4])
        elif category == 3:
                book_y = (input("출판연도 : "))
                for i in range(0, len(bookDB.lines)):
                    if book_y in a[i]:
                        print(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4])
        elif category == 4:
                book_p = input("출판사명 : ")
                for i in range(0, len(bookDB.lines)):
                    if book_p in a[i]:
                        print(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4])
        elif category == 5:
                book_g = input("장르 : ")
                for i in range(0, len(bookDB.lines)):
                    if book_g in a[i]:
                        print(a[i][0], a[i][1], a[i][2], a[i][3], a[i][4])
        else:
                print("번호를 다시 입력하세요.")

    def modify_book(self): # 도서 수정
        myBook.show_book()
        line_num = int(input("수정할 도서의 줄 번호를 입력하세요. : "))
        modify_a = input("수정할 도서명, 저자, 출판연도, 출판사명, 장르를 입력하세요.(공백으로 구분) : ")
        bookDB.lines[line_num - 1] = modify_a + '\n'
        myBook.save_book()
        
    def delete_book(self): # 도서 삭제
        myBook.show_book()
        line_num = int(input("삭제할 도서의 줄 번호를 입력하세요. : "))
        for i in range(len(bookDB.lines)):
            if line_num == i:
                bookDB.lines.pop(i-1) # (i-1)번째 요소 삭제
        print("삭제되었습니다.")
        myBook.save_book()
        
    def show_book(self): # 현재 도서 목록 출력
        print("현재 도서 목록입니다.")
        with open("C:\python\input.txt", "r") as file: # 도서목록 불러오기
            lines = file.readlines()
            for line in lines:
                line = line.strip()
                print(line)
                
    def save_book(self): # 입력파일에 저장
        with open("C:\python\input.txt", "w") as file:
            for b in bookDB.lines:
                file.write(b)
        print("저장되었습니다.")

myBook = Book() # 클래스 변수

while(1):
    myBook.menu()
