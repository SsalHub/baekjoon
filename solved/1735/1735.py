import sys
input = sys.stdin.readline

def getgcd(a, b):
    while (b != 0):
        t = b
        b = a % b
        a = t
    return a

A, B = map(int, input().strip().split())
C, D = map(int, input().strip().split())
denominator = B * D
numerator = A * D + C * B
gcd = getgcd(numerator, denominator)
print(numerator // gcd, denominator // gcd)