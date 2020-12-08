import random
from typing import List


def bozoSort(arr:[], bl:bool):
    c = True
    while c:
        r1 = random.randint(0, len(arr) - 1)
        r2 = random.randint(0, len(arr) - 1)
        tmp = arr[r1]
        arr[r1] = arr[r2]
        arr[r2] = tmp

        if bl:
            tmpBool = True
            for i in range(len(arr) - 1):
                if arr[i] > arr[i + 1]:
                    tmpBool = False
                    break
            c = not tmpBool
        else:
            tmpBool = True
            for i in range(len(arr) - 1):
                if arr[i] < arr[i + 1]:
                    tmpBool = False
                    break
            c = not tmpBool

    return arr

n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

print(bozoSort(arr, 0))