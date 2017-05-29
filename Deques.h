#ifndef DEQUES_H
#define DEQUES_H

#include <stdexcept>
#include <cstdlib>
#include <iostream>

template <class T>
class Node
{
public:
    T item;
    Node *next;
    Node<T>(){
        next = NULL;
    };
    virtual ~Node(){
        item = -1;
        next = NULL;
    }

};

template <class T>
class Deques
{
    public:
        Deques();
        Deques(const Deques& toBeCopied);
        virtual ~Deques();
        void operator=(const Deques &rhs);
        T insert_front(T frontInsert);
        T insert_back(T backInsert);
        T remove_front();
        T remove_back();
        T peek_front();
        T peek_back();
        void printAll();
        bool empty();
        int size();

    private:
        Node<T> *frontQueue;
        Node<T> *backQueue;
        int sizeQueue;

};

//Basic constructor for a double-ended queue
template <class T>
Deques<T>::Deques()
{
    frontQueue = NULL;
    backQueue = NULL;
    sizeQueue = 0;
}
//Destructor for a double ended queue
template <class T>
Deques<T>::~Deques()
{
    Node<T> *curr = frontQueue;
    Node<T> *next;
    while(curr!=NULL)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
    frontQueue = NULL;
    backQueue = NULL;
    sizeQueue = 0;
}
//Insertion into the front of the queue
template <class T>
T Deques<T>::insert_front(T frontInsert)
{
    Node<T> *newNode = new Node<T>();
    newNode->item = frontInsert;
    newNode->next = frontQueue;
    frontQueue = newNode;
    sizeQueue++;
    if(sizeQueue==1)
    {
        backQueue=newNode;
    }
    return frontInsert;


}
//Insertion into the back of the queue
template <class T>
T Deques<T>::insert_back(T backInsert)
{
    if(sizeQueue == 0)
    {
        this->insert_front(backInsert);
    } else {
    Node<T> *newNode = new Node<T>();
    newNode->item = backInsert;
    newNode->next = NULL;
    backQueue->next = newNode;
    backQueue = newNode;
    sizeQueue++;
    }
    return backInsert;
}
//Removal from the front of the queue
template <class T>
T Deques<T>::remove_front()
{
    if(sizeQueue<=0)
    {
        return NULL;
    } else {
    T returnValue = frontQueue->item;
    Node<T> *del = frontQueue;
    frontQueue = frontQueue->next;
    delete del;
    del = NULL;
    sizeQueue--;

    return returnValue;
    }
}
//Removal from the back of the queue, performed recursively
template <class T>
T Deques<T>::remove_back() //Implemented recursively
{
    static Node<T> *predecessor = frontQueue;
    T returnValue;
    if(predecessor == NULL)
    {
        //std::cout << "Error: Not found" << std::endl;
        return NULL;
    }
    if(predecessor->next == NULL)
    {
        //std::cout << "Only one item in queue" << std::endl;
        returnValue = predecessor->item;
        delete predecessor;
        predecessor = NULL;
        frontQueue = NULL;
        backQueue = NULL;
        //std::cout << "Removed " << returnValue << " from list\n";
        return returnValue;
    }
    if(predecessor->next->next == NULL)
    {
        returnValue = predecessor->next->item;
        backQueue = predecessor;
        delete predecessor->next;
        predecessor->next = NULL;
        predecessor = NULL;
        sizeQueue--;
        //std::cout << "Removed " << returnValue << " from list\n";
        return returnValue;
    }
    predecessor = predecessor->next;
    return remove_back();



}
//Returns the very first item in the queue
template <class T>
T Deques<T>::peek_front()
{
    return this->frontQueue->item;
}
//Returns the very last item in the queue
template <class T>
T Deques<T>::peek_back()
{
    return this->backQueue->item;
}
//Assignment operator, takes two pre-existing queues and copies one to the other
template <class T>
void Deques<T>::operator=(const Deques &rhs)
{
    this->~Deques();
    Node<T> *curr = rhs.frontQueue;

    while(curr!=NULL)
    {
        this->insert_back(curr->item);
        curr = curr->next;
    }
}
//Copy constructor, creates a new queue using data from an existing queue
template <class T>
Deques<T>::Deques(const Deques& toBeCopied)
{
    frontQueue = NULL;
    backQueue = NULL;
    sizeQueue = 0;

    Node<T> *curr = toBeCopied.frontQueue;

    while(curr!=NULL)
    {
        this->insert_back(curr->item);
        curr = curr->next;
    };
}
//Checks if the queue is empty
template <class T>
bool Deques<T>::empty()
{
    if(sizeQueue==0) return true;
    else return false;
}
//Returns the size of the queue
template <class T>
int Deques<T>::size()
{
    return sizeQueue;
}
//Prints out everything in the queue
template <class T>
void Deques<T>::printAll()
{
    Node<T> *iter;
    iter = frontQueue;
    while (iter != NULL)
    {
        std::cout << iter->item << " ";
        iter = iter->next;
    }
}




#endif // DEQUES_H
