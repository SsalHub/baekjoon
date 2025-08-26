import sys
input = sys.stdin.readline

def getChangeBlocks(board, beginX, beginY):
    change_B, change_W = 0, 0
    # if starts with B
    for i in range(beginY, beginY + 8):
        for j in range(beginX, beginX + 8):
            if (i % 2 == 0 and j % 2 == 0) or (i % 2 == 1 and j % 2 == 1):
                # B
                if board[i][j] != 'B':
                    change_B += 1
                else:
                    change_W += 1
            else:
                if board[i][j] != 'W':
                    change_B += 1
                else:
                    change_W += 1
    return min(change_B, change_W)


N, M = map(int, input().strip().split())
board = [input().strip() for _ in range(N)]
change = 33
for i in range(N-8+1):
    for j in range(M-8+1):
        change = min(change, getChangeBlocks(board, j, i))
print(change)