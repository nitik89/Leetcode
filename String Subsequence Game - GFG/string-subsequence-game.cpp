// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  set<string>st;
  void getAns(string str,int idx,string curr){
      if(idx>=str.size()){
          int i=curr.size()-1;
          if(curr[i]=='a'||curr[i]=='e'||curr[i]=='i'||curr[i]=='o'||curr[i]=='u'){
              return;
          }
          
          if(curr.size()!=1&&curr!=""){
              st.insert(curr);
          }
          return;
      }
      if(str[idx]=='a'||str[idx]=='e'||str[idx]=='i'||str[idx]=='o'||str[idx]=='u'){
          getAns(str,idx+1,curr+str[idx]);
          getAns(str,idx+1,curr);
      }
      else{
            if(curr[0]=='a'||curr[0]=='e'||curr[0]=='i'||curr[0]=='o'||curr[0]=='u'){
                getAns(str,idx+1,curr+str[idx]);
                getAns(str,idx+1,curr);
            }
            else{
                getAns(str,idx+1,curr);
            }
      }
  }
    set<string> allPossibleSubsequences(string S) {
       getAns(S,0,"");
       
       if(st.size()==0){
           st.insert("-1");
       }
       return st;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
  // } Driver Code Ends