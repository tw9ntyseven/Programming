n = int(input())
arr = []
vector = []
x = 0

for i in range(n):
    arr.append(input())

for i in range(n):
    if arr[i][0] == 'a' and arr[i][8] == '1' and arr[i][7] == '6' and arr[i][6] == '6' and arr[i][5] == '5' and arr[i][4] == '5':
        vector.append(arr[i])
        x = 1
        
if x:
    for i in range(len(vector)):
        print(vector[i])
else:
    print("-1\n")