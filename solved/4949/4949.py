import sys
from collections import deque
input = sys.stdin.readline

while (True):
    s = input()[:-1]
    if len(s) < 2 and s == '.':
        break
    bracket = deque([])
    for c in s[:-1]:
        if c == ']':
            if not bracket or bracket.pop() != '[':
                bracket.append(c)
                break
        elif c == ')':
            if not bracket or bracket.pop() != '(':
                bracket.append(c)
                break
        elif c == '[' or c == '(':
            bracket.append(c)
    if not bracket:
        print('yes')
    else:
        print('no')
