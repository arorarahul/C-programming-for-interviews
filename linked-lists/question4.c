/*
Iterative program to reverse a linked list
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void reverse(struct node  **head){
	//reversing the list
	struct node *curr, *prev,*nextNode;
	curr = *head;
	
	prev = NULL;
	while(curr){
		nextNode = curr->link;
		curr->link = prev;
		prev = curr;
		curr = nextNode;
		
	}
	*head = prev; //assigning the address the updated value
}

void printList(struct node *t){
	if(t){
		//interchanging these lines will print it in reverse order
		printf("%d\n", t->data);
		printList(t->link);
	}
}

int main(){

	struct node *head = (struct node *)malloc(sizeof(struct node));

	struct node *t = head;

	int counter = 1;
	while(counter<=5){

		t->data = counter*10;
		if(counter == 5){
			t->link = NULL;
		}else{
			t->link = (struct node *)malloc(sizeof(struct node));
		}

		t = t->link;

		counter++;
	}
	t = head;
	printList(t);
	t = head;
	
	reverse(&head); //passing the address of the pointer pointing to the first address of the linked list
	printList(head);

}	