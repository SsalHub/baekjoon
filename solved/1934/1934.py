import sys
input = sys.stdin.readline

def gcd(a, b):
    while b != 0:
        t = b
        b = a % b
        a = t
    return a

def lcm(a, b):
    return (a * b) // gcd(a, b)

T = int(input().strip())
for _ in range(T):
    A, B = map(int, input().strip().split())
    print(lcm(A, B))