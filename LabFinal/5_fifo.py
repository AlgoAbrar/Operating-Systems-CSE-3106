n = int(input("Enter number of pages: "))
pages = list(map(int, input("Enter page reference string: ").split()))
f = int(input("Enter number of frames: "))

frames = []
for i in range(f):
    frames.append(-1)

miss = 0
hit = 0
idx = 0 

for i in range(n):
    found = 0

    for j in range(f):
        if frames[j] == pages[i]:
            found = 1
            hit += 1
            break

    if found == 0:
        # MISS
        frames[idx] = pages[i]
        idx = (idx + 1) % f
        miss += 1
        print("Page", pages[i], "-> FAULT ->", end=" ")
    else:
        print("Page", pages[i], "-> HIT   ->", end=" ")

    # frame
    for j in range(f):
        print(frames[j], end=" ")

    print()

print("\nPage Miss =", miss)
print("Page Hits =", hit)