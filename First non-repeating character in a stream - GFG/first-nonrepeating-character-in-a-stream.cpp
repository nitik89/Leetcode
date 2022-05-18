// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char>q;
		    int n=A.size();
		    q.push(A[0]);
		    string ans="";
		    unordered_map<char,int>mp;
		    ans+=A[0];
		    mp[A[0]]=1;
		    for(int i=1;i<n;i++){
		         mp[A[i]]++;
		        while(!q.empty()&&mp[q.front()]>=2){
		            q.pop();
		        }
		       
		        if(mp[A[i]]==1){
		            
		            q.push(A[i]);
		        }
		        if(q.empty()){
		            ans+='#';
		        }
		        else{
		            ans+=q.front();
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends