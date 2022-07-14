class Solution {
public:
    int swimInWater(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=arr[0][0];
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first,j=it.second;
            if(i+1<n){
                int x1=max(cost[i][j],arr[i+1][j]);
                if(x1<cost[i+1][j]){
                cost[i+1][j]=x1;
                    q.push({i+1,j});
                }
            }
            if(i>0){
                int x2=max(cost[i][j],arr[i-1][j]);
                if(x2<cost[i-1][j]){
                cost[i-1][j]=x2;
                    q.push({i-1,j});
                }
            }
             if(j+1<m){
                int x3=max(cost[i][j],arr[i][j+1]);
                if(x3<cost[i][j+1]){
                cost[i][j+1]=x3;
                    q.push({i,j+1});
                }
            }
             if(j>0){
                int x4=max(cost[i][j],arr[i][j-1]);
                if(x4<cost[i][j-1]){
                cost[i][j-1]=x4;
                    q.push({i,j-1});
                }
            }
        }
        return cost[n-1][m-1];
    }
};