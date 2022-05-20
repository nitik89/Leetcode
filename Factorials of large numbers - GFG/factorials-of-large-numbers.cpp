// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>vec;
        vec.push_back(1);
        int n=2;
        while(n<=N){
            int carry=0;
            for(int j=0;j<vec.size();j++){
                int val=n*vec[j];
                val+=carry;
                vec[j]=val%10;
                carry=val/10;
            }
            while(carry){
                int r=carry%10;
                vec.push_back(r);
                carry/=10;
            }
            n++;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends