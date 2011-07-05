//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_UNIT_MODULE "nt2 bitwise toolbox - firstbitset/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of bitwise components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
/// 
#include <boost/simd/toolbox/bitwise/include/firstbitset.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/functor/meta/call.hpp>
#include <boost/simd/sdk/unit/tests.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/include/constants/infinites.hpp>


BOOST_SIMD_TEST_CASE_TPL ( firstbitset_float_1_0,  (float))
{
  
  using boost::simd::firstbitset;
  using boost::simd::tag::firstbitset_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<firstbitset_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::as_integer<T, unsigned>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Inf<T>()), 8388608u);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Minf<T>()), 8388608u);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Nan<T>()), boost::simd::One<r_t>());
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Signmask<T>()), boost::simd::One<r_t>()+boost::simd::Valmax<r_t>()/2);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for float

BOOST_SIMD_TEST_CASE_TPL ( firstbitset_double_1_0,  (double))
{
  
  using boost::simd::firstbitset;
  using boost::simd::tag::firstbitset_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<firstbitset_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::as_integer<T, unsigned>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Inf<T>()), 4503599627370496ull);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Minf<T>()), 4503599627370496ull);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Nan<T>()), boost::simd::One<r_t>());
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Signmask<T>()), boost::simd::One<r_t>()+boost::simd::Valmax<r_t>()/2);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for double

BOOST_SIMD_TEST_CASE_TPL ( firstbitset_signed_int__1_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{
  
  using boost::simd::firstbitset;
  using boost::simd::tag::firstbitset_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<firstbitset_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::as_integer<T, unsigned>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::One<T>()), boost::simd::One<r_t>());
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Signmask<T>()), boost::simd::One<r_t>()+boost::simd::Valmax<r_t>()/2);
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for signed_int_

BOOST_SIMD_TEST_CASE_TPL ( firstbitset_unsigned_int__1_0,  BOOST_SIMD_UNSIGNED_TYPES)
{
  
  using boost::simd::firstbitset;
  using boost::simd::tag::firstbitset_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<firstbitset_(T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::as_integer<T, unsigned>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::One<T>()), boost::simd::One<r_t>());
  BOOST_SIMD_TEST_EQUAL(firstbitset(boost::simd::Zero<T>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_
