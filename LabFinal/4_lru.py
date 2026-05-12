n = int(input("Enter number of pages: "))
pages = list(map(int, input("Enter page reference string: ").split()))
f = int(input("Enter number of frames: "))

frames = [-1] * f
order = []

hit = 0
miss = 0

for i in range(n):
    page = pages[i]

    if page in frames:
        hit += 1
        print(f"Page {page} -> HIT   -> ", end="")

        # update recent
        if page in order:
            order.remove(page)
        order.append(page)

    else:
        miss += 1
        print(f"Page {page} -> FAULT -> ", end="")

        if -1 in frames:
            idx = frames.index(-1)
            frames[idx] = page
        else:
            # remove least recent
            lru_page = order.pop(0)
            idx = frames.index(lru_page)
            frames[idx] = page

        order.append(page)

    # print status
    for j in range(f):
        print(frames[j], end=" ")
    print()

print("\nPage Miss =", miss)
print("Page Hits =", hit)