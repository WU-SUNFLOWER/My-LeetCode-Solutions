class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, std::vector<std::string>> bucket;

        for (auto& str : strs) {
            std::map<char, int> counter;
            for (char ch : str) {
                ++counter[ch];
            }
            bucket[counter].push_back(std::move(str));
        }

        std::vector<std::vector<std::string>> ans;
        for (auto& pair : bucket) {
            std::vector<std::string>& str_vec = pair.second;
            ans.push_back(std::move(str_vec));
        }

        return ans;
    }
};