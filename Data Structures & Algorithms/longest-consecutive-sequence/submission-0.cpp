class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(),arr.end());
        int ans = 0;
        for(int num : st) {
            if(!st.count(num-1)) {
                int len = 1;
                while(st.count(num+1)) {
                    len++;
                    num++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
