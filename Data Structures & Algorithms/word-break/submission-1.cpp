class Solution {
private:
    int n,m;
    bool f(int idx,string s,vector<string>& arr,vector<int>& dp) {
        if(idx >= s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        for(string str : arr) {
            if(idx+str.size() <= s.size() && s.substr(idx,str.size()) == str) {
                if(f(idx+str.size(),s,arr,dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& arr) {
        n = s.size() , m = arr.size();
        vector<int> dp(n,-1);
        return f(0,s,arr,dp);
    }
};
