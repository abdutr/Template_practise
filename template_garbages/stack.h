#pragma once
#include <vector>
#include <iostream>
#include <cassert>

template<typename T, T Val = T{} >
T square() {
    return Val * Val;
};

template<auto Val, typename T = decltype(Val)>
T square2() {
    return Val * Val;
};

template<char const* val>
void print() {
    std::cout << val << std::endl;
}

template<typename T>
class Stack;
template<typename T>
std::ostream& operator<< (std::ostream&, Stack<T> const&);

template<typename T>
class Stack {

private:

    std::vector<T> elems;      // elements

public:
    Stack() = default;
    //Stack(T const& elem) :elems(elem) {};
    //Stack(T const& elem) :elems{ elem } {};
    Stack(T elem) :elems{ std::move(elem)} {};
   


    void push(T const& elem);  // push element

    void pop();                // pop element

    T const& top() const;      // return top element

    bool empty() const {       // return whether the stack is empty

        return elems.empty();

    }

    void printOn(std::ostream& strm) const {
        for (T const& elem : elems) {
            strm << elem << ' ';        // call << for each element
        }
    }

    //template<typename U>
    //friend std::ostream& operator<< (std::ostream&, Stack<U> const&);

    friend std::ostream& operator<< <T> (std::ostream&,
        Stack<T> const&);

};

Stack(char const*)  ->Stack<std::string>;

template<typename T>
void Stack<T>::push(T const& elem)
{

    elems.push_back(elem);      // append copy of passed elem
}



    template<typename T>

    void Stack<T>::pop()

    {

        assert(!elems.empty());

        elems.pop_back();           // remove last element

    }



    template<typename T>

    T const& Stack<T>::top() const

    {

        assert(!elems.empty());

        return elems.back();        // return copy of last element

    }

    //template<typename U>
    //std::ostream& operator<<(std::ostream& stream, Stack<U> const& stack)
    //{
    //    // TODO: insert return statement here
    //    stack.printOn(stream);
    //    return stream;
    //}

    template<typename T>
    std::ostream& operator<< <T> (std::ostream& stream,
        Stack<T> const& stack) {
        stack.printOn(stream);
        return stream;
    }