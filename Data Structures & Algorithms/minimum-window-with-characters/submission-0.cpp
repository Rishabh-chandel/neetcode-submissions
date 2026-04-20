class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        int mini = 1e9 , idx = -1;
        for(int i=0;i<n;i++) {
            vector<int> hash(256,0);
            for(char ch : t) hash[ch]++;
            int cnt = 0;
            for(int j=i;j<n;j++) {
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;
                if(cnt == m) {
                    if(j-i+1 < mini) {
                        mini = j-i+1;
                        idx = i;
                    }
                    break;
                }
            }  
        }
        return (idx == -1) ? "" : s.substr(idx, mini);
    }
};
