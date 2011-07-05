/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::meta::make_integer"

#include <boost/mpl/placeholders.hpp>
#include <boost/simd/sdk/config/types.hpp>
#include <boost/simd/sdk/meta/make_integer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/unit/tests/basic.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test make_integer output
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(make_integer)
{
  using boost::simd::meta::make_integer;
  using boost::is_same;
  using namespace boost;

  BOOST_SIMD_TEST( (is_same<boost::simd::int8_t   , make_integer<1, signed  >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int16_t  , make_integer<2, signed  >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int32_t  , make_integer<4, signed  >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int64_t  , make_integer<8, signed  >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint8_t  , make_integer<1,unsigned >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint16_t , make_integer<2,unsigned >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint32_t , make_integer<4,unsigned >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint64_t , make_integer<8,unsigned >::type >::value)  );
}

////////////////////////////////////////////////////////////////////////////////
// Test make_integer transformed output
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(make_integer_transform)
{
  using boost::simd::meta::make_integer;
  using boost::add_pointer;
  using boost::is_same;
  using boost::mpl::_;
  using namespace boost;

  BOOST_SIMD_TEST( (is_same<boost::simd::int8_t*  , make_integer<1, signed , add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int16_t* , make_integer<2, signed , add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int32_t* , make_integer<4, signed , add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::int64_t* , make_integer<8, signed , add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint8_t* , make_integer<1,unsigned, add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint16_t*, make_integer<2,unsigned, add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint32_t*, make_integer<4,unsigned, add_pointer<_> >::type >::value)  );
  BOOST_SIMD_TEST( (is_same<boost::simd::uint64_t*, make_integer<8,unsigned, add_pointer<_> >::type >::value)  );
}
