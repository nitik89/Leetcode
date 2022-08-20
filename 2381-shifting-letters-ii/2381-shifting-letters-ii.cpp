class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>&sh) {
        vector<int>vec(s.size()+1,0);
        string str="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
        
        int i=0;
        
        
        for(auto x:sh){
            int st=x[0];
            int end=x[1];
            int dir=x[2];
            if(dir==1){
                vec[st]++;
                vec[end+1]--;
                
            }
            if(dir==0){
                vec[st]--;
                vec[end+1]++;
                
            }
        }
        for(int i=1;i<vec.size();i++){
            vec[i]+=vec[i-1];
        }
     
        for(int i=0;i<vec.size()-1;i++){
            // cout<<i<<" ";
            int sh=vec[i]%26;
            int idx=26+(s[i] - 'a');
            // cout<<idx-sh<<" ";
            // cout<<sh<<" "<<idx<<"\n";
            s[i]=str[idx+sh];
            
        }
        return s;
        
    }
};