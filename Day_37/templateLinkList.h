#ifndef TEMPLATELINKLIST_H
#define TEMPLATELINKLIST_H


#include<iostream>
#include<iomanip>
#include<string>
#include<memory>

template <typename T>
class Node
{
private:
    T  *ptrT;
    Node<T> *linkNode;
public:
    Node() : ptrT(nullptr) , linkNode(nullptr) {}

    Node(T inVal) : linkNode(nullptr) {
        ptrT = new T(inVal);
    }

    Node(T inVal , Node<T> *inNode){
        ptrT = new T(inVal);
        linkNode = inNode;
    }

    Node(const Node<T>& inNode ){
        ptrT = new T(inNode.ptrT);
        linkNode = inNode.linkNode;
    }

    T getValue() {
        return *ptrT;
    }

    Node<T>* getLinkNode(){
        return linkNode;
    }

    void setVaue(T inVal){
        if(ptrT) delete ptrT;
        ptrT = new T(inVal);
    }

    void setLinkNode(Node<T> *inNode){
        linkNode = inNode;
    }

    void displayNode(){
        std::cout << std::setfill(' ') << std::setw(15) << std::left << this << "  ";
        std::cout << std::setfill(' ') << std::setw(15) << std::left << linkNode << "  ";
        std::cout << std::setfill(' ') << std::setw(15) << std::left << ptrT << "  ";
        std::cout << " -> "<< *ptrT << std::endl;
    }

    ~Node(){
        if( ptrT) delete ptrT;
    }
};

// template <typename nodeType>
// using _Node = Node<nodeType>

template <typename listType>
class myList
{

private:
    Node<listType> *pNode; //last Node of myList
public:
    myList() : pNode(nullptr) {}

    void push_back(listType inVal)
    {
        // Append new Node
        pNode = new Node<listType>( inVal , pNode);
    }
    void pop_back()
    {
        //remove last Node
        if(pNode){
            Node<listType> *curr = pNode;
            pNode = curr->getLinkNode();
            delete curr;
        }
    }
    int size()
    {
        // counting total Node
        int ret = 0 ;
        Node<listType> *curr = pNode;
        while( curr ){
            ret++;
            if(curr->getLinkNode() == nullptr)
                break;
            curr = curr->getLinkNode();
        }
        return ret;

    }
    void displayList(){
        // list all Node
        Node<listType> * curr = pNode;
        while(curr) {
            curr->displayNode();
            curr = curr->getLinkNode();
        }
    }
    ~myList(){
        //remove all Node
        while(pNode){
            pop_back();
        }
    }
};


#endif //TEMPLATELINKLIST_H

