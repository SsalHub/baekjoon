import sys
import bisect
input = sys.stdin.readline

def is_prime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    while not is_prime(N):
        N += 1
    print(N)