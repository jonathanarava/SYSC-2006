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

				//Part D
struct node *reverseList(struct node *list){

	struct node *reverseHead;

	if(list==NULL ||list->next==NULL){
		return list;
	}
	reverseHead = reverseList(list->next);

	list->next->next = list;
	list->next=NULL;

	return reverseHead;
}

int main(void){

	struct node a = {2,0};
	struct node b = {4, &a};	// test numbers in order: 2, 4, 8, 10
	struct node c = {8, &b};
	struct node d = {10, &c};

	struct node *list1 = &d;

	//Outputting partD: reverseList
	printf("Part D: Reverse List \n");
	print_list(list1);
	printf("\n");
	print_list(reverseList(list1));  // reverses the list to 10, 8, 4, 2
	printf("----------------------------------\n");

	
	
	
	
}
