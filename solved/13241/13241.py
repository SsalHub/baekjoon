import sys
input = sys.stdin.readline

def gcd(a, b):
    while b != 0:
        t = b
        b = a % b
        a = t
    return a

A, B = map(int, input().strip().split())
print(A * B // gcd(A, B))