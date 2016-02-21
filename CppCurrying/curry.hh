/**
 * Implementation of currying and partial application in modern C++.
 */

/**
 * Partial application.
 */
template<typename F, typename Arg>
auto partial(F && f, Arg && arg) {
    return [f=std::forward<F>(f), arg=std::forward<Arg>(arg)]
            (auto &&... rest) {
        return f(arg, decltype(rest)(rest)...);
    };
}

template<typename F, typename Arg, typename... Args>
auto partial(F && f, Arg && arg, Args &&... args) {
    return partial(partial(std::forward<F>(f),
            std::forward<Arg>(arg)), std::forward<Args>(args)...);
}

/**
 * Function traits, transfer lambda expression, function pointer and member method to std::function.
 */ 
// for lambda expression, and functor object.
template <typename Functor>
struct function_traits
    : public function_traits<decltype(&Functor::operator())>
{};

// for std::function and ordinary functions.
template<typename Return, typename... Args>
struct function_traits<Return(Args...)> {
    using func_type = std::function<Return(Args...)>;
};

// for member function.
template <typename Class, typename Return, typename... Args>
struct function_traits<Return(Class::*)(Args...)> {
    using func_type = std::function<Return(Args...)>;
};

// for capturing lambda transformed lambda expression and function object. 
template <typename Class, typename Return, typename... Args>
struct function_traits<Return(Class::*)(Args...) const> {
    using func_type = std::function<Return(Args...)>;
};

// for function pointer.
template <typename Return, typename... Args>
struct function_traits<Return (*)(Args...)> {
    using func_type = std::function<Return(Args...)>;
};

/**
 * Currying for std::function and lambda expressions.
 */
template<typename Return>
auto curry_impl(std::function<Return()> & f) {
    return std::forward<decltype(f)>(f);
}

template<typename Return, typename Arg>
auto curry_impl(std::function<Return(Arg)> & f) {
    return std::forward<decltype(f)>(f);
}

template<typename Return, typename Arg, typename... Args>
auto curry_impl(std::function<Return(Arg, Args...)> & f) {
    return [f=std::forward<decltype(f)>(f)](Arg arg) {
        std::function<Return(Args...)> rest = [&f, &arg](Args... args) -> Return {
            return f(arg, args...);
        };
        return curry_impl(rest);
    };
}
template<typename F>
auto curry(F const & f) {
    typename function_traits<F>::func_type _f = f;
    return curry_impl(_f);
}


