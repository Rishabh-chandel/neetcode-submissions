class Solution {
private:
    int f(int idx,string s,vector<int>& dp) {
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int one = f(idx+1,s,dp);
        int two = 0;
        if(idx < s.size()-1) {
            string str = "";
            str.push_back(s[idx]);
            str.push_back(s[idx+1]);
            int num2 = stoi(str);
            if(num2 <= 26) two += f(idx+2,s,dp);
        }
        return dp[idx] = one+two;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }
};
