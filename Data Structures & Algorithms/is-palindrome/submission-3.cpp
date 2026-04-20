class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int st = 0 , ed = n-1;
        while(st < ed) {
            if(isalnum(s[st]) && isalnum(s[ed])) {
                char s_ch = tolower(s[st]);
                char e_ch = tolower(s[ed]);
                if(s_ch != e_ch) return false;
                st++ , ed--;
            }
            else {
                if(!isalnum(s[st])) st++;
                if(!isalnum(s[ed])) ed--;
            }
        }
        return true;
    }
};
