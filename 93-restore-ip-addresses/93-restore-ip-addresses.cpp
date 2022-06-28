class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       // case 1
        if(s.length()>12 || s.length()<4)
            return {};
        return dfs(s,s.length(),3);
        
    }
    vector<string> dfs(string s,int n,int k){
        if(n<0)
        return {};
        if(k==0){
            string m=s.substr(0,n);
            if(n==0)
                return {};
            if(n==3 && stoi(m)>=100 && stoi(m)<=255)
                return {m};
            else if(n==2 && stoi(m)>=10)
                return {m};
            else if(n==1)
                return {m};
            else
                return {};
        }
        // vector<string> p1=dfs(s,n-1,k-1);
        // for(auto &it:p1){
        //       if(it=="")
        //         continue;
        //     it+='.';
        //     it+=s.substr(max(0,n-1),1);
        // }
        // vector<string> p2=dfs(s,n-2,k-1);
        // for(auto &it:p2){
        //     if(it=="")
        //         continue;
        //     it+='.';
        //     it+=s.substr(max(0,n-2),2);
        // }
      
        vector<string> p1;
        vector<string> p2;
        vector<string> p3;
        if(n-1>=0){
              string x1=s.substr(n-1,1);
        if(stoi(x1)>=0){
           p1=dfs(s,n-1,k-1);
            for(auto &it:p1){
              if(it=="")
                continue;
            it+='.';
            it+=x1;
            }
        }
        }
        if(n-2>=0){
        string x2=s.substr(n-2,2);
        if(stoi(x2)>=10){
           p2=dfs(s,n-2,k-1);
            for(auto &it:p2){
              if(it=="")
                continue;
            it+='.';
            it+=x2;
            }
        }
        }
        if(n-3>=0){
        string x3=s.substr(max(0,n-3),3);
        if(stoi(x3)<=255 && stoi(x3)>=100){
           p3=dfs(s,n-3,k-1);
            for(auto &it:p3){
              if(it=="")
                continue;
            it+='.';
            it+=x3;
            }
        }
        }
        vector<string> ans;
        for(auto &it:p1)
            ans.push_back(it);
        for(auto &it:p2)
            ans.push_back(it);
        for(auto &it:p3)
            ans.push_back(it);
        return ans;
        // submitting right now , it has to be accepted
        // accepted. periods.
    }
};