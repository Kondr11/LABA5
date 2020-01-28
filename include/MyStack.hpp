// Copyright 2020 Kondr11

#ifndef INCLUDE_MYSTACK_HPP_
#define INCLUDE_MYSTACK_HPP_

#include <type_traits>
#include <utility>
#include <exception>

template <typename T>
class MainStack {
public:
    MainStack() = default;
    MainStack(const MainStack &stack) = delete; //имеет константный член
    // без определяемого пользователем  конструктора по умолчанию или
    // инициализатора члена по умолчанию
    MainStack(MainStack &&stack) noexcept = default;// нет исключений

    MainStack &operator=(const MainStack &stack)
            = delete;//перегрузка копирования
    MainStack &operator=(MainStack &&stack) noexcept
            = default;//перегрузка пермещения

    void push(T&& value){
        auto *previousNode = headNode;
        headNode = new StackNode{std::forward<T>(value), previousNode};
    }

    const T& head() const{
        if (!headNode) {
            std::exception();
        }

        return headNode->value;
    }

    ~MainStack()
    {
        while (headNode) {
            auto *currentNode = headNode;
            headNode = currentNode->prev;

            delete currentNode;
        }
    }
};

template <typename T>
struct StackNode{
    T value;
    StackNode *previous = nullptr;
};

protected:
StackNode *headNode = nullptr;





#endif // INCLUDE_MYSTACK_HPP_
