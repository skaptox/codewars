def next_bigger(n):
	st = list(str(n)) 
	for i in xrange(len(st)-1,0,-1):
		if st[i] > st[i-1]:
			st[i:] = sorted(st[i:])
			j = i + (next(x[0] for x in enumerate(st[i:]) if x[1] > st[i-1]))
			st[i-1],st[j] = st[j],st[i-1]
			st[i:] = sorted(st[i:])
			return int("".join(st))
	return -1



# You have to create a function that takes a positive integer number and returns the next bigger number formed by the same digits:

# next_bigger(12)==21
# next_bigger(513)==531
# next_bigger(2017)==2071

# If no bigger number can be composed using those digits, return -1:

# next_bigger(9)==-1
# next_bigger(111)==-1
# next_bigger(531)==-1




