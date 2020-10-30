s, l1, l2, r1, r2 = map(int, input().split())

x1 = l1
x2 = s - x1
lr2 = r2 - l2

if x2 < l2:
    range = l2 - x2
    
    if range >= lr2 :
        print("-1")
    else:
        x2 += range
        x1 -= range
        print(x1,x2)
        
elif x2 > r2:
    range = x2 - r2
    
    if range >= lr2:
        print("-1")
    else:
        x2 -= range
        x1 += range
        print(x1,x2)
else:
    print(x1,x2)