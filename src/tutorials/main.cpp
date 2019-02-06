//
// Created by Dan Fritchman on 11/17/18.
//

#include <iostream>
#include <array>
#include <vector>
#include <map>

#include "print.h"
#include "auto_decl.h"
#include "other.h"
#include "enum.h"
#include "deleted.h"
#include "override.h"
#include "templates.h"
#include "locks.h"
#include "init.h"
#include "nullptr.h"
#include "const_thread.h"
#include "move.h"
#include "smart_ptr.h"
#include "lambda.h"
#include "concurrency.h"
#include "tweaks.h"
#include "pimpl/tests.h"

int main() {
    // Tell the people we alive
    print("Hello World!");

    // Run all this stuff
    locks::test_all();
    enums::test_all();
    templates::test_all();
    deleted::test_all();
    auto_decl::test_all();
    overrides::test_all();
    init::test_all();
    nullptrs::test_all();
    const_thread::test_all();
    moves::test_all();
    smart_ptr::test_all();
    other::test_all();
    pimpl::test_all();
    lamdbas::test_all();
    concurrency::test_all();
    tweaks::test_all();

    // And bounce
    print("Goodbye World!");
    return 0;
}
