// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int cnt=0;
        int bal=0;
        for(int i=0;i<S.size();i++){
            if(S[i]==']'){
                cnt++;
                if(cnt>0){
                    bal+=cnt;
                }
            }
            else{
                cnt--;
            }
        }
       
        return bal;
        
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends