import itertools

word = input()
words = list(set(itertools.permutations(word)))
words.sort()
print(len(words))
for ele in words:
    print(''.join(ele))
