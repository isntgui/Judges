n = int(input())
vt = []
for i in range(n):
    en = input().split()
    value = float(en[-1])
    weight = float(en[-2])
    name = " ".join(en[:-2])
    vt.append((value / weight, name))
print(max(vt, key=lambda x : x[0])[1])