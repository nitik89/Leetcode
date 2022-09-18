class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0){
            return 0;
        }
        int leftMax[n],rightMax[n];
        memset(leftMax,0,sizeof(leftMax));
        memset(rightMax,0,sizeof(rightMax));
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(rightMax[i],leftMax[i])-height[i];
        }
        
        return res;
    }
};