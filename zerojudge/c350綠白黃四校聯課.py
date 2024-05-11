def judge(N, K, W):
    if K > N:
        return N
    else:
        return int(W * (N // float(K)) + N)  # 使用浮點數除法

N, K, W = map(int, input().split())
p=judge(N, K, W)
if p>K:
    print(judge(N, K, W))