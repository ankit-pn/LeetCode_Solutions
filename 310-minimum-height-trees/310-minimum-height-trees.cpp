class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>> g(n);
        vector<int> d(n,0);
        // a plain forward modification of simple bfs, all you need is to make a plain copy of degree of each node nd play according to that thing.
        for(int i=0;i<n-1;i++){
            d[edges[i][0]]++;
            d[edges[i][1]]++;
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> qu;
        for(int i=0;i<n;i++){
            if(d[i]==1){
                qu.push(i);
                d[i]--;
            }
        }
         vector<int> ans;
        // int rem=n-qu.size();
        // while(rem>2){
        //     int x=qu.front();
        //     qu.pop();
        //     for(auto it:g[x]){
        //         if(d[it]==1){
        //             qu.push(it);
        //         d[it]--;
        //             rem--;
        //         }
        //     }
        // }
        // here you have to perfrom bfs inside the loop ...
        // so here we go again...
        
        while(n>2){
            int sz=qu.size();
            n-=sz;
            while(sz>0){
                int a=qu.front();
                qu.pop();
                for(auto it:g[a]){
                    d[it]--;
                    if(d[it]==1){
                        qu.push(it);
                        // d[it]--;
                    }
                }
                sz--;
            }
        }
        while(!qu.empty()){
            ans.push_back(qu.front());
            qu.pop();
        }
        return ans;
    }

    
      
};