/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_DISPATCH_DSL_SEMANTIC_OF_HPP_INCLUDED
#define BOOST_DISPATCH_DSL_SEMANTIC_OF_HPP_INCLUDED

#include <boost/proto/traits.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_reference.hpp>

////////////////////////////////////////////////////////////////////////////////
// For a given proto expression class, retrieves its semantic info as a type
// Expression semantic info is void by design while SemanticRichExpression
// types expose a dispatch_semantic_tag that can be retrieved here.
// Such information are used into expression hierarchy.
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace dispatch { namespace meta
{
  template<class Expr, class Enable = void>
  struct semantic_of
  {
    typedef void type;
  };
  
  template<class Expr>
  struct semantic_of<const Expr, typename boost::enable_if_c< boost::proto::arity_of<Expr>::value == 0>::type>
    : add_const<typename semantic_of<Expr>::type>
  {
  };
  
  template<class Expr>
  struct semantic_of<const Expr, typename boost::disable_if_c< boost::proto::arity_of<Expr>::value == 0>::type>
    : semantic_of<Expr>
  {
  };
  
  template<class Expr>
  struct semantic_of<Expr&, typename boost::enable_if_c< boost::proto::arity_of<Expr>::value == 0>::type>
    : add_reference<typename semantic_of<Expr>::type>
  {
  };
  
  template<class Expr>
  struct semantic_of<Expr&, typename boost::disable_if_c< boost::proto::arity_of<Expr>::value == 0>::type>
    : semantic_of<Expr>
  {
  };
  
} } }

#endif
