import math

def euler_phi(n):
    return sum(math.gcd(n, i) == 1 for i in range(1, n+1))

while 1:
    try:
        x=int(input())
        print(euler_phi(x),end='\n')
    except EOFError:
        break