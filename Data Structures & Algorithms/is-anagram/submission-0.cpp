class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++) {
            hash1[s[i]-'a']++;
            hash2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(hash1[i] != hash2[i]) return false;
        }
        return true;
    }
};
