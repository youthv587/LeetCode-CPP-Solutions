int singleNonDuplicate(int* nums, int numsSize) {
    int hi, lo, mi;
	hi = numsSize - 1; lo = 0;
	while (lo < hi) {
		mi = (hi + lo) >> 1;
		if (nums[mi] ^ nums[mi^1]) hi = mi;
		else lo = mi + 1;
	}
	
	return nums[lo];
}