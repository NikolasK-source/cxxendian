/*
 * Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
 * This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
 */

#pragma once

#include <ostream>

#include "int.hpp"

/**
 * @brief namespace for all members of the cxxendian library
 */
namespace cxxendian {

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator+(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return Host_Int<T>(a.get_raw() + b.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator+=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() += b.get_raw();
    return a;
}

template <typename T>
inline Host_Int<T> operator-(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return Host_Int<T>(a.get_raw() - b.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator-=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() -= b.get_raw();
    return a;
}

template <typename T>
inline Host_Int<T> operator*(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return Host_Int<T>(a.get_raw() * b.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator*=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() *= b.get_raw();
    return a;
}

template <typename T>
inline Host_Int<T> operator/(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return Host_Int<T>(a.get_raw() / b.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator/=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() /= b.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator%(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return Host_Int<T>(a.get_raw() % b.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator%=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() %= b.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> &operator++(Base_Int<T, void> &a) noexcept {
    ++a.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator++(Base_Int<T, void> &a, int) noexcept {  // NOLINT
    Host_Int<T> ret(a);
    --a.get_raw();
    return ret;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> &operator--(Base_Int<T, void> &a) noexcept {
    --a.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator--(Base_Int<T, void> &a, int) noexcept {  // NOLINT
    Host_Int<T> ret(a);
    --a.get_raw();
    return ret;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator+(const Base_Int<T, void> &a) noexcept {
    return Host_Int<T>(a);
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator-(const Base_Int<T, void> &a) noexcept {
    return Host_Int<T>(-a.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator==(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() == b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator!=(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() != b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator>(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() > b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator<(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() < b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator>=(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() >= b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator<=(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() <= b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator!(const Base_Int<T, void> &a) noexcept {
    return Host_Int<T>(!a.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator&&(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() && b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline bool operator||(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() || b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator~(const Base_Int<T, void> &a) noexcept {
    return Host_Int<T>(~a.get_raw());
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator&(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() & b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator&=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() &= b.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator|(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() | b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator|=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() |= b.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator^(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() ^ b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator^=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() ^= b.get_raw();
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator<<(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() << b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator<<=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() <<= b.get_raw();
    return a;
}

template <typename T,
          typename T2,
          typename = typename std::enable_if_t<std::is_integral<T>::value>,
          typename = typename std::enable_if_t<std::is_integral<T2>::value>>
inline Host_Int<T> operator<<(const Base_Int<T, void> &a, T2 b) noexcept {
    return a.get_raw() << b;
}

template <typename T,
          typename T2,
          typename = typename std::enable_if_t<std::is_integral<T>::value>,
          typename = typename std::enable_if_t<std::is_integral<T2>::value>>
inline Base_Int<T> &operator<<=(Base_Int<T, void> &a, T2 b) noexcept {
    a.get_raw() <<= b;
    return a;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Host_Int<T> operator>>(const Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    return a.get_raw() >> b.get_raw();
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline Base_Int<T> &operator>>=(Base_Int<T, void> &a, const Base_Int<T, void> &b) noexcept {
    a.get_raw() >>= b.get_raw();
    return a;
}

template <typename T,
          typename T2,
          typename = typename std::enable_if_t<std::is_integral<T>::value>,
          typename = typename std::enable_if_t<std::is_integral<T2>::value>>
inline Base_Int<T> &operator>>=(Base_Int<T, void> &a, T2 b) noexcept {
    a.get_raw() >>= b;
    return a;
}

template <typename T,
          typename T2,
          typename = typename std::enable_if_t<std::is_integral<T>::value>,
          typename = typename std::enable_if_t<std::is_integral<T2>::value>>
inline Host_Int<T> operator>>(const Base_Int<T, void> &a, T2 b) noexcept {
    return a.get_raw() >> b;
}

template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
inline std::ostream &operator<<(std::ostream &o, const Base_Int<T, void> &i) {
    o << i.get_raw();
    return o;
}

}  // namespace cxxendian
