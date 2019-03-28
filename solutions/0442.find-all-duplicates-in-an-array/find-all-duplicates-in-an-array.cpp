class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       	vector<int> resnums;
	    for (auto i : nums) {
	        nums[abs(i)-1] = -nums[abs(i)-1];
	        if (nums[abs(i)-1] > 0) resnums.push_back(abs(i));
	    }
	return resnums;
    }
};