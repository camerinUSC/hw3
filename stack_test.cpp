#include <iostream>
#include "stack.h"

int main() {
    Stack<int> s;

    try {
        s.pop();  //underflow_error
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    s.push(72);
    s.push(84);
    std::cout << "Stack top: " << s.top() << std::endl;

    s.pop();
    s.pop();

    try {
        s.pop();  
    } catch (const std::underflow_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}