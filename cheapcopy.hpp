/*
 * cheapcopy.hpp            -- best function parameter type selector
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

#ifndef __CHEAPCOPY_HPP_2011_08_17__
#define __CHEAPCOPY_HPP_2011_08_17__

#include <type_traits>

namespace NReinventedWheels
{
    namespace NPrivate
    {
        template <class TValue, bool Small_>
        struct TCheapCopyImplementation
        {
            typedef TValue TValueType;
        };

        template <class TValue>
        struct TCheapCopyImplementation<TValue, false>
        {
            typedef const TValue& TValueType;
        };
    }

    // TODO: use is_trivially_copyable instead of is_pod once it will be
    // implemented in compiler
    template <class TValue>
    struct TIsCheapCopyable
    {
        static const bool Value_ =
            (std::is_pod<TValue>::value && sizeof(TValue) <= sizeof(void*))
            || std::is_pointer<TValue>::value;
    };

    template <class TValue>
    struct TCheapCopy : NPrivate::TCheapCopyImplementation<TValue,
        TIsCheapCopyable<TValue>::Value_>
    {
    };
}

#endif

