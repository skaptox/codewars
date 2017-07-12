def next_bigger(n)
  ary = n.to_s.chars.permutation.to_a.map {|e| e.join.to_i }.sort
  for i in ary
  	return i if i > n
  end
  n
end


puts next_bigger(2017) == 2071


=begin

You have to create a function that takes a positive integer number and returns the next bigger number formed by the same digits:

next_bigger(12)==21
next_bigger(513)==531
next_bigger(2017)==2071

If no bigger number can be composed using those digits, return -1:

next_bigger(9)==-1
next_bigger(111)==-1
next_bigger(531)==-1

=end
