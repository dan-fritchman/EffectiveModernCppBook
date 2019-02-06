//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_TEMPLATES_H
#define CPP_TUTORIALS_TEMPLATES_H

namespace templates {

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

    void test_all() {
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
}
#endif //CPP_TUTORIALS_TEMPLATES_H

