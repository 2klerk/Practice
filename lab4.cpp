//1) Очистить стек(поочерёдно удаляются и выводятся все элементы)
//2) Добавить в стек
//3) Извлечь из стека верхушку(с её выводом)
//4) Поменять местами два верхних элемента(с их выводом)
//5) Удалить самый нижний элемент стека(с его выводом)
//6) Поменять местами верхний и нижний элемент стека(тоже с выводом)
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include<string>
//поставил char вместо define из-за ошибки
using namespace std;
#define NOT_FOUND       "Command not found!\n"
#define NO_SPACE        "ERROR: No more space!\n"
#define ST_EMPTY        "Stack is empty\n\n";


//используется кривое слово успех
bool success = true;
bool mem = true;
char Error_message[30]="";
void not_ok() {
	success = false;
}
void mem_error() {
	mem = false;
}
void again_true() {
	success = true;
}
void mem_true() {
	mem = true;
}
typedef int* arr_t;
typedef struct arr {
	arr_t ptr;
	int size = 0;
} stack_t;

bool isnoempty(stack_t& st) {
	if (st.size == 0)return false;
	else return true;
}

void clear(stack_t& st) {
	if (st.size != 0)free(st.ptr);
	st.ptr = NULL;
	st.size = 0;
}


void clear_console() {
	system("cls");
}


void st_increase(stack_t& st) {
	st.size++;
	arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
	if (t == NULL) {
		//strcat(Error_message, "ERROR: Realloc field!\n");
		mem_error();
		not_ok();
		clear(st);
		//exit(0);          
	}
	else st.ptr = t;
}

void st_decrease(stack_t& st) {
	st.size--;
	arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
	if (t == NULL) {
		//strcat(Error_message, "ERROR: Realloc field!\n");
		clear(st);
		not_ok();
		mem_error();
		//exit(0);
	}
	else st.ptr = t;
}


void create(stack_t& st) {               
	st.ptr = (int*)malloc(sizeof(int) * st.size);
	if (st.ptr == NULL) {
		//strcat(Error_message, "ERROR: Malloc field!\n");
		not_ok();

		//exit(0);
	}
}

void push(stack_t& st, int new_el) {
	st_increase(st);
	st.ptr[st.size - 1] = new_el;
}

int peak(stack_t& st) {
	if (isnoempty(st) != 0) {
		return st.ptr[st.size - 1];
	}
	else {
		not_ok();
		return -1;
	}
}

int pop(stack_t& st) {
	int buff;
	if (st.size == 0) {
		not_ok();
		return -222;      
	}
	else {
		buff = st.ptr[st.size - 1];
		st_decrease(st);
	}
	return buff;
}

//неправильная работа при 1 элементе
void task4(stack_t& st) {
	if (isnoempty(st)== 0)cout << "Stack is empty!\n\n";
	else {
		int t1 = pop(st);
		if (isnoempty(st) == true) {
			int t2 = pop(st);
			push(st, t1);
			push(st, t2);
			again_true();
		}
		else {
			push(st, t1);  //возвращаем элемент в случае неудачи
			not_ok();
		}
	}	
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
//
string space(string s) {
	return string(17 - s.length(), ' ');
}
void print_stack(stack_t& st) {
	if (isnoempty(st)) {
		cout << "+-----------------+\n";
		for (int i = 0; i < st.size; i++) {
			cout << '|' << st.ptr[i] << space(to_string(st.ptr[i])) << '|' << endl;
		}
		cout << "+-----------------+\n";
	}
	else cout << "#######\n"
		      << "#EMPTY#\n"
			  << "#######\n";
}


void task5(stack_t& st) {
	stack_t temp;
	create(temp);
	while (isnoempty(st)) {
		push(temp, pop(st));
	}
	pop(temp);
	while (isnoempty(temp)) {
		push(st, pop(temp));
	}
	again_true();
}
//обработать когда элемент один
void task6(stack_t& st) {
	stack_t temp;
	create(temp);
	if (success == true) {
		int t1 = pop(st);
		if (success == true) {
			while (isnoempty(st)) {
				push(temp, pop(st));
			}
			int t2 = pop(temp);
			push(temp, t1);
			while (isnoempty(temp)) {
				push(st, pop(temp));
			}
			push(st, t2);

		}
		else cout << "Operation is failed!\n\n";
	}
}
void print_log() {
	if (mem == false) {
		cout << Error_message;
		cout << "Some memory error\n";      //Серьезность	Код	Описание	Проект	Файл	Строка	Состояние подавления
		mem_true();                         //Ошибка	C4996	'strcat': This function or variable may be unsafe.Consider using strcat_s instead.To disable deprecation, 
		                                    //use _CRT_SECURE_NO_WARNINGS.See online help for details.lab4
	}
	else cout << "No errors\n";
}
void menu() {
	stack_t st;
	char choice;
	create(st);
	bool f = false;
	while (f == false) {
		task_info();
		cin >> choice;
		switch (choice) {
		case'1': {
			print_stack(st);
			clear(st);
			cout << "#########\n"
				 << "#Cleaned#\n"
				 << "#########\n\n";
		
			break;
		}
		case'2': {
			int x;
			cout << "Enter value: ";
			cin >> x;
			push(st, x);
			if (success == true) {
				cout << "#########\n"
					<< "#PUSHED#\n"
					<< "#########\n\n";
			}
			else {
				cout << Error_message;
				again_true();
			}
			break;
		}
		case'3': {
			if (success == true) {
				cout << "Peek = " << peak(st) << endl;
				cout << "#########\n"
					<< "#  PEAK #\n"
					<< "#########\n\n";
			}
			else {
				cout << ST_EMPTY;
			}
			again_true();
			break;
		}
		case'4': {
			task4(st);
			print_stack(st);
			if (success == true)
				cout << "#########\n"
				<< "#CHANGED#\n"
				<< "#########\n\n";
			else {
				//cout << "No changes!\n\n";
				again_true();

			}
			break;
		}
		case'5': {
			task5(st);
			print_stack(st);
			if(isnoempty(st)==true)
			cout << "#########\n"
				<< "#DELETED#\n"
				<< "#########\n\n";
			break;
		}
		case'6': {
			task6(st);
			print_stack(st);
			if (success == true) {
				cout << "#########\n"
					<< "#SWAPED #\n"
					<< "#########\n\n";
			}
			else again_true();
			break;
		}
		case'p':print_stack(st); break;
		case'c':clear_console(); break;
		case'l':print_log(); break;
		case'e':f = true; break;
		default:cout << NOT_FOUND; break;
		}
	}
}

int main()
{
	menu();
}


//pop
//pop
//push
//push


//push --перегон
//pop
//push --обратно

//pop ->t1
//task5
//pop ->t2
//push t1
//переворачиватеся 
