import sys
input = sys.stdin.readline

N = int(input().strip())
emp = set()
for _ in range(N):
    name, status = input().strip().split()
    if status == 'enter':
        emp.add(name)
    else:
        emp.remove(name)
emp = sorted(emp, reverse=True)
for e in emp:
    print(e)