// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(vector<vector<int>>&range, vector<int>que){
        sort(range.begin(),range.end());
        vector<int>ran;
          int j=0;
        for(int i=1;i<range.size();i++){
            if(range[j][1]>=range[i][0]){
                range[j][1]=max(range[i][1],range[j][1]);
            }
            else{
                j++;
                range[j]=range[i];
            }
        }
        int k=0;
        vector<vector<int>>an;
        while(k<=j){
            an.push_back({range[k][0],range[k][1]});
            k++;
        }
        for(int i=0;i<an.size();i++){
        ran.push_back(an[i][1]-an[i][0]+1);    
        }
        for(int i=1;i<an.size();i++){
            ran[i]+=ran[i-1];
        }
        vector<int>ans;
        for(auto x:que){
            auto it=lower_bound(ran.begin(), ran.end(), x);
            int idx=it-ran.begin();
            // cout<<idx<<" ";
            if(idx>=ran.size()){
                ans.push_back(-1);
            }
            else{
                int ele=an[idx][0];
                int prev=idx-1>=0?ran[idx-1]:0;
                //  cout<<idx<<" ";
                int curr=prev+1;
                //   cout<<curr<<" ";
                int now=(x-curr)+ele;
                // cout<<now<<" "<<"\n";
                ans.push_back(now);
                
            }
        }
        return ans;
    } 
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(range, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}
  // } Driver Code Ends