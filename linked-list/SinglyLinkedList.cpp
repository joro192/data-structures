#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
};

// counts the number of nodes in the list
int ListLength(struct ListNode *head)
{
    struct ListNode *current = head;
    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

void ShowLinkedList(ListNode *head)
{
    struct ListNode *current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

// insert a new node into the list
void InsertInLinkedList(struct ListNode **head, int data, int position)
{
    int k = 1;
    struct ListNode *p, *q, *newNode;
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

    if (!newNode)
    {
        cout << "Memory Error";
        return;
    }

    newNode->data = data;
    p = *head;

    // inserting at the beginning
    if (position == 1)
    {
        newNode->next = p;
        *head = newNode;
    }
    else
    {
        // traverse the list until the position where we want to insert
        while (p != NULL && k < position)
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode; // more optimum way tho do this
        newNode->next = p;
    }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position)
{
    int k = 1;
    struct ListNode *p, *q;
    if (*head == NULL)
    {
        cout << "List Empty";
        return;
    }

    p = *head;

    // from the beginning
    if (position == 1)
    {
        *head = (*head)->next;
        free(p);
        return;
    }
    else
    {
        // traverse the list arriving ar the position from which we wanr to delete
        while (p != NULL && k < position)
        {
            k++;
            q = p;
            p = p->next;
        }

        if (p == NULL)
            cout << "Position does not exist";
        else
        {
            q->next = p->next;
            free(p);
        }
    }
}

void DeleteLinkedList(struct ListNode **head)
{
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;

    while (iterator)
    {
        auxilaryNode = iterator->next;

        free(iterator);

        iterator = auxilaryNode;
    }

    *head = NULL;
}

int main()
{
    struct ListNode **head;

    InsertInLinkedList(head, 1, 1);
    InsertInLinkedList(head, 2, 2);
    InsertInLinkedList(head, 3, 4);
    InsertInLinkedList(head, 4, 3);
    InsertInLinkedList(head, 5, 6);
    InsertInLinkedList(head, 6, 5);
    DeleteNodeFromLinkedList(head, 1);
    // DeleteLinkedList(head);

    ShowLinkedList(*head);

    return 0;
}