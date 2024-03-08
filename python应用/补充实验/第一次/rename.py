import os

x = (os.listdir('.'))
for i in x:
    if i.endswith('.docx'):
        p = i.index('题号')
        
        os.rename(i,i[p:])
