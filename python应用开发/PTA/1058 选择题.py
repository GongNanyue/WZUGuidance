class Problem:
    def __init__(self):
        self.score = 0
        self.choice = 0
        self.rightChoice = 0
        self.lst = []
    def __init__(self,score,choice,right,lst):
        self.score = score
        self.choice = choice
        self.rightChoice = right
        self.lst = lst
    def isRight(self,l):
        sorted(l)
        if self.rightChoice != len(l):
            return False
        for i in range(self.rightChoice):
            if self.lst[i] != l[i]:
                return False
        return True


n,m = map(int,input().split())
problems = []
for i in range(m):
    inp = input().split()
    score = int(inp[0])
    choice = int(inp[1])
    right = int(inp[2])
    lst = inp[3:]
    sorted(lst)
    problems.append(Problem(score,choice,right,lst))

mp = dict()
for i in range(n):
    inp = input()
    inp = inp[1:-1]
    groups = inp.split(') (')
    reply = []
    for group in groups:
        reply.append(group.split()[1:])

    score = 0
    for i in range(m):
        if problems[i].isRight(reply[i]):
            score += problems[i].score
        else:
            if mp.get(i+1) == None:
                mp[i+1] = 1
            else:
                mp[i+1] += 1
    print(score)

maxL = []
maxC = 0
for k,v in mp.items():
    if v > maxC:
        maxL = [k]
        maxC = v
    elif v == maxC:
        maxL.append(k)

if len(mp) == 0:
    print("Too simple")
else:
    print(maxC,end=" ")
    print(" ".join(map(str,maxL)),end="")


