n = int(input())
arr = []
for i in range(n):
    u, v = list(map(int, input().split()))
    arr.append((v, u))
arr.sort()
count = 0
ans = 0
last = 0
for i in range(n):
    if arr[i][1] >= last:
        count += 1
        last = arr[i][0]
    ans = max(ans, count)
print(ans)

