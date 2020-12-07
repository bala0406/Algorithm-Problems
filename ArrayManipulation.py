
#refer to the maximum sub array problem which is related to the solution of the following problem in hacker rank

def arrayManipulation(n, queries):
    
    resultArray = [0] * (n + 1)
    
    for i in range(len(queries)):
        startingIndex = queries[i][0] - 1
        endingIndex = queries[i][1]
        element = queries[i][2]
        resultArray[startingIndex] += element
        resultArray[endingIndex] -= element
        
    maximum = 0 
    sumValue = 0
    for element in resultArray:
        sumValue += element
        if(maximum < sumValue):
            maximum = sumValue  
             
    return maximum

#sample input
#5 3
#1 2 100
#2 5 100
#3 4 100
