num = int(input())
def Elevate(a:int):
    if a == 0:
        return 0
    var = 2
    count = 1

    while var < a:
        var *= 2
        count += 1
    return count
print(Elevate(num))