=begin

In this kata you will have to calculate fib(n) where:

fib(0) := 0
fib(1) := 1
fin(n + 2) := fib(n + 1) + fib(n)

Write an algorithm that can handle n where 1000000 ≤ n ≤ 1500000.

Your algorithm must output the exact integer answer, to full precision. Also, it must correctly handle negative numbers as input.

HINT I: Can you rearrange the equation fib(n + 2) = fib(n + 1) + fib(n) to find fib(n) if you already know fin(n + 1) and fib(n + 2)? Use this to reason what value fib has to have for negative values.

HINT II: See http://mitpress.mit.edu/sicp/chapter1/node15.html

=end

$mem = {0 => 0, 1 => 1}
def fib(n)
   if(n < 0) 
	  return n % 2 == 1 ? fib(-n) : -fib(-n)
   end  
   return $mem[n] if $mem.include? n
   if n % 2 == 0
	  $mem[n] = ((2 * fib((n / 2) - 1)) + fib(n / 2)) * fib(n / 2)
	  return $mem[n]
   else
	  $mem[n] = (fib((n - 1) / 2) ** 2) + (fib((n+1) / 2) ** 2)
	  return $mem[n]
   end
end

puts (fib(-1000000))

#This is based on the derivation from a note by Prof. Edsger Dijkstra. 
#The solution exploits the fact that to calculate both F(2N) and F(2N-1) you only need to know F(N) and F(N-1). 


#Best solution on Codewars

=begin

require 'matrix'

def fib(n)
  (Matrix[[1,1],[1,0]] ** n)[1,0]
end

=end

