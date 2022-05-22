// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
int j=0;
string ans="";
for(int i=0;i<S.size();i++){
    //  cout<<i<<" ";
    if(i==index[j]){
        int len=sources[j].size();
        // cout<<len<<" "<<i<<"\n";
        string str=S.substr(i,len);
        // cout<<str<<" "<<sources[j]<<"\n";
        if(str==sources[j]){
            ans+=targets[j];
            i+=len-1;
        
        }
        else{
           ans+=S[i]; 
        }
        j++;
        
    }
    else{
        ans+=S[i];
    }
}
return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends