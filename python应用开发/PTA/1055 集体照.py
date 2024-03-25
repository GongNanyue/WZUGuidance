n,k=map(int,input().split(' '))
 
 
personnel=[]
result=[]
 
 
#输入
#Input
for i in range(n):
    personnel.append(input().split(' '))
    
 
#对高度和姓名进行排序
#Sort by height and name
personnel=sorted(personnel,key=lambda x:(-int(x[1]),x[0]),reverse=True)
 
 
a=n//k
b=n-a*(k-1)
 
 
#对拍照者分组
#Group people to be photographed
for j in range(k,0,-1):
    if j==k:
        c=personnel[(j-1)*a:]
        c.reverse()
        result.append(c)
    else:
        c=personnel[(j-1)*a:j*a]
        c.reverse()
        result.append(c)
        
    
#依次对每组进行插入排位
#Insert and rank each group in turn
for m in result:
    length=len(m)
    flag=length//2
    middle=flag
    c=[' ']*length
    c[middle]=m[0][0]
    use=1
    for z in range(1,flag+1):
        if (middle-z)>=0:
            c[middle-z]=m[use][0]
            use=use+1
        if (middle+z)<length:
            c[middle+z]=m[use][0]
            use=use+1
            
            
    #按格式输出
    #Output in format
    print(*c)
        
    
 
