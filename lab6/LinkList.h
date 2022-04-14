#ifndef LINKLIST_H
#define LINKLIST_H
typedef struct Node{
    Node*head;
    int value;
}List;
List*create(int data);
void pushback(List*&root,double data);
void print_list(List*list);
List*deletelem(List*list,List*root);
int search_max(List*list);
int search_min(List*list);
#endif