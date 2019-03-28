public class Solution {
    public int[] countBits(int num) {
        int[] arr = new int[num+1];
		arr[0] = 0;
		for (int j = 1; j < arr.length; ++j) {
			arr[j] = arr[j&j-1] +1;
		}
		return arr;
    }
}