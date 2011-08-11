//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 boost.simd.predicates toolbox - is_not_finite/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.predicates components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
/// 
#include <boost/simd/toolbox/predicates/include/is_not_finite.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/simd/sdk/meta/logical.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/include/constants/real.hpp>


NT2_TEST_CASE_TPL ( is_not_finite_real__1_0,  BOOST_SIMD_REAL_TYPES)
{
  
  using boost::simd::is_not_finite;
  using boost::simd::tag::is_not_finite_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<is_not_finite_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(is_not_finite(-boost::simd::Zero<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Half<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Inf<T>()), boost::simd::True<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Minf<T>()), boost::simd::True<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Mone<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Nan<T>()), boost::simd::True<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::One<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Quarter<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Two<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for real_

NT2_TEST_CASE_TPL ( is_not_finite_signed_int__1_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{
  
  using boost::simd::is_not_finite;
  using boost::simd::tag::is_not_finite_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<is_not_finite_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Mone<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::One<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Two<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( is_not_finite_unsigned_int__1_0,  BOOST_SIMD_UNSIGNED_TYPES)
{
  
  using boost::simd::is_not_finite;
  using boost::simd::tag::is_not_finite_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<is_not_finite_(T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type u_t;
  typedef typename boost::simd::meta::logical<T>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(is_not_finite(boost::simd::One<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Two<T>()), boost::simd::False<r_t>());
  NT2_TEST_EQUAL(is_not_finite(boost::simd::Zero<T>()), boost::simd::False<r_t>());
} // end of test for unsigned_int_