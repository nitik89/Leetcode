// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](vector<int>&a,vector<int>&b){
            return a[0]<b[0];
        });
        int j=0;
        int s,e;
        for(int i=1;i<in.size();i++){
            if(in[i][0]<=in[j][1]){
                in[j][1]=max(in[i][1],in[j][1]);
            }
            else{
                j++;
                in[j]=in[i];
            }
        }
        vector<vector<int>>ans;
        int p=0;
        while(p<=j){
            ans.push_back(in[p]);
            p++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends