// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({price[i],i+1});
        }
        sort(vec.begin(),vec.end());
        int curr=k;
        int cnt=0;
        for(int i=0;i<n;i++){
            int s=0;
            int e=vec[i].second;
            int buy=0;
            while(s<=e){
                int mid=(s+e)>>1;
                if(vec[i].first*mid<=curr){
                    buy=mid;
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
            curr-=vec[i].first*buy;
            cnt+=buy;
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends