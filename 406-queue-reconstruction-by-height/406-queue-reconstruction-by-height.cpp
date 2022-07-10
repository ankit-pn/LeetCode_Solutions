class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        else
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> ans(n);
        vector<int> check(n,-1);
        sort(people.begin(),people.end(),cmp);
        for(auto &it:people){
            int k=it[1];
            for(int i=0;i<n;i++){
                if(check[i]==-1){
                    if(k==0){
                        ans[i]=it;
                        check[i]=0;
                        break;
                    }
                    else
                    k--;
                }
            }
        }
        return ans;
    }
};