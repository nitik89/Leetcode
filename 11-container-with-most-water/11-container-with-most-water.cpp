class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
           int ans=(j-i)*min(height[i],height[j]); //calc height curr 
            mx=max(ans,mx); 
            if(height[i]>height[j]){ //now move to that side which is good 
                j--;
            }
            else{
                i++;
            }
        }
        return mx;
    }
};