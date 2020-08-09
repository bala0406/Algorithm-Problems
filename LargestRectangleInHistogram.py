
#Iterative - O(n^2) - not an efficient method
def largestRectangle(heights : list):

    maxArea = 0

    for i in range(len(heights)):
        minHeight = heights[i]
        for j in range(i,len(heights)):
            minHeight = min(minHeight,heights[j])
            maxArea = max(maxArea,minHeight * ((j-i) + 1))

    return maxArea


print(largestRectangle([2,1,5,6,2,3]))




    
