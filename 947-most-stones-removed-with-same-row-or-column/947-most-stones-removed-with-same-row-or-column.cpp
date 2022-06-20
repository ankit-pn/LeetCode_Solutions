class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // here we go , with standard dfs,call;
        map<int,vector<pair<int,int>>> row;
        map<int,vector<pair<int,int>>> col;
        for(auto it:stones){
            row[it[0]].push_back({it[0],it[1]});
            col[it[1]].push_back({it[0],it[1]});
        }
        set<pair<int,int>> v;
        int res=0;
        for(auto it:stones){
            pair<int,int> q={it[0],it[1]};
            if(v.find(q)==v.end()){
                res++;
        dfs(row,col,v,q);
            }
        }
        return stones.size()-res;
    }
    void dfs(map<int,vector<pair<int,int>>> &row, map<int,vector<pair<int,int>>> &col,set<pair<int,int>> &v,pair<int,int> q){
        if(v.find(q)!=v.end())
            return ;
        v.insert(q);
        for(auto it:row[q.first])
            dfs(row,col,v,it);
        for(auto it:col[q.second])
            dfs(row,col,v,it);
    }
};