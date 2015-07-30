/************************************************************************************
*                                                                                   *
*   Copyright (c) 2014, 2015 Axel Menzel <info@axelmenzel.de>                       *
*                                                                                   *
*   This file is part of RTTR (Run Time Type Reflection)                            *
*   License: MIT License                                                            *
*                                                                                   *
*   Permission is hereby granted, free of charge, to any person obtaining           *
*   a copy of this software and associated documentation files (the "Software"),    *
*   to deal in the Software without restriction, including without limitation       *
*   the rights to use, copy, modify, merge, publish, distribute, sublicense,        *
*   and/or sell copies of the Software, and to permit persons to whom the           *
*   Software is furnished to do so, subject to the following conditions:            *
*                                                                                   *
*   The above copyright notice and this permission notice shall be included in      *
*   all copies or substantial portions of the Software.                             *
*                                                                                   *
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
*   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
*   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
*   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
*   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
*   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
*   SOFTWARE.                                                                       *
*                                                                                   *
*************************************************************************************/

#include <catch/catch.hpp>

#include <rttr/type>

using namespace rttr;
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("variant::operator<() - empty", "[variant]")
{
    SECTION("empty type")
    {
        variant a;
        variant b;

        CHECK((a < b) == false);
    }

    SECTION("full type lhs")
    {
        variant a = 23;
        variant b;

        CHECK((a < b) == false);
    }

    SECTION("full type rhs")
    {
        variant a;
        variant b = 23;

        CHECK((a < b) == false);
    }

}

/////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("variant::operator<() - integer", "[variant]")
{
    SECTION("equal")
    {
        variant a = static_cast<int8_t>(100);
        variant b = static_cast<int32_t>(100);

        CHECK((a < b) == false);
    }

    SECTION("lower < bigger")
    {
        variant a = static_cast<int8_t>(100);
        variant b = static_cast<int32_t>(10000);

        CHECK((a < b) == true);
    }

    SECTION("bigger < lower")
    {
        variant a = static_cast<int32_t>(10000);
        variant b = static_cast<int8_t>(100);

        CHECK((a < b) == false);
    }

    SECTION("lower < bigger[unsigned]")
    {
        variant a = static_cast<int32_t>(-10000);
        variant b = static_cast<int8_t>(100);

        CHECK((a < b) == true);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("variant::operator<() - float", "[variant]")
{
    SECTION("lower < bigger")
    {
        variant a = static_cast<int8_t>(123);
        variant b = 123.2f;

        CHECK((a < b) == true);
    }

    SECTION("bigger < lower")
    {
        variant a = 123.2f;
        variant b = static_cast<int8_t>(123);

        CHECK((a < b) == false);
    }

    SECTION("lower < bigger")
    {
        variant a = -1230.3f;
        variant b = static_cast<int8_t>(100);

        CHECK((a < b) == true);
    }

     SECTION("lower < bigger")
    {
        variant a = -1230.37f;
        variant b = -1230.31;

        CHECK((a < b) == true);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("variant::operator<() - double", "[variant]")
{
    SECTION("lower < bigger")
    {
        variant a = static_cast<int8_t>(123);
        variant b = 123.2;

        CHECK((a < b) == true);
    }

    SECTION("int - bigger < lower")
    {
        variant a = 123.2;
        variant b = static_cast<int8_t>(123);

        CHECK((a < b) == false);
    }

    SECTION("int UnSigned - lower < bigger")
    {
        variant a = -1230.3;
        variant b = static_cast<int8_t>(100);

        CHECK((a < b) == true);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
