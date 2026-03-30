class LRUCache {
public:
    vector<pair<int,int>>cache;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // if we found key then simply erase from that position nd put in the end
        // as to make it most recent used 
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                pair<int,int>temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if key already exist update the value nd move it to the end
        for(int i = 0; i < cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return;
            }
        }
        // if cache is full remove the first element as it is the least recent used.
        // after that add the elem
        if(cache.size() == capacity){
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
    }
};
