#include<iostream>
#include"stack.h"
using namespace std;

void clear_console() {
	system("cls");
}
void task4(stack_t& st) {
	stack_t newstack;
	createcopy(st,newstack);
	if (success == false) {
        clear(newstack);
		return;
	}
	if (isnoempty(newstack)== false)cout << "Stack is empty!\n\n";
	else {
		int t1 = pop(newstack);
		if (isnoempty(newstack) == true) {

			int t2 = pop(newstack);
			if (mem == false && success == false) {
				not_ok();
                clear(newstack);
				return;
			}
			push(newstack, t1);
			if (mem == false && success == false) {
				not_ok();
                clear(newstack);
				return;
			}
			push(newstack, t2);
			if (mem == false && success == false) {
				not_ok();
                clear(newstack);
				return;
			}
			clear(st);
			st = newstack;
		}
		else {
			not_ok();
		}
	}	
}

void task5(stack_t& st) {
	stack_t newstack;
	createcopy(st,newstack);
	stack_t temp;
	create(temp);
	while (isnoempty(newstack)) {
        if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
		push(temp, pop(newstack));
	}
	pop(temp);
	while (isnoempty(temp)) {
        if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
		push(newstack, pop(temp));
	}
	clear(st);
	if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
	st = newstack;
}

void task6(stack_t& st) {
	stack_t newstack;
	createcopy(st, newstack);
	stack_t temp;
	create(temp);
	if (success == true) {
		int t1 = pop(newstack);
		if (mem == true && success == true) {
			while (isnoempty(newstack)) {
				if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
				push(temp, pop(newstack));
			}
			if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
			int t2 = pop(temp);
			if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
			push(temp, t1);
			if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
			while (isnoempty(temp)) {
				if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
				push(newstack, pop(temp));
			}
			if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
			push(newstack, t2);
			if (mem == false && success == false) { clear(newstack);not_ok(); mem_error(); return; }
			st = newstack;
		}
	}
}

void task_info() {
	cout<< "(1)Clear stack   (1)\n"        //
		<< "(2)Add to stack  (2)\n"		//!
		<< "(3)Peek          (3)\n"		//!
		<< "(4)Change n-1 & n(4)\n"		//!
		<< "(5)Delete bottom (5)\n"		//
		<< "(6)Change 1 & n  (6)\n"		//
		<< "(p)PrintStack    (p)\n"		//
		<< "(c)Clear Console (c)\n"		//!
		<< "(e)EXIT          (e)\n";
}
void print_log() {
	if (mem == false) {
		cout << Error_message;
		cout << "Some memory error\n";    
		mem_true();                         

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
			peak(st);
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
			
			if (isnoempty(st)&&success == true) {
				print_stack(st);
				cout << "#########\n"
					<< "#CHANGED#\n"
					<< "#########\n\n";
			}
			else {
				cout << "No changes!\n\n";
				again_true();
			}
			break;
		}
		case'5': {
			task5(st);
			if (mem == true && success == true) {
				print_stack(st);
				if (isnoempty(st) == true)
					cout << "#########\n"
					<< "#DELETED#\n"
					<< "#########\n\n";
				break;
			}
			else {
				again_true();
				mem_true();
			}

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
int main(){}
