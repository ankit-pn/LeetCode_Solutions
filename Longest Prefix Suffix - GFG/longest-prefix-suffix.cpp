// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int n=s.length();
	    int i=0,j=1;
	    vector<int> dp(n,0);
	    while(i<n && j<n){
	        if(s[i]==s[j]){
	            dp[j]=i+1;
	            i++;
	            j++;
	        }
	        else{
	            if(i>0)
	            i=dp[i-1];
	            else
	            j++;
	        }
	    }
	    return dp[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends