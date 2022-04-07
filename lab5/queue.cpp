#include<iostream>
#include"queue.h"
//memory
queue create(queue q){
    q.arr=(arr_t)malloc(0*sizeof(arr_t));
    if(q.arr==NULL){
        //throw("Error: Malloc field!\n");
    }
    q.head=-1;
    q.tail=-1;
    q.size=0;
    return q;
}

void clear(queue&q) {
	free(q.arr);
	q.arr = NULL;
	q.size = 0;
    q.tail=-1;
    q.head=-1;
}

void q_increase(queue&q) {
	q.size++;
	arr_t t = (int*)realloc(q.arr, sizeof(int) * q.size);
	if (t == NULL) {
		//throw(ERROR_REALLOC);
		clear(q);        
	}
	else q.arr = t;
}

void q_decrease(queue&q) {
    for(int i=1;i<q.size;i++){
        q.arr[i-1]=q.arr[i];
    }
	q.size--;
	arr_t t = (int*)realloc(q.arr, sizeof(int) * q.size);
	if (t == NULL) {
		//throw(ERROR_REALLOC);
		clear(q);        
	}
	else q.arr = t;
}

void new_reallocation(queue& q, int new_size) {  
	arr_t temp = (arr_t)realloc(q.arr, (new_size) * sizeof(arr_t*));
	if (temp == NULL && new_size != 0) {
		//throw(ERROR_REALLOC);
	}
	else {
		q.arr = temp;
		q.size = new_size;
	}
}
//memory

//base
bool isempty(queue&q){
    if(q.size==0)return true; 
    else return false;
}

void enqueue(queue&q,int x){
    if(q.tail==-1){
        q.tail++;
        q.head++;
    }
    else{
        q.tail++;
    }
    q_increase(q);
    q.arr[q.tail]=x;
}

int dequeue(queue&q){
    int temp;
    if(isempty(q)==false){
        temp=q.arr[q.head];
        q.tail--;
        q_decrease(q);
    }
    else clear(q);
    return temp;
   
}

void createcopy(queue q, queue& new_q) {	
	new_reallocation(new_q, q.size);
	// if (success == false && mem == false) {
	// 	strcat(Error_message, "ERROR: Copy not created!\n");
	// 	not_ok();
	// 	mem_error();
	// }
	//else {
		for (int i = 0; i < q.size; ++i) {
			new_q.arr[i] = q.arr[i];
		}
        new_q.head=q.head;
        new_q.tail=q.tail;
        new_q.size=q.size;
	//}
}

void q_print(queue&q){
    if(isempty(q)==false){
        cout<<q.head<<" "<<q.tail<<endl;
        for(int i=q.head;i<=q.tail;i++){
            cout<<"<-["<<q.arr[i]<<"]";
        }
        cout<<endl;
    }
    else {
        cout<<QUEUE_EMPTY;
        clear(q);
    }
}
//base