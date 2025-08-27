import sys
input = sys.stdin.readline

N = int(input().strip())
X = list(map(int, input().strip().split()))
X_ = sorted(set(X))
indexdict = { X_[i]: i for i in range(0, len(X_)) }
print(' '.join(str(indexdict[i]) for i in X))