// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int search(string text, string pat)
	{
	    if(pat.size()>text.size()){
	        return 0;
	    }
	    int m=pat.size();
	    for(int i=0;i<=text.size()-m;i++){
	        if(text[i]==pat[0]){
	            string temp=text.substr(i,m);
	           // cout<<temp<<" ";
	            if(temp==pat){
	                return 1;
	            }
	        }
	    }
	    return 0;
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
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}  // } Driver Code Ends