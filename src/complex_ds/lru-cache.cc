class LRUCache;

class CacheNode {
private:
    int key_ { 0 };
    int value_ { 0 };

    CacheNode* prev { nullptr };
    CacheNode* next { nullptr };

    friend class LRUCache;

public:
    CacheNode() {}
    CacheNode(int key, int value) : key_(key), value_(value) {}
};

class LRUCache {
private:
    int size_ { 0 };
    int capacity_;
    std::unordered_map<int, CacheNode*> cache_;

    CacheNode head_;
    CacheNode tail_;

public:
    LRUCache(int capacity) : capacity_(capacity) {
        head_.next = &tail_;
        head_.prev = &tail_;
        tail_.next = &head_;
        tail_.prev = &head_;
    }
    
    int get(int key) {
        if (cache_.contains(key)) {
            CacheNode* cache_node = cache_.at(key);
            MoveToHead(cache_node);
            return cache_node->value_;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 如果目标键已存在在缓存中，则直接更新
        CacheNode* cache_node = nullptr;
        if (cache_.contains(key)) {
            cache_node = cache_.at(key);
            cache_node->value_ = value;
            // 别忘了将当前节点提升到链表头部
            MoveToHead(cache_node);
            return;
        }
        // 否则就要新建缓存项
        cache_node = new CacheNode(key, value);
        // 将缓存项存入链表头部
        MoveToHead(cache_node);
        // 将缓存项存入hashmap当中
        cache_[key] = cache_node;
        // 更新缓存大小
        // 如果缓存大小超过了容量，就要淘汰掉活跃度最低的缓存项
        if (++size_ > capacity_) {
            RemoveFromTail();
            --size_;
        }
    }

    void MoveToHead(CacheNode* node) {
        CacheNode* prev = node->prev;
        CacheNode* next = node->next;
        // 将node从原先位置摘除
        if (prev) prev->next = next;
        if (next) next->prev = prev;
        // 将node与新的前驱、后继节点连接
        node->next = head_.next;
        node->prev = head_.next->prev;
        // 修改node现在的前驱和后继的指针
        head_.next->prev = node;
        head_.next = node;
    }

    void RemoveFromTail() {
        CacheNode* target = tail_.prev;
        // 将target从hashmap中摘除
        cache_.erase(target->key_);
        // 将target从原先的位置摘除
        CacheNode* prev = target->prev;
        CacheNode* next = target->next;
        prev->next = next;
        next->prev = prev;
        //std::cout << "淘汰{" << target->key_ << ", " << target->value_ << std::endl;
        // 释放target对象
        delete target;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */