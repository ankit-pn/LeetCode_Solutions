class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       sort(costs.begin(),costs.end());
        int i=0,n=costs.size();
        while(i<n && coins>=0){
            coins-=costs[i];
            i++;
        }
        return coins>=0 ? n : i-1;
    }
};