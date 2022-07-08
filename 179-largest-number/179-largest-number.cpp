class Solution {
public:
    static bool cmp(int &a,int &b){
        string a1=to_string(a);
        string a2=to_string(b);
        return a1+a2>a2+a1;
    }
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(auto &it:arr){
            ans+=to_string(it);
        }
        int i;
        for(i=0;i<ans.length();i++){
            if(ans[i]!='0')
                break;
        }
        if(i==ans.length())
            return "0";
        if(i==0)
        return ans;
        else
        return ans.substr(i,ans.length()-i);
    }
};