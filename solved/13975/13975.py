import sys
import heapq
input = sys.stdin.readline

T = int(input().strip())
for _ in range(T):
    K = int(input().strip())
    chapter = list(map(int, input().strip().split()))
    heapq.heapify(chapter)
    sum = 0
    while 1 < len(chapter):
        a, b = heapq.heappop(chapter), heapq.heappop(chapter)
        sum += a + b
        heapq.heappush(chapter, a + b)
    print(sum)