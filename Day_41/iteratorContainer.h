#ifndef TEMPLATEITERATOR_H
#define TEMPLATEITERATOR_H

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

    Node(T inVal) : linkNode(nullptr)
    {
        ptrT = new T(inVal);
    }

    Node(T inVal , Node<T> *inNode)
    {
        ptrT = new T(inVal);
        linkNode = inNode;
    }

    Node(const Node<T>& inNode )
    {
        ptrT = new T(inNode.ptrT);
        linkNode = inNode.linkNode;
    }

    T getValue()
    {
        return *ptrT;
    }

    Node<T>* getLinkNode()
    {
        return linkNode;
    }

    void setVaue(T inVal)
    {
        if(ptrT) delete ptrT;
        ptrT = new T(inVal);
    }

    void setLinkNode(Node<T> *inNode)
    {
        linkNode = inNode;
    }

    void displayNode()
    {
        std::cout << std::setfill(' ') << std::setw(15) << std::left << this << "  ";
        std::cout << std::setfill(' ') << std::setw(15) << std::left << linkNode << "  ";
        std::cout << std::setfill(' ') << std::setw(15) << std::left << ptrT << "  ";
        std::cout << " -> "<< *ptrT << std::endl;
    }

    ~Node()
    {
        if( ptrT) delete ptrT;
    }
};

template <typename itrType>
class myListIterator
{
private:
    Node<itrType> *ptrNode; // Node that iterator pointing

public:
    myListIterator() : ptrNode(nullptr) {};
    myListIterator(Node<itrType> *ptr) : ptrNode(ptr) {};

    myListIterator& operator++() noexcept
    {
        ptrNode = ptrNode->getLinkNode();
        return *this;
    }

    myListIterator& operator++(int) noexcept
    {
        //it++
        ptrNode = ptrNode->getLinkNode();
        return *this;
    }

    itrType operator*()
    {
        return ptrNode->getValue();
    }

    bool operator==(const myListIterator& other) const
    {
        return (this->ptrNode == other.ptrNode);
    }
    bool operator!=(const myListIterator& other) const
    {
        return (this->ptrNode != other.ptrNode);
    }
};

// template <typename nodeType>
// using _Node = Node<nodeType>

template <typename listType>
class myList
{
public:
    using valueType = listType;
    typedef myListIterator<listType>    iterator;

private:
    Node<listType> *pNode; //last Node of myList
public:
    myList() : pNode(nullptr) {}  // default constructor

    void push_back(listType inVal)
    {
        // Append new Node
        pNode = new Node<listType>( inVal , pNode);
    }
    void pop_back()
    {
        //remove last Node
        if(pNode)
        {
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
        while( curr )
        {
            ret++;
            if(curr->getLinkNode() == nullptr)
                break;
            curr = curr->getLinkNode();
        }
        return ret;

    }
    void displayList()
    {
        // list all Node
        Node<listType> * curr = pNode;
        while(curr)
        {
            curr->displayNode();
            curr = curr->getLinkNode();
        }
    }

    Node<listType>& lastNode() noexcept
    {
        return *pNode;
    }

    Node<listType>& firstNode() noexcept
    {
        Node<listType> *curr = pNode;
        while(curr)
        {
            if(curr->getLinkNode() == nullptr)
            {
                break;
            }
            curr = curr->getLinkNode();
        }
        return *curr;
    }

    iterator begin() noexcept
    {
        return iterator(pNode);
    }

    iterator end() noexcept
    {
        return iterator(nullptr);
    }


    ~myList()
    {
        //remove all Node
        while(pNode){
            pop_back();
        }
    }
};


#endif // TEMPLATEITERATOR_H
