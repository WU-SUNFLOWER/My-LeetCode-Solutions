class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        // build my map
        std::map<std::string, std::set<std::string>> convert;
        for (auto& pair: similarPairs) {
            convert[pair[0]].insert(pair[1]);
            convert[pair[1]].insert(pair[0]);
        }
        // check
        for (int i = 0; i < sentence1.size(); ++i) {
            std::string& s1 = sentence1[i];
            std::string& s2 = sentence2[i];
            if (
                s1 != s2 
                && convert[s1].find(s2) == convert[s1].end()
            ) {
                return false;
            }
        }
        return true;
    }
};