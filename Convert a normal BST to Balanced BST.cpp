#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int key){
    Node* temp = new Node();
    temp->data = key;
    temp->left=temp->right=NULL;
    return temp;
}
void inorderTraversal(Node* root , vector<Node*> &inorder){
    if(root==NULL)return;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root);
    inorderTraversal(root->right,inorder);
}
Node* BuildBalancedTree(vector<Node*> &inorder , int start , int end){
    if(start>end)return NULL;
    int mid = (start+end)/2;
    Node* root= inorder[mid];
    root->left = BuildBalancedTree(inorder,start,mid-1);
    root->right = BuildBalancedTree(inorder,mid+1,end);
    return root;
}
Node* BuildTree(Node* root){
    vector<Node*>inorder;
    inorderTraversal(root,inorder);
    int n = inorder.size();
    return BuildBalancedTree(inorder,0,n-1);
}
void postorder(Node* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
    root = BuildTree(root);
    cout<<"Post Order Traversal of the balanced BST is : ";
    postorder(root);
    cout<<endl;
    return 0;
}