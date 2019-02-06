//
// Created by Dan Fritchman on 2019-02-04.
//

#ifndef CPP_TUTORIALS_LAMBDA_H
#define CPP_TUTORIALS_LAMBDA_H

#include "print.h"

namespace lamdbas {
    void test_lambda() {
        int x;                                 // x is local variable
        auto c1 = [x](int y) { return x * y > 55; };

        auto c2 = c1;                          // c2 is copy of c1
        auto c3 = c2;                          // c3 is copy of c2
    }

    using FilterContainer = std::vector<std::function<bool(int)>>;
    FilterContainer filters;

    class Widget {
    public:
        int divisor;

        void addFilter() const;

        bool isValidated() const;

        bool isProcessed() const;

        bool isArchived() const;
    };

    void Widget::addFilter() const {
        auto divisorCopy = divisor;                // copy data member

        filters.emplace_back(
                [divisorCopy](int value)                 // capture the copy
                { return value % divisorCopy == 0; }     // use the copy
        );
    }

    bool Widget::isValidated() const { return true; }

    bool Widget::isProcessed() const { return true; }

    bool Widget::isArchived() const { return true; }

    void test_capture() {
        Widget w{11};
        w.addFilter();
    }


    void test_init_cap() {
        auto pw = std::make_unique<Widget>();   // create Widget; see
        auto func = [pw = std::move(pw)] {
            return pw->isValidated() && pw->isProcessed()
                   && pw->isArchived();
        };
    }

    void test_bind() {
        std::vector<double> data{1.1, 2.1, 3.1};

        auto func = std::bind(
                [](const std::vector<double> &data) { print(data[0]); },
                std::move(data)
        );

        func();
    }

    void test_all() {
        print("Testing Lambdas");
        test_lambda();
        test_capture();
        test_init_cap();
        test_bind();
    }
}
#endif //CPP_TUTORIALS_LAMBDA_H
