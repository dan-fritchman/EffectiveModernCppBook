//
// Created by Dan Fritchman on 12/7/18.
//

#ifndef CPP_TUTORIALS_DELETED_H
#define CPP_TUTORIALS_DELETED_H

#include "print.h"

/* Test the delete assignment on some functions. */

template<typename T>
void my_ptr(T *ptr) {
    print(&ptr);
}

template<>
void my_ptr<void>(void *) = delete;

template<>
void my_ptr<char>(char *) = delete;

template<>
void my_ptr<const void>(const void *) = delete;

template<>
void my_ptr<const char>(const char *) = delete;

class Widget {
public:
    template<typename T>
    void processPointer(T *ptr) { print(&ptr); }
};

template<>
void Widget::processPointer<void>(void *) = delete;

void test_deleted() {
    int *ip = new int;
    my_ptr(ip);
    char *a = new char(100);
//    my_ptr(a);
    auto w = Widget();
    w.processPointer(ip);
    void * vp = ip;
//    w.processPointer(vp);
}


#endif //CPP_TUTORIALS_DELETED_H
