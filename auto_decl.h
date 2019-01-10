//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_AUTO_DECL_H
#define CPP_TUTORIALS_AUTO_DECL_H

namespace auto_decl {

    void someFunc(int k, double j) {
        print(k);
    }

    void test_auto() {
        /*
         * Test some auto-based type inference.
         */

        const int b = 42;
        auto c = b;
        print(c);
        auto d = &c;
        print(d);

        auto x = 27;
        print(x);
        const auto cx = x;
        print(cx);
        const auto &rx = x;
        print(rx);

        const char name[] = "RN Briggs";
        auto arr1 = name;
        auto &arr2 = name;


        auto func1 = someFunc;
        auto &func2 = someFunc;

    }

    template<typename C, typename I>
    decltype(auto) access(C &&c, const I &i) {
        return std::forward<C>(c)[i];
    };

    void test_decltype() {
        /* Test a bunch of decltype stuff. */

        int k = 3;
        print(k);
        decltype(k) t = 4;
        print(t);

        int a[] = {1, 2, 3};
        auto z = access(a, 1);
        print(z);
        access(a, 1) = 4;
        print(a[1]);

        /*auto y = access(int[]({4, 5, 6}), 1);
        print(y);
        access(y, 1) = 4;
        print(y);*/
    }

    void test_all(){
        test_auto();
        test_decltype();
    }

}

#endif //CPP_TUTORIALS_AUTO_DECL_H
