class TimeMap {
public:
    map<string,vector<pair<int,string>>> mp;
    TimeMap() {}
    
    void set(string key, string val, int tm) {
        mp[key].push_back({tm,val});
    }
    
    string get(string key, int tm) {
        if(!mp.count(key)) return "";
        auto& it = mp[key];
        int l = 0 , r = it.size()-1;
        string ans;
        while(l <= r) {
            int mid = (l+r)/2;
            if(it[mid].first <= tm) {
                ans = it[mid].second;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};
