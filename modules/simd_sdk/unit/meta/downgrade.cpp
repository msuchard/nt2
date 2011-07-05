/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::meta::downgrade"

#include <boost/simd/sdk/config/types.hpp>
#include <boost/simd/sdk/meta/downgrade.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/unit/tests/basic.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test that downgrade is correct for middle-sized types
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(downgrad_ints)
{
  using boost::simd::meta::downgrade;
  using boost::is_same;

  BOOST_SIMD_TEST( (is_same<downgrade<double  			>::type,float 				>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<float   			>::type,float					>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int64_t >::type,boost::simd::int32_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int32_t >::type,boost::simd::int16_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int16_t >::type,boost::simd::int8_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint64_t>::type,boost::simd::uint32_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint32_t>::type,boost::simd::uint16_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint16_t>::type,boost::simd::uint8_t  >::value ));
}

////////////////////////////////////////////////////////////////////////////////
// Test that downgrade is correct w/r to forced sign
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(downgrade_ints_forced_signed)
{
  using boost::simd::meta::downgrade;
  using boost::is_same;

	BOOST_SIMD_TEST( (is_same<downgrade<double  			,	unsigned>::type,float 				>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<float   			,	unsigned>::type,float 				>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int64_t ,	unsigned>::type,boost::simd::uint32_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int32_t ,	unsigned>::type,boost::simd::uint16_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int16_t ,	unsigned>::type,boost::simd::uint8_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint64_t,	unsigned>::type,boost::simd::uint32_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint32_t,	unsigned>::type,boost::simd::uint16_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint16_t,	unsigned>::type,boost::simd::uint8_t  >::value ));

	BOOST_SIMD_TEST( (is_same<downgrade<double  			,	signed>::type,float 				>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<float   			,	signed>::type,float					>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int64_t ,	signed>::type,boost::simd::int32_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int32_t ,	signed>::type,boost::simd::int16_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int16_t ,	signed>::type,boost::simd::int8_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint64_t,	signed>::type,boost::simd::int32_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint32_t,	signed>::type,boost::simd::int16_t 	>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint16_t,	signed>::type,boost::simd::int8_t  	>::value ));
}

////////////////////////////////////////////////////////////////////////////////
// Test that downgrade is correct w/r to tpye of sizeof == 1
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE(downgrade_sizeof_1)
{
  using boost::simd::meta::downgrade;
  using boost::is_same;

  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int8_t	>::type,boost::simd::int8_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint8_t >::type,boost::simd::uint8_t>::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int8_t	,unsigned	>::type,boost::simd::uint8_t >::value ));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint8_t ,unsigned	>::type,boost::simd::uint8_t>::value 	));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::int8_t	,signed		>::type,boost::simd::int8_t >::value 	));
  BOOST_SIMD_TEST( (is_same<downgrade<boost::simd::uint8_t ,signed		>::type,boost::simd::int8_t>::value 	));
}

