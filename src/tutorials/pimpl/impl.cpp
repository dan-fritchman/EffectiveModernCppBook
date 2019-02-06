//
// Created by Dan Fritchman on 2019-01-11.
//

#ifndef CPP_TUTORIALS_IMPL_H
#define CPP_TUTORIALS_IMPL_H

#include <iostream>
#include "pimpl.h"

class Pimpl::Impl {
private:
    float a{0}, b{1}, c{2};
};

/*
 * Special Function Definitions
 *   Construct/Destruct, Move, etc.
 *   Have to be in implementation-file, *after* definition of `Impl`, for fun reasons.
 */

Pimpl::Pimpl() : impl(std::make_unique<Impl>()) {}

Pimpl::~Pimpl() = default;

Pimpl::Pimpl(Pimpl &&rhs) noexcept = default;

Pimpl &Pimpl::operator=(Pimpl &&rhs) noexcept = default;

Pimpl::Pimpl(const Pimpl &rhs) : impl(nullptr) {
    if (rhs.impl) impl = std::make_unique<Impl>(*rhs.impl);
}

Pimpl &Pimpl::operator=(const Pimpl &rhs) {
    if (!rhs.impl) impl.reset();
    else if (!impl) impl = std::make_unique<Impl>(*rhs.impl);
    else *impl = *rhs.impl;

    return *this;
}

#endif //CPP_TUTORIALS_IMPL_H
