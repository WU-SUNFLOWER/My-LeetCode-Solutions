class Solution {
  private:
    enum TokenType {
        kWord,
        kLParent,
        kRParent,
        kNumber
    };

    struct Token {
        std::string contain;
        TokenType type;
        Token(std::string contain, TokenType type)
         : contain(contain), type(type) {}
    };

  private:
    std::vector<Token> tokens_;
    int pos_{0};

  public:
    const Token& PeekToken() { return tokens_[pos_]; }

    Token& ConsumeToken(TokenType type) {
        assert(tokens_[pos_].type == type); 
        return tokens_[pos_++]; 
    }

    bool HasMoreToken() { return pos_ < tokens_.size(); }

    std::string ParseNumberExpression() {
        const auto& token = ConsumeToken(kNumber);
        int number = std::stoi(token.contain);
        
        std::string result = "";

        ConsumeToken(kLParent);
        {
            std::string sub_result = ParseProgram();
            while (number-- > 0) {
                result += sub_result;
            }
        }
        ConsumeToken(kRParent);

        return result;
    }

    std::string ParseExpression(bool* finished) {
        std::string result;
        const auto& token = PeekToken();
        switch (token.type) {
            case kWord:
                result += token.contain;
                ConsumeToken(kWord);
                break;
            case kNumber:
                result += ParseNumberExpression();
                break;
            case kRParent:
                *finished = true;
                break;
            default:
                assert(0);
        }
        return result;
    }

    std::string ParseProgram() {
        std::string result;
        bool finished = false;
        while (HasMoreToken() && !finished) {
            result += ParseExpression(&finished);
        }
        return result;
    }

    // 分词
    void SplitToTokens(const std::string& s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] == '[') {
                tokens_.emplace_back("", kLParent);
                ++i;
            } else if (s[i] == ']') {
                tokens_.emplace_back("", kRParent);
                ++i;
            } else if ('0' <= s[i] && s[i] <= '9') {
                std::string contain;
                while ('0' <= s[i] && s[i] <= '9') {
                    contain.push_back(s[i]);
                    ++i;
                }
                tokens_.emplace_back(std::move(contain), kNumber);
            } else if ('a' <= s[i] && s[i] <= 'z') {
                std::string contain;
                while ('a' <= s[i] && s[i] <= 'z') {
                    contain.push_back(s[i]);
                    ++i;
                }
                tokens_.emplace_back(std::move(contain), kWord);
            } else {
                assert(0);
            }
        }
    }

    std::string decodeString(std::string s) {
        SplitToTokens(s);
        return ParseProgram();
    }
};