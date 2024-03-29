/*
 * linkage.cpp              -- traits linkage test
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

template <class TValue>
void Double(TValue, typename TCheapCopy<TValue>::TValueType value)
{
    TValue result = TValue(value + value);
    static_cast<void>(result);
}

struct TConst
{
    static const int I_ = 4;
};

int main()
{
    Double(TConst::I_, TConst::I_);
    enum { Red, Green, Blue };
    Double(Red, Green);
}

