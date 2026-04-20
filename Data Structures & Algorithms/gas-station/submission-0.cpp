class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int tank = 0;
        int st = 0;
        for(int i=0;i<n;i++) {
            int dif = gas[i] - cost[i];
            tank+=dif;
            total+=dif;
            if(tank < 0) {
                st = i+1;
                tank = 0;
            }
        }
        return (total >= 0) ? st : -1;
    }
};