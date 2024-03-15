import os

os.listdir('.')
for f in os.listdir('.'):
    if f.endswith('.docx') or f.endswith('.doc'):
        s = f.replace('学号','22211870xxx')
        s = s.replace('姓名','xxx')
        os.rename(f,s)
