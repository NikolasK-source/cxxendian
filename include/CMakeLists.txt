#
# Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
# This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
#

target_sources(cf_dummy PRIVATE cxxendian.hpp)
target_sources(cf_dummy PRIVATE cxxendian/base_int.hpp cxxendian/int.hpp cxxendian/int_operators.hpp)
target_sources(cf_dummy PRIVATE cxxendian/base_float.hpp cxxendian/float.hpp cxxendian/float_operators.hpp)
target_sources(cf_dummy PRIVATE cxxendian/endian.hpp)
