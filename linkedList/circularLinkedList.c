#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;



int listLength(Node *head){
    if (head == NULL)
        return 0;;
    Node *curr = head;
    int count = 0;
    do{
        curr = curr->next;
        count++;
    }while(curr != head);

    return count;
}


void printList(Node *head){
    if (head == NULL)
        return;

    Node *curr = head;
    do {
        printf("%d->",curr->data);
        curr = curr->next;
    }while(curr != head);

    printf("\n");
}


void insertHead(Node **head, int val){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;

    if (*head == NULL){
        n->next = n;
        *head = n;
        return;
    }

    Node *curr = *head;
    while (curr->next != *head)
        curr = curr->next;

    curr->next = n;
    n->next = *head;
    *head = n;

}

void insertEnd(Node **head, int val){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    if (*head == NULL){
        *head = n;
        n->next = *head;
        return;
    }

    Node *curr = *head;
    while (curr->next != *head)
        curr = curr->next;

    curr->next = n;
    n->next = *head;

}

void deleteLast(Node **head){
    if (*head == NULL)
        return;

    Node *curr = *head;
    Node *prev = *head;
    while (curr->next != *head){
        prev = curr;
        curr = curr->next;
    }

    prev->next = *head;
    free(curr);
}


void deleteHead(Node **head){
    if (*head == NULL)
        return;

    Node *curr = *head;

    while (curr->next != *head){
        curr = curr->next;
    }

    curr->next = (*head)->next;
    *head = (*head)->next;
    free(*head);

}


void deleteVal(Node **head, int val){
    if (*head == NULL)
        return;

    Node *curr = *head;
    Node *prev = *head;
    Node *t;
    while(curr->next != *head){
        if (curr->data == val){
            t = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(t);
            return;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    if (curr->data == val){
        t = curr;
        prev->next = curr->next;
        free(t);
    }
}

Node * createList(int val){
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = val;
    n->next = n;
    return n;
}


int main(){
    printf("creating circular linked list\n");
    Node *list = createList(1);
    insertEnd(&list, 2);
    insertEnd(&list, 3);
    insertEnd(&list, 4);
    insertEnd(&list, 5);
    insertEnd(&list, 6);
    printList(list);

    printf("inserting from head\n");
    insertHead(&list, 0);
    insertHead(&list, -1);
    insertHead(&list, -2);
    insertHead(&list, -3);
    printList(list);

    printf("delete last\n");
    deleteLast(&list);
    printList(list);

    printf("delete val 0\n");
    deleteVal(&list, 0);
    printList(list);
}
