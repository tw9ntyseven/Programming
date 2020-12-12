array = []
count = int(input())

if count <= 5:

    for i in range(count):
        array.append(int(input()))
        array = list(reversed(sorted(array)))
        print(array)

else:
    for i in range(5):
        array.append(int(input()))
        arr = list(reversed(sorted(array)))
        print(array)

    for i in range(5, count):
        cin = int(input())
        isSorted = True

        for j in range(4, 0, -1):
            if cin < array[j]:
                array.pop(0)
                array.append(cin)
                isSorted = False
                break

        if not isSorted:
            array = list(reversed(sorted(array)))
        print(array)