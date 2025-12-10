#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n = 0;  // current size of array

void display() {
    if(n == 0) {
        printf("\nArray is Empty!\n");
        return;
    }
    printf("\nArray Elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertBeginning() {
    if(n == MAX) {
        printf("\nArray is Full! Cannot Insert.\n");
        return;
    }
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    for(int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    n++;
    printf("\nInserted at Beginning Successfully.\n");
}

void insertEnd() {
    if(n == MAX) {
        printf("\nArray is Full! Cannot Insert.\n");
        return;
    }
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    arr[n] = value;
    n++;
    printf("\nInserted at End Successfully.\n");
}

void insertPosition() {
    if(n == MAX) {
        printf("\nArray is Full! Cannot Insert.\n");
        return;
    }
    int pos, value;
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    if(pos < 1 || pos > n + 1) {
        printf("\nInvalid Position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for(int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    n++;
    printf("\nInserted at Position %d Successfully.\n", pos);
}

void deleteBeginning() {
    if(n == 0) {
        printf("\nArray is Empty! Cannot Delete.\n");
        return;
    }
    printf("\nDeleted %d from Beginning.\n", arr[0]);
    for(int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void deleteEnd() {
    if(n == 0) {
        printf("\nArray is Empty! Cannot Delete.\n");
        return;
    }
    printf("\nDeleted %d from End.\n", arr[n - 1]);
    n--;
}

void deletePosition() {
    if(n == 0) {
        printf("\nArray is Empty! Cannot Delete.\n");
        return;
    }
    int pos;
    printf("Enter position (1 to %d): ", n);
    scanf("%d", &pos);
    if(pos < 1 || pos > n) {
        printf("\nInvalid Position!\n");
        return;
    }

    printf("\nDeleted %d from Position %d.\n", arr[pos - 1], pos);
    for(int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main() {
    int choice;

    printf("\n===== ARRAY SIMULATION PROJECT =====\n");

    // Take initial array input from user
    printf("Enter initial number of elements (Max %d): ", MAX);
    scanf("%d", &n);

    if(n > MAX || n < 0) {
        printf("Invalid Size! Setting size to 0.\n");
        n = 0;
    } else if(n > 0) {
        printf("Enter %d elements:\n", n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
    }

    while(1) {
        printf("\n-------------------------------------\n");
        printf("1. Display Array\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Specific Position\n");
        printf("8. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: display(); break;
            case 2: insertBeginning(); break;
            case 3: insertEnd(); break;
            case 4: insertPosition(); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: 
                printf("\nThank You! Exiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }
    return 0;
}