/*!The Graphic Box Library
 * 
 * GBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * GBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with GBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2014 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        float.c
 * @ingroup     core
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "float.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
tb_size_t gb_float_unit_divide(gb_float_t numer, gb_float_t denom, gb_float_t* result)
{
    // check
    tb_assert_abort(result);

    // negate it
    if (numer < 0) 
    {
        numer = -numer;
        denom = -denom;
    }

    // must be valid numerator and denominator
    if (0 == denom || 0 == numer || numer >= denom) 
        return 0;

    // the result: numer / denom
    gb_float_t r = gb_div(numer, denom);

    // must be finite value
    tb_assert_and_check_return_val(gb_isfinite(r), 0);

    // must be in range: [0, 1)
    tb_assert_and_check_return_val(r >= 0 && r < GB_ONE, 0);

    // too smaller? not save result
    tb_check_return_val(r != 0, 0);

    // save result
    *result = r;

    // ok
    return 1;
}

