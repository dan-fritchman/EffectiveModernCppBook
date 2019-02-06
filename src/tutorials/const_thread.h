//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_CONST_THREAD_H
#define CPP_TUTORIALS_CONST_THREAD_H

#include <mutex>
#include "print.h"

namespace const_thread {
    class Widget {
        /*
         * An implementation of the "const methods should be thread-safe" rule.
         */
    public:
        int expensiveComputation1() const { return 3; }

        int expensiveComputation2() const { return 4; }

        int magicValue() const {
            std::lock_guard<std::mutex> guard(m);   // lock m

            if (cacheValid) return cachedValue;
            else {
                auto val1 = expensiveComputation1();
                auto val2 = expensiveComputation2();
                cachedValue = val1 + val2;
                cacheValid = true;
                return cachedValue;
            }
        }                                         // unlock m

    private:
        mutable std::mutex m;
        mutable int cachedValue;                  // no longer atomic
        mutable bool cacheValid{false};         // no longer atomic
    };

    void test_const_thread() {
        Widget w;
        auto k = w.magicValue();
        print(k);

    }

    void test_all() {
        print("Running const_thread tests");
        test_const_thread();
    }
}
#endif //CPP_TUTORIALS_CONST_THREAD_H
