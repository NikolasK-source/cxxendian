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
class LE_Float;

template <typename T>
class BE_Float;

/**
 * @brief class that represents a floating point value using little endian
 * @tparam T data type (floating point only)
 */
template <typename T>
class LE_Float final : public Base_Float<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    explicit LE_Float(T v) noexcept : Base_Float<T>(endian::little_to_host(v)) {}

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit LE_Float(const Base_Float<t_other> &other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit LE_Float(Base_Float<t_other> &&other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief create from int type (type conversion)
     * @tparam t_other data type of other instance (must be a integer type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_integral<t_other>::value>>
    explicit LE_Float(Base_Int<t_other> &other) noexcept : Base_Float<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    LE_Float<T> &operator=(const Base_Float<t_other> &other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    LE_Float<T> &operator=(Base_Float<t_other> &&other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    LE_Float<T> &operator=(T v) noexcept {
        Base_Float<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return endian::host_to_little(Base_Float<T>::data); }

    //* default destructor
    ~LE_Float() override = default;
};

/**
 * @brief class that represents a floating point value using big endian
 * @tparam T data type (floating point only)
 */
template <typename T>
class BE_Float final : public Base_Float<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    explicit BE_Float(T v) noexcept : Base_Float<T>(endian::big_to_host(v)) {}

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit BE_Float(const Base_Float<t_other> &other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit BE_Float(Base_Float<t_other> &&other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief create from int type (type conversion)
     * @tparam t_other data type of other instance (must be a integer type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_integral<t_other>::value>>
    explicit BE_Float(Base_Int<t_other> &other) noexcept : Base_Float<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    BE_Float<T> &operator=(const Base_Float<t_other> &other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    BE_Float<T> &operator=(Base_Float<t_other> &&other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    BE_Float<T> &operator=(T v) noexcept {
        Base_Float<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return endian::host_to_big(Base_Float<T>::data); }

    //* default destructor
    ~BE_Float() override = default;
};

/**
 * @brief class that represents a floating point value using the hosts endianness
 * @tparam T data type (floating point only)
 */
template <typename T>
class Host_Float final : public Base_Float<T> {
public:
    /**
     * @brief create from base data type
     * @param v value
     */
    Host_Float(T v) noexcept : Base_Float<T>(v) {}  // NOLINT: non-explicit constructor is intentional

    /**
     * @brief copy constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit Host_Float(const Base_Float<t_other> &other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief move constructor
     * @tparam t_other data type of other instance (must match)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    explicit Host_Float(Base_Float<t_other> &&other) noexcept : Base_Float<T>(other.get_raw()) {}

    /**
     * @brief create from int type (type conversion)
     * @tparam t_other data type of other instance (must be a integer type)
     * @param other other instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_integral<t_other>::value>>
    explicit Host_Float(Base_Int<t_other> &other) noexcept : Base_Float<T>(static_cast<T>(other.get_raw())) {}

    /**
     * @brief assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    Host_Float<T> &operator=(const Base_Float<t_other> &other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief move assign from float type with any endianness
     * @tparam t_other base data type of other instance (must match)
     * @param other other instance
     * @return this instance
     */
    template <typename t_other, typename = typename std::enable_if_t<std::is_same<T, t_other>::value>>
    Host_Float<T> &operator=(Base_Float<t_other> &&other) noexcept {
        Base_Float<T>::data = other.data;
        return *this;
    }

    /**
     * @brief assign from base data type
     * @param v value
     * @return this instance
     */
    Host_Float<T> &operator=(T v) noexcept {
        Base_Float<T>::data = v;
        return *this;
    }

    /**
     * @brief get data in the actual endianness of the object
     * @return data in the objects endianness
     */
    inline T get() const noexcept override { return Base_Float<T>::data; }

    //* default destructor
    ~Host_Float() override = default;
};

}  // namespace cxxendian
