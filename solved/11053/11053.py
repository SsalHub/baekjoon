import sys
input = sys.stdin.readline
N = int(input().strip())
nums = list(map(int, input().strip().split()))
sequence = [1] * (N + 1)
for i in range(2, N+1):
    for j in range(i-1, 0, -1):
        if nums[j - 1] < nums[i - 1]:
            sequence[i] = max(sequence[i], sequence[j] + 1)
print(max(sequence))