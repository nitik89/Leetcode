class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        if(special.size()==0){
            return top-bottom+1;
        }
        sort(special.begin(),special.end());
        int mxcnt=special[0]-bottom;
        for(int i=1;i<=special.size()-1;i++){
            mxcnt=max(special[i]-special[i-1]-1,mxcnt);
        }
        mxcnt=max(top-special[special.size()-1],mxcnt);
        
        
        return mxcnt;
    }
};