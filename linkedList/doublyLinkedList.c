#include <stdio.h>
#include <stdlib.h>




typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;


/*
 * Insert Node at Head
 * Time: O(1)
 */
void insertHead(Node ** head, int val){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;
    n->next = NULL; n->prev = NULL;
    n->next = *head;
    (*head)->prev = n;
    *head = n;

}

/*
 * Insert Node at the end of list
 * Time: O(n)
 */
void insertEnd(Node **head, int val){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;
    n->next = NULL; n->prev = NULL;
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void insertMiddle(Node **head, int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL; n->prev = NULL;
    Node *fast = *head;
    Node *slow = *head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    n->next = slow->next;
    n->prev = slow;
    slow->next->prev = n;
    slow->next = n;
}


void insertPosition(Node **head, int val, int position){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;
    n->next = NULL; n->prev = NULL;
    Node *temp = *head;
    int k = 0;
    while(temp != NULL && k != position){
        temp = temp->next;
        k++;
    }

    if (k == position){
        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
        n->next->prev = n;
    }
}


void deleteHead(Node **head){
    if (*head == NULL)
        return;

    Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;

    free(temp);

}

void deleteEnd(Node **head){
    Node *temp = *head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}


void deleteMiddle(Node **head){
    Node *fast = *head;
    Node *slow = *head;
    Node *temp;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    temp = slow;
    slow->prev->next = slow->next;
    slow->next->prev = slow->prev;
    free(temp);

}


void deleteMultiple(Node **head, int val){
    Node *curr = *head;
    Node *t;
    while (curr != NULL){
        if (curr->data == val){
            if (curr == *head){
                t = curr;
                *head = curr->next;
                (*head)->prev = NULL;
                curr = *head;
                free(t);
            }
            else {
                t = curr;
                if (curr->next == NULL){
                    curr->prev->next = NULL;
                    free(t);
                    break;
                }
                else{
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr = curr->next;
                free(t);

                }
            }
        }
        else {
            curr = curr->next;
        }
    }
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

Node * createList(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    n->prev = NULL;
    n->data = val;
    return n;
}

int main(){


    printf("Creating Doubly Linked List\n");
    Node *list = createList(1);
    insertHead(&list, 2);
    insertHead(&list, 3);
    insertHead(&list, 20);
    insertHead(&list, 5);
    insertHead(&list, 4);
    printList(list);

    printf("Inserting Node at the end\n");
    insertEnd(&list, 10);
    insertEnd(&list, 8);
    insertEnd(&list, 9);
    insertEnd(&list, 20);
    insertEnd(&list, 7);
    printList(list);

    printf("Inserting Node at the Middle\n");
    insertMiddle(&list, 6);
    insertMiddle(&list, 5);
    printList(list);

    printf("Inserting Node at position 3\n");
    insertPosition(&list, 3, 3);
    printList(list);

    printf("Deleting Head\n");
    deleteHead(&list);
    printList(list);

    printf("Deleting End Node\n");
    deleteEnd(&list);
    printList(list);

    printf("deleting middle node\n");
    deleteMiddle(&list);
    deleteMiddle(&list);
    printList(list);

    printf("deleting multiple values\n");
    deleteMultiple(&list, 20);
    printList(list);
    deleteEnd(&list);
    printList(list);
}
