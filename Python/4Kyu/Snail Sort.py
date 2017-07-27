# Snail Sort

# Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

# array = [[1,2,3],
#          [4,5,6],
#          [7,8,9]]
# snail(array) #=> [1,2,3,6,9,8,7,4,5]
# For better understanding, please follow the numbers of the next array consecutively:

# array = [[1,2,3],
#          [8,9,4],
#          [7,6,5]]
# snail(array) #=> [1,2,3,4,5,6,7,8,9]

def snail(array):
   if (array == [[]]):
      return []
   i = j = top = left = 0
   bottom = right = len(array) - 1
   move = 'right'
   sol = []
   for k in range(len(array)**2):
      sol.append (array[i][j])
      if move == 'right':
         j+=1
         if j == right:
            move = 'down'
            top+=1 
         continue
      if move == 'down':
         i+=1
         if i == bottom:
            move = 'left'
            right-=1
         continue
      if move == 'left':
         j-=1
         if j == left:
            move = 'up'
            bottom-=1
         continue
      if move == 'up':
         i-=1
         if i == top:
            move = 'right'
            left+=1
   return sol

print (snail([[1, 2, 3, 4, 5], 
             [6, 7, 8, 9, 10], 
             [11, 12, 13, 14, 15], 
             [16, 17, 18, 19, 20], 
             [21, 22, 23, 24, 25]]) == 
   [1, 2, 3, 4, 5, 10, 15, 20, 25, 24, 23, 22, 21, 16, 11, 6, 7, 8, 9, 14, 19, 18, 17, 12, 13])
    