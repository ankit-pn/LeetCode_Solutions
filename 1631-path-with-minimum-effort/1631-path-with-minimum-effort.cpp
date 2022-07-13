class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        cost[0][0]=0;
        while(!q.empty()){
            int curr_cost=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            // first case.
            if(j+1<m){
                int diff1=abs(arr[i][j]-arr[i][j+1]);
                int x1=max(cost[i][j],diff1);
                if(x1<cost[i][j+1]){
                    q.push({diff1,{i,j+1}});
                    cost[i][j+1]=x1;
                }
            }
            if(i+1<n){
                int diff2=abs(arr[i][j]-arr[i+1][j]);
                int x2 = max(cost[i][j],diff2);
                if(x2<cost[i+1][j]){
                    q.push({diff2,{i+1,j}});
                    cost[i+1][j]=x2;
                }
            }
            if(i-1>=0){
                int diff3=abs(arr[i][j]-arr[i-1][j]);
                int x3=max(cost[i][j],diff3);
                 if(x3<cost[i-1][j]){
                    q.push({diff3,{i-1,j}});
                     cost[i-1][j]=x3;
                }
            }
            if(j-1>=0){
                int diff4=abs(arr[i][j]-arr[i][j-1]);
                int x4=max(cost[i][j],diff4);
                  if(x4<cost[i][j-1]){
                    q.push({diff4,{i,j-1}});
                      cost[i][j-1]=x4;
                }
            }
        }
        return cost[n-1][m-1];
    }
};