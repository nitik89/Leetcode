// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({arr[i],i});
        }
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int
        >&b){
            int x=__builtin_popcount(a.first);
            int y=__builtin_popcount(b.first);
           if(x==y){
               return a.second<b.second;
           }
           return x>y;
        });
        for(int i=0;i<n;i++){
            arr[i]=vec[i].first;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends