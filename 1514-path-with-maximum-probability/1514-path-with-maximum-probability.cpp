class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& su, int start, int end) {
        vector<double> res(n,0);
        vector<vector<pair<int,double>>> g(n);
        int qi=0;
        int ind=0;
        int we=0;
        for(auto it:edges){
            g[it[0]].push_back({it[1],su[qi]});
            g[it[1]].push_back({it[0],su[qi]});
            qi++;
        }
        queue<int> q;
        q.push(start);
        res[start]=1;
        // well mark my word , you are getting problem in marking visited array, that is never gonna resolve to you by this method.
        // good luck mate , wa coming
        // after this modification , i.e calcuating degree of end , i am sure that it will get accepted.
        // finally got the mistake , there is no need to maintain visited array , all we need to check and push only when it is greter , this will terminate a lot of call nd this is what real bfs is
        // nd other mistake of using doble instead of int.
        // period.
        int g1=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto &it:g[x]){
                double yy=res[x]*it.second;
                if(res[it.first]<yy){
                    res[it.first]=yy;
                    q.push(it.first);
                }
            }
        }
        return res[end];
    }
};