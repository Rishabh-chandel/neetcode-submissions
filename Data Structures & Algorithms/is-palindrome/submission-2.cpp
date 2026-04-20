class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0 , ed = s.size()-1;
        while(st < ed) {
            if(isalnum(s[st]) && isalnum(s[ed])) {
                char stchar = tolower(s[st]);
                char edchar = tolower(s[ed]);
                if(stchar != edchar) return false;
            }
            if(isalnum(s[st]) && isalnum(s[ed])) {
                st++,ed--;
            }
            else {
                if(!isalnum(s[st])) st++;
                if(!isalnum(s[ed])) ed--;
            }
        }
        return true;
    }
};
