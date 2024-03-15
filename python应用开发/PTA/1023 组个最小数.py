l = list(map(int,input().split()))
idx = 1
while l[idx] == 0:
    idx += 1
print(idx,end='')
print("0" * l[0],end='')
print(str(idx) * (l[idx] - 1),end='')
for i in range(idx + 1,len(l)):
    print(str(i) * l[i],end='')
