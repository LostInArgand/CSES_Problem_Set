from itertools import combinations

n = int(input())
arr = list(map(int, input().split()))
summ = sum(arr)
if n == 1:
    print(arr[0])
    exit()
ans = summ
for i in range(1, n):
    temp = combinations(arr, i)
    for ele in temp:
        val = sum(ele)
        ans = min(ans, abs(summ - 2 * val))
print(ans)
