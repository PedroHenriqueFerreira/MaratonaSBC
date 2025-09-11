n = int(input())
v = list(map(int, input().split()))

total = 0

for i in range(n):
    for j in range(n):
        for k in range(n - max(i, j)):
            if v[i + k] == v[j + k]:
                total += 1
            else:
                break

def mdc(a: int, b: int):
    if a < b:
        a, b = b, a
    
    if b == 0:
        return a
    
    return mdc(b, a % b)
    
nn = n ** 2

d = mdc(total, nn)
                
print(f'{total // d}/{nn // d}')