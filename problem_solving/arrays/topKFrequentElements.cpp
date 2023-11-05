class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        sort(nums.begin(), nums.end());
        frequency[nums[0]] = 1;
        for(int i=1; i< nums.size(); i++){  
           frequency[nums[i]]++;
        }
        vector<int> counts;
        for(auto it = frequency.begin(); it != frequency.end(); it++){
            counts.push_back(it->second);
        }
        sort(counts.begin(), counts.end(),greater<int>());
        vector<int> result;
        for(int i=0; i<k;i++){
            for(auto it = frequency.begin(); it != frequency.end(); it++){
                if(it->second == counts[i]){
                    result.push_back(it->first);
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
