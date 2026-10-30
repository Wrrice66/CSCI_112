#pragma once
#include "node.hpp"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr;
    listSize = 0;
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    while(_head != nullptr) {
        Node<T1> *_prevNode = _head;
        _head = _head->getNext();
        delete _prevNode;
    }
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if (_head == nullptr && _tail == nullptr) return true;
    return false;
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    if (_head == nullptr)
        return 0;
    else {
        int currSize = 1;
        Node<T1> *_currNode = _head;
        while (_currNode->getNext() != nullptr){
            _currNode = _currNode->getNext();
            currSize += 1;
        }
        return currSize;
    }
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1> *newNode = new Node<T1>;
    cout << "DEBUG: New node created" << endl;
    newNode->setData(data);
    newNode->setNext(_head);
    _head = newNode;
    if (this->empty()) {
        cout << "DEBUG: Entered if statement" << endl;
        _tail = newNode; // Because if there's only one element, _head and _tail would be the same
        return;
    }
    else return;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if (this->empty()) {
        cout << "List is empty." << endl;
        return 0;
    }
    else
        return _head->getData();
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    if (this->empty()) {
        cout << "List is empty." << endl;
        return 0;
    }
    else {
        T1 toReturn = _head->getData();
        Node<T1> *toBeDeleted = _head;
        _head = _head->getNext();
        delete toBeDeleted;
        return toReturn;
    }
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1> *newNode = new Node<T1>;
    cout << "DEBUG: New node created" << endl;
    newNode->setData(data);
    newNode->setNext(nullptr);
    if (this->empty()) {
        cout << "DEBUG: Entered if statement" << endl;
        newNode->setPrev(this->_tail);
        this->_tail = newNode;
        this->_head = newNode; // Same reason as above
    }
    else {
        newNode->setPrev(this->_tail);
        this->_tail = newNode;
    }
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (this->empty()) {
        cout << "List is empty." << endl;
        return 0;
    }
    else
        return _tail->getData();
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (this->empty()) {
        cout << "List is empty." << endl;
        return 0;
    }
    else {
        T1 toReturn = _tail->getData();
        Node<T1> *toBeDeleted = _tail;
        _tail = _tail->getPrev();
        delete toBeDeleted;
        return toReturn;
    }
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1> *_currNode = list._head;
    while (_currNode != nullptr) {
        cout << _currNode->getData() << " ";
        _currNode = _currNode->getNext();
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    Node<T1> *_1currNode = this->_head;
    Node<T1> *_2currNode = rhs._head;
    if (_1currNode == nullptr && _2currNode == nullptr) return true;
    else if (_1currNode == nullptr || _2currNode == nullptr) return false;
    else {
        while (_1currNode != nullptr) {
            if (_1currNode->getData() == _2currNode->getData()) {
                _1currNode = _1currNode->getNext();
                _2currNode = _2currNode->getNext();
                continue;
            }
            else return false;
        }
        return true;
    }
}