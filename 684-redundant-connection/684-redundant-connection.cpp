class Solution {
public:
    // finest union find question
    int find(int x,vector<int> &parent){
        return parent[x]==x?x:find(parent[x],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2,0);
        int n=edges.size();
        vector<int> parent(n+1,0);
        for(int i=0;i<n+1;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            int a=find(edges[i][0],parent);
            int b=find(edges[i][1],parent);
            if(a!=b){
                parent[b]=a;
            }
            else{
                res[0]=edges[i][0];
                res[1]=edges[i][1];
            }
        }
        return res;
        
    }
};