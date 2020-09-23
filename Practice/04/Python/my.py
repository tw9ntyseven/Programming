# 1 способ
a = int(input())
b = int(input())
buf = a
a = b
b = buf
print(a)
print(b)

# 2 способ
c = int(input())
d = int(input())
c = c + d
d = c - d
c = c - d
print(c)
print(d)