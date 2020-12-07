# bubble Sort Method
# This method will get TLE error as its obviously O(n^2)
def minimumBribes(inputArray):
    inputArray = [element - 1 for element in inputArray]
    swapped = False
    swaps = 0
    for index, element in enumerate(inputArray):
        # if an element bribes more than two then its chaotic
        if(element - index > 2):
            print("Too chaotic")
            return

    for k in range(len(inputArray)):
        for i in range(len(inputArray) - 1):
            if(inputArray[i] > inputArray[i+1]):
                inputArray[i], inputArray[i+1] = inputArray[i+1], inputArray[i]
                swaps += 1
    print(swaps)


# in this method instead of swapping we just find how many times the element is bribed
def minimumBribes(inputArray):

    inputArray = [element - 1 for element in inputArray]
    swapped = False
    swaps = 0
    for index, element in enumerate(inputArray):
        # if an element bribes more than two then its chaotic
        if(element - index > 2):
            print("Too chaotic")
            return
        # if the element element which bribes must be in front of the currentIndex and is greater
        for j in range(max(0, element - 2), index):
            if(inputArray[j] > inputArray[index]):
                swaps += 1
    print(swaps)
