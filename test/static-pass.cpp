/*
 * static-pass.cpp          -- traits static tests
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
using NReinventedWheels::TIsCheapCopyable;

#include "helpers.hpp"

static_assert(TIsCheapCopyable<int>::Value_, "");
static_assert(!TIsCheapCopyable<void*[2]>::Value_, "");
static_assert(TIsCheapCopyable<int*>::Value_, "");
static_assert(TIsCheapCopyable<TPod>::Value_, "");
static_assert(!TIsCheapCopyable<TBigPod>::Value_, "");
static_assert(!TIsCheapCopyable<TCopyable>::Value_, "");

