#pragma once
#define INIT_QUEUE 3
#define ERROR_REALLOC "ERROR:Reallocation failed!\n"
#define QUEUE_EMPTY   "Queue is empty!\n"
#include <exception>
#include <string>
using namespace std;
typedef int*arr_t;
typedef struct array{
    arr_t arr;
    int size;
    int tail;
    int head;
}queue;
//extern bool error;
queue create(queue q);
void clear(queue&q);
void q_increase(queue&q);
void q_decrease(queue&q);
void q_print(queue&q);
int dequeue(queue&q);
void enqueue(queue&q,int x);
bool isempty(queue&q);
void createcopy(queue q, queue& new_q);