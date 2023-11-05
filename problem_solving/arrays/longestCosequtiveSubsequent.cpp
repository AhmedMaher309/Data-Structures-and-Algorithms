class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
  if (nums.empty()) {
        return 0;
    }
    int count = 1;
    int max_count = 1;
    sort(nums.begin(), nums.end());
    auto current = nums.begin() + 1;
    auto prev = nums.begin();
    while (current != nums.end()) {
        if (*current - *prev == 1) {
            count++;
        }
        else if(*prev == *current){

        } 
        else{
            max_count = max(max_count, count);
            count = 1;
        }
        prev = current;
        current++;
    }
    return max(max_count, count);
    }
};
