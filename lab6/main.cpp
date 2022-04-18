#include<iostream>
#include"LinkList.h"
// Задание по следующей лабе:
// 1) инициализировать линейный однонаправленный список
// 2) найти все элементы с данным значением и удалить их
// 3) найти в списке наибольшее и наименьшее значение
// 4) поменять наибольшее и наименьшее значение местами через указатели
// 5) вывести все элементы списка в прямом и обратном порядке
using namespace std;


void task2(List*&list,int data){

    List*t = list,*prev;
    if(t->value == data) {      // Deleting the head of the list
      t = t->head;
    }else {
      while (t != NULL && t->head != NULL) {
        if (t->head->value == data) {
            t->head=t->head;
            t->head=t->head;
        }
      else t = t->head;
    }
  }
}
void task6(List*&list){
  cout<<"Before: ";
  print_list(list);
  cout<<"After: ";
  reverse(list,list);
  cout<<endl;
}
void info(){
  cout<<"(1)AddLink    (1)\n"
      <<"(2)DeleteValue(2)\n"
      <<"(3)FindMax    (3)\n"
      <<"(4)FindMin    (4)\n"
      <<"(5)SwapMinMax (5)\n"
      <<"(6)Reverse    (6)\n"
      <<"(p)Print      (p)\n";
}
void menu(){
  bool f=false;
  List*list;
  list=create(0);
  while(f==false){
    char choice;
    info();
    cin>>choice;
    switch(choice){
      case '1':{
        int value;
        cin>>value;
        pushback(list,value);
        break;
      }
      case '2':{
        int value;
        cin>>value;
        task2(list,value);
        break;
      }
      case '3':{
        cout<<"Max: "<<search_max(list)<<endl;
        break;
      }
      case '4':{
        cout<<"Min: "<<search_min(list)<<endl;
        break;
      }
      case '5':{
        SwapMinMax(list);
      }
      case '6':task6(list);break;
      case 'p':print_list(list);break;
      case 'e':f=true;break;
    }
  }
}
int main(){
    menu();
    return 0;
}

