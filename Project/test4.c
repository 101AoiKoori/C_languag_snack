#include<stdio.h>
int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    int k = numsSize;
    int result[5];
    for (int i = 0, j = numsSize - 1; j <= i;)
    {
        if (nums[i] * nums[i] > nums[j] * nums[j])
        {
            result[k] = nums[i] * nums[i];
            k--;
            i++;
        }
        else
        {
            result[k] = nums[j] * nums[j];
            k--;
            j--;
        }
    }
    return result;
}

int main(){
    int arr[5] = {-3, -2, -1, 0, 1};
    int i=sizeof(arr)/sizeof(arr[0]);
    sortedSquares(arr, i, i);
}