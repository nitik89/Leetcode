class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>&sh) {
        vector<int>vec(s.size()+1,0);
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
        int i=0;
        for(auto x:vec){
            
            int v=x%26;
             // cout<<v<<" ";
            if(v>0){
                int shift;
                if(('z'- s[i] )>=abs(v)){
                    shift=(v);
                    s[i]=(char)(s[i] + shift);
                }
                else{
                    int shift=(abs(v)-('z' - s[i])-1);
                    s[i]=(char)('a' + shift);
                }
            }
            else if(v<0){
                int shift;
                if((s[i] - 'a')>=abs(v)){
                    shift=(v);
                    s[i]=(char)(s[i] + shift);
                }
                else{
                    shift=26-(abs(v)-(s[i] - 'a'));
                    s[i]=(char)('a' + shift);
                }
                
                
                
            }
            
            
            i++;
        }
        return s;
        
    }
};