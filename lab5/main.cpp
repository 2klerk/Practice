#include<iostream>
#include"queue.h"
//output
void info(){
    cout<<"(1)Clear       (1)\n"
        <<"(2)Enqueue     (2)\n"
        <<"(3)Dequeue     (3)\n"
        <<"(4)InsertZero  (4)\n"
        <<"(5)DeleteTail  (5)\n"
        <<"(6)SwapHeadTail(6)\n"
        <<"(p)PrintQ      (p)\n"
        <<"(e) Exit       (e)\n";
}
//output

//task
void task2(queue&q){
    int x;
    cin>>x;
    enqueue(q,x);
}
void task4(queue&q){
    queue temp;
    temp=create(temp);
    bool act=false;
    while(isempty(q)==false){
        int value;
        if(act==false){
            value=dequeue(q);
            enqueue(temp,value);
            act=true;
        }
        else{
            enqueue(temp,0);
            act=false;
        }
    }
    clear(q);
    q=temp;
}
void task5(queue&q){
    queue temp;
    temp=create(temp);
    while(isempty(q)==false){
        int value;
        value=dequeue(q);
        if(isempty(q)!=true)enqueue(temp,value);
    }
    clear(q);
    q=temp;
}
    //a[0]- head
    //a[1]- tail
void task6(queue&q){
    queue temp,copy;
    temp=create(temp);
    copy=create(copy);
    createcopy(q,copy);
    int a[2];
    a[0]=dequeue(copy);
    if(isempty(copy)==false){
        short k=1;
        while(isempty(copy)==false){
            int value;
            a[1]=dequeue(copy);
            k++;
        }
        clear(copy);
        if(k==2){
            enqueue(temp,a[1]);
            enqueue(temp,a[0]);
        }
        else{
            createcopy(q,copy);
            dequeue(copy);
            enqueue(temp,a[1]);
            while(isempty(copy)==false){
                int value;
                value=dequeue(copy);
                if(isempty(copy)==false)enqueue(temp,value);
                else enqueue(temp,a[0]);
            }
        }
        clear(copy);
        clear(q);
        q=temp;
    }
    else {
        clear(copy);
        clear(temp);
        cout<<"Queue have one element!\n";
    }
}
//task

void menu(){
    bool f=false;
    queue q;
    q=create(q);
    while(f==false){
        char ch;
        info();
        cin>>ch;
        switch (ch)
        {
        case '1':clear(q);break;
        case '2':{
                task2(q);
                break;
            }
        case '3':{
            if(isempty(q)==false)
                cout<<"Head: "<<dequeue(q)<<endl;
            else cout<<QUEUE_EMPTY;
            break;
        }
        case '4':task4(q);break;
        case '5':task5(q);break;
        case '6':task6(q);break;
        case 'p':q_print(q);break;
        case 'e':f=true;break;
        default:cout<<"Command not found!\n";break;
        }
    }
}

int main(){
    setlocale(0,"");
    // try{
        menu();
    // }
    // catch(string error){
    //     cout<<error<<endl;
    // }
    return 0;
}