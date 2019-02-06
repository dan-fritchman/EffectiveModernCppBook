//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_MOVING_H
#define CPP_TUTORIALS_MOVING_H

#include <vector>
#include "print.h"


namespace init {
    /*
     * Tests of new initialization features
     */


    void test_init() {
        std::vector<int> v{1, 3, 5};
        print(v[0]);
    }

    class Widget {
    private:
        int x{0};
        int y{2};
        int z{2};
    };

    void test_distinguish() {
        print("Running test_distinguish()");
        long x(0);
        long y = 0;
        long z{0};
        print(x);

        long sum1{x + y + z};

        std::vector<long> v{x, y, z};
        Widget w;
    }


    void test_all() {
        test_init();
        test_distinguish();
    }


}
#endif //CPP_TUTORIALS_MOVING_H
