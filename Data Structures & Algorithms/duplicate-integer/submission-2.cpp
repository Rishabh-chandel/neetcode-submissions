class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(),arr.end());
        return st.size() != n; 
    }
};