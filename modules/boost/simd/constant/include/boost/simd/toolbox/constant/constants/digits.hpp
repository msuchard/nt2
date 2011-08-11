//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DIGITS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DIGITS_HPP_INCLUDED

/*!
 * \file
 * \brief Defines natural number constants
 */

#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/constant/common.hpp>
#include <boost/simd/sdk/constant/constant.hpp>
#include <boost/simd/toolbox/constant/include.hpp>
#include <boost/simd/include/functions/splat.hpp>

namespace boost { namespace simd { namespace tag
{
  //============================================================================
  /*!
   * This tag represents the constant \c N
   * \tparam N Value to generate
   */
  //============================================================================
  template<boost::simd::int64_t N> struct Digit{};
} } }

#define BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(VAL,NAME)		\
namespace boost { namespace simd							\
{								\
  template<class Target> inline				        \
  typename dispatch::meta::call<tag::Digit<VAL>(dispatch::meta::as_<Target>)>::type \
  NAME()							\
  {								\
    typename dispatch::make_functor<tag::Digit<VAL>, Target>::type callee; \
    return callee( dispatch::meta::as_<Target>() );			\
  }								\
} }								\
/**/

  //============================================================================
  // Constant functions from -10 to 10 and 20
  //============================================================================
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-10, Mten  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-9 , Mnine )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-8 , Meight)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-7 , Mseven)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-6 , Msix  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-5 , Mfive )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-4 , Mfour )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-3 , Mthree)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-2 , Mtwo  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(-1 , Mone  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 0 , Zero  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 1 , One   )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 2 , Two   )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 3 , Three )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 4 , Four  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 5 , Five  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 6 , Six   )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 7 , Seven )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 8 , Eight )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 9 , Nine  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 10, Ten   )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 11, Eleven)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 12, Twelve)  
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 20, Twenty)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 24, Twentyfour)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 120, _120)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 720, _720)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(5040, _5040)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(40320, _40320)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(362880, _362880)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(3628800, _3628800)
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(39916800, _39916800)


  //============================================================================
  // Hundred and Thousand
  //============================================================================
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 100 , Hundred  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(1000 , Thousand )

  //============================================================================
  // Values useful for trigonometric and angle related computations
  //============================================================================
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 45, Fortyfive         )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 90, Ninety            )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(180, Onehundredeighty  )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(180, C_180             )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 45, _45               )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION( 90, _90               )
  BOOST_SIMD_CONSTANT_DIGITS_IMPLEMENTATION(180, _180              )

  //============================================================================
  // Custom integral constant genertor function
  //============================================================================
namespace boost { namespace simd {
  template<class Target, boost::simd::int64_t N> inline
  typename dispatch::meta::call<tag::Digit<N >(dispatch::meta::as_<Target>)>::type
  integral_constant()
  {
    typename dispatch::make_functor< tag::Digit<N>, Target >::type callee;
    return callee( dispatch::meta::as_<Target>() );
  }
} }

//==============================================================================
// Register dispatch over digits<N>
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_TPL( boost::simd::tag::Digit<N> , tag::cpu_
                                , (boost::simd::int64_t N)(class A0)
                                , (target_< scalar_< fundamental_<A0> > >)
                                )
  {
    typedef typename A0::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return  splat<result_type>(N);
    }
  };
} } }

//#include <boost/simd/toolbox/constant/constants/scalar/digits.hpp>
#include <boost/simd/toolbox/constant/constants/simd/all/digits.hpp>

#endif