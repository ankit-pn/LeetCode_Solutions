class Solution {
public:
    int find(int x,vector<int> &parent){
        return parent[x]==x?x:find(parent[x],parent);
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        int n1=arr.size();
        // if(n1<n-1)
        //     return -1;
        vector<int> parent(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
        int c=0;
        for(int i=0;i<n1;i++){
            int a=find(arr[i][0],parent);
            int b=find(arr[i][1],parent);
            if(a!=b)parent[a]=b;
            else c++;
        }
        // you did here wrong to calculate number of edges.
        // cout<<c<<"\n";
        // map<int,int> g;
        // for(int i=0;i<n;i++){
        //     cout<<parent[i]<<"\n";
        //     g[parent[i]]++;
        // }
        // int x1=g.size();
        // cout<<x1<<"\n";
        int x1=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                x1++;
        }
        // cout<<x1<<"\n";
        
        if(c>=x1-1)
            return x1-1;
        else
            return -1;
        
        
    }
};