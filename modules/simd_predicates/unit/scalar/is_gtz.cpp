//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_UNIT_MODULE "nt2 predicates toolbox - is_gtz/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of predicates components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
/// 
#include <boost/simd/toolbox/predicates/include/is_gtz.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/simd/sdk/meta/logical.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/functor/meta/call.hpp>
#include <boost/simd/sdk/unit/tests.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/include/constants/infinites.hpp>


BOOST_SIMD_TEST_CASE_TPL ( is_gtz_real__1_0,  BOOST_SIMD_REAL_TYPES)
{
  
  using boost::simd::is_gtz;
  using boost::simd::tag::is_gtz_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<is_gtz_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(is_gtz(-boost::simd::Zero<T>()), boost::simd::False<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Half<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Inf<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Minf<T>()), boost::simd::False<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Mone<T>()), boost::simd::False<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Nan<T>()), boost::simd::False<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::One<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Quarter<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Two<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for real_

BOOST_SIMD_TEST_CASE_TPL ( is_gtz_signed_int__1_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{
  
  using boost::simd::is_gtz;
  using boost::simd::tag::is_gtz_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<is_gtz_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Mone<T>()), boost::simd::False<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::One<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Two<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for signed_int_

BOOST_SIMD_TEST_CASE_TPL ( is_gtz_unsigned_int__1_0,  BOOST_SIMD_UNSIGNED_TYPES)
{
  
  using boost::simd::is_gtz;
  using boost::simd::tag::is_gtz_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<is_gtz_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::One<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Two<T>()), boost::simd::True<r_t>());
  BOOST_SIMD_TEST_EQUAL(is_gtz(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for unsigned_int_
