// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        string s1="";
        string s2="";
        reverse(arr,arr+n);
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1.push_back(arr[i] - '0');
            }
            else{
                s2.push_back(arr[i] - '0');
            }
        }
        
        string ans="";
        int i=0,j=0,carry=0;
        while(i<s1.size()||j<s2.size()||carry!=0){
            int a1=0;
            if(i<s1.size()){
                a1=s1[i] + '0';
                i++;
            }
            int a2=0;
            if(j<s2.size()){
                a2=s2[j] + '0';
                j++;
            }
            int sum=a1+a2+carry;
            ans+=(sum%10 + '0');
            carry=sum/10;
            
            
        }
        reverse(ans.begin(),ans.end());
        i=0;
        
        while(i<ans.size()&&ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
        
        
        
        
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends