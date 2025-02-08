class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return { };
        }

        // <char, how many this char in current window>
        std::unordered_map<char, int> target;
        std::unordered_map<char, int> window;

        // initialize target window
        for (char ch : p) {
            ++target[ch];
        }

        // initialize current window
        for (int i = 0; i < p.size(); ++i) {
            ++window[s[i]];
        }

        std::vector<int> answer;
        for (int i = 0; i <= s.size() - p.size(); ++i) {
            if (window == target) {
                answer.push_back(i);
            }

            if (i == s.size() - p.size()) {
                break;
            }

            --window[s[i]];
            if (window[s[i]] == 0) {
                window.erase(s[i]);
            } 
            ++window[s[i + p.size()]];
        }

        return answer;
    }
};