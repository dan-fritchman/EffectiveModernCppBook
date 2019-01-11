//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_SMART_PTR_H
#define CPP_TUTORIALS_SMART_PTR_H

#include "print.h"


namespace smart_ptr {

    class Top {
    };

    class Sub1 : public Top {
    };

    class Sub2 : public Top {
    };

    template<typename... Ts>
    static auto factory(Ts &&... params) {
        /* Factory function returning unique-pointers */
        auto deleter = [](Top *pTop) {
            print("Deleting Unique Pointer!");
            print(pTop);
            delete pTop;
        };

        std::unique_ptr<Top, decltype(deleter)> pInv(nullptr, deleter);

        if (true) {
            pInv.reset(new Sub1(std::forward<Ts>(params)...));
        } else if (false) {
            pInv.reset(new Sub2(std::forward<Ts>(params)...));
        } else {
            pInv.reset(new Top(std::forward<Ts>(params)...));
        }
        return pInv;
    }

    void deleter_func(Top *pTop) {
        print("Deleting Shared Pointer!");
        print(pTop);
        delete pTop;
    };

    void test_smart_ptrs() {
        auto t = factory();
        auto t2 = std::move(t);

        using SharedPtrTop = std::shared_ptr<Top>;
        SharedPtrTop sptr = factory();
        auto sptr2 = sptr;
        auto sptr3 = sptr;
        auto s4 = std::make_shared<Top>();
        auto s5 = std::shared_ptr<Top>(new Sub1, deleter_func);
        auto s6 = SharedPtrTop(s5);

        auto w1 = std::weak_ptr<Top>(s6);
    }

    void test_all() {
        print("Testing smart pointers!");
        test_smart_ptrs();
        print("End Testing smart pointers!");
    }
}
#endif //CPP_TUTORIALS_SMART_PTR_H
