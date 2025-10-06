#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // cấp phát dộng cho 1 node mới
    newNode->data = data;
    newNode->next = NULL; // khởi tạo con trỏ next là NULL để tránh lỗi truy cập vùng nhớ rác và duyệt danh sách liên kết
    return newNode;
}

void printlist(Node *head) // truyền con trỏ đầu danh sách vào hàm giống như truyền tham trị,
                           // không làm thay đổi con trỏ đầu danh sách
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void pushFront(Node **head, int data) // truyền con trỏ đến con trỏ đầu danh sách để có thể thay đổi con trỏ đầu danh sách
{
    Node *newNode = createNode(data);
    newNode->next = *head; // toán từ dải tham chiếu để truy cập và thay đổi con trỏ đầu danh sách
    *head = newNode;       // cập nhật con trỏ đầu danh sách để trỏ đến node mới
}
void pushBack(Node **head, int data)
{
    Node *newNode = createNode(data);
    Node *current = *head; // vì truyền con trỏ của con trỏ head nên *head là giá trị của con trỏ head,
                           // khác với pushFront truyền vào  con trỏ head nên head là giá trị của con trỏ head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while (current->next != NULL) //  trỏ đến node cuối cùng ,
                                      // chú ý nnode cuối không phải là NULL mà node cuối có con trỏ next là NULL
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
int countNodes(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insertNode(Node **head, int data, int position)
{
    Node *newNode = createNode(data);
    Node *current = *head;
    if (position == 1)
    {
        pushFront(head, data); // gọi hàm pushFront để chèn node vào đầu danh sách
        return;
    }
    if (position < 1 || position > countNodes(*head) + 1) // vì khai báo **head nên phải truyền *head vào hàm countNodes
    {
        printf("Position is out of range\n");
        return;
    }
    else
    {
        int index = 1;
        while (current->next != NULL && index < position - 1) // dừng đúng vị trí cần chèn
        {
            current = current->next;
            index++;
        }
        newNode->next = current->next;
        current->next = newNode;
        while (current->next != NULL) // di chuyển con trỏ current đến cuối danh sách để tránh lỗi truy cập vùng nhớ rác
        {
            current = current->next;
        }
    }
}
void DeleteFirstNode(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = *head;
    *head = current->next;
    free(current); // free dùng để giải phóng vùng nhớ đã cấp phát động
}
void DeleteLastNode(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = *head;
    if (current->next == NULL)
    {
        free(current);
        *head = NULL;
        return;
    }
    while (current->next->next != NULL) // dừng ở node kế cuối để xóa node cuối
    {
        current = current->next;
    }
    free(current->next);  // giải phóng vùng nhớ của node cuối,
                          // tuy nhiên con trỏ next của node kế cuối vẫn trỏ đến vùng nhớ đã giải phóng ( dangling pointer)
    current->next = NULL; // cập nhật con trỏ next của node kế cuối thành NULL để tránh lỗi truy cập vùng nhớ rác
}
void deleteNodeAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (position < 1 || position > countNodes(*head))
    {
        printf("Position is out of range\n");
        return;
    }
    Node *current = *head;
    if (current->next == NULL)
    { // danh sách chỉ có 1 node
        free(current);
        *head = NULL;
        return;
    }
    if (position == 1)
    {
        DeleteFirstNode(head);
        return;
    }
    int index = 1;

    while (current->next != NULL && index < position - 1)
    {
        current = current->next;
        index++;
    }
    current->next = current->next->next;
    free(current->next);
}

void sortNode(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    for (Node *i = *head; i->next != NULL; i = i->next)
    {
        Node *minNode = i;
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (minNode->data > j->data)
            {
                minNode = j;
            }
        }
        int temp = minNode->data;
        minNode->data = i->data;
        i->data = temp;
    }
}
int main()
{
    Node *head = NULL;
    for (int i = 1; i <= 5; i++)
    {
        pushFront(&head, i); // &head truyền địa chỉ của con trỏ đầu danh sách
                             // để hàm pushFront có thể thay đổi con trỏ đầu danh sách
    }
    int choice, data, position;

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node at Position\n");
        printf("7. Print List\n");
        printf("8. Count Nodes\n");
        printf("9. Sort List nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            pushFront(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            pushBack(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertNode(&head, data, position);
            break;
        case 4:
            DeleteFirstNode(&head);
            break;
        case 5:
            DeleteLastNode(&head);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deleteNodeAtPosition(&head, position);
            break;
        case 7:
            printlist(head);
            break;
        case 8:
            printf("Total nodes: %d\n", countNodes(head));
            break;
        case 9:
            printf("Sort list nodes \n");
            sortNode(&head);
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}