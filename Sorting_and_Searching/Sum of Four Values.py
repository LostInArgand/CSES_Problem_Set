from collections import defaultdict


def solve():
    for i in range(len(sum_arr)):
        a, p, q = sum_arr[i]
        b = x - a
        if b in mem:
            for ele in mem[b]:
                r, s = ele
                check = {p, q, r, s}
                if len(check) == 4:
                    ans = ' '.join(map(str, [p + 1, q + 1, r + 1, s + 1]))
                    return ans
    return 'IMPOSSIBLE'


n, x = list(map(int, input().split()))
arr = list(map(int, input().split()))
sum_arr = []
for i in range(n):
    for j in range(i, n):
        if i != j:
            sum_arr.append((arr[i] + arr[j], i, j))
mem = defaultdict(set)
for i in range(len(sum_arr)):
    mem[sum_arr[i][0]].add((sum_arr[i][1], sum_arr[i][2]))
ans = solve()
print(ans)
