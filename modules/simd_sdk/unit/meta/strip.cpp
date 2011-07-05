/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::meta::strip"

#include <boost/simd/sdk/meta/strip.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/unit/tests/basic.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test that strip is correct
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(strip)
{
  using boost::is_same;
  using boost::simd::meta::strip;

  BOOST_SIMD_TEST( (is_same<double , strip<double>::type >::value)       );
  BOOST_SIMD_TEST( (is_same<double , strip<double&>::type >::value)      );
  BOOST_SIMD_TEST( (is_same<double , strip<double const>::type >::value) );
  BOOST_SIMD_TEST( (is_same<double , strip<double const&>::type >::value));
}
