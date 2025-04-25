#include<stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i;

    for(i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;
        if(hashTable[newIndex] == -1){
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash table is Full\n");
}

void search(int key) {
    int index = hash(key);
    for(int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;
        if(hashTable[newIndex] == key){
            printf("Found %d at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Not Found\n");
}

void delete(int key) {
    int index = hash(key);
    for(int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;
        if(hashTable[newIndex] == key){
            hashTable[newIndex] = -1;
            printf("Deleted %d at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Element not present\n");
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d => %d\n", i, hashTable[i]);
}

int main() {
    int choice, key;
    init();

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