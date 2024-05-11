x = int(input())
price = list(map(int, input().split(' ')))  # 將 map 物件轉換成列表

result = 0

for i in range(x):
    result += price[i] * (i+1)

print(result)
