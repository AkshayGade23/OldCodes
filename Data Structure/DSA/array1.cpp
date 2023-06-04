// Saraswati has an array of N non-negative integers. The i-th integer of the array is A. She wants to choose a contiguous arithmetic subarray from her array that as the maximum length. Please help her to length of the longest contiguuos arithmetic subarray.

#include <iostream>
using namespace std;

int longestContiguousArithmeticSubarray(int arr[], int n)
{
    int currentDiff = arr[0] - arr[1];
    int maxSubarray = 2;
    int currentSubarray = 2;

    for (int i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] == currentDiff)
            currentSubarray++;

        else
        {
            currentDiff = arr[i] - arr[i - 1];
            if (maxSubarray < currentSubarray)
                maxSubarray = currentSubarray;
        }
    }
    return maxSubarray;
}

int secondLargestNumber(int arr[], int n)
{
    int smax = -1;
    int max = arr[0];
    int max = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (smax < arr[i] && arr[i] < max)
            smax = arr[i];
    }

    return smax;
}

int main()
{
    int arr[8] = {90, 8, 90, 6};
    int f;
    f = secondLargestNumber(arr, 4);
    std::cout << " answer is  =  " << f;
    return 0;
}