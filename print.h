//
// Created by Dan Fritchman on 12/7/18.
//

#ifndef CPP_TUTORIALS_PRINT_H
#define CPP_TUTORIALS_PRINT_H

#include <iostream>

template<typename T>
void print(const T &p) {
    /* print a semi-arbitrary type of thing, along with its type-name.
     * Maybe the python coming out. */
    std::cout << typeid(p).name() << " " << p << std::endl;
}


#endif //CPP_TUTORIALS_PRINT_H
