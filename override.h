//
// Created by Dan Fritchman on 12/7/18.
//

#ifndef CPP_TUTORIALS_OVERRIDE_H_H
#define CPP_TUTORIALS_OVERRIDE_H_H

class Base {
public:
    virtual void mf1() const = 0;
    virtual void mf2(int x) = 0;
    virtual void mf4() const = 0;
};

class Derived : public Base {
public:
    virtual void mf1() const override { return; };
    virtual void mf2(int x) override { return; };
    virtual void mf4() const override { return; };
};

void test_override() {
    auto d = Derived();
    d.mf1();
    d.mf2
    return;
}

#endif //CPP_TUTORIALS_OVERRIDE_H_H
