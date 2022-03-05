
def zArray(string, pattern):
    word = pattern + "$" + string

    n = len(word)
    l, r, k = 0, 0, 0
    z = [0 for i in range(n)]
    for i in range(1, n):
        if i > r:
            l, r = i, i

            while r < n and word[r - l] == word[r]:
                r += 1
            z[i] = r - l
            r -= 1
        else:
            k = i - 1

            if z[k] < r - i + 1:
                z[i] = z[k]
            else:
                l = i
                while r < n and word[r - l] == word[r]:
                    r += 1
                z[i] = r - l
                r -= 1
    return z

string = input()
pattern = input()

arr = zArray(string, pattern)
ans = 0
for ele in arr:
    if ele == len(pattern):
        ans += 1
print(ans)
