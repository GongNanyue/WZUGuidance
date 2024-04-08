weight = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
M = ['1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2']


def check(s):
    if not s[:-1].isdigit():
        return False

    sm = sum(weight[idx] * int(char) for idx, char in enumerate(s[:-1]))
    return M[sm % 11] == s[-1]


n = int(input())
ans = True
for i in range(n):
    s = input()
    if not check(s):
        ans = False
        print(s)
if ans:
    print("All passed")
