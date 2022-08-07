/*
 * Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
 * This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
 */

#pragma once

#include "base_float.hpp"
#include "base_int.hpp"
#include "endian.hpp"

/**
 * @brief namespace for all members of the cxxendian library
 */
namespace cxxendian {

template <typename T>
class LE_Int;

template <typename T>
class BE_Int;

/**
 * @brief class that represents a integer value using little endian
 * @tparam T data type (floating point only)
 */
template <typename T>
class LE_Int final : public Base_Int<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    explicit LE_Int(T v) noexcept : Base_Int<T>(endian::host_to_little(v)) {}

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit LE_Int(const Base_Int<t_other> &other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit LE_Int(Base_Int<t_other> &&other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief create from float type (type conversion)
     * @tparam t_other data type of other instance (must be a floating point type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_floating_point<t_other>::value>>
    explicit LE_Int(Base_Float<t_other> &other) noexcept : Base_Int<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    LE_Int<T> &operator=(const Base_Int<t_other> &other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move move assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    LE_Int<T> &operator=(Base_Int<t_other> &&other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    LE_Int<T> &operator=(T v) noexcept {
        Base_Int<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return endian::host_to_little(Base_Int<T>::data); }

    //* default destructor
    ~LE_Int() override = default;
};

/**
 * @brief class that represents a integer value using big endian
 * @tparam T data type (floating point only)
 */
template <typename T>
class BE_Int final : public Base_Int<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    explicit BE_Int(T v) noexcept : Base_Int<T>(endian::host_to_big(v)) {}

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit BE_Int(const Base_Int<t_other> &other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit BE_Int(Base_Int<t_other> &&other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief create from float type (type conversion)
     * @tparam t_other data type of other instance (must be a floating point type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_floating_point<t_other>::value>>
    explicit BE_Int(Base_Float<t_other> &other) noexcept : Base_Int<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    BE_Int<T> &operator=(const Base_Int<t_other> &other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move move assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    BE_Int<T> &operator=(Base_Int<t_other> &&other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    BE_Int<T> &operator=(T v) noexcept {
        Base_Int<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return endian::host_to_big(Base_Int<T>::data); }

    //* default destructor
    ~BE_Int() override = default;
};

/**
 * @brief class that represents a integer value using the hosts endianness
 * @tparam T data type (floating point only)
 */

template <typename T>
class Host_Int final : public Base_Int<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    Host_Int(T v) noexcept : Base_Int<T>(v) {}  // NOLINT: non-explicit constructor is intentional

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit Host_Int(const Base_Int<t_other> &other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit Host_Int(Base_Int<t_other> &&other) noexcept : Base_Int<T>(other.get_raw()) {}

    /**
     * @brief create from float type (type conversion)
     * @tparam t_other data type of other instance (must be a floating point type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_floating_point<t_other>::value>>
    explicit Host_Int(Base_Float<t_other> &other) noexcept : Base_Int<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    Host_Int<T> &operator=(const Base_Int<t_other> &other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move move assign from integer type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    Host_Int<T> &operator=(Base_Int<t_other> &&other) noexcept {
        Base_Int<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    Host_Int<T> &operator=(T v) noexcept {
        Base_Int<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return Base_Int<T>::data; }

    //* default destructor
    ~Host_Int() override = default;
};

}  // namespace cxxendian
