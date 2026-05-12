n= int(input("enter number of request"))

addresses= list(map(int,input("enter the number of request: ").split()))

head= int(input("enter head: "))

totalmovement=0
current=head

for i in addresses:
	totalmovement+= abs(current-i)
	current=i

print(f"total movement { totalmovement}")