n = int(input("enter number of request"))

addresses = list(map(int, input("enter the number of request: ").split()))

head = int(input("enter head: "))
disksize = int(input("Enter disk size (max track number): "))
addresses.sort()

totalmovement = 0
current = head
sequence = [head]   # track movement

higher = [x for x in addresses if x >= head]
lower = [x for x in addresses if x < head]

# Move right
for i in higher:
    totalmovement += abs(current - i)
    current = i
    sequence.append(i)

# Go to end
totalmovement += abs(current - (disksize - 1))
current = disksize - 1
sequence.append(current)

# Move left
for i in reversed(lower):
    totalmovement += abs(current - i)
    current = i
    sequence.append(i)

print("Total head movement (Scan):", totalmovement)
print("Sequence:", sequence)

'''
number of request: 7
Sample Input: 82 170 43 140 24 16 190
head 50
max track number: 200

'''