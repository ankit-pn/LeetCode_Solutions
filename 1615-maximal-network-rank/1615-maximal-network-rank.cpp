class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n);
        for(int i=0;i<roads.size();i++){
            int a=roads[i][0];
            int b=roads[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int mx1=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            int x=g[i].size();
            if(x>mx1){
                mx1=x;
                ind=i;
            }
        }
        int mx2=-1;
        for(int i=0;i<n;i++){
            int x=g[i].size();
            if(x>mx2 && i!=ind)
                mx2=x;
        }
        vector<int> cmp;
        for(int i=0;i<n;i++){
            int x=g[i].size();
            if(x==mx2 && i!=ind)
                cmp.push_back(i);
                
        }
        if(mx1!=mx2){
        bool p=0;
        // for(auto it:cmp)
        //     cout<<it<<" ";
        for(int j=0;j<cmp.size();j++){
            bool f1=0;
        for(int i=0;i<g[ind].size();i++){
                if(g[ind][i]==cmp[j])
                    f1=1;
            }
            if(!f1)
                p=1;
        }
         // cout<<ind<<" "<<mx2<<"\n";
        return p==1 ? mx1+mx2 : mx1+mx2-1;
        }
        else if(mx1==mx2){
               bool p=0;
        // for(auto it:cmp)
        //     cout<<it<<" ";
        for(int j=0;j<cmp.size();j++){
            bool f1=0;
        for(int i=0;i<g[ind].size();i++){
                if(g[ind][i]==cmp[j])
                    f1=1;
            }
            if(!f1)
                p=1;
        }
        bool p2=0;
            int ind2 = cmp[0];
              for(int j=1;j<cmp.size();j++){
            bool f1=0;
        for(int i=0;i<g[ind2].size();i++){
                if(g[ind2][i]==cmp[j])
                    f1=1;
            }
            if(!f1)
                p2=1;
        } 
            return p || p2 ? mx1+mx2 : mx1+mx2-1;               
        }
        else
            return mx1+mx2;
    }
};