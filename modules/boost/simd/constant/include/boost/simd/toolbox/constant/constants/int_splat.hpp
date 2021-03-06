//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_INT_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_INT_SPLAT_HPP_INCLUDED

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/meta/int_c.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup boost_simd_constant_int_splat Int_splat
 *
 * \par Description
 * TODO Put description here
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/int_splat.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::int_splat_(A0)>::type
 *     Int_splat();
 * }
 * \endcode
 *
 * 
 * \param T template parameter of Int_splat
 * 
 * \return type T value
 *  
 *  
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag Int_splat of functor Int_splat 
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    template<boost::simd::int64_t I>
    struct Intpattern 
    { 
      template<class Target, class Dummy=void> 
      struct apply : meta::int_c<Target, Target(I)> {};  
    };
  }

  template<class Target, boost::simd::int64_t N> 
  inline Target integral_constant()
  {
    typename dispatch::make_functor< tag::Intpattern<N>, Target >::type callee;
    return callee( dispatch::meta::as_<Target>() );
  }
} }

#endif
