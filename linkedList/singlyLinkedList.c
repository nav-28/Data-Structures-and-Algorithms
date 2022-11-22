#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;


/*
 * Add a node to its head
 * Time: O(1)
 */
void push(Node **head, int val){
	Node *n = (Node *) malloc(sizeof(Node));
	n->data = val;
	n->next = *head;
	*head = n;
}


/*
 * Add a node to end of linkedList
 * Time: O(n)
 */
void pushEnd(Node **head, int val){
	Node *n = (Node *) malloc(sizeof(Node));
	n->next = NULL;
	n->data = val;
	// if linkedList is Empty add to head
	if (*head == NULL){
		*head = n;
		return;
	}

	Node *temp = *head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
}


/*
 * Insert a node in the middle of a linkedList
 * Time: O(n)
 */
void pushMiddle(Node **head, int val){
	if (*head == NULL){
		push(head, val);
		return;
	}
	Node *fast = *head;
	Node *slow = *head;

	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	// slow will be at the middle
	Node * n = (Node *)malloc(sizeof(Node));
	n->data = val;
	n->next = slow->next;
	slow->next = n;
}

void printList(Node *head){
	while (head){
		if (head->next != NULL)
			printf("%d->", head->data);
		else 
			printf("%d", head->data);
		head = head->next;
	}
	printf("\n\n");

}


/*
 * Delete node at the end
 * Time: O(n)
 */
void deleteEndNode(Node **head){
	if (*head == NULL){
		return;
	}

	Node *curr = *head;
	Node *prev = *head;
	if (curr->next == NULL){
		free(curr);
		return;
	}

	while (curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	free(curr);
}


/*
 * Delete head node
 * Time: O(1)
 */
void deleteHead(Node **head){
	if (*head == NULL)
		return;
	Node *temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

/*
 * Delete the middle Node
 * Time: O(n)
 */
void deleteMiddle(Node **head){
	if (*head == NULL)
		return;

	Node * fast = *head;
	Node * slow = *head;
	Node * prev = *head;

	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}

	prev->next = slow->next;
	free(slow);
}

/*
 * Delete a node with the given val
 * Note use **Node
 * Time: O(n)
 */
void deleteNode(Node **head, int val){
	Node *curr = *head;
	Node *prev = *head;
	while(curr){
		if(curr->data == val ){
			// condition if head contains the value
			if (curr == *head){
				*head = curr->next;
				free(curr);
				return;
			}
			else {
				prev->next = curr->next;
				free(curr);
				return;
			}
		}
		else{
			prev = curr;
			curr = curr->next;

		}

	}

}

/*
 * delete multiple occurences of a value
 *
 */
void deleteMul(Node **head, int val){
	Node * temp = *head;
	Node * prev = *head;
	Node * tt;
	while (temp != NULL){
		if (temp->data == val){
			if (temp == *head){
				prev = temp->next;
				free(temp);
				*head = prev;
				temp = *head;
			}
			else{
				tt = temp;
				temp = temp->next;
				free(tt);
				prev->next = temp;
			}
		}

		else{
			prev = temp;
			temp = temp->next;
		
		}
	}

}


int main(){


	// create node
	Node *list = (Node *) malloc(sizeof(Node));
	list->next = NULL;

	printf("Creating LinkedList\n");
	// testing push
	push(&list, 2);
	push(&list, 2);
	push(&list, 1);
	push(&list, 2);
	push(&list, 3);
	push(&list, 2);
	push(&list, 4);
	push(&list, 2);
	printList(list);
	printf("Inserting at the end\n");
	pushEnd(&list, 10);
	pushEnd(&list, 9);
	pushEnd(&list, 8);
	pushEnd(&list, 7);
	printList(list);
	printf("Inserting at the middle\n");

	pushMiddle(&list, 5);
	pushMiddle(&list, 25);

	//print
	printList(list);


	// deleting test
	printf("deleting 4\n");
	deleteNode(&list, 4);
	printList(list);


	printf("deleting all 2s\n");
	deleteMul(&list, 2);	
	printList(list);

	printf("deleting end node\n");
	deleteEndNode(&list);
	printList(list);

	printf("deleting head node\n");
	deleteHead(&list);
	printList(list);

	printf("deleting middle node\n");
	deleteMiddle(&list);
	printList(list);




	return 0;
}



