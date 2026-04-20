class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        int mini = 1e9 , idx = -1;
        int i = 0 , j = 0 , cnt = 0;
        unordered_map<char,int> mp;
        for(char ch : t) mp[ch]++;
        while(j < n) {
            if(mp[s[j]] > 0) cnt++;
            mp[s[j]]--;
            while(cnt == m) {
                if((j-i+1) < mini) {
                    mini = j-i+1;
                    idx = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        } 
        return (idx == -1) ? "" : s.substr(idx, mini);
    }
};
