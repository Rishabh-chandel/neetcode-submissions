class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        if(n > m) return false;
        map<char,int> mp1 , mp2;
        for(char ch : s1) mp1[ch]++;
        int i = 0;
        for(int j = 0; j < m; j++) {
            mp2[s2[j]]++;
            if(j-i+1 > n) {
                mp2[s2[i]]--;
                if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                i++;
            }
            if(mp1 == mp2) return true;
        }
        return false;
    }
};
