#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

// Tạo node mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// In danh sách (chỉ để kiểm tra)
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Thêm node vào đầu stack (Push)
void pushNode(Node **top, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// Xóa node đầu stack (Pop)
void popNode(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

// Trả về giá trị đầu stack (Top)
int Top(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
        return -1; // giá trị báo lỗi
    }
    return top->data;
}

// Đếm số node trong stack (Size)
int sizeListNode(Node *top)
{
    int count = 0;
    Node *current = top;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    int choice, value;
    Node *stack = NULL; // stack rỗng ban đầu

    while (1)
    {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Size\n");
        printf("5. Print Stack\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            pushNode(&stack, value);
            printf("Pushed %d onto stack.\n", value);
            break;
        case 2:
            popNode(&stack);
            printf("Popped top element.\n");
            break;
        case 3:
            value = Top(stack);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;
        case 4:
            printf("Stack size: %d\n", sizeListNode(stack));
            break;
        case 5:
            printf("Stack contents: ");
            printList(stack);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
