class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> letter_bucket;
        for (char ch : magazine) {
            ++letter_bucket[ch];
        }
        for (char ch : ransomNote) {
            if (!letter_bucket.contains(ch)) {
                return false;
            }
            --letter_bucket[ch];
            if (letter_bucket[ch] == 0) {
                letter_bucket.erase(ch);
            }
        }
        return true;
    }
};