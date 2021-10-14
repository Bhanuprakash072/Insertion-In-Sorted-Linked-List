/* Program to insert in a sorted list */
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void sortedInsert(struct Node** head_ref,struct Node* new_node)
{
	struct Node* current;
	if (*head_ref == NULL || (*head_ref)->data>= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		current = *head_ref;
		while (current->next != NULL && current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

struct Node* newNode(int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	int n;
	printf("Enter the number of nodes. n=");
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		int temp;
		printf("Enter the value of %d-th node: ", i);
		scanf("%d",&temp);
		struct Node* new_node = newNode(temp);
		sortedInsert(&head, new_node);
	}

	printf("Created Linked List: ");
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");

	return 0;
}
