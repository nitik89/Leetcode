// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    int n=price.size();
    int left[n]={0};
    left[0]=0;
    int right[n]={0};
    right[n-1]=0;
    int mx=price[0],mxl=price[n-1];
    for(int i=1;i<n;i++){
        mx=min(mx,price[i]);
        left[i]=max(price[i]-mx,left[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        mxl=max(mxl,price[i]);
        right[i]=max(mxl-price[i],right[i+1]);
    }
    
   
    int profit=INT_MIN;
    for(int i=0;i<n;i++){
        profit=max(profit,left[i]+right[i]);
    }
    return profit;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends