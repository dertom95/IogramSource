//
// Copyright (c) 2016 - 2017 Mesh Consultants Inc.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


#pragma once
#include "Urho3D/Math/Color.h"

#define TO_DEC(x) (x/255.0f)

//dark theme
#define FLAT_BLACK Color::Zero
#define OFF_BLACK Color(TO_DEC(8), TO_DEC(8), TO_DEC(8), TO_DEC(255))
#define VERY_DARK_GREY Color(TO_DEC(20), TO_DEC(20), TO_DEC(20), TO_DEC(255))
#define DARK_GRAY Color(TO_DEC(45), TO_DEC(45), TO_DEC(45), TO_DEC(255))
#define MIDDLE_GRAY Color(TO_DEC(80), TO_DEC(80), TO_DEC(80), TO_DEC(255))
#define LIGHT_GREY Color(TO_DEC(120), TO_DEC(120), TO_DEC(120), TO_DEC(255))

//highlights
#define LIGHT_GREEN Color(TO_DEC(31), TO_DEC(222), TO_DEC(126), TO_DEC(255))
#define LESS_GREEN Color(TO_DEC(25), TO_DEC(175), TO_DEC(100), TO_DEC(255))
#define BRIGHT_ORANGE Color(TO_DEC(254), TO_DEC(93), TO_DEC(1), TO_DEC(255))
#define PURPLE Color(TO_DEC(105), TO_DEC(39), TO_DEC(154), TO_DEC(255))
#define SKY_BLUE Color(TO_DEC(2), TO_DEC(125), TO_DEC(212), TO_DEC(255))
#define YELLOW Color(TO_DEC(254), TO_DEC(197), TO_DEC(5), TO_DEC(255))