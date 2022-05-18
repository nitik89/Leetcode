// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
       vector<int>mp1(128,0);
       vector<int>mp2(128,0);
       for(auto x:p){
           mp1[x]++;
       }
       int i=0,j=0,count=0;
       string ans="";
       int len=INT_MAX;
       while(i<s.size()){
          mp2[s[i]]++;
          if(mp1[s[i]]){
              if(mp2[s[i]]<=mp1[s[i]]){
                  count++;
              }
          }
          while(j<i&&count>=p.size()){
              int l=i-j+1;
              if(l<len&&count>=p.size()){
                  ans=s.substr(j,i-j+1);
                  
                  len=l;
              }
              mp2[s[j]]--;
              if(mp1[s[j]]){
                  if(mp2[s[j]]<mp1[s[j]]){
                  count--;
                  }
              }
              j++;
              
              
          }
          if(count>=p.size()){
              int l=i-j+1;
              if(l<len){
                  ans=s.substr(j,i-j+1);
                  len=l;
              }
          }
          i++;
       }
       return ans==""?"-1":ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends