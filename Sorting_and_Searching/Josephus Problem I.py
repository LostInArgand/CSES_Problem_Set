
def solve(n):
    arr = []
    a = 1
    b = 0
    while n > 0:
        for i in range(2, n + 1, 2):
            arr.append(a * i + b)
        if n & 1:
            arr.append(a + b)
            b += a
        else:
            b -= a
        a <<= 1
        n >>= 1
    return ' '.join(map(str, arr))


n = int(input())
ans = solve(n)
print(ans)

