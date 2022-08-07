/*
 * Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
 * This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
 */

#pragma once

#include "float.hpp"

/**
 * @brief namespace for all members of the cxxendian library
 */
namespace cxxendian {

/**
 * @brief add operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return result (a+b)
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator+(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return Host_Float<T>(a.get_raw() + b.get_raw());
}

/**
 * @brief add assign operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return reference to left operand
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Base_Float<T> &operator+=(Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    a.get_raw() += b.get_raw();
    return a;
}

/**
 * @brief sub operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return result (a-b)
 */
template <typename T>
inline Host_Float<T> operator-(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return Host_Float<T>(a.get_raw() - b.get_raw());
}

/**
 * @brief sub assign operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return reference to left operand
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Base_Float<T> &operator-=(Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    a.get_raw() -= b.get_raw();
    return a;
}

/**
 * @brief mul operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return result (a*b)
 */
template <typename T>
inline Host_Float<T> operator*(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return Host_Float<T>(a.get_raw() * b.get_raw());
}

/**
 * @brief mul assign operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return reference to left operand
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Base_Float<T> &operator*=(Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    a.get_raw() *= b.get_raw();
    return a;
}

/**
 * @brief div operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return result (a/b)
 */
template <typename T>
inline Host_Float<T> operator/(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return Host_Float<T>(a.get_raw() / b.get_raw());
}

/**
 * @brief div assign operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return reference to left operand
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Base_Float<T> &operator/=(Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    a.get_raw() /= b.get_raw();
    return a;
}

/**
 * @brief mod operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return result (a%b)
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator%(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return Host_Float<T>(a.get_raw() % b.get_raw());
}

/**
 * @brief mul assign operator
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return reference to left operand
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Base_Float<T> &operator%=(Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    a.get_raw() %= b.get_raw();
    return a;
}

/**
 * @brief prefix increment operator
 * @tparam T base data type
 * @param a instance
 * @return reference to a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> &operator++(Base_Float<T, void> &a) noexcept {
    ++a.get_raw();
    return a;
}

/**
 * @brief postfix increment operator
 * @tparam T base data type
 * @param a instance
 * @return copy of a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator++(Base_Float<T, void> &a, int) noexcept {  // NOLINT
    Host_Float<T> ret(a);
    --a.get_raw();
    return ret;
}

/**
 * @brief prefix decrement operator
 * @tparam T base data type
 * @param a instance
 * @return reference to a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> &operator--(Base_Float<T, void> &a) noexcept {
    --a.get_raw();
    return a;
}

/**
 * @brief postfix decrement operator
 * @tparam T base data type
 * @param a instance
 * @return copy of a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator--(Base_Float<T, void> &a, int) noexcept {  // NOLINT
    Host_Float<T> ret(a);
    --a.get_raw();
    return ret;
}

/**
 * @brief Unary plus operator
 * @tparam T base data type
 * @param a instance
 * @return copy of a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator+(const Base_Float<T, void> &a) noexcept {
    return Host_Float<T>(a);
}

/**
 * @brief Unary minus operator
 * @tparam T base data type
 * @param a instance
 * @return -a
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline Host_Float<T> operator-(const Base_Float<T, void> &a) noexcept {
    return Host_Float<T>(-a.get_raw());
}

/**
 * @brief Comparison: ==
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a == b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator==(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() == b.get_raw();
}

/**
 * @brief Comparison: !=
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a != b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator!=(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() != b.get_raw();
}

/**
 * @brief Comparison: >
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a > b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator>(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() > b.get_raw();
}

/**
 * @brief Comparison: <
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a < b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator<(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() < b.get_raw();
}

/**
 * @brief Comparison: >=
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a >= b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator>=(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() >= b.get_raw();
}

/**
 * @brief Comparison: <=
 * @tparam T base data type
 * @param a left operand
 * @param b right operand
 * @return a <= b
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline bool operator<=(const Base_Float<T, void> &a, const Base_Float<T, void> &b) noexcept {
    return a.get_raw() <= b.get_raw();
}

/**
 * @brief output data to output stream
 * @tparam T base data type
 * @param o output stream
 * @param f instance to output
 * @return output stream
 */
template <typename T, typename = typename std::enable_if_t<std::is_floating_point<T>::value>>
inline std::ostream &operator<<(std::ostream &o, const Base_Float<T, void> &f) {
    o << f.get_raw();
    return o;
}

}  // namespace cxxendian
