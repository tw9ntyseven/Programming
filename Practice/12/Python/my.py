num = int(input())
def Fact(a: int):
    if a > 1:
        return Fact(a - 1) * a
    else:
        return 1
print(Fact(num))