class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0 , j = n-1;
        int l = 0 , h = n-1;
        int cnt1 = 0 , cnt2 = 0;
        while(i <= j) {
            if(s[i] == s[j]) {
                i++ , j--;
            }
            else {
                cnt1++;
                if(cnt1 > 1) break;
                i++;
            }
        }
        while(l <= h) {
            if(s[l] == s[h]) l++, h--;
            else {
                cnt2++;
                if(cnt2 > 1) break;
                h--;
            }
        }
        return cnt1 == 0 || cnt1 == 1 || cnt2 == 0 || cnt2 == 1; 
    }
};