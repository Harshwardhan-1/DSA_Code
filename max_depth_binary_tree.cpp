#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
//Building a binary tree
Node*buildTree(vector<int>arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    Node*root=new Node(arr[idx]);
    root->left=buildTree(arr);
    root->right=buildTree(arr);
    return root;
}
//Height/Maximum depth of binary tree
int height(Node*root){
   if(root==NULL){
    return 0;
   } 
   int left=height(root->left);
   int right=height(root->right);
   return max(left,right)+1;
}
int main(){
    vector<int>arr={1,2,-1,-1,3,4,-1,-1,6,-1,-1};
    Node*root=buildTree(arr);
    cout<<height(root);
    return 0;
}
