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
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i] == '0') dp[i] = 0;
            else {
                int one = dp[i+1];
                int two = 0;
                if(i < n-1) {
                    string str = "";
                    str.push_back(s[i]);
                    str.push_back(s[i+1]);
                    int num2 = stoi(str);
                    if(num2 <= 26) two = dp[i+2];
                }
                dp[i] = one+two;
            }
        }
        return dp[0];
    }
};
