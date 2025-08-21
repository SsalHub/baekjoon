import sys
from collections import deque

def isValidPS(s):
    stack = deque([])
    s = s[:-1]  # remove '\n'
    for ch in s:
        if ch == '(':
            stack.append(ch)
        elif stack:
            stack.pop()
        else:
            return False
    return False if stack else True

input = sys.stdin.readline
T = int(input())
s = []
for _ in range(T):
    s.append(input())
for ps in s:
    if isValidPS(ps):
        print("YES")
    else:
        print("NO")