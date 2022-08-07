/*
 * Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
 * This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
 */

#pragma once

#include <cstddef>
#include <type_traits>

/**
 * @brief namespace for all members of the cxxendian library
 */
namespace cxxendian {

/**
 * @brief abstract base class for storing integer values
 *
 * @tparam T data type (floating point only)
 */
template <typename T, typename = typename std::enable_if_t<std::is_integral<T>::value>>
class Base_Int {
protected:
    //* the actual data is stored her
    T data;

    /**
     * @brief create instance from base data type
     * @param v data for initialization
     */
    explicit Base_Int(T v) noexcept : data(v) {}

    /**
     * @brief copy constructor
     * @param other other instance
     */
    explicit Base_Int(const Base_Int<T> &other) noexcept : data(other.data) {}

public:
    //* default destructor
    virtual ~Base_Int() = default;

    /**
     * @brief get data in the endianness that the object represents
     * @return data in requested endianness
     */
    virtual T get() const noexcept = 0;

    /**
     * @brief access raw data (for internal use only)
     * @return raw data
     */
    inline T &get_raw() noexcept { return data; }

    /**
     * @brief get copy of raw data (for internal use only)
     * @return raw data
     */
    inline T get_raw() const noexcept { return data; }
};

}  // namespace cxxendian
