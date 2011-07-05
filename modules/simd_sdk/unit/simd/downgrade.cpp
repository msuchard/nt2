/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define BOOST_SIMD_UNIT_MODULE "boost::simd::meta::downgrade SIMD"

#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/meta/downgrade.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/simd/sdk/unit/tests/basic.hpp>
#include <boost/simd/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test that downgrade is correct for SIMD types
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_TEST_CASE_TPL(downgrade, BOOST_SIMD_TYPES)
{
  using boost::simd::native;
  using boost::simd::meta::downgrade;
  using boost::is_same;

  typedef BOOST_SIMD_DEFAULT_EXTENSION      ext_t;
  typedef native<T,ext_t>                 native_t;
  typedef typename downgrade<T>::type base_t;

  BOOST_SIMD_TEST( (is_same<typename downgrade<native_t>::type::value_type,base_t>::value ));
}

