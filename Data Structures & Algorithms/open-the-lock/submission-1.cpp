class Solution {
public:
    int openLock(vector<string>& arr, string s) {
        int n = size(arr);
        queue<pair<int,string>> q;   //{steps,str}
        q.push({0,"0000"});
        unordered_set<string> st(arr.begin(),arr.end());
        if(st.count("0000")) return -1;
        set<string> vis;
        vis.insert("0000");
        while(!q.empty()) {
            auto [steps,str] = q.front();
            q.pop();
            if(str == s) return steps;
            for(int i=0;i<4;i++) { 
                int curr = str[i]-'0';
                int nxt = (curr+1)%10;
                int prev = ((curr-1)+10)%10;
                string s1 = str , s2 = str;
                s1[i] = nxt+'0';
                s2[i] = prev+'0';
                if(!st.count(s1) && !vis.count(s1)) {
                    q.push({steps+1,s1});
                    vis.insert(s1);
                }
                if(!st.count(s2) && !vis.count(s2)) {
                    q.push({steps+1,s2});
                    vis.insert(s2);
                }
            }
        }
        return -1;
    }
};