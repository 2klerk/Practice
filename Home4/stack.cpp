#include<iostream>
#include"stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include<string>

using namespace std;

bool mem = true;
char Error_message[30]="";
bool success=true;

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

bool isnoempty(stack_t& st) {
	if (st.size == 0)return false;
	else return true;
}

void clear(stack_t& st) {
	if (st.size != 0)free(st.ptr);
	st.ptr = NULL;
	st.size = 0;
}


void st_increase(stack_t& st) {
	st.size++;
	arr_t t = (int*)realloc(st.ptr, sizeof(int) * st.size);
	if (t == NULL) {
		strcpy(Error_message, "ERROR: Realloc field!\n");
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
	if (st.size!=0 &&t == NULL) {                           //так как при размере 0 t=Null
		strcpy(Error_message, "ERROR: Realloc field!\n");
		not_ok();
		mem_error();
		clear(st);
		//exit(0);
	}
	else st.ptr = t;
}


void create(stack_t& st) {               
	st.ptr = (int*)malloc(sizeof(int) * st.size);
	if (st.ptr == NULL) {
		strcat(Error_message, "ERROR: Malloc field!\n");
		not_ok();
		//exit(0);
	}
}
void new_reallocation(stack_t& stack, int new_size) {  
	arr_t temp = (arr_t)realloc(stack.ptr, (new_size) * sizeof(arr_t*));
	if (temp == NULL && new_size != 0) {
		strcat(Error_message, "ERROR: Realloc field!\n");
		not_ok();
		mem_error();
	}
	else {
		stack.ptr = temp;
		stack.size = new_size;
		again_true();
	}
}

void createcopy(stack_t st, stack_t& newstack) {	
	new_reallocation(newstack, st.size);
	if (success == false && mem == false) {
		strcat(Error_message, "ERROR: Copy not created!\n");
		not_ok();
		mem_error();
	}
	else {
		for (int i = 0; i < newstack.size; ++i) {
			newstack.ptr[i] = st.ptr[i];
		}
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