class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int idx=0;idx<n;idx++) {
            // odd len
            int i = idx , j = idx;
            int cnt = 0;
            while(i >= 0 && j < n) {
                if(s[i] != s[j]) break;
                if(s[i] == s[j]) {
                    cnt++;
                    if((j-i+1) > ans.size()) {
                        ans = s.substr(i,j-i+1);
                    }
                }
                i-- , j++;
            }
            // even len
            i = idx , j = idx+1;
            cnt = 0;
            while(i >= 0 && j < n) {
                if(s[i] != s[j]) break;
                if(s[i] == s[j]) {
                    cnt++;
                    if((j-i+1) > ans.size()) {
                        ans = s.substr(i,j-i+1);
                    }
                }
                i-- , j++;
            }
        }
        return ans;
    }
};
