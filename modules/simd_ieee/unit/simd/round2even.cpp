//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_UNIT_MODULE "nt2 ieee toolbox - round2even/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <boost/simd/toolbox/ieee/include/round2even.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/simd/sdk/functor/meta/call.hpp>
#include <boost/simd/sdk/unit/tests.hpp>
#include <boost/simd/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/include/constants/real.hpp>
#include <boost/simd/include/constants/infinites.hpp>
#include <boost/simd/sdk/memory/is_aligned.hpp>
#include <boost/simd/sdk/memory/aligned_type.hpp>
#include <boost/simd/include/functions/load.hpp>


BOOST_SIMD_TEST_CASE_TPL ( round2even_real__1_0,  BOOST_SIMD_REAL_TYPES)
{
  using boost::simd::round2even;
  using boost::simd::tag::round2even_;
  using boost::simd::load; 
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::simd::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::simd::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::simd::meta::call<round2even_(vT)>::type r_t;
  typedef typename boost::simd::meta::call<round2even_(T)>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::splat<vT>(1.4))[0], 1);
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::splat<vT>(1.5))[0], 2);
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::splat<vT>(1.6))[0], 2);
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::splat<vT>(2.5))[0], 2);
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Half<vT>())[0], boost::simd::Zero<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Inf<vT>())[0], boost::simd::Inf<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Mhalf<vT>())[0], boost::simd::Zero<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Minf<vT>())[0], boost::simd::Minf<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Mone<vT>())[0], boost::simd::Mone<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Nan<vT>())[0], boost::simd::Nan<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::One<vT>())[0], boost::simd::One<sr_t>());
  BOOST_SIMD_TEST_EQUAL(round2even(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
} // end of test for real_
