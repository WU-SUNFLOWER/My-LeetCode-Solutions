class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        std::map<int, int> convert;
        std::vector<int> ans;
        for (int i = 0; i < nums2.size(); ++i) {
            convert[nums2[i]] = i;
        }
        for (int elem: nums1) {
            ans.push_back(convert[elem]);
        }
        return ans;
    }
};