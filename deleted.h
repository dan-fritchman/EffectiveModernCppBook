//
// Created by Dan Fritchman on 12/7/18.
//

#ifndef CPP_TUTORIALS_DELETED_H
#define CPP_TUTORIALS_DELETED_H

#include "print.h"

namespace deleted {
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
        void *vp = ip;
        //    w.processPointer(vp);
    }


    class Base {
        /*
         * Idea is to test deleting operators.
         * No worky, yet.
         */
    public:
        int k{0};

        Base() {
            print("Running Default Constructor");
        };

        Base(const Base &base) {
            k = base.k;
        }

        Base &operator=(const Base &base) {
            // FIXME: Why don't this get called yet?
            print("Running Assignment Op");
            if (&base == this) {
                return *this;
            }
            this->k = base.k;
            return *this;
        }
    };

    void test_delete_ops() {
        // FIXME: not alive yet
        Base b;
        Base b2 = b;
        Base b3(b);
        Base b4{b};
    }

    void test_all() {
        test_deleted();
        test_delete_ops();
    }

}

#endif //CPP_TUTORIALS_DELETED_H
