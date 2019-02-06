//
// Created by Dan Fritchman on 2019-01-11.
//

#ifndef CPP_TUTORIALS_PIMPL_H
#define CPP_TUTORIALS_PIMPL_H

class Pimpl {
public:
    Pimpl();

    ~Pimpl();

    Pimpl(Pimpl &&rhs) noexcept;

    Pimpl &operator=(Pimpl &&rhs) noexcept;

    Pimpl(const Pimpl &rhs);

    Pimpl &operator=(const Pimpl &rhs);

private:
    class Impl;

    std::unique_ptr<Impl> impl;
};

#endif //CPP_TUTORIALS_PIMPL_H
