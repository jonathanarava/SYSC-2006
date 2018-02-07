#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct node Node;
struct node {
	int value;
	int priority;
	struct node *next;
}*front = NULL;

void print_list(struct node *base){
	while (base!=NULL){
		printf("%d ", base->value);
		base = base->next;
	}
	printf("\n");
}

							//Part A
void enqueue (int number , int priority_number){ // void function created to 
												 //takes in a value and a priority number

	 Node *p = malloc(sizeof(Node)); 
	 Node *temp=NULL; 
	 assert(p!=NULL); 
		
	if (priority_number >0 && priority_number<11){
	
		p->value=number; 
		p->priority= priority_number; 
		

		if (front==NULL || priority_number > front->priority){ 
			p->next= front; 
			front=p; 
		}
		else{
			temp=front; 
			while (temp->next!=NULL && temp->next->priority <=priority_number){ // searches the list as long as the element is not null and 
				temp=temp->next;												//the priority number the user enters is greater than 
				p->next=temp->next; 											//its previous priority number
				temp->next=p; 
				
				 
			}
		}

	}
}

int dequeue (void){ 
	Node *temp;
	int remove_element;
	if (front==NULL){ 
		printf("Empty Queue");
		exit(1);
	}
	else{
		temp=front; 
		remove_element= temp->value; 
		printf ("removed element %d\n", remove_element);
		front =front->next; // moves down to the next element
		free(temp);		// removes the element from the queue which is the first element
	}

	return 0;
}
void display (void){ 
	Node *p_2;
	p_2= front; 					// points to the front of the queue
	if (front ==NULL){ 			    // if there is no element then it is empty
		printf("Empty Queue");
	}
	else{
		while (p_2!=NULL){
			printf("Queue: %d\n Priority item: %d\n", p_2 ->value,p_2 ->priority); 
			
			p_2=p_2->next;   // prints untill it reaches the end of the list
			printf("\n");
		}
	}

}

int main(void){
	
	//partA
	enqueue(1,2); // sample test cases
	enqueue(2,1);
	enqueue(3,3);
	enqueue(6,5);
	enqueue(8,10);
	dequeue(); //removes 8 because it is the element that is added last
	display();
}
