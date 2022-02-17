/******************************************************************************

1) Ввести массив 
2) Добавить элемент в конец
3) Удалить элемент по позиции 
4) Удалить элементы по значению

a-массив
n-длина массива
x-Число, позиция, значение

*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int*to_end(int*a,int n,int x){
    a=(int*)realloc (a,sizeof(int)*n);
    a[n-1]=x;
    return a;
}

int*del_ind(int*a,int n,int x){
    for(int i=x-1;i<n;i++){
        a[i]=a[i]+1;
    }
    n--;
    a=(int*)realloc (a,sizeof(int)*n);
    return a;
}


int global_n;
int*del_weight(int*a,int n,int x){
    for (int i = 0; i < n; i++) {
        if (a[i] == x) { 
            int step = i;
            for (int j = i; j < n - 1; j++) { a[step] = a[j + 1]; step++; } //сдвиг влево
            n--;
            }
        } 
    global_n=n;
    a=(int*)realloc (a,sizeof(int)*n);
    return a;
}

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int n,x;
    cout<<"input length: ";
    cin>>n;
    int*a=new int[n];
    cout<<"input digits:\n";
    for(int i=0;i<n;i++){   cin>>a[i];  }
    cout<<"input (digits,index): ";
    cin>>x;
    
    cout<<"Task(1): ";
    n++;
    to_end(a,n,x);
    print(a,n);
    n--;
    
    if(x<=n){
        cout<<"Task(2): ";
        del_ind(a,n,x);
        n--;
        print(a,n);
    }
    else cout<<"Error: out of range!";
    cout<<"Task(3): ";
    n++;
    del_weight(a,n,x);
    print(a,global_n);
    
    delete[]a;
    return 0;
}
