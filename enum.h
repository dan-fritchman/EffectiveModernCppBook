//
// Created by Dan Fritchman on 12/7/18.
//

#ifndef CPP_TUTORIALS_ENUM_H
#define CPP_TUTORIALS_ENUM_H

namespace enums {
    template<typename E>
    constexpr std::underlying_type_t<E> as_underlying_type(E enumerator) noexcept {
        return static_cast<std::underlying_type_t<E>>(enumerator);
    }

    enum class Color {
        red, white, blue
    };

    enum class State : long {
        before, during, after
    };

    void test_scoped_enum() {
        /* Try making some of the new scoped-enum classes,
         * converting and printing them. */
        auto red = false;
        print(red);
        auto r = Color::red;
        auto ru = as_underlying_type(r);
        print(ru);

        auto b = Color::blue;
        auto bu = as_underlying_type(b);
        print(bu);

        auto s = State::before;
        auto su = as_underlying_type(s);
        print(su);
        s = State::during;
        print(as_underlying_type(s));
        s = State::after;
        print(as_underlying_type(s));
    }
}

#endif //CPP_TUTORIALS_ENUM_H
