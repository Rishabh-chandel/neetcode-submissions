class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int i = 0 , j = 0;
        int ans = 0;
        while(j < n) {
            if(mp.count(s[j]) && mp[s[j]] >= i) {
                i = mp[s[j]]+1;
            }
            mp[s[j]] = j;
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
