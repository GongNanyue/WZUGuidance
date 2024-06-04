import math


def InsertStep(a, i):
    jdx = 0
    while jdx < i and a[jdx] < a[i]:
        jdx += 1
    tmp = a[i]
    for j in range(i, jdx, -1):
        a[j] = a[j - 1]
    a[jdx] = tmp
    return a


def InsertTry(a, b):
    for i in range(len(a)):
        a = InsertStep(a[:], i)
        if a == b:
            a = InsertStep(a[:], i + 1)
            return a
    return None


def MergeStep(a, i):
    i = 1 << i
    for j in range(0, len(a), i):
        a[j:j + i] = sorted(a[j:j + i])
    return a


def MergeTry(a, b):
    for i in range(0, math.ceil(math.log(len(a), 2)) + 1):
        a = MergeStep(a[:], i)
        if a == b:
            a = MergeStep(a[:], i + 1)
            return a
    return None


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
x = MergeTry(a, b)
if x is not None:
    print('Merge Sort')
    print(' '.join(map(str, x)))
else:
    x = InsertTry(a, b)
    if x is not None:
        print('Insertion Sort')
        print(' '.join(map(str, x)))
