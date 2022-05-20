// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int>ans(n);
	    int p=0,neg=0;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            neg++;
	        }
	        else{
	            p++;
	        }
	    }
	   // cout<<neg<<" "<<p<<"\n";
	    
	    int cnt=min(p,neg);
	   // cout<<cnt<<"    ";
	    p=0;
	    neg=1;
	    int save=n;
	    int cntp=0;
	   for(int i=0;i<n&&cntp<cnt;i++){
	       if(arr[i]>=0){
	           ans[p]=arr[i];
	           p+=2;
	           cntp++;
	       }
	       if(cntp==cnt){
	           save=i;
	           break;
	       }
	       
	   }
	   int cntn=0,save2=n;
	   for(int i=0;i<n&&cntn<cnt;i++){
	       if(arr[i]<0){
	           ans[neg]=arr[i];
	           neg+=2;
	           cntn++;
	       }
	       if(cntn==cnt){
	           save2=i;
	           break;
	       }
	       
	   }
	   //cout<<save<<" "<<save2<<"\n";
	   if(save==n&&save2==n){
	       //continue;
	   }
	   else{
	   p=2*cnt;
	   for(int i=save+1;i<n;i++){
	       if(arr[i]>=0){
	           ans[p]=arr[i];
	           p++;
	       }
	   }
	   neg=2*cnt;
	   //cout<<save2<<"     ";
	   for(int i=save2+1;i<n;i++){
	       if(arr[i]<0){
	           ans[neg]=arr[i];
	           neg++;
	       }
	   }
	  
	    
	    for(int i=0;i<n;i++){
	        arr[i]=ans[i];
	    }
	   }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends