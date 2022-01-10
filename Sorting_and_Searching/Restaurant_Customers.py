n = int(input())
arr = []
fov_arr = []
rev_arr = []
for i in range(n):
    u, v = list(map(int, input().split()))
    fov_arr.append(u)
    rev_arr.append(v)
fov_arr.sort()
rev_arr.sort()
count = 0
ans = 0
i = 0
j = 0
while i < n:
    count += 1
    if fov_arr[i] >= rev_arr[j]:
        count -= 1
        j += 1
    i += 1
    ans = max(ans, count)
print(ans)


