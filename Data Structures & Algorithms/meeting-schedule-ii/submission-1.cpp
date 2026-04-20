/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
private:
    static bool comp(pair<int,int>& d1,pair<int,int>& d2) {
        return d1.first < d2.first;
    }
public:
    int minMeetingRooms(vector<Interval>& arr) {
        int n = arr.size();
        vector<pair<int,int>> sweep;
        int maxi = 0 , curr = 0;
        for(int i=0;i<n;i++) {
            int st = arr[i].start , ed = arr[i].end;
            sweep.push_back({st,+1});
            sweep.push_back({ed,-1});
        }
        sort(sweep.begin(),sweep.end());
        for(int i=0;i<sweep.size();i++) {
            curr+=(sweep[i].second);
            maxi = max(maxi,curr);
        }
        return maxi;
    }
};
