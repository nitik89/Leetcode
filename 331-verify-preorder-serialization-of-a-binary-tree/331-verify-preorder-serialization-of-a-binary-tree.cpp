class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        if(n==1&&preorder!="#"){
            return false;
        }
        stack<string>stk;
        int i=0;
        string t="";
        while(i<preorder.size()&&preorder[i]!=','){
            t+=preorder[i++];
        }
        if(t!="#"){
        stk.push(t);
        }
        // cout<<i<<" ";
        i++;
        for(;i<n;i++){
            if(stk.empty()){
                return false;
            }
            stk.pop();
            string a="";
            while(i<n&&preorder[i]!=','){
                a+=preorder[i++];
            }
            string b="";
            i++;
            // cout<<i<<" ";
            while(i<n&&preorder[i]!=','){
                b+=preorder[i++];
            }
            // cout<<a<<" --- "<<b<<"\n";
            if(a==""||b==""){
                return false;
            }
            if(a!="#"){
                stk.push(a);
            }
            if(b!="#"){
                stk.push(b);
            }
        }
        return true;
    }
};