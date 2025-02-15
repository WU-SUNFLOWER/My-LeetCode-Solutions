class RandomizedSet {
private:
    // <value, index_in_values>
    std::unordered_map<int, int> index_map_;
    std::vector<int> nums_;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (index_map_.contains(val)) {
            return false;
        }
        nums_.push_back(val);
        index_map_[val] = nums_.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!index_map_.contains(val)) {
            return false;
        }
        // 确定val在nums_当中的下标位置idx
        int idx = index_map_[val];
        // 将nums_当中的最后一项移动到idx处
        nums_[idx] = nums_.back();
        // 更新index_map_
        index_map_[nums_[idx]] = idx;
        // 将nums_的大小-1
        nums_.pop_back();
        // 摘除val在index_map_当中的记录
        index_map_.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums_[std::rand() % nums_.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */