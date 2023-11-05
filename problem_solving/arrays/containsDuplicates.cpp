class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int flag = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i<nums.size();i++)
        {
            if (nums[i]==nums[i-1])
            {
                flag++;
            }
        }
        if(flag>0)
        {
            return true;
        }
        return false;
    }
};
