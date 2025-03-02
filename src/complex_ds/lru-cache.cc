struct CacheNode {
    int key_;
    int val_;

    struct CacheNode* prev = nullptr;
    struct CacheNode* next = nullptr;

    CacheNode() : key_(-1), val_(-1) {}
    CacheNode(int key, int val) : key_(key), val_(val) {}
};

class LRUCache {
private:
    int size_;
    int capacity_;

    struct CacheNode head;  // 链表头部哨兵

    std::unordered_map<int, struct CacheNode*> cache_map_;

public:
    LRUCache(int capacity)
    : size_(0), capacity_(capacity) {
        head.next = &head;
        head.prev = &head;
    }
    
    int get(int key) {
        if (cache_map_.contains(key)) {
            struct CacheNode* node = cache_map_.at(key);
            // 将节点移动到链表头部
            MoveNodeToListHead(node);
            // 返回节点值
            return node->val_;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // 如果目标节点存在
        if (cache_map_.contains(key)) {
            struct CacheNode* node = cache_map_.at(key);
            // 将节点移动到链表头部
            MoveNodeToListHead(node);
            // 设置节点的值
            node->val_ = value;
        }
        // 如果目标节点不存在
        else {
            // 如果LRU缓存已满，则淘汰链表尾部的元素
            if (size_ == capacity_) {
                struct CacheNode* tail_node = RemoveTailNode();
                cache_map_.erase(tail_node->key_);
                delete tail_node;
            } else {
                ++size_;
            }
            // 创建新节点，并插入到链表头部
            struct CacheNode* new_node = new CacheNode(key, value);
            InsertNodeToList(new_node);
            // 更新map
            cache_map_[key] = new_node;
        }
    }

private:
    struct CacheNode* RemoveTailNode() {
        auto tail_node = head.prev;
        tail_node->prev->next = tail_node->next;
        tail_node->next->prev = tail_node->prev;
        return tail_node;
    }

    void InsertNodeToList(struct CacheNode* node) {
        auto new_next = head.next;
        head.next = node;
        node->prev = &head;
        node->next = new_next;
        new_next->prev = node;
    }

    void MoveNodeToListHead(struct CacheNode* node) {
        // 连接node原先的前驱和后继
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // 将node插入到head和head.next之间
        InsertNodeToList(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */