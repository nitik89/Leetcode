// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int n=a.size(),m=a[0].size();
      int mxs=INT_MIN;
      int sr=-1,sc=-1,er=-1,ec=-1;
      for(int j=0;j<m;j++){
          vector<int>sum(n,0);
          for(int i=j;i<m;i++){
              
              for(int k=0;k<n;k++){
                  sum[k]+=a[k][i];
              }
              unordered_map<int,int>mp;
              int sm=0;
              
              for(int k=0;k<n;k++){
                  sm+=sum[k];
                  if(sm==0){
                      int size=(i-j+1)*(k+1);
                    //   cout<<size<<"\n";
                      if(mxs<size){
                      er=k;
                      sr=0;
                      sc=j;
                      ec=i;
                      mxs=size;
                      }
                      
                  }
                  else if(mp.find(sm)!=mp.end()){
                       int size=(k-(mp[sm]+1)+1)*(i-j+1);
                      if(mxs<size){
                      er=k;
                      sr=mp[sm]+1;
                      sc=j;
                      ec=i;
                      mxs=size;
                      }
                      
                  }
                  mp[sm]=k;
                  
              }
          }
      }
      vector<vector<int>>ans;
    //   cout<<sr<<" "<<er<<" "<<ec<<" "<<sc<<"\n";
    if(sr==-1||er==-1||ec==-1||sc==-1){
        return {{-1}};
    }
      for(int i=sr;i<=er;i++){
          vector<int>temp;
          for(int j=sc;j<=ec;j++){
              temp.push_back(a[i][j]);
          }
          ans.push_back(temp);
      }
      return ans;
  }
};


// { Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}  // } Driver Code Ends