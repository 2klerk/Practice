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

void reverse(List*root,List*t){
    List*buff=t;
    if(t->head!=NULL){
        t=t->head;
        reverse(root,t);
      
    }
    if(buff!=root){
        cout<<'['<<buff->value<<"]->";
    }
}

//value
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
//value

//node
void SwapMinMax(List*& list) {

  List*max = list->head; //Пропускаем певый узел
  List*min = list->head;
  List*temp = list->head;
  while(temp->head != NULL) {     
      if(temp->value > max->value) max = temp;
      if(temp->value < min->value) min = temp;
      temp = temp->head;
  }

  if(temp->value > max->value) max = temp;      
  if(temp->value < min->value) min = temp;


  auto max_ptr = max->head;
  auto min_ptr = min->head;

  temp = list;
  //swap
  if(temp == max) {      
    list = min;
    list->head = max_ptr;
    } 
  else if(temp == min) {     
    list = max;
    list->head = min_ptr;
  }

  while(temp->head != NULL) {
    if(temp->head == max) {
      temp->head = min;
      min->head = max_ptr;
    } 
    else if(temp->head == min) {
      temp->head = max;
      max->head = min_ptr;
    }
    temp = temp->head;
  }
}
//node
//try catch