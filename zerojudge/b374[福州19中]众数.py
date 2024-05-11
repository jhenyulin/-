from collections import Counter

while True:
  try:
    n = int(input())                          # 有幾個數字
    num = [int(i) for i in input().split()]   # 將輸入的文字轉換成數字串列
    a = Counter(num)      # 計算每個數字出現的次數，轉成字典的型態
    b, c = [], []         # 建立兩個空串列，記錄數字以及排序使用
    for key in a:
      b.append(a[key])    # 將所有的次數存入串列中
    m = max(b)            # 取出數字裡的最大值 ( 眾數的次數 )
    for key in a:
      if a[key] == m:     # 如果該數字的次數等於最大值
        c.append(key)     # 將該數字存入 c 串列
    c.sort()              # 排序
    for i in c:
      print(f'{i} {m}')   # 印出結果
  except:
    break