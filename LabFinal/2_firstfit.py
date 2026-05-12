MAX = 10

blockSize = [0] * MAX
processSize = [0] * MAX
blockAllocated = [0] * MAX
allocation = [-1] * MAX

totalInternalFrag = 0
totalExternalFrag = 0

nBlocks = int(input("Enter number of memory blocks: "))

print("Enter sizes of memory blocks:")
for i in range(nBlocks):
    blockSize[i] = int(input(f"Block {i + 1}: "))

nProcesses = int(input("\nEnter number of processes: "))

print("Enter sizes of processes:")
for i in range(nProcesses):
    processSize[i] = int(input(f"Process {i + 1}: "))
    allocation[i] = -1

for i in range(nProcesses):
    for j in range(nBlocks):
        if not blockAllocated[j] and blockSize[j] >= processSize[i]:
            allocation[i] = j
            blockAllocated[j] = 1
            totalInternalFrag += blockSize[j] - processSize[i]
            break

# Output
print("\nProcess No.\tProcess Size\tBlock No.")
for i in range(nProcesses):
    print(f"{i + 1}\t\t{processSize[i]}\t\t", end="")
    if allocation[i] != -1:
        print(allocation[i] + 1)
    else:
        print("Not Allocated")

print(f"\nTotal Internal Fragmentation: {totalInternalFrag}")

for i in range(nBlocks):
    if not blockAllocated[i]:
        totalExternalFrag += blockSize[i]

print(f"Total External Fragmentation: {totalExternalFrag}")