/**
 * @brief The implementation of the Linked List data structure
 */

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

//- Make sure description and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

// ====================================================
//Your name: ??? (TODO: Add your name)
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node* ptr;
    for (ptr = front; front; ptr = front) {
        front = front->next;
        delete ptr;
    }
    //TODO: Add code here. Make sure memory is released properly.
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    if (front == NULL) {
        return true;
    }
    else
    {
        return false;
    }

    return count == 0;
    // TODO: Add code here
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    Node* temp = front;

    int i = 0;

    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
    //TODO: Add code here
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

//TODO: Add comments
void LinkedList::addRear(T val) {
    if (isEmpty()) {
        addFront(val);
    }
    else
    {
        Node* newNode = new Node;
        Node* temp;
        newNode->val = val;
        newNode->next = NULL;
        if (front == NULL) {
            front = newNode;
        }
        else {
            temp = front;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
        count++;
    }
    // TODO: Add code here
    // consider the two cases of whether the list was empty
}

//TODO: Add comments
void LinkedList::addFront(T val) {
    if (isEmpty()) {
        front = new Node(val);
        rear = front->next;
        count++;
    }
    else
    {
        Node* temp = new Node;
        temp->val = val;
        temp->next = front;

        front = temp;
        rear = temp->next;
        count++;
    }
    // TODO: Add code here
    // consider the two cases of whether the list was empty
} 

//TODO: Add comments
bool LinkedList::deleteFront(T &OldNum) {
    if (front != NULL) {
        Node* temp = front;
        OldNum = temp->val;
        front = front->next;
        delete temp;
        return OldNum;
    }
    else
        return false;
    // TODO: Add code here
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

//TODO: Add comments
bool LinkedList::deleteRear(T &OldNum) {
    if (front == NULL)
        return false;
    else {
        Node* temp = front;
        if (temp->next == NULL) {
            OldNum = temp->val;
            front = NULL;
            delete temp;
            return OldNum;
        }
        else {
            Node* temp = front;
            while (temp->next->next != NULL)
                temp = temp->next;

            Node* lastNode = temp->next;
            OldNum = lastNode->val;
            temp->next = NULL;
            delete lastNode;
            return OldNum;
        }
    }
    // TODO: Add code here
    // consider if the list was empty and return false if the list is empty
    // consider the special case of deleting the only node in the list
} 

/* --- harder ones for test 2 and 3 -- */

    /**
    * Implement the deleteAt function to delete a node at a given position.
    */
bool LinkedList::deleteAt(int pos, T &val) {
    if (pos < 0 || pos > count + 1)
        return false;
    else
    {
        if (pos == 0 && front != NULL) {
            deleteFront(val);
            return true;
        }
        else {
            Node* temp = front;
            for (int i = 1; i < pos; i++) {
                if (temp != NULL) {
                    temp = temp->next;
                }
            }

            if (temp != NULL && temp->next != NULL) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                val = nodeToDelete->val;
                delete nodeToDelete;

                return true;
            }
            else {
                return false;
            }
        }
        count--;
    }
    return true;
    //TODO: Add code here
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value.
}

    /**
     * Implement the insertAt function here.
     */
bool LinkedList::insertAt(int pos, T val) {
    if (pos < 0 || pos > count)
        return false;
    else if (pos == 0)
        addFront(val);
    else if (pos == count || pos == count + 1)
        addRear(val);
    else {
        Node* temp = front;
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }


    return true;
    //TODO: Add code here
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    // TODO: Add code here. Interate through the other list and add a new node to this list
    // for each node in the other list. The new node should have the same value as the other node.
    Node* ptr = other.front;
    while (ptr != nullptr) {
        addRear(ptr->val);
        ptr = ptr->next;
    }
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList& LinkedList::operator=(const LinkedList &other) {
    if (this != &other) { // check if the same object
        // Delete all nodes in this list
        // TODO: Add code here
        Node* temp = front;
        while (temp != nullptr) {
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        front = nullptr;
        rear = nullptr;
        count = 0;

        Node* ptr = other.front;
        while (ptr != nullptr) {
            addRear(ptr->val);
            ptr = ptr->next;
        }
    
        // Interate through the other list and add a new node to this list
        // Be sure to set the front and rear pointers to the correct values
        // Be sure to set the count to the correct value
        // TODO: Add code here
    }
    return *this;
}

/**
 * Implement the search function.
 * 
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
int LinkedList::search(const T& val) const {
    Node* ptr = front;

    // TODO: Add code here to complete the search function
    while (ptr != NULL) {
        if (ptr->val == val) {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}


 

