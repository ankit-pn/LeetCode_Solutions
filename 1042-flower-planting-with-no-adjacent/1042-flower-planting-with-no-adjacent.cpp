class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& arr) {
        vector<vector<int>> g(n+1);
        int m=arr.size();
        for(int i=0;i<m;i++){
            int a=arr[i][0],b=arr[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++){
            vector<int> color(5,0);
            for(auto it:g[i]){
                color[ans[it-1]]=1;
                // basically we are mapping res color to color vector , so that we can know which space is open to fill.....
            }
            for(int j=1;j<5;j++){
                if(!color[j]){
                    ans[i-1]=j;
                    break;
                }
            }
        }
        return ans;
        // vector<int> color(n,0);
        // vector<int> v(n,0);
        // color[0]=1;
        // for(int i=1;i<=n;i++)
        // if(v[i-1]==0){
        //     // well color[i-1] is the required mistake that i have.............
        //     color[i-1]=1;
        // dfs(g,color,i,v);
        // }
        // return color;
    }
    // void dfs(vector<vector<int>> &g,vector<int> &color,int in,vector<int> &v){
    //     if(v[in-1])
    //         return ;
    //     else
    //         v[in-1]=1;
    //         int co=color[in-1];
    //         if(co==1){
    //             int p=g[in].size();
    //             if(p>0)
    //             color[g[in][0]-1]=2;
    //             if(p>1)
    //             color[g[in][1]-1]=3;
    //             if(p>2)
    //             color[g[in][2]-1]=4;
    //         }
    //         else if(co==2){
    //               int p=g[in].size();
    //             if(p>0)
    //             color[g[in][0]-1]=1;
    //             if(p>1)
    //             color[g[in][1]-1]=3;
    //             if(p>2)
    //             color[g[in][2]-1]=4;
    //         }
    //         else if(co==3){
    //               int p=g[in].size();
    //             if(p>0)
    //             color[g[in][0]-1]=1;
    //             if(p>1)
    //             color[g[in][1]-1]=2;
    //             if(p>2)
    //             color[g[in][2]-1]=4;
    //         }
    //         else if(co==4){
    //              int p=g[in].size();
    //             if(p>0)
    //             color[g[in][0]-1]=1;
    //             if(p>1)
    //             color[g[in][1]-1]=2;
    //             if(p>2)
    //             color[g[in][2]-1]=3;
    //         }
    //         for(auto it:g[in])
    //             dfs(g,color,it,v);
    //     }
    // this whole dfs soln is rubbish, and even in further process this is not going to work..........
    // presenting a much better soln, i hope u will able to grapse it................
};