#include"tree.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool empty(tnode*tree){
  if(!tree){
      return true;
  }
  else return false;
}
void addnode(tnode*&head,int data){
  if(head==NULL){
    tnode *t=(tnode*)malloc(sizeof(tnode));
    t->field=data;
    t->right=NULL;
    t->left=NULL;
    head=t;
  }
  else{
    if(head->field>data)addnode(head->left,data);
    else addnode(head->right,data);
  }
}

void freemem(tnode*&tree) {
  if (tree->left)freemem(tree->left); 
  if (tree->right)freemem(tree->right); 
  delete tree;
  tree=NULL; 
}

void treeprint(tnode *tree) {   //не обход в ширину
  if (tree!=NULL) { //Пока не встретится пустой узел
    cout << tree->field<<endl; //Отображаем корень дерева
    treeprint(tree->left); //Рекурсивная функция для левого поддерева
    treeprint(tree->right); //Рекурсивная функция для правого поддерева
  }
}




//delete
tnode*find_value(tnode*tree,int value ){
   if (tree == NULL || value == tree->field)return tree;
   if (value < tree->field)return find_value(tree->left, value);
   else return find_value(tree->right, value);
}
void tree_review(tnode *tree,vector<int>&v) {   
  if (tree!=NULL) { 
    v.push_back(tree->field); 
    tree_review(tree->left,v); 
    tree_review(tree->right,v); 
  }
}
tnode*prev(tnode*tree,tnode*root){ //x
  if (tree!=NULL) { 
    if(tree->left==root){
      tree->left=NULL;
      cout<<"left\n";
      return tree;
    }
    else if(tree->right==root){
      tree->right=NULL;
      cout<<"right\n";
      return tree;
    }
    prev(tree->left); 
    prev(tree->right); 
  }
}


void delete_value(tnode*&tree,int value){
  tnode*t;
  tnode*root=find_value(tree,value);        //узел с удаляемым элементом
  if(root->left==NULL&&root->right==NULL){
    if(tree!=root){//X удаление единственного элемента
      t=prev(tree,root);
      cout<<t->field<<endl;                    
      freemem(root);
    }
    else{//!
      freemem(root);
      root=NULL;
      tnode*new_tree=NULL;
      tree=new_tree;
    }
  }                
  else{    
      vector<int>v;                                 //вектор для переноса значений
      if(tree!=root){//X 
        if(root->left!=NULL)tree_review(root->left,v);
        if(root->right!=NULL)tree_review(root->right,v);
        t=prev(tree,root);                             //родитель узла root
        cout<<t->field<<" "<<v.size()<<endl;
        freemem(root);
        root=NULL;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){    
          addnode(t,v[i]);
        }
      }
      else{//!
        if(root->left!=NULL)tree_review(root->left,v);
        if(root->right!=NULL)tree_review(root->right,v);
        freemem(root);
        root=NULL;
        for(int i=0;i<v.size();i++){    
          addnode(root,v[i]);
        }
        tree=root;
      }
  }
}
//delete

void printTree(tnode*treePtr, int p) //для наглядной видимости дерева
{
    int i;
        if(treePtr != NULL)
    {
        printTree(treePtr->right,p+3);
        for(i=0;i<p;i++)
        {
            printf(" ");
        }
        printf("%3d\n", treePtr->field);
        printTree(treePtr->left,p+3);
    }
}

void bfs(tnode head){
  queue<tnode>q;
  q.push(head);
  while(!q.empty()){
    tnode node=q.front();
    q.pop();
    cout<<(node.field);
    if(node.left!=NULL)q.push(*node.left);
    if(node.right!=NULL)q.push(*node.right);
  }
}