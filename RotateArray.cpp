#include <iostream>
#include <vector>
using namespace std;

//Method 1
vector<int> rotateLeft1(vector<int> a, int rotationCount)
{
    vector<int> rotatedArray;
    int startingIndex = rotationCount % a.size();

    for (int i = 0; i < a.size(); i++)
    {
        rotatedArray.push_back(a[(startingIndex + i) % a.size()]);
    }
    return rotatedArray;
}

void reverse(int startingIndex, int endingIndex, vector<int> &a)
{
    while (startingIndex < endingIndex)
    {
        int temp = a[startingIndex];
        a[startingIndex] = a[endingIndex];
        a[endingIndex] = temp;
        startingIndex++;
        endingIndex--;
    }
}

//Method 2
vector<int> rotateLeft2(vector<int> a, int rotationCount)
{
    int startingIndex = rotationCount % a.size();
    reverse(0, a.size() - 1, a);
    reverse(0, a.size() - startingIndex - 1, a);
    return a;
}

//Method-3 juggling method
//method-4 gcd method
//method-5 brute force
