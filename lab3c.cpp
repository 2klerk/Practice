/******************************************************************************
1) Ввести массив
2) Добавить элемент в конец
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
#define ERROR_LEN       "ERROR: Length equals 0!\n"
#define ERROR_REALLOC   "ERROR: Reallocation field!\n"
#define ERROR_OUT       "ERROR: Out of range\n"


int* declare(int &n) {
    int*a = (int*)malloc(sizeof(int)*n);
    return a;
}

void change_size(int* a, int& n) {
    int* t = (int*)realloc(a, sizeof(int)*(n));
    if (t == NULL) {
        if (n == 0) {
            cout <<ERROR_LEN;
        }
        else { 
            cout << ERROR_REALLOC;
        }
        free(t);
        a = NULL;
        exit(0);
    }
    else {
        a = t;
    }
}

int* to_end(int*a, int& n, int& x) {
    n++;
    change_size(a, n);
    a[n - 1] = x;
    return a;
}

int* del_ind(int* a, int& n, int& x) {
    n--;
    for (int i = x - 1; i < n; i++) {
        a[i] = a[i + 1];
    }
    change_size(a, n);
    return a;
}

int*del_weight(int* a, int& n, int& x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            int step = i;
            for (int j = i; j < n - 1; j++) { a[step] = a[j + 1]; step++; } //сдвиг влево
            n--;
        }
    }
    change_size(a, n);
    return a;
}

void print(int* a, int& n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}



int*task1(int*& a, int& n, int x) {
    cout << "Task(1): ";
    a = to_end(a, n, x);
    print(a, n);
    return a;
}

int*task2(int* a, int& n, int x) {
    if (x <= n) {
        cout << "Task(2): ";
        del_ind(a, n, x);
        print(a, n);
    }
    else cout << ERROR_OUT;
    return a;
}

int*task3(int* a, int& n, int x) {
    cout << "Task(3): ";
    del_weight(a, n, x);
    print(a, n);
    return a;
}

int* enter_value(int* a, int& n) {
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
        int* a;
        a=declare(n);
        if (a == NULL) {
            cout << ERROR_UNCORRECT;
            exit(0);
        }
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
