n = int(input())

for i in range(n):
    H1, M1, H2, M2, M3 = map(int, input().split())
    if(((H2*60+M2) - (H1*60+M1)) >= M3):
        print("Yes")
    else:
        print("No")