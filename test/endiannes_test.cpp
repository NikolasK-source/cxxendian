/*
 * Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
 * This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
 */

#include "cxxendian.hpp"

#include <iostream>
#include <iomanip>

using namespace cxxendian;

int main() {
    int a = 42;
    std::cout << a << std::endl;
    int b = a;
    std::cout << b << std::endl;
    int c = a + b;
    std::cout << c << std::endl;
    int d = a + -b;
    std::cout << d << std::endl;
    int e = a << 3;
    std::cout << e << std::endl;
    int f = -8;
    std::cout << d << std::endl;
    f += a;
    std::cout << f << std::endl;
    f -= c;
    std::cout << f << std::endl;
    int g = f | a;
    std::cout << g << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;

    Host_Int<int> A(42);
    std::cout << A << std::endl;
    auto B = A;
    std::cout << B << std::endl;
    auto C = A + B;
    std::cout << C << std::endl;
    auto D = A + -B;
    std::cout << D << std::endl;
    auto E = A << 3;
    std::cout << E << std::endl;
    Host_Int<int> F = -8;
    std::cout << D << std::endl;
    F += A;
    std::cout << F << std::endl;
    F -= C;
    std::cout << F << std::endl;
    auto G = F | A;
    std::cout << G << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    {
        float a = 100.f;
        float b = a;
        float c = a / 42.375f;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;
    {
        Host_Float<float> a(100.f);
        auto b = a;
        auto c = a / Host_Float<float>(42.375f);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    Host_Int<long long > x(0x420000AA55000011);
    BE_Int<long long> y(x);
    std::cout << std::hex << x.get() << std::endl;
    std::cout << std::hex << y.get() << std::endl;

}
