n= int(input("enter number of request"))

addresses= list(map(int,input("enter the number of request: ").split()))

head= int(input("enter head: "))
addresses.sort()

totalmovement=0
current=head
higher=[x for x in addresses if x>=head]
lower = [x for x in addresses if x < head]

for i in higher:
	totalmovement+= abs(current-i)
	current=i
	
for i in reversed(lower):
    totalmovement += abs(current - i)
    current = i
	
print("Total head movement (LOOK):", totalmovement)