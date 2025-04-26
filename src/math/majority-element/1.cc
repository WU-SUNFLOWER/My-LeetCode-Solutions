class Solution {
public
    int majorityElement(vectorint& nums) {
        int low = nums.size()  2;
        stdunordered_mapint, int my_map;
        for (int num  nums) {
            if (my_map.contains(num)) {
                my_map[num] += 1;
            } else {
                my_map[num] = 1;
            }
        }
        for (const auto& record  my_map) {
            int num = record.first;
            int cnt = record.second;
            if (cnt  low) return num;
        }
        return -1;
    }
};