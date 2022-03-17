//1) Очистить стек(поочерёдно удаляются и выводятся все элементы)
//2) Добавить в стек
//3) Извлечь из стека верхушку(с её выводом)
//4) Поменять местами два верхних элемента(с их выводом)
//5) Удалить самый нижний элемент стека(с его выводом)
//6) Поменять местами верхний и нижний элемент стека(тоже с выводом)
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#define STACK_MAX_SIZE 20
#define ERROR_NOT_FOUND "ERROR: Command not found!\n"
#define MALLOC_FIELD    "ERROR: Malloc field!\n"
#define REALLOC_FIELD   "ERROR: Realloc field!\n"
#define NO_SPACE        "ERROR: No more space!\n"
typedef int* arr_t;
typedef struct arr {
	arr_t ptr;
	int size=0;
} stack_t;

void clear(stack_t& st) {
	free(st.ptr);
	st.size == 0;
	cout<< "#########\n"
	    << "#Cleaned#\n"
		<< "#########\n\n";
}
void clear_console() {
	system("cls");
}
void st_increase(stack_t& st) {
	st.size++;
	if (st.size == 0)clear(st);
	else {
		arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
		if (t == NULL) {
			cout << REALLOC_FIELD;
			clear(st);
			exit(0);          //
		}
		else st.ptr = t;
	}
}



void create(stack_t&st) {               //-
	st.ptr = (int*)malloc(sizeof(int) * st.size);
	if (st.ptr == NULL) {
		cout << MALLOC_FIELD;
		exit(0);
	}
}

void push(stack_t& st, int new_el) {

	st_increase(st);
	st.ptr[st.size - 1] = new_el;
	cout <<"#########\n"
		<< "#PUSHED#\n"
		<< "#########\n\n";
}

void swap_2last(stack_t &st) {
	if (st.size == 1)cout << "Stack has 1 element!\n\n";
	else {
		int temp = st.ptr[st.size - 2];
		st.ptr[st.size - 2] = st.ptr[st.size - 1];
		st.ptr[st.size - 1] = temp;
		cout << "n-1 = " << st.ptr[st.size - 2]<<endl
			<< "n   = " << st.ptr[st.size - 1]
			<< endl << endl;
	}
}
//void pop(stack_t&st) {
//	st.size--;
//	if (st.size == 0)clear(st);
//	else {
//		arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
//		if (t == NULL) {
//			cout << REALLOC_FIELD;
//			clear(st);
//			exit(0);          //
//		}
//		else st.ptr = t;
//	}
//}
void peak(stack_t&st) {
	if (st.size != 0) {
		cout << "#########\n"
			<< "#  PEAK #\n"
			<< "#########\n";
		//return st.ptr[st.size - 1];
		cout<<"Peak = " << st.ptr[st.size - 1]<<endl<<endl;
	}
	else cout << "Stack is empty\n\n";
}

void task_info() {
	cout << "(1)Clear stack   (1)\n"        //
		<< "(2)Add to stack  (2)\n"		//!
		<< "(3)Peek          (3)\n"		//!
		<< "(4)Change n-1 & n(4)\n"		//!
		<< "(5)Delete bottom (5)\n"		//
		<< "(6)Change 1 & n  (6)\n"		//
		<< "(p)PrintStack    (p)\n"		//
		<< "(c)Clear Console (c)\n"		//!
		<< "(e)EXIT          (e)\n";
}
void print_stack(stack_t&st) {
	cout << "###################\n";
	for (int i = 0; i < st.size; i++) {
		cout << st.ptr[i] << endl;
	}
	cout << "###################\n";
}
void pop(stack_t& st) {
	st.size--;
	if (st.size == 0)clear(st);
	else {
		arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
		if (t == NULL) {
			cout << REALLOC_FIELD;
			clear(st);
			exit(0);          //
		}
		else st.ptr = t;
	}
}
void delete_first(stack_t&st){//Ошибка ловит мусор вне функции (исправлено)
	stack_t temp;
	temp.size = st.size - 1;
	create(temp);
	for (int i = 1; i < st.size; i++) {
		temp.ptr[i-1] = st.ptr[i];
	}
	pop(st);
	free(st.ptr);
	st = temp;
	//print_stack(st);  
}

void menu() {
	stack_t st;
	char choice;
	create(st);
	bool f = false;
	while(f==false){
		task_info();
		cin >> choice;
		switch (choice) {
		case'1':clear(st); break;
			case'2': {
				int x;
				cout << "Enter value: ";
				cin >> x;
				push(st, x);
				break; 
			}
			case'3':peak(st); break;
			case'4':swap_2last(st); break;
			case'5': {
				delete_first(st);
				break; 
			}
			case'6':break;
			case'p':print_stack(st); break;
			case'c':clear_console(); break;
			case'e':f = true; break;
			default:cout << ERROR_NOT_FOUND; break;
	}
	}
}

int main()
{
	menu();
}
