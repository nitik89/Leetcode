// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void getAns(vector<vector<int>>&image,int i,int j,int clr,vector<vector<int>>&vis,int n,int m,int val){
    if(i<0||j<0||i>=n||j>=m||image[i][j]!=val||vis[i][j]){
        return;
    }
    image[i][j]=clr;
    vis[i][j]=1;
    getAns(image,i+1,j,clr,vis,n,m,val);
    getAns(image,i,j+1,clr,vis,n,m,val);
    getAns(image,i-1,j,clr,vis,n,m,val);
    getAns(image,i,j-1,clr,vis,n,m,val);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,(vector<int>(m,0)));
        int val=image[sr][sc];
        
        getAns(image,sr,sc,newColor,vis,n,m,val);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends