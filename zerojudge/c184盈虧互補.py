def DS(n):
    return sum([sum({i,n//i}) for i in range(1,int(n**0.5)+1) if n%i==0])-n

def DS2(n):
    return sum([sum({i,n//i}) for i in range(1,int(n**0.5)+1) if n%i==0])-n-1

def findPerfect(k):
    return [i for i in range(1,k+1) if DS(i) == i]

def amicablePair(k): #求小於k的友好數對
    return [(i,DS(i)) for i in range(1,k+1) if i< DS(i) and DS(DS(i))==i]

def betrothedPair(k): #求小於k的婚約數對
    return [(i,DS2(i)) for i in range(1,k+1) if i< DS2(i) and DS2(DS2(i))==i]
    
print(amicablePair(100000))