// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int save=-1;
         for(int i=0;i<n;i++){
             
             int idx=abs(arr[i]);
            if(arr[idx-1]<0){
                save=idx-1;
            }
             arr[idx-1]=-arr[idx-1];
             
            }
            int* a=new int(2);
            a[0]=save+1;
            int idx=1;
        for(int i=0;i<n;i++){
            if(arr[i]>0&&i!=save){
                a[idx]=i+1;
                idx++;
            }
        }
        return a;
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends