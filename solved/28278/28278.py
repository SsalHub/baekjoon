import sys
from collections import deque
input = sys.stdin.readline

N = int(input().strip())
stack = deque()
for _ in range(N):
    cmd = list(map(int, input().strip().split()))
    if cmd[0] == 1:
        stack.append(cmd[1])
    elif cmd[0] == 2:
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif cmd[0] == 3:
        print(len(stack))
    elif cmd[0] == 4:
        print(0 if len(stack) else 1)
    elif cmd[0] == 5:
        if stack:
            print(stack[-1])
        else:
            print(-1)