#include <iostream>
using namespace std;

struct angka {
    int data;
    angka *next;
};
angka *node, *head, *temp;
void createNode(int data) {
    node = new angka();
    node->data = data;
    node->next = NULL;
}
void insertNode(int data) {
    createNode(data);
    if (head == NULL) {
        head = node;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}
void ReverseList() {
    angka *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
int main() {
    head = NULL;
    insertNode(5);
    insertNode(4);
    insertNode(3);
    insertNode(2);
    insertNode(1);

    temp = head;
    cout << "Original Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    ReverseList();
    temp = head;
    cout << "Reversed Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}