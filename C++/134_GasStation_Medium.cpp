/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique. 

Tags: Greedy
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0;
        int gasAll = 0, costAll = 0, tank = 0;
        
        for(int i = 0; i < gas.size(); ++i) {
            gasAll  += gas[i];
            costAll += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0) {
                start = i + 1;
                tank  = 0;
            }
        }
        return (gasAll < costAll) ? -1 : start;
    }
};
