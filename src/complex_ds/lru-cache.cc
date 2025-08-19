struct LruNode {
    int key{0};
    int val{0};
    LruNode* prev{nullptr};
    LruNode* next{nullptr};

    LruNode() = default;
    LruNode(int key, int val) : key(key), val(val) {
        prev = next = this;
    }
};

class LRUCache {
  private:
    int capacity_;
    LruNode lru_list_head_;
    std::unordered_map<int, std::unique_ptr<LruNode>> kv_cache_;

  public:
    explicit LRUCache(int capacity) {
        assert(capacity > 0);
        capacity_ = capacity;
        lru_list_head_.next = &lru_list_head_;
        lru_list_head_.prev = &lru_list_head_;
    }
    
    void PromoteNodeToHead(LruNode* node) {
        // 将node从原来的位置摘出来
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 调整node自身的指针
        node->prev = &lru_list_head_;
        node->next = lru_list_head_.next;
        // 调整原先的首个节点的prev指针
        lru_list_head_.next->prev = node;
        // 调整头节点的next指针
        lru_list_head_.next = node;
    }

    int get(int key) {
        if (kv_cache_.contains(key)) {
            // 将key对应的LruNode提升到链表的首端
            PromoteNodeToHead(kv_cache_[key].get());
            // 返回结果
            return kv_cache_[key]->val;
        }
        return -1;
    }
    
    // 情况一 缓存中已有key
    // 情况二 缓存中没有key，缓存未满
    // 情况三 缓存中没有key，缓存已满
    void put(int key, int value) {
        // 情况一
        if (kv_cache_.contains(key)) {
            // 将key对应的LruNode提升到链表的首端
            PromoteNodeToHead(kv_cache_[key].get());
            // 更新缓存中的内容
            kv_cache_[key]->val = value;
            return;
        }

        // 情况二
        if (kv_cache_.size() < capacity_) {
            // 为新的node分配内存
            kv_cache_[key] = std::make_unique<LruNode>(key, value);
            // 将新的node插入到链表首端
            PromoteNodeToHead(kv_cache_[key].get());
            return;
        }

        // 情况三
        LruNode* raw_tail_node = lru_list_head_.prev;
        if (raw_tail_node) {
            int old_key = raw_tail_node->key;
            std::unique_ptr<LruNode> free_tail_node = std::move(kv_cache_[old_key]);
            assert(raw_tail_node == free_tail_node.get());
            // 将链表末尾的key从缓存中剔除出去
            kv_cache_.erase(old_key);
            // 复用tail_node，用来存新的key和value
            free_tail_node->key = key;
            free_tail_node->val = value;
            // 此时tail_node已经旧瓶装新酒了，让我们在缓存中用新的key来索引它，
            // 并且将它提升到链表的头部。
            kv_cache_[key] = std::move(free_tail_node);
            PromoteNodeToHead(kv_cache_[key].get());
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */