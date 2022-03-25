#ifndef STACK_H
#define STACK_H
#define NOT_FOUND       "Command not found!\n"
#define NO_SPACE        "ERROR: No more space!\n"
#define ST_EMPTY        "Stack is empty\n\n"
typedef int* arr_t;
typedef struct arr {
	arr_t ptr=NULL;
	int size = 0;
} stack_t;
extern bool mem ;
extern char Error_message[30];
extern bool success;
void mem_true();
void not_ok();
void mem_error();
void again_true();
bool isnoempty(stack_t& st);
void clear(stack_t& st);
void st_increase(stack_t& st);
void st_decrease(stack_t& st);
void create(stack_t& st);
void createcopy(stack_t st, stack_t& newstack);
int peak(stack_t& st);
void push(stack_t& st, int new_el);
int pop(stack_t& st);
void print_log();
void print_stack(stack_t& st);
#endif