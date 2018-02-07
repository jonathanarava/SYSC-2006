#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



struct node {
	int value;
	struct node *next;
};

void print_list(struct node *base){
	while (base!=NULL){
		printf("%d ", base->value);
		base = base->next;
	}
	printf("\n");
}

					//Part C
struct node *eliminateFromList(struct node *list, int number){
	if (list==NULL){
		return NULL;
	}
	if(list->value == number){
		struct node *tempNext;

		tempNext = list->next;

		free(list); 		//Deallocate the node
		return tempNext;
	} 

	list->next = eliminateFromList(list->next, number);

	return list;
}
int main(void){

	struct node a = {2,0};
	struct node b = {3, &a};  // numers used for the test: 2, 3, 4, 6
	struct node c = {4, &b};
	struct node d = {6, &c};

	struct node *list1 = &d;


	//Prints Part C: eliminateFromList
	printf("Part C: Eliminate from List \n");
	print_list(list1);
	printf("\n");
	print_list(eliminateFromList(list1,3)); // test case, eliminates 3 from the list
	printf("----------------------------------\n");

	
}
