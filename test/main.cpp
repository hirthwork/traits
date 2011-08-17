/*
 * main.cpp                 -- type traits main test
 *
 * Copyright (C) 2011 Dmitry Potapov <potapov.d@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cheapcopy.hpp>
using NReinventedWheels::TCheapCopy;

#include "helpers.hpp"

#define BOOST_TEST_MODULE LazyTest
#include <boost/test/unit_test.hpp>

template <class TValue>
void CheckAddress(const TValue& original,
    typename TCheapCopy<TValue>::TValueType copy, bool equal)
{
    if (equal)
    {
        BOOST_REQUIRE_EQUAL(&original, &copy);
    }
    else
    {
        BOOST_REQUIRE_NE(&original, &copy);
    }
}

template <class TValue>
void DoTest(bool equal)
{
    TValue value;
    CheckAddress(value, value, equal);
}

BOOST_AUTO_TEST_CASE(address)
{
    DoTest<int>(false);
    DoTest<void*[2]>(true);
    DoTest<int*>(false);
    DoTest<TPod>(false);
    DoTest<TBigPod>(true);
    DoTest<TCopyable>(true);
}

