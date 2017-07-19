

# A format for expressing an ordered list of integers is to use a comma separated list of either

#     individual integers
#     or a range of integers denoted by the starting integer separated from the end integer in the range by a dash, '-'. The range includes all integers in the interval including both endpoints. It is not considered a range unless it spans at least 3 numbers. For example ("12, 13, 15-17")

# Complete the solution so that it takes a list of integers in increasing order and returns a correctly formatted string in the range format.

# Example:


def solution(args):
   sol = ""
   i = 0
   while i < len(args): 
      j = i
      while j < len(args) - 1: #Looking for final index of sucesion 
         if args[j] + 1 != args [j+1]:
            break
         j += 1
      if j - i < 2:
         sol += str(args[i]) + ","
      else:
         sol += str(args[i])+ "-" + str(args[j]) + ","
         i = j
      i += 1
   return sol[:-1] #Discard last comma

print solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20])
# returns "-6,-3-1,3-5,7-11,14,15,17-20"