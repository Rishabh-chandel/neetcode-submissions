class Solution {
private:
    int n;
    bool f(int idx,int cnt,string s,vector<vector<int>>& dp) {
        if(cnt < 0) return false;
        if(idx == n) return (cnt == 0);
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        if(s[idx] == '(') return f(idx+1,cnt+1,s,dp);
        if(s[idx] == ')') return f(idx+1,cnt-1,s,dp);
        return dp[idx][cnt] = f(idx+1,cnt+1,s,dp) || f(idx+1,cnt-1,s,dp) || f(idx+1,cnt,s,dp);
    }
public:
    bool checkValidString(string s) {
        n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,s,dp);
    }
};
