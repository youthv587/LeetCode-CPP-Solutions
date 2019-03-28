/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *singleNumber(int *nums, int numsSize, int *returnSize)
{
	int i, j, m, pivot, *ret;
	i = j = m = 0;
	ret = (int *)calloc(*returnSize = 2, sizeof(int));
	
	while (i < numsSize) m ^= nums[i++];
	pivot = (m & m - 1) ^ m;
	for (i = 0; i < numsSize; ++i)
		if (nums[i] & pivot) ret[0] ^= nums[i];
		else ret[1] ^= nums[i];
	
	return ret;
}