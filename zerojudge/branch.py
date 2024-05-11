def is_triangle(a, b, c):
    return a + b > c and a + c > b and b + c > a

x = 0
for i in range(5):
    a, b, c = map(int, input().split())
    if is_triangle(a, b, c):
        x += 1

print(x)
