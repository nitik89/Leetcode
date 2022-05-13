// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        for(auto x:s){
            mp[x]++;
        }
        for(auto x:mp){
            pq.push(x.second);
            
        }
        while(!pq.empty()&&k--){
            int x=pq.top();
            pq.pop();
            x--;
            if(x>0){
                pq.push(x);
            }
        }
        int cnt=0;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            cnt+=x*x;
        }
        return cnt;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends