class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int current_gas = 0;
        int start_station = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total_gas += diff;
            current_gas += diff;

            if (current_gas < 0) {
                start_station = i + 1;
                current_gas = 0;
            }
        }

        return total_gas >= 0 ? start_station : -1;
    }
};