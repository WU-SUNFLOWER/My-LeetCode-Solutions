class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string s1, s2;
        for (vector<int>& elem: shift) {
            int len = s.length();
            int direction = elem[0];
            int amount = elem[1] % len;
            // 左移
            if (direction == 0) {
                s1 = s.substr(0, amount);
                s2 = s.substr(amount);
            } 
            // 右移
            else {
                s1 = s.substr(0, len - amount);
                s2 = s.substr(len - amount);
            }
            s = s2 + s1;
        }
        return s;
    }
};