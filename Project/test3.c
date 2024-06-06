#include<stdio.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b, *b = t;
}

void moveZeroes(int *nums, int numsSize)
{
    int left = 0, right = 0;
    while (right < numsSize)
    {
        if (nums[right])
        {
            swap(nums + left, nums + right);
            left++;
        }
        right++;
    }
}

int main()
{
    int i, arr[5] = {0,1,0,3,12};
    i = sizeof(arr) / sizeof(arr[0]);
    moveZeroes(arr, i);
    
    for (int f = 0; f < i; f++)
        printf("%d ", arr[f]);
    return 0;
}