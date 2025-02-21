class Solution {
public:
    string simplifyPath(string path) {
        std::vector<std::string> my_stack;
        std::string tmp;
        for (int i = 0; i <= path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (tmp.size() > 0) {
                    if (tmp == ".") {
                        tmp.resize(0);
                    }
                    else if (tmp == "..") {
                        if (!my_stack.empty()) {
                            my_stack.pop_back();
                        }
                        tmp.resize(0);
                    }
                    else {
                        my_stack.push_back(std::move(tmp));
                        tmp.resize(0);                        
                    }
                }
            } else {
                tmp.push_back(path[i]);
            }
        }
        
        std::string ans;
        for (int i = 0; i < my_stack.size(); ++i) {
            ans += "/" + my_stack[i];
        }

        return ans.size() > 0 ? ans : "/";
    }
};