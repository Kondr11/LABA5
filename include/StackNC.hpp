// Copyright 2020 Kondr11

#ifndef TEMPLATE_STACKNC_HPP
#define TEMPLATE_STACKNC_HPP

#include "MyStack.hpp"

template<class T>
class StackNC : public MainStack<T> {
public:
    template <typename ... Args>
    void push_emplace(Args &&... value)
    {
        auto *prevNode = MainStack<T>::headNode;

        MainStack<T>::headNode = new StackNode<T>{
                {std::forward<Args>(value)...},
                prevNode,
        };
    }

    T pop()
    {
        if (!StackAbstract<T>::headNode) {
            throw std::exception();
        }

        auto *prevNode = MainStack<T>::headNode;
        MainStack<T>::headNode = MainStack<T>::headNode->previous;

        T value = std::move(prevNode->value);
        delete prevNode;
        return value;
    }
};


#endif //TEMPLATE_STACKNC_HPP
