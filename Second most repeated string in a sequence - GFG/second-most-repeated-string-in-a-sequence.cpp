// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int mxval=INT_MIN,sec=INT_MIN;
        string mxs="";
        string secmx="";
        for(auto x:mp){
            if(x.second>mxval){
                sec=mxval;
                secmx=mxs;
                mxs=x.first;
                mxval=x.second;
            }
            else if(x.second>sec){
                secmx=x.first;
                sec=x.second;
            }
        }
        return secmx;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends