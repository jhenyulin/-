ans = list(map(int, input().strip())) 
n = int(input())


for i in range(n):
    guess = list(map(int, input().strip()))
    A=0
    for i in range(4):
        if ans[i] == guess[i]:
            A=A+1
    same = [k for k in ans if k in guess]
    print(A,"A",len(same)-A,"B",sep='')

