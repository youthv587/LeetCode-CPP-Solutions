void moveZeroes(int* nums, int numsSize) {
    int i, j;
    for (i = j = 0; i < numsSize; i++)
        if (nums[i]) {
            nums[j] = nums[i];
            if (i != j) nums[i] = 0;
            j++;
        }    
}