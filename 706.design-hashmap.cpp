/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
			hashtable = vector<pair<int, int>>(N, {-1, -1});
    }
		auto getHashValue(int key){
			int k = key % N;
			while(hashtable[k].first != key && hashtable[k].first != -1){
				k = (k + 1) % N;
			}
			return k; 
		}

    /** value will always be non-negative. */
    void put(int key, int value) {
			auto k = getHashValue(key);
			hashtable[k] = {key, value};
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
			auto k = getHashValue(key);
			if(hashtable[k].first == -1){
				return -1;
			}
			return hashtable[k].second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
			auto k = getHashValue(key);
			if(hashtable[k].first != -1){
				hashtable[k].first = -2;
			}
    }
private:
		const static int N = 20011;
		vector<pair<int, int>> hashtable;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
