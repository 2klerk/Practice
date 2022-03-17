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
#include <stdlib.h>
using namespace std;
#define ERROR_UNCORRECT "ERROR: You enter uncorrect value!\n"
#define ERROR_CHANGE    "ERROR: Changing array!\n"
#define ERROR_ALLOC     "ERROR: Memory allocation field!\n"
#define ERROR_REALLOC   "ERROR: Reallocation field!\n"
#define ERROR_OUT       "ERROR: Out of range\n"

typedef int* arr_t;
int* declare(int &n) {
    arr_t a = (int*)malloc(sizeof(int)*n);
    if (a == NULL) {
        cout << ERROR_ALLOC;
        exit(0);
    }
    return a;
}

void change_size(arr_t&a, int n) {
    arr_t t = (int*)realloc(a, sizeof(int)*(n));
    if (t == NULL && n!=0) {
        cout << ERROR_REALLOC;
        free(a);
        a = NULL;
        exit(0);
    }
    else {
        a = t;
    }
}

int* to_end(arr_t&a, int& n, int& x) {
    n++;
    change_size(a, n);
    //cout << a[0] << a[1] << a[2]<<endl;
    a[n - 1] = x;
    //cout << a[0] << a[1] << a[2] << endl;
    return a;
}

int* del_ind(arr_t&a, int& n, int& x) {
    n--;
    for (int i = x - 1; i < n; i++) {
        a[i] = a[i + 1];
    }
    change_size(a, n);
    return a;
}

int*del_weight(arr_t&a, int& n, int& x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            for (int j = i; j < n - 1; j++) { a[j] = a[j + 1]; } //сдвиг влево
            n--;
        }
    }
    change_size(a, n);
    return a;
}

void print(arr_t&a, int& n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}



int*task1(arr_t&a, int& n, int x) {
    cout << "Task(1): ";
    a = to_end(a, n, x);
    print(a, n);
    return a;
}

int*task2(arr_t&a, int& n, int x) {
    if (x <= n) {
        cout << "Task(2): ";
        del_ind(a, n, x);
        print(a, n);
    }
    else cout << ERROR_OUT;
    return a;
}

int*task3(arr_t&a, int& n, int x) {
    cout << "Task(3): ";
    del_weight(a, n, x);
    print(a, n);
    return a;
}

int* enter_value(arr_t&a, int& n) {
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    return a;
}

int input_X() {
    int x;
    cout << "input (digits,index): ";
    cin >> x;
    return x;
}

void menu() {
    int n, x;
    cout << "input length: ";
    cin >> n;
    char choice;
    if (n >= 1) {
        arr_t a;
        a=declare(n);
        cout << "input digits:\n";
        a = enter_value(a, n);
        bool f=false;
        while(f==false){
            cout << "-Select task:\n--(1) ADD  (1)\n--(2)DelInd(2)\n--(3)DelVal(3)\n--(e) exit (e)\n--(c)clear (c)\n";
            cin >> choice;
            switch (choice) {
            case'1': { x = input_X(); a = task1(a, n, x); break; }
            case'2': { x = input_X(); a = task2(a, n, x); break; }
            case'3': { x = input_X(); a = task3(a, n, x); break; }
            case'e': {f = true; break; }
            case'c': {
                system("cls");
                cout << "Length: " << n << endl;
                cout << "Your sequence: "; 
                print(a,n); 
                break; 
            }
            default: cout << "Command not found!\n";
            }
        }
        free(a);
        a = NULL;
    }
    else cout<<ERROR_UNCORRECT;
}
int main()
{
    menu();
    return 0;
}
