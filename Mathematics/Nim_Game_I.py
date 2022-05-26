T = int(input())
for t in range(T):
    n = int(input())
    arr = list(map(int, input().split()))
    cumm_arr = 0
    for ele in arr:
        cumm_arr ^= ele
    if cumm_arr != 0:
        print('first')
    else:
        print('second')

