import sys
from collections import deque
input = sys.stdin.readline

K = int(input().strip())
book = deque()
for _ in range(K):
    N = int(input().strip())
    if N == 0 and book:
        book.pop()
    else:
        book.append(N)
print(sum(book))