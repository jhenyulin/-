def classify_triangle(a, b, c):
    if a + b <= c:
        return "No"
    elif a ** 2 + b ** 2 < c ** 2:
        return "Obtuse"
    elif a ** 2 + b ** 2 == c ** 2:
        return "Right"
    elif a ** 2 + b ** 2 > c ** 2:
        return "Acute"

def sort_sides(a, b, c):
    sides = [a, b, c]
    sides.sort()
    return sides

while True:
    try:
        a, b, c = map(int, input().split())
        sides = sort_sides(a, b, c)
        classification = classify_triangle(sides[0], sides[1], sides[2])
        print(" ".join(map(str, sides)))
        print(classification)
    except EOFError:
        break
