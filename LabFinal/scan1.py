n= int(input("enter number of request"))

addresses= list(map(int,input("enter the number of request: ").split()))

head= int(input("enter head: "))
disksize = int(input("Enter disk size (max track number): "))

addresses.sort()

totalmovement=0
current=head
higher=[x for x in addresses if x>=head]
lower = [x for x in addresses if x < head]

for i in higher:
	totalmovement+= abs(current-i)
	current=i

totalmovement+= abs(current-(disksize-1))
current= disksize-1

for i in reversed(lower):
    totalmovement += abs(current - i)
    current = i

print("Total head movement (Scan):", totalmovement)