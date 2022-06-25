class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      // well here we go, always start from vertices whose indegree in 0 
        // well this question is now much more intresting as you dont even need to do dfs traversal, just count indegree.
        //period.
        // vector<vector<int>> g(n);
        vector<int> indg(n);
        for(int i=0;i<edges.size();i++){
            // int a=edges[i][0];
            int b=edges[i][1];
            // g[a].push_back(b);
            indg[b]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(!indg[i])
                ans.push_back(i);
        return ans;
    }
};