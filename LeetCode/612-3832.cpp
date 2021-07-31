class MapSum {
public:
    /** Initialize your data structure here. */
    map<string, int> mp;
    MapSum() {
        mp.clear();
    }

    void insert(string key, int val) {
        if (mp.find(key) == mp.end()) {
            mp.insert({key, val});
        } else {
            mp[key] = val;
        }
    }

    int sum(string prefix) {
        int total = 0;
        for (auto i: mp) {
            if (i.first.length() >= prefix.length() && i.first.substr(0, prefix.length()) == prefix) {
                total += i.second;
            }
        }
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
