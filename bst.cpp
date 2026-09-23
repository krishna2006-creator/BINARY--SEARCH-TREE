#include <cstdlib>
#include <iostream>
#include <ostream>
#include <pthread.h>
#include<stdlib.h>
struct tree{
  int data;
  tree *left;
  tree *right;
};
tree *insert(tree *&root,int val);
tree *createnode(int data){
  tree *newnode=(struct tree*)malloc(sizeof(struct tree));
  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
void inserting(tree *&root){
  std::cout<<"how many values to insert in the binary tree"<<std::endl;
  int n;
  std::cin>>n;
  int value;
  for(int i=0;i<n;i++){
    std::cin>>value;
    root=insert(root,value);
  }
}
void searching(tree *&root,int value){
  if(root==NULL){
  return;
  }
searching(root->left,value);
if(root->data==value){
  std::cout<<"the number is found"<<":"<<root->data<<std::endl;
}
searching(root->right,value);
}
void search(tree *&root){
int number;
std::cout<<"enter the number to search"<<std::endl;
std::cin>>number;
searching(root,number);
//cout<<"there is no element in the binary search tree try another number "<<std::endl;
}
tree *insert(tree *&root,int val){
  if(root==NULL){
    root=createnode(val);
    return root;
  }
  else if(val<root->data)// 40<50 means it should go to left field so 
    {
      root->left=insert(root->left,val);
    }
  else {
  root->right=insert(root->right,val);
  }
  return root;
}
void display(tree *&root){
if(root==NULL){
  return;
}
display(root->left);
std::cout<<root->data<<std::endl;
display(root->right);
}
int main(void){
  tree *root=NULL;
 /* int val=0;
  root=insert(root, val=1);
  std::cout<<root->data<<std::endl;
*/
  int choice=0;
std::cout<<"binary search tree"<<std::endl;
do{
  std::cout<<"1.insert/n2.display/n3.search"<<std::endl;
  std:: cin>>choice;
  switch (choice) {
    case 1:
      inserting(root);
  break;
    case 2:
  display(root);
  break;
    case 3:
  search(root);
  break;
  std::cout <<"wrong choice try again"<<std::endl;
  }
}while(choice !=4);
}
