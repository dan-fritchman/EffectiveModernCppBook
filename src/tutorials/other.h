//
//  Created by Dan Fritchman on 12/6/18.
//

#ifndef other_hpp
#define other_hpp

#include <vector>

namespace other {
    /*
     * Other stuff, perhaps to be organized.
     */

    void test_const_iter() {
        /* Make a constant iterator or two. */
        std::vector<int> values{1982, 1983, 1984};
        auto it = std::find(values.cbegin(), values.cend(), 1983);
        values.insert(it, 2019);
    }

    int f(int x) noexcept {
        /* A very simple no-exception method. */
        return 3;
    }

    void test_noexcept() {
        /* Test exception specs*/
        int k = f(3);
    }

    constexpr int pow(const int base, const unsigned exp) noexcept {
        /* Compute something like std::pow at compile-time */
        auto result = 1;
        for (unsigned i = 0; i < exp; ++i) result *= base;
        return result;
    }

    class Point {
    public:
        constexpr Point(double xVal = 0, double yVal = 0) noexcept
                : x(xVal), y(yVal) {}

        constexpr double xValue() const noexcept { return x; }

        constexpr double yValue() const noexcept { return y; }

        constexpr void setX(double newX) noexcept { x = newX; }

        constexpr void setY(double newY) noexcept { y = newY; }

    private:
        double x, y;
    };

    constexpr Point p1(9.4, 27.7);

    constexpr Point reflection(const Point &p) noexcept {
        Point result;                       // create non-const Point

        result.setX(-p.xValue());           // set its x and y values
        result.setY(-p.yValue());

        return result;                      // return copy of it
    }

    constexpr Point pr = reflection(p1);

    void test_constexpr() {
        /* Try some const-expressions */
        constexpr std::array<int, 4> v{1, 2, 3, 4};
        // Create a constexpr-function-sized array!
        std::array<int, pow(2, 2)> x;

        Point p2 = p1;
        print(p2.xValue());

    }


    void test_map() {
        print("No worky yet");
//    std::map<std::string, int> m ("a", 1);
    }


    void test_func_ptr() {
        std::function<bool(const std::unique_ptr<int> &, const std::unique_ptr<int> &)> func;
    }


    void test_all() {
        print("Testing Other Stuff");
        test_const_iter();
        test_noexcept();
        test_constexpr();
        test_map();
        test_func_ptr();
    }
}

#endif /* other_hpp */
