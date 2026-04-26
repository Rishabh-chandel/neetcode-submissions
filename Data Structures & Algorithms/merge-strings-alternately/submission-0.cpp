class Solution {
public:
    string mergeAlternately(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        string ans;
        int i = 0 , j = 0;
        bool fststr = 1;
        while(i < n && j < m) {
            if(fststr) ans+=s1[i++];
            else ans+=s2[j++];
            fststr = !fststr;
        }
        while(i < n) {
            ans+=s1[i++];
        }
        while(j < m) {
            ans+=s2[j++];
        }
        return ans;
    }
};