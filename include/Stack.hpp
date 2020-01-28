// Copyright 2020 Kondr11
#ifndef TEMPLATE_STACK_HPP
#define TEMPLATE_STACK_HPP

#include "MyStack.hpp"

template<class T>
class Stack: public MainStack<T> {
public:
    void push(const T &value)
    {
        auto *prevNode =  MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{
                value,
                prevNode,
        };
    }

    void pop()
    {
        if ( !MainStack<T>::headNode) {
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;
        MainStack<T>::headNode = MainStack<T>::headNode->previous;

        delete prevNode;
    }
};

#endif //TEMPLATE_STACK_HPP
