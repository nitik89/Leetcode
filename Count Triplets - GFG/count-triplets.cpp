// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    unordered_map<int,int>mp;
    struct Node* temp=head;
    while(temp!=NULL){
        mp[temp->data]++;
        temp=temp->next;
    }
    temp=head;
    int cnt=0;
    while(temp!=NULL){
        int val=temp->data;
        struct Node* t=temp->next;
        int tar=x-val;
        
        while(t!=NULL){
            int v=t->data;
            int diff=tar-t->data;
            
            if(diff==t->data){
                if(mp[diff]>1){
                    cnt++;
                }
            }
            
            else if(diff>t->data){
                if(mp[diff]>0){
                cnt++;
                }
            }
            // cout<<val<<" "<<t->data<<" "<<diff<<" "<<cnt<<"\n";
            while(t!=NULL&&t->data==v){
                t=t->next;
            }
            
        }
         while(temp!=NULL&&temp->data==val){
                temp=temp->next;
            }
    }
    return cnt;
} 