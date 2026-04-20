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
    static bool comp(Interval d1,Interval d2) {
        return d1.end < d2.end;
    }
    int maxMeetings(vector<Interval>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        sort(arr.begin(),arr.end(),comp);
        int cnt = 1 ; 
        int freetm = arr[0].end;
        for(int i=1;i<n;i++) {
            if(arr[i].start >= freetm) {
                cnt+=1;
                freetm = arr[i].end;
            }
        }
        return cnt;
    }
public:
    bool canAttendMeetings(vector<Interval>& arr) {
        int meet = maxMeetings(arr);
        return meet == arr.size();
    }
};
