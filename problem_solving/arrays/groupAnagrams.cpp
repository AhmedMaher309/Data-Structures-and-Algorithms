class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lettersVsWords;
        vector<vector<string>> out;
        for(int i =0; i<strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            lettersVsWords[key].push_back(strs[i]);
        }
        for(auto it = lettersVsWords.begin(); it != lettersVsWords.end(); it++)
        {
            out.push_back(it->second);
        }
        return out;
    }
};

