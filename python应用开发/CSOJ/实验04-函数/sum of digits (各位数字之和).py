import functools

print(functools.reduce(lambda x, y: int(x) + int(y), input(), 0))