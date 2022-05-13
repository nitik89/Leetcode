// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool dp[21][21];
  vector<vector<string>>getAns(string s,int i){
      vector<vector<string>>an;
      if(i>=s.size()){
          an.push_back({});
          return an;
      }
      
      for(int j=i;j<s.size();j++){
          if(dp[i][j]){
              string str=s.substr(i,j+1-i);//make the string
              
              vector<vector<string>>ans=getAns(s,j+1);
              for(auto x:ans){
                
                  x.push_back(str);
                  an.push_back(x);
              }
              
          }
      }
    
      return an;
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        int n=s.size();
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        
        vector<vector<string>>ans=getAns(s,0);
        vector<vector<string>>an;
        for(auto x:ans){
            // int i=0,j=x.size()-1;
            vector<string>temp;
            for(int j=x.size()-1;j>=0;j--){
                temp.push_back(x[j]);
            }
            an.push_back(temp);
        }
        return an;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends