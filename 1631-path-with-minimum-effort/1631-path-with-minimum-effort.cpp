class Solution {
public:
    static bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
        return a.first>b.first;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(&cmp)> q(cmp);
        q.push({0,{0,0}});
        cost[0][0]=0;
        // well it could be further optimise using pq.
        // le me do it.
        while(!q.empty()){
            int curr_cost=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            // first case.
            if(j+1<m){
                int diff1=abs(arr[i][j]-arr[i][j+1]);
                int x1=max(cost[i][j],diff1);
                if(x1<cost[i][j+1]){
                    q.push({x1,{i,j+1}});
                    cost[i][j+1]=x1;
                }
            }
            if(i+1<n){
                int diff2=abs(arr[i][j]-arr[i+1][j]);
                int x2 = max(cost[i][j],diff2);
                if(x2<cost[i+1][j]){
                    q.push({x2,{i+1,j}});
                    cost[i+1][j]=x2;
                }
            }
            if(i-1>=0){
                int diff3=abs(arr[i][j]-arr[i-1][j]);
                int x3=max(cost[i][j],diff3);
                 if(x3<cost[i-1][j]){
                    q.push({x3,{i-1,j}});
                     cost[i-1][j]=x3;
                }
            }
            if(j-1>=0){
                int diff4=abs(arr[i][j]-arr[i][j-1]);
                int x4=max(cost[i][j],diff4);
                  if(x4<cost[i][j-1]){
                    q.push({x4,{i,j-1}});
                      cost[i][j-1]=x4;
                }
            }
        }
        return cost[n-1][m-1];
    }
};