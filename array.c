#include <stdio.h>
#define MAX 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int element, int pos) {
    if (*n >= MAX) {
        printf("Insertion failed! Array is full.\n");
        return;
    }
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = element;
    (*n)++;
    printf("Element %d inserted at position %d.\n", element, pos);
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Deletion failed! Array is empty.\n");
        return;
    }
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    int deleted = arr[pos - 1];
    for (int i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
    printf("Deleted element %d from position %d.\n", deleted, pos);
}

int main() {
    int arr[MAX], n, choice, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display Array\n2. Insert Element\n3. Delete Element\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(arr, &n, element, pos);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
