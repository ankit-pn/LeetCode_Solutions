class Solution {
public:
    int find(int x,vector<int> &parent){
        return x==parent[x]?x:find(parent[x],parent);
    }
    static bool cpm(string &s1,string &s2){
        return s1[1]>s2[1];
    }
    bool equationsPossible(vector<string>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),cpm);
        vector<int> parent(26,0);
        for(int i=0;i<26;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            // cout<<arr[i]<<"\n";
            int a=find(arr[i][0]-'a',parent);
            int b=find(arr[i][3]-'a',parent);
            // cout<<char(a+'a')<<"hrr"<<char(b+'b')<<"\n";
            string s=arr[i].substr(1,2);
            if(s=="=="){
                if(a!=b)
                parent[a]=b;
            }
            else{
                if(a==b)
                    return 0;
            }
        }
        return 1;
    }
};