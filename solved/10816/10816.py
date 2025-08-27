import sys
input = sys.stdin.readline

N = int(input().strip())
cards = {}
nums = list(map(int, input().strip().split()))
for n in nums:
    if cards.get(n):
        cards[n] += 1
    else:
        cards[n] = 1
M = int(input().strip())
answer = []
nums = list(map(int, input().strip().split()))
for n in nums:
    if cards.get(n):
        answer.append(cards[n])
    else:
        answer.append(0)
print(*answer)