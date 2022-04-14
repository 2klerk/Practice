#include"LinkList.h"
#include<iostream>
using namespace std;
List*create(int data){
    List *t=(List*)malloc(sizeof(List));
    t->value=data;
    t->head=NULL;
    return(t);
}
void pushback(List*&root,double data){
  List *t=(List*)malloc(sizeof(List));
  t->value=data;
  t->head=NULL;
  List*p=root;
  while(p->head!=NULL)p=p->head;   //идём в конец
  p->head=t;
}
void print_list(List*list){
  bool f=false;
  List*ptr;
  ptr=list;
  while(ptr->head!=NULL){
    if(f==true)cout<<'['<<ptr->value<<"]->"; //пропускаем 1-ый элемент 
    ptr=ptr->head;
    f=true;
  }
  cout<<'['<<ptr->value<<']'<<endl;   //последний элемент
}
List*deletelem(List*list,List*root){
  List*t;
  bool f=false;
  t=root;
  while(t->head!=list){
    t=t->head;
  }
  t->head=list->head;
  free(list);
  return t;
}
int search_max(List*list){
  List*t;
  int maxi=-222222;
  t=list;
  bool f=false;
  while(t->head!=NULL){
    if(f==false){
      f=true;
    }
    else {
        t=t->head;
        if(maxi<t->value)maxi=t->value;
      }
  }
  return maxi;
}
int search_min(List*list){
  List*t;
  int mini=222222;
  t=list;
  bool f=false;
  while(t->head!=NULL){
    if(f==false){
      f=true;
    }
    else {
        t=t->head;
        if(mini>t->value)mini=t->value;
      }
  }
  return mini;
}