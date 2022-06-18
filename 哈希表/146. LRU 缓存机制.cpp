#include <iostream>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    DLinkedNode* prev;
    DLinkedNode* next;
    int key, val;
    DLinkedNode() : key(0), val(0), prev(nullptr), next(nullptr){};
    DLinkedNode(int _key, int _val)
        : key(_key), val(_val), prev(nullptr), next(nullptr){};
};
class LRUCache {
   public:
    //默认是private
    LRUCache(int cap) {
        head = new DLinkedNode();
        tail = new DLinkedNode();  //需要了解一下new的具体原理和delete的具体原理
        head->next = tail;
        tail->prev = head;
        this->capcity = cap;
        this->size = 0;
    }
    void put(int key, int val) {
        //首先先查找hash表
        if (!hash_map.count(key)) {
            //表示没有
            DLinkedNode* node = new DLinkedNode(key, val);
            hash_map[key] = node;  //注意要添加入缓存中
            addHead(node);
            if (this->size == this->capcity) {
                node = DeleteTailNode();
                hash_map.erase(node->key);
                delete node;  // delete关键字
            } else {
                this->size++;
            }
        } else {
            DLinkedNode* node = hash_map[key];
            node->val = val;
            removeNode(node);
            addHead(node);
        }
    }
    int get(int key) {
        if (!hash_map.count(key))
            return -1;
        DLinkedNode* node = hash_map[key];
        removeNode(node);
        addHead(node);
        return node->val;
    }
    void addHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    DLinkedNode* DeleteTailNode() {
        DLinkedNode* node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        return node;
    }
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

   private:
    DLinkedNode* head;
    DLinkedNode* tail;  //使用表头节点和表尾节点,相当于哨兵
    unordered_map<int, DLinkedNode*> hash_map;
    int size;
    int capcity;
};