t = int(input())   # 有幾筆測試資料
for p in range(t):
  n, m = map(int, input().split())    # 串列的大小
  a, b = [], []        # 定義 a 和 b 兩個空矩陣
  for q in range(n):
    arr = [int(i) for i in input().split()]   # 將每筆輸入的數字拆成串列
    a.append(arr)   # 將資料填入 a              # 由前而後填入串列
    b.insert(0,arr[::-1])   # 將資料填入 b      # 由後而前填入反轉的串列

  if b == a:
    print('go forward')    # 如果 b 等於 a，輸出 go forward
  else:
    print('keep defending')