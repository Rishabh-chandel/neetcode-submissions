class Solution {
private:
    struct data {
        int st , ed , pos;
        data() : st(0), ed(0), pos(0) {}
    };
    static bool comp(data d1,data d2) {
        return d1.ed < d2.ed;
    }
    int maxMeetings(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        vector<data> ans(n);
        for(int i=0;i<n;i++) {
            ans[i].st = arr[i][0];
            ans[i].ed = arr[i][1];
            ans[i].pos = i+1;
        }
        sort(ans.begin(),ans.end(),comp);
        vector<int> ds;
        int cnt = 1 ; 
        int freetm = ans[0].ed;
        ds.push_back(ans[0].pos);
        for(int i=1;i<n;i++) {
            if(ans[i].st >= freetm) {
                cnt+=1;
                freetm = ans[i].ed;
                ds.push_back(ans[i].pos);
            }
        }
        return cnt;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int meet = maxMeetings(arr);
        return arr.size() - meet;
    }
};
