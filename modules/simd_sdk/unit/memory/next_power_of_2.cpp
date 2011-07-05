/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 0x01.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::memory::next_power_of_2"

#include <boost/simd/sdk/memory/meta/next_power_of_2.hpp>

#include <boost/mpl/int.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/unit/tests/relation.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test the meta::next_power_of_2 version on int_
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(next_power_of_2)
{
  using boost::simd::meta::next_power_of_2;
  using boost::mpl::int_;

  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x00> >::value), 0x00 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x01> >::value), 0x01 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x02> >::value), 0x02 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x03> >::value), 0x04 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x04> >::value), 0x04 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x05> >::value), 0x08 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x06> >::value), 0x08 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x07> >::value), 0x08 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x08> >::value), 0x08 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x0D> >::value), 0x10 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x14> >::value), 0x20 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x33> >::value), 0x40 );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2< int_<0x6A> >::value), 0x80 );
}

////////////////////////////////////////////////////////////////////////////////
// Test the meta::next_power_of_2 version on integral constant
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(next_power_of_2_c)
{
  using boost::simd::meta::next_power_of_2_c;

  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x00 >::value), 0x00U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x01 >::value), 0x01U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x02 >::value), 0x02U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x03 >::value), 0x04U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x04 >::value), 0x04U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x05 >::value), 0x08U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x06 >::value), 0x08U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x07 >::value), 0x08U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x08 >::value), 0x08U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x0D >::value), 0x10U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x14 >::value), 0x20U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x33 >::value), 0x40U );
  BOOST_SIMD_TEST_EQUAL( (next_power_of_2_c< 0x6A >::value), 0x80U );
}
