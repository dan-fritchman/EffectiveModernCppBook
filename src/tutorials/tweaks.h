//
// Created by Dan Fritchman on 2019-02-06.
//

#ifndef CPP_TUTORIALS_TWEAKS_H
#define CPP_TUTORIALS_TWEAKS_H

namespace tweaks {
    /* Material from Effective Modern C++ Chapter 8, Tweaks */

    void test_one() {
        std::vector<std::string> vs;         // container of std::string
        vs.push_back("xyzzy");               // add string literal;
        vs.emplace_back(50, 'x');            // add 50x string literal;
        print(vs[1]);
    }

    void test_all() {
        test_one();
    }
}
#endif //CPP_TUTORIALS_TWEAKS_H
