class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int map[255];
        for (int i = 0; i < keyboard.length(); ++i) {
            map[keyboard[i]] = i;
        }
        int pos = 0;
        int ans = 0;
        for (char ch: word) {
            int newPos = map[ch];
            ans += std::abs(newPos - pos);
            pos = newPos;
        }
        return ans;
    }
};