//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_AVX_MAKE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_AVX_MAKE_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_AVX_SUPPORT

#include <boost/simd/toolbox/operator/functions/make.hpp>
#include <boost/simd/toolbox/operator/functions/simd/details/make_helper.hpp>

//==============================================================================
// make for double
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< double_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(4)
    {
      result_type that = { _mm256_setr_pd(a0, a1, a2, a3) };
      return that;
    }
  };
} } }

//==============================================================================
// make for 64bits integers
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< ints64_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(4)
    {
      result_type that = { _mm256_setr_epi64x(a0, a1, a2, a3) };
      return that;
    }
  };
} } }

//==============================================================================
// make for float
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< float_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(8)
    {
      result_type that = { _mm256_setr_ps(a0, a1, a2, a3, a4, a5, a6, a7) };
      return that;
    }
  };
} } }

//==============================================================================
// make for 32 bits integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< ints32_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(8)
    {
      result_type that = { _mm256_setr_epi32(a0, a1, a2, a3, a4, a5, a6, a7) };
      return that;
    }
  };
} } }

//==============================================================================
// make for 16 bits integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< ints16_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(16)
    {
      result_type that = { _mm256_setr_epi16( a0, a1,  a2,  a3,  a4,  a5,  a6,  a7
                                            , a8, a9, a10, a11, a12, a13, a14, a15 )
                         };
      return that;
    }
  };
} } }

//==============================================================================
// make for 8 bits integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::avx_, (A0)
                            , ((target_< simd_< ints8_<A0>, boost::simd::tag::avx_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(32)
    {
      result_type that = { _mm256_setr_epi8(  a0,  a1,  a2,  a3,  a4,  a5,  a6,  a7
                                           ,  a8,  a9, a10, a11, a12, a13, a14, a15
                                           , a16, a17, a18, a19, a20, a21, a22, a23
                                           , a24, a25, a26, a27, a28, a29, a30, a31 )
                         };
      return that;
    }
  };
} } }

#endif
#endif