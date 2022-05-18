// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int getAns(int x){
    if(x<5){
        return 0;
    }
    return x/5+getAns(x/5);
}
        int findNum(int n)
        {
            int s=1,e=1e9;
            int ans=-1;
            while(s<=e){
                int mid=(s+e)>>1;
                int y=getAns(mid);
                if(y>=n){
                    ans=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends