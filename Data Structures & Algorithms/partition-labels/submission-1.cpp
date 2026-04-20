class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> hash(26);
        for(int i=0;i<n;i++) hash[s[i]-'a'] = i;
        vector<int> ans;
        int st = 0 , ed = 0;
        for(int i=0;i<n;i++) {
            ed = max(ed,hash[s[i]-'a']);
            if(i == ed) {
                ans.push_back(ed-st+1);
                st = i+1;
            }
        }
        return ans;
    }
};
