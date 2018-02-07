#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node Node;
struct node{ 		//declaration of structure
	int value; 	
	struct node *next; // structure that points to the next node in the queue 
}; 

Node *head1 = NULL; // pointer for the first linked list
Node *head2 = NULL; // pointer for the second linked list

void list1 (int value){ 		// void function created that makes the first list
    Node *p = malloc(sizeof(Node)); // allocates memory
    p->value=value; 				// stores the value
    p->next=head1;
    head1=p;
}

void list2 (int value){			// void function that makes the second list
    Node *p1 = malloc(sizeof(Node));   // allocates memory
    p1->value=value;					// stores the value
    p1->next=head2;
    head2=p1;
}

void display1(void) {
    Node *current;
    current = head1;
    if(current!= NULL) {
    	printf("List is: ");
         while (current!= NULL){
            printf("%d ",current->value);
            current = current->next;
		}
        printf("\n\n");
    }
    
 
}
void display2(void) {
    Node *current;
    current = head2;
    if(current!= NULL) {
    	printf("List is: \n");
         while (current!= NULL){
            printf("%d ",current->value); //print the data in each node
            current = current->next;
	}
        printf("\n\n");
    }
  
 
}




void appendLists (Node *head1, Node *head2) {	// function that appends the 2 lists
	
	Node *append = head1;
	while (append->next != NULL) {
		append = append->next;
	}
	append->next = head2;			
}



int main(void) {
    list1(6);
    list1(50);		// test values for list 1 and list 2
    display1();
    display2();
    list2(40);
    list2(125);
    list2(70);
    display2();
	appendLists(head1, head2);	//appends the 2 lists
	display1();
	

    return 0;
}


