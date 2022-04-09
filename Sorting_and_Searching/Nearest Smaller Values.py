from collections import deque

n = int(input())
arr = list(map(int, input().split()))

ans = [0 for i in range(n)]

stack = deque()
for i in range(n - 1, -1, -1):
    while stack:
        val, ind = stack.pop()
        if val > arr[i]:
            ans[ind] = i + 1
        else:
            stack.append((val, ind))
            break
    stack.append((arr[i], i))
print(' '.join(map(str, ans)))

