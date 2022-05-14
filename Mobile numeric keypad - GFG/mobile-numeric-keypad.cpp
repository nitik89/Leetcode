// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int n)
	{
	    vector<vector<int>>v;
  v.push_back({0, 8});
  v.push_back({1, 2, 4});
  v.push_back({1, 2, 3, 5});
  v.push_back({2, 3, 6});
  v.push_back({1, 4, 5, 7});
  v.push_back({2, 4, 5, 6, 8});
  v.push_back({3, 5, 6, 9});
  v.push_back({4, 7, 8});
  v.push_back({5, 7, 8, 9, 0});
  v.push_back({6, 8, 9});
  
  long long dp[n+1][10];
  for(int i=0;i<=n;i++){
      for(int j=0;j<10;j++){
          if(i==0){
              dp[i][j]=0;
          }
          else if(i==1){
              dp[i][j]=1; //because keys are pressed only once so not dependednt on any prev
              }
            else{
                //now if we look at 5 it has neigh given in v so we need to check how many times it has been pressed already like agar pehle 2 dabaya hoga fir 5 ,4 ke baad fir 5 aise nikalo kitni baari daala tha count usme
                long long sum=0;
                for(auto x:v[j]){//picking my neigh
                    sum+=dp[i-1][x];
                }
                dp[i][j]=sum;
            }
      }
  }
  //doing the sum of the last row
  long long ans=0;
  for(int i=0;i<10;i++){
      ans+=dp[n][i];
  }
  return ans;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends