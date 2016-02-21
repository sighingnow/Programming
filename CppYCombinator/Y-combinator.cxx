/**
 * The Y Fix-point Combinator in C++.
 */

#include <iostream>
#include <functional>

template<typename F, typename T>
auto Y(auto recurse) -> F {
    auto helper = [=](auto self) -> F {
        return recurse([=](T x) {
            return self(self)(x);
        });
    };
    return helper(helper);
};

int main() {
    auto fact = Y<std::function<int(int)>, int>([](auto recurse) {
        return [=](auto n) {
            return n == 0 ? 1 : n * recurse(n-1);
        };
    });
    auto fibonacci = Y<std::function<int(int)>, int>([](auto recurse) {
        return [=](auto n) {
            return n == 0 ? 0 : n == 1 ? 1 : recurse(n-1) + recurse(n-2);
        };
    });
    std:: cout << fact(10) << ' ' << fibonacci(10) << std::endl;

    return 0;
}
