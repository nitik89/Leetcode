// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int idx1=-1,idx2=-1;
        int mn=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            idx1=i;
        }
        if(a[i]==y){
            idx2=i;
        }
        if(idx1!=-1&&idx2!=-1){
            mn=min(abs(idx2-idx1),mn);
        }
    }
    return mn==INT_MAX?-1:mn;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends