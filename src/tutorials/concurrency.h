//
// Created by Dan Fritchman on 2019-02-04.
//

#ifndef CPP_TUTORIALS_CONCURRENCY_H
#define CPP_TUTORIALS_CONCURRENCY_H

#include <future>
#include <algorithm>

namespace concurrency {
//    template<typename F, typename... Ts>
//    inline auto reallyAsync(F &&f, Ts &&... params) {
//        return std::async(std::launch::async,
//                          std::forward<F>(f),
//                          std::forward<Ts>(params)...);
//    }
//
//    int k (int x){
//        return x*3;
//    }
//
//    void test_really_async() {
//        auto r = std::async(k);
//        auto f = reallyAsync(k);
//    }

    // Item 37

    class ThreadRAII {
    public:
        enum class DtorAction {
            join, detach
        };

        ThreadRAII(std::thread &&t, DtorAction a)  // in dtor, take
                : action(a), t(std::move(t)) {}            // action a on t

        ~ThreadRAII() {                                          // see below for
            if (t.joinable()) {                      // joinability test

                if (action == DtorAction::join) {
                    t.join();
                } else {
                    t.detach();
                }

            }
        }

        std::thread &get() { return t; }           // see below

    private:
        DtorAction action;
        std::thread t;
    };

    void f() {
        print("Running f");
    }

    void test_thread_raii() {
        ThreadRAII tr{std::thread(f), ThreadRAII::DtorAction::join};
    }

    void test_std_atomic() {
        /* Item 40, std::atomic */
        std::atomic<int> ai(0);    // initialize ai to 0
        ai = 10;                   // atomically set ai to 10
        print(ai);                 // atomically read ai's value
        ++ai;                      // atomically increment ai to 11
        print(ai);                 // atomically read ai's value
        --ai;                      // atomically decrement ai to 10
        print(ai);                 // atomically read ai's value

// This part no good yet.
//        std::atomic<bool> valAvailable(false);
//        print(valAvailable);
//
//        std::thread([&valAvailable] {
//            print("In thread!");
//            print(valAvailable);
//            valAvailable.store(true);
//            print(valAvailable);
//            print("Finishing in thread!");
//        });
//        print("Launched thread");
//
//        print(valAvailable);
//        while (!valAvailable.load()) {
//            print("Waiting");
//        }
//        print("Should be done Waiting");
//        print(valAvailable);
    }

    void test_all() {
//        test_really_async();
        test_thread_raii();
        test_std_atomic();
    }
}
#endif //CPP_TUTORIALS_CONCURRENCY_H
