//
// Created by Dan Fritchman on 11/17/18.
//

#include <iostream>
#include <array>
#include <vector>
#include <map>

#include "print.h"
#include "other.h"
#include "enum.h"
#include "deleted.h"
#include "override.h"

template<typename T>
void f(const T &p) {
    T p3 = p * 3;
    print(p3);
}

template<typename T>
void g(T &&p) {
    print(p);
}

template<typename T>
void h(T p) {
    p = 11;
    T p4 = 4 * p;
    print(p4);
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
    print(N);
    return N;
};

void test_templates() {
    /*
     * Test some template-based type inference.
     */
    int j = 1;
    f(j);
    g(j);
    h(j);
    long k = 2;
    f(k);
    g(k);
    h(k);
    float l = 3.0;
    f(l);
    g(l);
    h(l);
    double m = 4.0;
    f(m);
    g(m);
    h(m);

    // Try an array thing or two
    int arr[] = {1, 2, 3, 4, 5};
    print(arr);
    print(arraySize(arr));
    // FIXME: not sure why this part dont work.
    /*const std::array <int, arraySize(arr)> arr2;
    array_stuff(arr2);
    N = arraySize(arr2);
    std::cout << N << std::endl;*/

}

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

void test_map() {
    print("No worky yet");
//    std::map<std::string, int> m {"a", 1};
}

void test_init() {
    std::vector<int> v{1, 3, 5};
    print(v[0]);
}

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

void test_lock_guard() {
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

void test_func_ptr() {
    std::function<bool(const std::unique_ptr<int> &, const std::unique_ptr<int> &)> func;
}


int main() {
    // Tell the people we alive
    print("Hello World");

    // Run all this stuff
    test_other_stuff();
    test_templates();
    test_auto();
    test_decltype();
    test_map();
    test_init();
    test_lock_guard();
    test_func_ptr();
    test_scoped_enum();
    test_deleted();
    test_override();

    // And bounce
    return 0;
}

