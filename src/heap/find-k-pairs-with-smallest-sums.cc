struct Comparer {
    bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<2>(a) > std::get<2>(b);
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        // tuple<i, j, nums1[i] + nums2[j]>
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, Comparer> q;
        q.push({ 0, 0, nums1[0] + nums2[0] });

        std::set<std::pair<int, int>> visited = { { 0, 0 } };

        std::vector<std::vector<int>> ans;
        while (!q.empty() && ans.size() < k) {
            auto [i, j, sum] = q.top();
            q.pop();

            ans.push_back({ nums1[i], nums2[j] });

            if (i + 1 < len1 && !visited.contains({ i + 1, j })) {
                visited.insert({ i + 1, j });
                q.push({ i + 1, j, nums1[i + 1] + nums2[j] });
            }

            if (j + 1 < len2 && !visited.contains({ i, j + 1 })) {
                visited.insert({ i, j + 1 });
                q.push({ i, j + 1, nums1[i] + nums2[j + 1] });
            }
        }

        return ans;
    }
};