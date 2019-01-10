//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_LOCKS_H
#define CPP_TUTORIALS_LOCKS_H

#include <mutex>

namespace locks {

    template<typename F, typename M, typename P>
    decltype(auto) lock_and_call(F func, M &mutex, P ptr) {
        using MuxGuard = std::lock_guard<M>;
        MuxGuard g(mutex);
        return func(ptr);
    };

    int f1(void *p) {
        /* Really just checks whether pointer-argument p is `nullptr`.
         * Returns one of two integer values. */
        if (p == nullptr) {
            return 23;
        } else {
            return 45;
        }
    }

    void test_all() {
        /* Test the "wrap with mutex-locking template" above. */
        std::mutex m1;

        // Try once with a null-pointer
        auto i = 0;
        i = lock_and_call(f1, m1, nullptr);
        print(i);

        // And try again with a (hopefully) non-null-pointer
        int *p = &i;
        i = lock_and_call(f1, m1, p);
        print(i);
    }

}
#endif //CPP_TUTORIALS_LOCKS_H

