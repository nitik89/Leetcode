// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int n=S.size();
	   vector<int>vec(n);
	   for(int i=0;i<n;i++){
	       if(S[i]=='0'){
	           vec[i]=1;
	       }
	       else{
	           vec[i]=-1;
	       }
	   }
	   int sum=0,mx=INT_MIN;
	   for(int i=0;i<n;i++){
	       sum+=vec[i];
	       mx=max(mx,sum);
	       if(sum<0){
	           sum=0;
	       }
	   }
	   return mx;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends