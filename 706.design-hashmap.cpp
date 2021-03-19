/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
struct MyListNode{
	int key; 
	int val;
	MyListNode* next;
	MyListNode() : key(-1), val(-1), next(nullptr) {}
	MyListNode(int _key, int _val) : key(_key), val(_val), next(nullptr) {}
};
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
			data.resize(N);
    }
		auto getHashValue(int key){
			return key % N;
		}

    /** value will always be non-negative. */
    void put(int key, int value) {
			auto hashkey = getHashValue(key);
			auto& head = data[hashkey];
			if(head==nullptr){
				head = new MyListNode(key, value);
				return;
			}
			auto p = head;
			auto tail = p;
			// add value which has been added
			while(p != nullptr){
				if(p->key == key){
					p->val = value;
					return;
				}
				tail = p;
				p = p->next;
			}
			// add new value
			tail->next = new MyListNode(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
			auto hashkey = getHashValue(key);
			auto& head = data[hashkey];
			if(head==nullptr){
				return -1;
			}
			auto p = head;
			while(p != nullptr){
				if(p->key == key){
					return p->val;
				}
				p = p->next;
			}
			return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
			auto hashkey = getHashValue(key);
			auto& head = data[hashkey];
			if(head==nullptr){
				return;
			}
			auto p = head;
			MyListNode* prev = nullptr;
			while(p != nullptr){
				if(p->key == key){
					// remove head
					if(prev == nullptr){
						auto dummy = head;
						head = head->next; // nullptr
						dummy->next = nullptr;
						delete dummy;
					}
					else{
						prev->next = p->next;
						p->next = nullptr;
						delete p;
					}
					return;
				}
				prev = p;
				p = p->next;
			}
    }
private:
		const int N = 1001;
		vector<MyListNode*> data;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
