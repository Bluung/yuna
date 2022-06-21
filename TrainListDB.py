# TrainList DB

with open("C:\python\TrainList.txt", "r") as f:
    lines = f.readlines()
    for line in lines:
        line = line.strip() # \n 제거
        print(line)
