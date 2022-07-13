class Solution {
public:
    static bool cmp1(vector<int>&a,vector<int>&b){
        return a[0]-a[1]<b[0]-b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0,c=0;
        int n=costs.size()/2;
        sort(costs.begin(),costs.end(),cmp1);
        for(auto it:costs){
            if(c<n)
                sum+=it[0];
            else
                sum+=it[1];
            c++;
        }
        return sum;
   
    }
};