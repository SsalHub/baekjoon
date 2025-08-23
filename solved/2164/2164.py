import sys
from collections import deque

input = sys.stdin.readline
N = int(input())
cards = deque([i + 1 for i in range(N)])
while 1 < len(cards):
    cards.popleft()
    cards.append(cards.popleft())
print(cards.popleft())