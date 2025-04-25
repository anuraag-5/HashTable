#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = key;
    newNode -> next = hashTable[index];
    hashTable[index] = newNode;

    printf("Element %d inserted at index %d\n", key, index);
}

void search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while(temp) {
        if(temp -> data == key){
            printf("Found %d at index %d\n", key, index);
            return;
        }

        temp = temp -> next;
    }

    printf("Not found\n");
}

void delete(int key) {
    int index = hash(key);

    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while(temp) {
        if(temp -> data == key){
            if(prev)
                prev -> next = temp -> next;
            else {
                hashTable[index] = temp -> next;
            }
            printf("Deleted %d from index %d\n", key, index);
            free(temp);
            return;
        }

        prev = temp;
        temp = temp -> next;
    }
    printf("Key not found\n");
}

void display() {
    int i;
    for(i = 0; i < SIZE; i++) {
        printf("Index %d: ",i);
        struct Node *temp = hashTable[i];

        while(temp){
            printf("%d -> ",temp -> data);
            temp = temp -> next;
        }

        printf("NULL\n");
    }
}

int main() {
    int choice = 0,key;

    while(choice != 5){
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter key: "); scanf("%d", &key); insert(key); break;
            case 2: printf("Enter key: "); scanf("%d", &key); search(key); break;
            case 3: printf("Enter key: "); scanf("%d", &key); delete(key); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
        }
    }

    return 0;
}