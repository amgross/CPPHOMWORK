//
// Created by אריה גרוס on 27 מרץ 2018.
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * This sample is about how to implement a queue in c
 *
 * Type of item is int
 * Add item to head, tail or any position
 * Get item from head, tail or any position
 * Get and remove item from head, tail or any position
 * Can get the size
 * Can display all item
 */
/**
 * The Node struct,
 * contains item and the pointers that point to previous node/next node.
 */
typedef struct Node {
    int item;
    // previous node
    struct Node* prev;
    // next node
    struct Node* next;
} Node;
/**
 * The LinkedList struct, contains the pointers that
 * point to first node and last node, the size of the LinkedList,
 * and the function pointers.
 */
typedef struct LinkedList {
    Node* head;
    Node* tail;
    // size of this LinkedList
    int size;

    // add item to any position
    void (*add) (struct LinkedList*, int, int);
    // add item after tail
    void (*addLast) (struct LinkedList*, int);
    // add item before head
    void (*addFirst) (struct LinkedList*, int);

    // insert node
    void (*insertBefore) (struct LinkedList*, Node*, Node*);
    // get item from any position
    int (*get) (struct LinkedList*, int);
    // get last item
    int (*getLast) (struct LinkedList*);
    // get first item
    int (*getFirst) (struct LinkedList*);

    // remove item from any position
    int (*remove) (struct LinkedList*, int);
    // remove last item
    int (*removeLast) (struct LinkedList*);
    // remove first item
    int (*removeFirst) (struct LinkedList*);

    // display all element in the LinkedList
    void (*display) (struct LinkedList*);
    // create a node with item
    Node* (*createNode) (int);
} LinkedList;

/** add item to any position
 */
void add (LinkedList* _this, int item, int position);
/** add item to head
 */
void addFirst (LinkedList* _this, int item);
/** add item to tail
 */
void addLast (LinkedList* _this, int item);
/** insert one node before another,
 * newNdoe, node and node->prev should not be null.
 */
void insertBefore (LinkedList* _this, Node* node, Node* newNode);
/** get item from specific position
 */
int get (LinkedList* _this, int position);
/** get item from head
 */
int getFirst (LinkedList* _this);
/** get item from tail
 */
int getLast (LinkedList* _this);
/** get item and remove it from any position
 */
int _remove (LinkedList* _this, int position);
/** get and remove item from head
 */
int _removeFirst (LinkedList* _this);
/** get and remove item from tail
 */
int _removeLast (LinkedList* _this);
/** display the items in the list
 */
void display (LinkedList* _this);
/** create a LinkedList
 */
LinkedList createLinkedList ();
/** create a Node
 */
Node* createNode (int item);

int main () {
    LinkedList list = createLinkedList();

    // 3
    list.addFirst(&list, 3);
    // 3, 5
    list.addLast(&list, 5);
    // 3, 4, 5
    list.add(&list, 4, 1);
    list.display(&list);

    // 3, 4, 5, 6
    list.addLast(&list, 6);
    // 3, 4, 5, 6, 7
    list.addLast(&list, 7);
    list.display(&list);
    printf("Get item: %d\n", list.get(&list, 2));
    printf("Get item: %d\n", list.get(&list, 4));
    list.display(&list);
    // 4, 5, 6, 7
    printf("Remove item: %d\n", list.removeFirst(&list));
    // 4, 5, 6
    printf("Remove item: %d\n", list.removeLast(&list));
    // 4, 6
    printf("Remove item: %d\n", list.remove(&list, 1));
    list.display(&list);

    system("PAUSE");
}
/** add item to any position
 */


/** add item to tail
 */
void addLast (LinkedList* _this, int item) {
    Node* newNode = _this->createNode(item);
    Node* head = _this->head;
    Node* tail = _this->tail;
    // list is empty
    if (head == NULL)
        _this->head = newNode;
    else { // has item(s)
        Node* lastNode = tail;
        if (tail == NULL) // only head node
            lastNode = head;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        _this->tail = newNode;
    }
    _this->size++;
}





/** get and remove item from tail
 */
int _removeLast (LinkedList* _this) {
    // list is empty
    if (_this->size == 0) {
        printf("LinkedList#_removeLast: The list is empty.");
        system("PAUSE");
        exit(0);
    }
    for (Node i=_this->head;)
    if (_this->size == 1) { // only head node
        return _this->removeFirst(_this);
    } else {
        Node* tail = _this->tail;
        Node* prev = tail->prev;
        int item = tail->item;
        prev->next = NULL;
        if (_this->size > 1)
            _this->tail = prev;
        _this->size--;
        if (_this->size <= 1) // empty or only head node
            _this->tail = NULL;
        return item;
    }
}
/** display the items in the list
 */
void display (LinkedList* _this) {
    int i, size = _this->size;
    if (size == 0)
        printf("no item\n\n");
    else {
        printf("has %d items\n", size);
        Node* node = _this->head;
        for (i = 0; i < size; i++) {
            if (i > 0)
                printf(", ");
            printf("%d", node->item);
            node = node->next;
        }
        printf("\n\n");
    }
}
/** create a LinkedList
 */
LinkedList createLinkedList () {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.add = &add;
    list.addFirst = &addFirst;
    list.addLast = &addLast;
    list.insertBefore = &insertBefore;
    list.get = &get;
    list.getFirst = &getFirst;
    list.getLast = &getLast;
    list.remove = &_remove;
    list.removeFirst = &_removeFirst;
    list.removeLast = &_removeLast;
    list.display = &display;
    list.createNode = &createNode;
    return list;
}
/** create a Node
 */
Node* createNode (int item) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->item = item;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
