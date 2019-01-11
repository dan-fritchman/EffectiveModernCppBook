//
// Created by Dan Fritchman on 2019-01-11.
//

#ifndef CPP_TUTORIALS_TESTS_H
#define CPP_TUTORIALS_TESTS_H

#include "pimpl.h"

namespace pimpl {
    void test_all() {
        /* Try our pointer-to-implementation example, especially its copy/ move ops. */

        Pimpl p;
        auto p2(std::move(p));
        p = std::move(p2);
        auto p3 = Pimpl(p);
    }
}

#endif //CPP_TUTORIALS_TESTS_H
