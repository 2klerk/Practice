#include<iostream>
#include"LinkList.h"
// ������� �� ��������� ����:
// 1) ���������������� �������� ���������������� ������
// 2) ����� ��� �������� � ������ ��������� � ������� ��
// 3) ����� � ������ ���������� � ���������� ��������
// 4) �������� ���������� � ���������� �������� ������� ����� ���������
// 5) ������� ��� �������� ������ � ������ � �������� �������
using namespace std;


void task1(List*&list,int data){
  List*t,*prev;
  bool f=false;
  t=list;
  prev=list;
  while(t->head!=NULL ){
    if(f==false){
      t=t->head;
      f=true;
    }
    else{
      prev=prev->head;
      t=t->head;
    }
    if(t->value==data){
      prev=prev->head;
      prev=deletelem(t,list);
    }
    t=prev->head;
  }
}

void task2(List*&list){
  
}
void info(){
  cout<<"(1)AddLink    (1)\n"
      <<"(2)DeleteValue(2)\n"
      <<"(3)FindMax    (3)\n"
      <<"(4)FindMin    (4)\n"
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
        task1(list,value);
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
      case 'p':print_list(list);break;
      case 'e':f=true;break;
    }
  }
}
int main(){
    menu();
    return 0;
}

//��� ��������� ������ ����� ������ �������� �� ������� ����
//issue
//������� 2 ��� �������� ���������� � ���� ������

//��� ������� 4 ����� ��������������� ���������� �� task 1 ��� ���� ������� ������� �� ������ ����������
