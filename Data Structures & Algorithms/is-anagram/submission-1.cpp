class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size() , m = t.size();
        vector<int> hash1(26,0) , hash2(26,0);
        for(char ch : s) {
            int idx = ch - 'a';
            hash1[idx]++;
        }
        for(char ch : t) {
            int idx = ch - 'a';
            hash2[idx]++;
        }
        for(int i=0;i<26;i++) {
            if(hash1[i] != hash2[i]) return 0;
        }
        return 1;
    }
};
