#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
struct tnode {
  int field;           // ���� ������
  struct tnode *left;  // ����� �������
  struct tnode *right; // ������ �������
};
void addnode(tnode*&head,int data);
tnode*create(int data);
void freemem(tnode *&tree);
void treeprint(tnode *tree);
void printTree(tnode*treePtr, int p);
bool empty(tnode*tree);
void delete_value(tnode*&tree,int value);
void bfs(tnode head);
#endif