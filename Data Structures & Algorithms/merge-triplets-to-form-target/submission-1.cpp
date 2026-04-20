class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& arr, vector<int>& t) {
        int val1 = -1 , val2 = -1 , val3 = -1;
        for(auto it : arr) {
            int x = it[0] , y = it[1] , z = it[2];
            int tx = t[0] , ty = t[1] , tz = t[2];
            if(x > tx || y > ty || z > tz) continue;
            if(x == tx && y == ty && z == tz) return 1;
            if(x == tx) val1 = x;
            if(y == ty) val2 = y;
            if(z == tz) val3 = z;
        }
        return (val1 != -1) && (val2 != -1) && (val3 != -1);
    }
};
