class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>stk;
        int sum=0;
        for(auto x:ops){
            if(x=="+"){
                int y=stk.top();stk.pop();
                int z=stk.top();stk.pop();
                // cout<<y<<" "<<z<<"\n";
                int sum=y+z;
                stk.push(z);
                stk.push(y);
                stk.push(sum);
            }
            else if(x=="C"){
               // cout<<stk.top()<<" ";
                    stk.pop();
                
            }
            else if(x=="D"){
                
                    int x=stk.top();
                    // cout<<2*x<<" ";
                    stk.push(2*x);
                
            }
            else{
                 // cout<<stoi(x)<<" ";
                stk.push(stoi(x));
            }
        }
        
        while(!stk.empty()){
             // cout<<stk.top()<<" ";
            sum+=stk.top();
            stk.pop();
        }
        return sum;
    }
};