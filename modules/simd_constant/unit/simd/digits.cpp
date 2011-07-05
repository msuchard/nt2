/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::constants digits"

#include <boost/simd/include/constants/digits.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/unit/tests/relation.hpp>
#include <boost/simd/sdk/simd/native.hpp>

#ifdef BOOST_MSVC
  #pragma warning(disable: 4309) // truncation of constant value
#endif

////////////////////////////////////////////////////////////////////////////////
// Test value of digit constant for every base types
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE_TPL( digit_value, BOOST_SIMD_TYPES )
{
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef boost::simd::native<T,ext_t>             dst_t;

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mten<dst_t>())[i], static_cast<T>(  -10 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mnine<dst_t>())[i], static_cast<T>( -9 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Meight<dst_t>())[i], static_cast<T>( -8 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mseven<dst_t>())[i], static_cast<T>( -7 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Msix<dst_t>())[i], static_cast<T>( -6 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mfive<dst_t>())[i], static_cast<T>( -5 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mfour<dst_t>())[i], static_cast<T>( -4 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mthree<dst_t>())[i], static_cast<T>( -3 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mtwo<dst_t>())[i], static_cast<T>( -2 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Mone<dst_t>())[i], static_cast<T>( -1 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Zero<dst_t>())[i], static_cast<T>(  0 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Ten<dst_t>())[i], static_cast<T>(  10 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Nine<dst_t>())[i], static_cast<T>( 9 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Eight<dst_t>())[i], static_cast<T>( 8 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Seven<dst_t>())[i], static_cast<T>( 7 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Six<dst_t>())[i], static_cast<T>( 6 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Five<dst_t>())[i], static_cast<T>( 5 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Four<dst_t>())[i], static_cast<T>( 4 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Three<dst_t>())[i], static_cast<T>( 3 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Two<dst_t>())[i], static_cast<T>( 2 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::One<dst_t>())[i], static_cast<T>( 1 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Fortyfive<dst_t>())[i], static_cast<T>( 45 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Ninety<dst_t>())[i], static_cast<T>( 90 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Hundred<dst_t>())[i], static_cast<T>( 100 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Onehundredeighty<dst_t>())[i], static_cast<T>( 180 ) );

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::Thousand<dst_t>())[i], static_cast<T>( 1000 ) );
}

////////////////////////////////////////////////////////////////////////////////
// Test integral_constant for every base types
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE_TPL( integral_constant, BOOST_SIMD_TYPES )
{
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef boost::simd::native<T,ext_t>             dst_t;

  for(std::size_t i=0; i< boost::simd::meta::cardinal_of<dst_t>::value;++i)
    BOOST_SIMD_TEST_EQUAL( (boost::simd::integral_constant<dst_t,42>())[i], static_cast<T>(42) );
}
