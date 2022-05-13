// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
     vector<int> newV;
       for(int i=0; i<N; i++){
           for(int j=0; j<N; j++){
             newV.push_back(Mat[i][j]);
           }
       }
       sort(newV.begin(),newV.end());
       int index=0;
       for(int k=0; k<Mat.size(); k++){
           for(int p=0; p<Mat.size(); p++){
            Mat[k][p]=newV[index];
            index++;
           }
       }
       return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends