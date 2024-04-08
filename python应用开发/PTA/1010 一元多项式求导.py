l = list(map(int, input().split()))
dit = dict()
for i in range(0, len(l), 2):
    # dit[l[i]] = l[i + 1]
    # x = l[i] y = l[i + 1]
    if l[i + 1] > 0:
        dit[l[i + 1] - 1] = dit.get(l[i + 1] - 1, 0) + l[i] * l[i + 1]
nd = {ky: val for ky, val in dit.items() if not val == 0}
l = sorted(nd.items(), key=lambda x: x[0], reverse=True)
if len(l) == 0:
    print("0 0")
else:
    ans = []
    for x, y in l:
        ans.append(y)
        ans.append(x)
    print(" ".join(map(str, ans)))
# 如果最后的答案是0 那么只要输出0 0
# 不然的话 清除所有系数为0的项
