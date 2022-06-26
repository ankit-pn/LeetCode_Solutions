class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ind(n+1,0);
        vector<int> out(n+1,0);
        for(auto it:trust){
            ind[it[0]]++;
            out[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(out[i]==n-1 && ind[i]==0)
                return i;
        }
        return -1;
    }
};