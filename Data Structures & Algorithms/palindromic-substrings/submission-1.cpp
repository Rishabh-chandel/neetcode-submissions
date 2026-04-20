class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int idx=0;idx<n;idx++) {
            // odd len
            int i = idx , j = idx;
            while(i >= 0 && j < n) {
                if(s[i] != s[j]) break;
                if(s[i] == s[j]) ans++;
                i-- , j++;
            }
            // even len
            i = idx , j = idx+1;
            while(i >= 0 && j < n) {
                if(s[i] != s[j]) break;
                if(s[i] == s[j]) ans++;
                i-- , j++;
            }
        }
        return ans;
    }
};
