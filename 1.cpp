#include <iostream>
#include <cstdlib>
using namespace std;

int*to_end(int*a,int n,int x){
    a=(int*)realloc (a,sizeof(int)*n);
    a[n-1]=x;
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

    cout<<"Task(2): ";
    if(x<=n){
        del_ind(a,n,x);
        n--;
        print(a,n);
    }
    else cout<<"Error: out of range!";
    
    
    delete[]a;
    return 0;
}
