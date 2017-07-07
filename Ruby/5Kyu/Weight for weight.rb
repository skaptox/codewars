=begin 

My friend John and I are members of the "Fat to Fit Club (FFC)". John is worried because each
month a list with the weights of members is published and each month he is the last on the list
which means he is the heaviest.

I am the one who establishes the list so I told him: "Don't worry any more, I will modify the order
of the list". It was decided to attribute a "weight" to numbers. The weight of a number will be from
now on the sum of its digits.

For example 99 will have "weight" 18, 100 will have "weight" 1 so in the list 100 will come before
99. Given a string with the weights of FFC members in normal order can you give this string ordered
by "weights" of these numbers? Example:

"56 65 74 100 99 68 86 180 90 ordered by numbers weights becomes: 100 180 90 56 65 74 68 86 99

When two numbers have the same "weight", let us class them as if they were strings and not numbers:
100 is before 180 because its "weight" (1) is less than the one of 180 (9) and 180 is before 90
since, having the same "weight" (9) it comes before as a string.

All numbers in the list are positive numbers and the list can be empty. 


def order_weight(strng)
	weights = strng.split(" ") 
	digitsSum = weights.map{|x| x.chars.map(&:to_i).reduce(:+)} 
	indices = (0...weights.size()).to_a
	aHash = indices.zip(digitsSum).to_h 
	aHash = aHash.sort_by{|k,v| v}.to_h 

	keys,values = aHash.keys, aHash.values 

	result = []
	max = weights.size()
	i = 0
	while i < max
		pack = []
		pack << weights[keys[i]] 
		while i + 1 < max and values[i] == values[i + 1]
			pack << weights[keys[i+1]] 
			i += 1
		end
		pack = pack.sort 
		result += pack
		i += 1
	end
	result.join(" ")
end

=end

#Update : I didn't know to use two parameter in sort_by method

def order_weight(strng)
	return strng.split().sort_by {|e| [e.chars.map(&:to_i).reduce(:+),e]}.join(" ")
end


puts order_weight("71899703 200 6 91 425 4 67407 7 96488 6 4 2 7 31064 9 7920 1 34608557 27 72 18 81")

puts order_weight("71899703 200 6 91 425 4 67407 7 96488 6 4 2 7 31064 9 7920 1 34608557 27 72 18 81") == 
"1 2 200 4 4 6 6 7 7 18 27 72 81 9 91 425 31064 7920 67407 96488 34608557 71899703" #true
