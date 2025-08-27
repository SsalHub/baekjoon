import sys
input = sys.stdin.readline

def isEndNumber(n):
    count = 0
    while 0 < n:
        if n % 10 == 6:
            count += 1
        else:
            count = 0
        if 3 <= count:
            break
        n //= 10
    return False if count < 3 else True

N = int(input().strip())
i = 665
while 0 < N:
    i += 1
    if isEndNumber(i):
        N -= 1
print(i)