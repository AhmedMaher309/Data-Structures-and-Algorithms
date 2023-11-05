class Solution {
public:
/*
create a hash table and the first element of the array is the first key 
with the needed number to be added to get the target as the first element of value pair
and the index is the second element of the pair

loop through the array and see if the element of the array is needed for an existing key to get the target
if so, return the indeces of both elements as the result

else add this element to the hash table 

there is no probem in finding repeated element and updated it in the hash table as long as
it is not needed to get the target, which will be happended internally in the else condition
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, pair<int,int>> neededForTarget;
        neededForTarget[nums[0]].first = target - nums[0];
        neededForTarget[nums[0]].second = 0;
        for(int i = 1; i < nums.size();i++){
            int keyToSearch = target- nums[i];
            if(neededForTarget.find(keyToSearch) != neededForTarget.end()){
                result[0] = neededForTarget[keyToSearch].second;
                result[1] = i;
                break;
            }
            else{
                neededForTarget[nums[i]].first = target - nums[i];
                neededForTarget[nums[i]].second = i;
            }
        }
        return result;
    }
};
