class CountSquares {
public:
    map<int,map<int,int>> mp;
    CountSquares() {}
    
    void add(vector<int> p) {
        mp[p[0]][p[1]]++;
    }
    
    int count(vector<int> p) {
        int ans = 0;
        int x = p[0] , y = p[1];
        for(auto [y1,cnt] : mp[x]) {
            int sz = abs(y-y1);
            if(sz == 0) continue;
            int x1 = x-sz , x2 = x+sz;
            int c1 = cnt*mp[x1][y]*mp[x1][y1];
            int c2 = cnt*mp[x2][y]*mp[x2][y1];
            ans+=(c1+c2);
        }
        return ans;
    }
};
