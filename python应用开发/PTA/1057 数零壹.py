import functools

a = [i.lower() for i in input() if i.isalpha()]
a = map(lambda x: ord(x) - ord('a') + 1, a)
a = bin(sum(a))[2:]
if a == '0':
    print('0 0')
else:
    print(a.count('0'), a.count('1'))
