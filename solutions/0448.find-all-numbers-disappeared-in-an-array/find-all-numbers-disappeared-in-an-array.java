public class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<Integer>();
        int length = nums.length;
		for (int i = 0; i < length; ++i) nums[(nums[i]-1) % length] += length;
		for (int i = 0; i < length; ++i) if (nums[i] <= length) list.add(i + 1);
		return list;
    }
}