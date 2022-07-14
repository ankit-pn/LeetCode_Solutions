class Solution {
public:
    int shortestBridge(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        // intial dfs call.
        int f=1;
        for(int i=0;i<n && f;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    dfs(arr,i,j);
                    f=0;
                    break;
                }
            }
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   cout<<arr[i][j]<<" ";
                if(arr[i][j]==2){
                    q.push({i,j});
                }
            }
              cout<<"\n";
        }
        bfs(arr,q);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
                if(arr[i][j]==1){
                    if(i+1<n && arr[i+1][j]!=1 && arr[i+1][j]!=0){
                        ans=min(ans,arr[i+1][j]-arr[i][j]);
                    }
                    if(i>0 && arr[i-1][j]!=1  && arr[i-1][j]!=0)
                        ans=min(ans,arr[i-1][j]-arr[i][j]);
                    if(j+1<m && arr[i][j+1]!=1 && arr[i][j+1]!=0 )
                        ans=min(ans,arr[i][j+1]-arr[i][j]);
                    if(j>0 && arr[i][j-1]!=1 && arr[i][j-1]!=0)
                        ans=min(ans,arr[i][j-1]-arr[i][j]);
                }
            }
            cout<<"\n";
        }
        return ans-1;
    }
    void dfs(vector<vector<int>>&arr,int i,int j){
        int n=arr.size(),m=arr[0].size();
       if(i<0 || j<0  || i>=n || j>=m || arr[i][j]!=1)
           return ;
        arr[i][j]=2;
        dfs(arr,i+1,j);
        dfs(arr,i,j+1);
        dfs(arr,i-1,j);
        dfs(arr,i,j-1);
    }
    void bfs(vector<vector<int>>&arr,queue<pair<int,int>>&q){
        int n=arr.size(),m=arr[0].size();    
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int ii=it.first;
            int jj=it.second;
            
            if(ii+1<n && arr[ii+1][jj]==0 ){
            q.push({ii+1,jj});
            arr[ii+1][jj]=arr[ii][jj]+1;
            }
            
            if(jj+1<m && arr[ii][jj+1]==0){
            q.push({ii,jj+1});
            arr[ii][jj+1]=arr[ii][jj]+1;
            }
            
            if(ii>0 && arr[ii-1][jj]==0){
            q.push({ii-1,jj});
            arr[ii-1][jj]=arr[ii][jj]+1;
            }
            
            if(jj>0 && arr[ii][jj-1]==0){
            q.push({ii,jj-1});
            arr[ii][jj-1]=arr[ii][jj]+1;
            }
            
        }
    }
    
};