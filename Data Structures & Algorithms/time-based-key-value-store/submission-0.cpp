class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value}) ;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }        
         string res = "";

        // scan through all timestamps for this key
        for (auto &p : mp[key]) {
            if (p.first <= timestamp) {
                res = p.second;   // keep updating
            } else {
                break;            // timestamps are increasing
            }
        }
        return res;

    }
};
