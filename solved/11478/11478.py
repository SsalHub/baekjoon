import sys
input = sys.stdin.readline

S = input().strip()
subs = set()
for i in range(len(S)):
    for j in range(i+1, len(S) + 1):
        subs.add(S[i:j])
print(len(subs))