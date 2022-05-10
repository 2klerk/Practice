// 1) инициализировать бинарное дерево
// 2) удалить элемент из дерева с данным значением
// 3) вывести все элементы дерева обходом в ширину
#include<iostream>
#include <conio.h>
#include<cstdlib>
#include"tree.h"
#include<vector>
#include<ctime>
#include<random>
using namespace std;
void info(){
    cout<<"(1)add        (1)\n"
        <<"(2)DeleteValue(2)\n"
        <<"(3)  Print    (3)\n"
        <<"(c)  Clear    (c)\n"
        <<"(e)Exit       (e)\n";
}
void input_to_tree(tnode*&tree){
    srand(time(0));
    char choice;
    cout<<"(1)Manual(1)\n"
        <<"(2)Auto  (2)\n";
    cin>>choice;
    if(choice=='1'){
        cout<<"Enter tree size: ";
        int n;
        cin>>n;
        cout<<"Value: ";
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            addnode(tree,x);
        }
    }
    else{
        int n=rand()%5+1;
        cout<<"Tree size: "<<n<<endl;
        cout<<"Value: ";
        for(int i=0;i<n;i++){
            int x=rand()%10+1;
            addnode(tree,x);
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void menu(){
    tnode*tree=NULL;
    bool f=false;
    while(f==false){
        char choice;
        info();
        cin>>choice;
        switch (choice)
        {
        case '1':input_to_tree(tree);break;
        case '2':{
            int x;
            cout<<"Enter value: ";
            cin>>x;
            if(!empty(tree))delete_value(tree,x);
            else cout<<"Tree is empty!\n";
            break;
        }
        case '3':{
            if(!empty(tree))bfs(*tree);
            else cout<<"Tree is empty!\n";
            break;
        }
        case 'c':freemem(tree);break;    
        case 'e':f=true;break;
        default:cout<<"Command not found!\n";break;
        }
    }
}
int main(){
    menu();
    system("pause");
}
