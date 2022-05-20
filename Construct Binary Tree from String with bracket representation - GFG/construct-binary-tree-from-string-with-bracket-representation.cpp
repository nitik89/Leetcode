// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    int idx;
    Node* getAns(string str){
        
        string s="";
        while(idx<str.size()&&str[idx]>='0'&&str[idx]<='9'){
            s+=str[idx];
            idx++;
        }
        int val=stoi(s);
        
        Node* root=new Node(val);
        if(str[idx]=='('){
            idx++;
            root->left=getAns(str);
        }
        if(str[idx]=='('){
            idx++;
            root->right=getAns(str);
        }
        if(str[idx]==')'){
            idx++;
        }
        return root;
    }
    Node *treeFromString(string str)
    {
        idx=0;
    return getAns(str);   
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends