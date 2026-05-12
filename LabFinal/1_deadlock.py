n = int(input("Enter number of processes: ")) # col
r = int(input("Enter number of resources: ")) # row

# Allocation matrix
alloc = []
print("Enter Allocation Matrix:")
for i in range(n):
    row = list(map(int, input(f"P{i}: ").split()))
    alloc.append(row)

# Max matrix
maxm = []
print("Enter Max Matrix:")
for i in range(n):
    row = list(map(int, input(f"P{i}: ").split()))
    maxm.append(row)

# Available resources
avail = list(map(int, input("Enter Available Resources: ").split()))

f = [0] * n        # finished
ans = [0] * n      # safe sequence
ind = 0

# Need
need = [[0] * r for _ in range(n)]
for i in range(n):
    for j in range(r):
        need[i][j] = maxm[i][j] - alloc[i][j]

# Banker's Algorithm
for _ in range(n):
    for i in range(n):
        if f[i] == 0:
            flag = 0
            for j in range(r):
                if need[i][j] > avail[j]:
                    flag = 1
                    break

            if flag == 0:
                ans[ind] = i
                ind += 1
                for y in range(r):
                    avail[y] += alloc[i][y]
                f[i] = 1

print("The SAFE Sequence is as follows")
for i in range(n - 1):
    print(f"P{ans[i]} ->", end=" ")
print(f"P{ans[n - 1]}")