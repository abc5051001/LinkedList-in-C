/*
Shawn Lai G01182226
CS 262, Project 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct element{
	int randomInt;
	struct element *next;
};

typedef struct element node;


void insertNodeSorted(node*,int);
void printList(node*);
node *locate(node *, int);
void deleteList(node*);

int main(int argc, char *argv[]){
	int i, S, N, Max_val;
	node *start = NULL;
	if (argc != 4){
		perror("Error! Missing input values for <Seed> <Numbers> <Max_val>");
		exit(1);
	}
	for(i = 0; i < argc; i++){
		if(atoi(argv[i]) < 0){
			perror("All input values must be >0");
			exit(1);
		}
	}
	S = atoi(argv[1]);
	N = atoi(argv[2]);
	int rans[N];
	start = (node*) malloc(sizeof(node));
	start -> next = NULL;

	Max_val = atoi(argv[3]);
	srand(S);
	printf("--- Input Values: ------------\n Seed: %d\n Numbers: %d\n Interval [0,%d]\n------------------------------\n",S,N,Max_val);
	printf("Random Number\n");
	for(i = 0; i<N; i++){
		rans[i] = rand() %(Max_val+1);
		insertNodeSorted(start, rans[i]);
		printf("%d ",rans[i]);
	}
	printf("\n");
	printList(start -> next);
	deleteList(start);
	return 0;	
}


void insertNodeSorted(node *current, int num){
	node *insert, *temp;
	temp = locate(current,num);
	insert = (node*) malloc(sizeof(node));
	insert -> randomInt = num;
	insert -> next = temp -> next;
	temp -> next = insert;
	return;
}
node *locate(node *current,int num){
	node *temp = current;
	if(temp -> next == NULL){
		return(temp);
	}
	else{
		if(temp -> next -> randomInt > num){
			return(temp);
		}
		return locate(temp -> next, num);
	}
}

void printList(node *current){
	if(current == NULL){
		return;
	}
	printf("%d ", current->randomInt);
	printList(current->next);
}

void deleteList(node *current){
	node *deleted;
	if(current == NULL){
		return;
	}

	deleted = current -> next;
	free(current);
	deleteList(deleted);
}
