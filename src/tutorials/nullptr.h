//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_NULLPTR_H
#define CPP_TUTORIALS_NULLPTR_H

namespace nullptrs {
    int f1(void *p) {
        /* Really just checks whether pointer-argument p is `nullptr`.
         * Returns one of two integer values. */
        if (p == nullptr) {
            return 23;
        } else {
            return 45;
        }
    }

    void test_nullptr() {
        int i = f1(nullptr);
        int k{0};
        int j = f1(&k);
    }

    void test_all() {
        print("Running nullptrs::test_all");
        test_nullptr();
    }
}
#endif //CPP_TUTORIALS_NULLPTR_H
