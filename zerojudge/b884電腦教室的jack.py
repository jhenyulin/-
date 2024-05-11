n = int(input())

while n > 0:
    x,y = map(int,input().split())
    yee = 100 - x - y
    if 0<yee and yee<=30:
        print("sad!")
    elif 30<yee and yee<=60:
        print("hmm~~")
    elif 60<yee and yee<100:
        print("Happyyummy")
    else:
        print("evil!!")
    n-=1
