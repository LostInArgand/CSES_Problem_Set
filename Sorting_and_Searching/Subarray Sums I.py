from collections import deque

n, x = list(map(int, input().split()))
arr = list(map(int, input().split()))
window = deque()
summ = 0
ans = 0
for i in range(n):
    summ += arr[i]
    window.append(arr[i])
    while summ > x:
        val = window.popleft()
        summ -= val
    if summ == x:
        ans += 1
print(ans)
