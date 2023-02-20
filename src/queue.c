
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPOS  4
#define EMPTY  -1


struct Queue{
	int queueVect[MAXPOS];
	int front;
	int lastElement;
};

typedef struct Queue Queue;

void setup(Queue *ptrQueue){
	ptrQueue->front = EMPTY;
	ptrQueue->lastElement = EMPTY;
}

int isEmpty(Queue *ptrQueue){
	if(ptrQueue->lastElement==EMPTY && ptrQueue->front==EMPTY) {
		return 1;
	}else{
		return 0;
	}
}

void popElement(Queue *ptrQueue){
	if(isEmpty(ptrQueue)){
		printf("queue is Empty!\n");	
	}else{
		int data = ptrQueue->queueVect[ptrQueue->front];
		printf("%d data was poped!\n",data);
		ptrQueue->front++;
		if(ptrQueue->front >  ptrQueue->lastElement){
			setup(ptrQueue);
		}
	}
}

int isFull(Queue *ptrQueue){
	if(ptrQueue->lastElement<MAXPOS){
		return 0;
	}else{
		return 1;
	}
}

void saveData(Queue *ptrQueue, int data){
	ptrQueue->lastElement++;
	ptrQueue->queueVect[ptrQueue->lastElement]=data;
	printf("%d data was pushed at %d! \n", data, ptrQueue->lastElement);
}

void pushElement(Queue *ptrQueue, int data){
	if(isEmpty(ptrQueue)){
		ptrQueue->front++;
		saveData(ptrQueue, data);
	}else if(!isFull(ptrQueue)){	
		saveData(ptrQueue, data);
	}else{
		printf("queue is Full!\n");
	}
}

void fShow(Queue *ptrQueue){
	printf("queue front: [ ");
	for(int i=ptrQueue->front; i<=ptrQueue->lastElement; i++){
		printf("%d ",ptrQueue->queueVect[i]);
	}
	printf("] queue end \n");
}

int main(void)
{
	Queue queue;

	char  input[] = {'\0','\0','\0','\0','\0','\0'};
	char  comand[4] = {'\0','\0','\0','\0'};
	char  end[]   = "exit";
	int   data = 0;
	int   endProgram = 0;

	printf(	"Begin of the queue \n");
	setup(&queue);
	do{
	
    // Read the standart input of the terminal
		input[0] ='\0';
		comand[0] = '\0';
		fscanf(stdin,"%s",input);

		strcpy(comand, input);
		comand[4] = '\0';		
		
		if(!strcmp("pop",comand)){	
			
			printf("Pop comand\n");
			popElement(&queue);

		}else if(!strcmp("push",comand)){
			
 			printf("Push comand!\n");
			data = -('0' - input[4] );
			pushElement(&queue,data);
			data = 0;
			
		}else if(!strcmp("show",comand)){
		
			fShow(&queue);
		
		}else if(!strcmp(end,comand)){
		
			printf("Exit comand!\n");
			endProgram = 1;
		
		}else{
			printf("Comand not found!\nTry: push or pop\n");
		}
		
	}while(!endProgram);
	return 0;
}
