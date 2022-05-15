// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    int i=0;
		    sort(S.begin(),S.end());
		   help(i,S,ans);
		   sort(ans.begin(),ans.end());
		   return ans;
		}
		void help(int i,string s,vector<string> &ans){
		    if(i==s.length()){
		        ans.push_back(s);
		        return ;
		    }
		    
		    for(int k=i;k<s.length();k++){
		    swap(s[i],s[k]);
		    help(i+1,s,ans);
		    swap(s[i],s[k]);
		    }
		}
		
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends