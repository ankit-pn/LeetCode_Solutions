class Solution {
public:
    static bool cmp(pair<double,vector<int>>&a,pair<double,vector<int>>&b){
        return a.first>b.first;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,decltype(&cmp)> pq(cmp);
        for(auto &it:points){
            long long a=(it[0]*it[0])+(it[1]*it[1]);
            double temp=sqrt(a);
            pq.push({temp,it});
        }
        int c=0;
        vector<vector<int>> ans;
        while(c!=k){
            ans.push_back(pq.top().second);
            pq.pop();
            c++;
        }
        return ans;
    }
};