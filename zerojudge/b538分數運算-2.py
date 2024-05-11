import math

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def simplify_fraction(numerator, denominator):
    common_divisor = gcd(numerator, denominator)
    return numerator // common_divisor, denominator // common_divisor

while True:
    try:
        a, b, c, d, operator = map(str, input().split())
        a, b, c, d = int(a), int(b), int(c), int(d)
        
        if operator == '+':
            numerator = a * d + b * c
            denominator = b * d
        elif operator == '-':
            numerator = a * d - b * c
            denominator = b * d
        elif operator == '*':
            numerator = a * c
            denominator = b * d
        elif operator == '/':
            numerator = a * d
            denominator = b * c
        
        # Simplify the fraction
        simplified_numerator, simplified_denominator = simplify_fraction(numerator, denominator)
        
        if simplified_denominator == 1:
            print(simplified_numerator)
        else:
            print(f"{simplified_numerator}/{simplified_denominator}")
            
    except EOFError:
        break
