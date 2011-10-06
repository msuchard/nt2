//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_NOT_EQUAL_TO_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_NOT_EQUAL_TO_HPP_INCLUDED

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_not_equal_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmpneq_pd(a0,a1);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_not_equal_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm_cmpneq512_ps(a0,a1);

    }
  };



  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_not_equal_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmpneq_pi(a0,a1);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_not_equal_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<ints64_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<ints64_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmpneq_pq(a0,a1);
    }
  };
} } }

#endif