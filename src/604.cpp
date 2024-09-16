#define isAplpha(ch) ('a' <= (ch) && (ch) <= 'z' || 'A' <= (ch) && (ch) <= 'Z')
#define isNumber(ch) ('0' <= (ch) && (ch) <= '9') 
#define toNumber(ch) ((int)((ch) - '0'))

class StringIterator {
private:
    int pos = 0;
    int step = 0;
    int count = 0;
    const std::string str;
public:
    StringIterator(std::string& compressedString)
     : str(compressedString), pos(0), step(0), count(0)
    {

    }
    
    char next() {
        if (!hasNext()) return ' ';
        assert(count >= 0);
        if (count == 0) {
            pos += step;
            step = 0;
            assert(isAplpha(str[pos]));
            for (int i = pos + 1; i < str.length(); ++i) {
                ++step;
                if (!isNumber(str[i])) break;
                count = 10 * count + toNumber(str[i]);
            }
        }
        --count;
        return str[pos];
    }
    
    bool hasNext() {
        return count > 0 || pos + step + 1 < str.length();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */