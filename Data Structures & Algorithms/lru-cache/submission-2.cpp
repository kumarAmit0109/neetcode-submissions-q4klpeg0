class LRUCache {
public:
    // map stores <key, <value, address of that key in list>>
    unordered_map<int, pair<int, list<int>::iterator>>cache;
    list<int>order;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;    
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        order.erase(cache[key].second);
        order.push_back(key);
        // Update the iterator for key to point to its new position at the back of the list.
        cache[key].second = --order.end();
        return cache[key].first;    
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            order.erase(cache[key].second);
        }else if(cache.size() == capacity){
            // remove the least recently used key
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }

        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
