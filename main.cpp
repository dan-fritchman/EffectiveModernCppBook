//
// Created by Dan Fritchman on 11/17/18.
//

#include <iostream>

template<typename T>
void f(const T &p) {
    T p3 = p * 3;
    std::cout << p3 << std::endl;
}

void test_templates() {
    int j = 1;
    f(j);
    long k = 2;
    f(k);
    float l = 3.0;
    f(l);
    double m = 4.0;
    f(m);
}

int main() {
    // Tell the people we alive
    std::cout << "Hello World" << std::endl;

    // Run all this stuff
    test_templates();

    // And bounce
    return 0;
}