//
// Created by Dan Fritchman on 2019-01-09.
//

#ifndef CPP_TUTORIALS_MOVE_H
#define CPP_TUTORIALS_MOVE_H


namespace moves {
    class Base {
    public:
        Base() = default;

        virtual ~Base() = default;                // make dtor virtual

        Base(Base &&) = default;                   // support moving
        Base &operator=(Base &&) = default;

        Base(const Base &) = default;              // support copying
        Base &operator=(const Base &) = default;

    protected:
        int k{0};
    };

    class Derived : public Base {
    public:
        Derived() = default;

        Derived &operator=(Derived &&d) {
            print("Moving a Derived!");
            k = std::move(d.k);
            return *this;
        }
    };

    void test_all() {
        print("Testing moves");

        // Try some base-class copying
        Base b;
        auto b2 = b;
        // Now do some sub-class moving
        Derived d, d2;
        d2 = std::move(d);
    }

}
#endif //CPP_TUTORIALS_MOVE_H
