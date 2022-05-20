// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	 void powerset(string s,int index,vector<string>& ans,string output)
   {
       if(index==s.length())
        {
            if(output.length()>0)
             ans.push_back(output);
            return ;
        }
        powerset(s,index+1,ans,output+s[index]);
        powerset(s,index+1,ans,output);
   }

 vector<string> AllPossibleStrings(string s){
     // Code here
     vector<string> ans;
     int index=0;
     string output="";
     powerset(s,index,ans,output);
     sort(ans.begin(),ans.end());
     return ans;
 }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends