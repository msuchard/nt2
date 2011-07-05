//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_UNIT_MODULE "nt2 arithmetic toolbox - ldiv/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <boost/simd/toolbox/arithmetic/include/ldiv.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/functor/meta/call.hpp>
#include <boost/simd/sdk/unit/tests.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/include/constants/infinites.hpp>


BOOST_SIMD_TEST_CASE_TPL ( ldiv_real__2_0,  BOOST_SIMD_REAL_TYPES)
{
  
  using boost::simd::ldiv;
  using boost::simd::tag::ldiv_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<ldiv_(T,T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<boost::simd::meta::arithmetic(T,T)>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(T(2),T(1)), T(0.5), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Inf<T>(), boost::simd::Inf<T>()), boost::simd::Nan<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Minf<T>(), boost::simd::Minf<T>()), boost::simd::Nan<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::One<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Nan<T>(), boost::simd::Nan<T>()), boost::simd::Nan<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Nan<T>(), 0);
} // end of test for real_

BOOST_SIMD_TEST_CASE_TPL ( ldiv_unsigned_int__2_0,  BOOST_SIMD_UNSIGNED_TYPES)
{
  
  using boost::simd::ldiv;
  using boost::simd::tag::ldiv_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<ldiv_(T,T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<boost::simd::meta::arithmetic(T,T)>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(1,0), 0, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(2,3), 1, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(3,2), 0, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>(), 0);
} // end of test for unsigned_int_

BOOST_SIMD_TEST_CASE_TPL ( ldiv_signed_int__2_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{
  
  using boost::simd::ldiv;
  using boost::simd::tag::ldiv_;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef typename boost::simd::meta::call<ldiv_(T,T)>::type r_t;
  typedef typename boost::simd::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<boost::simd::meta::arithmetic(T,T)>::type wished_r_t;


  // return type conformity test 
  BOOST_SIMD_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(1,0), 0, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(2,3), 1, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(3,2), 0, 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::One<T>(), 0);
  BOOST_SIMD_TEST_ULP_EQUAL(ldiv(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>(), 0);
} // end of test for signed_int_
