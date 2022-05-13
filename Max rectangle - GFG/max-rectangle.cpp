// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   int largestRectangleArea(vector<int>& arr) {
            int n=arr.size();
        long long left[n];
        long long right[n];
        stack<long long>s;
        s.push(0);
        left[0]=-1;
        for(int i=1;i<n;i++){
            while(!s.empty()&&arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }
            else{
                left[i]=s.top();
            }
            s.push(i);
        }
        
           stack<long long>st;
        st.push(n-1);
    
        right[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        
        //calculate the width
        int res=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int ans=arr[i]*width;
            res=max(res,ans);
        }
         
        return res;
    }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
    
        
        if(n == 0)
            return 0;
        
        vector<int>dp(m,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             
                if(matrix[i][j]==1){
                dp[j]+=1;
                }
                else{
                    dp[j]=0;
                }
            }
               ans=max(ans,largestRectangleArea(dp));  
          }
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends