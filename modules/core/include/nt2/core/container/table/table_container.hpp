//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_TABLE_CONTAINER_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_TABLE_CONTAINER_HPP_INCLUDED

#include <nt2/core/settings/size.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/shape.hpp>
#include <nt2/core/settings/option.hpp>
#include <nt2/core/container/category.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/hierarchy_of.hpp>
#include <nt2/core/container/meta/make_block.hpp>
#include <nt2/core/container/meta/is_container.hpp>

namespace nt2 { namespace container
{
  //============================================================================
  /*!
   * table_container is the base class handling a table semantic, layout and
   * memory used by the table proto terminal class. It is built from a value
   * \c Type and a list of \c Settings describing how it should behave both at
   * runtime and compile-time.
   * 
   * Note that contrary to user defined table terminals, table_container only
   * require a few layout related options to be able to build a proper terminal
   * expression. Other layout like static ID are used by table_container to
   * select a proper block implementation but don't make sense when used in
   * larger expressions.
   *
   * \tparam Type Value type to store in the table
   * \tparam Setting Compound options list describing the behavior of the table
   **/
  //============================================================================
  template<class T, class S> struct table_container
  {
    typedef settings default_(_4D, matlab_index_, dense_);

    typedef typename meta::option<S, tag::of_size_, default_>::type extent_type;
    typedef typename meta::option<S, tag::index_  , default_>::type index_type;
    typedef typename meta::option<S, tag::shape_  , default_>::type shape_type;

    typedef nt2::settings settings_type(index_type,extent_type,shape_type);

    typedef typename make_block<T, settings_type>::type block_type;
    
    block_type block;
    extent_type size_;

    void resize( extent_type const& sz ) 
    { 
      size_ = sz;
      block.resize(size_); 
    }

    extent_type const& extent() const { return size_; }
  };
}

namespace meta
{
  //============================================================================
  // Register table_container as a proper container
  //============================================================================
  template<class T, class S>
  struct is_container< container::table_container<T, S> > : boost::mpl::true_
  {};
} }

namespace boost { namespace dispatch { namespace meta
{
  //============================================================================
  // Register table_container as a proper Hierarchizable
  //============================================================================
  template<class T, class S>
  struct value_of< nt2::container::table_container<T, S> >
  {
    typedef T type;
  };

  template<class T, class S, class Origin>
  struct hierarchy_of< nt2::container::table_container<T, S>, Origin >
  {
    typedef table_< typename property_of< typename value_of<T>::type
                                        , Origin
                                        >::type
                  , S
                  >                                   type;
  };

  //============================================================================
  // table_container produce container expression from proper type and settings.
  //============================================================================
  template<class T, class S>
  struct terminal_of< nt2::container::table_container<T, S> >
  {
    // Retrieve normalized settings
    typedef typename nt2::container::
            table_container<T, S>::settings_type                  settings_type;

    typedef nt2::container::table_container<T, settings_type>         container;

    typedef nt2::container::
            expression< typename boost::proto::terminal< container >::type
                      , container&
                      >                                                    type;
  };

  //============================================================================
  // table use table_container to do its biddings
  //============================================================================
  template<class T, class S> struct semantic_of< nt2::container::table<T, S> >
  {
    typedef nt2::container::table_container<T, S>& type;
  };
} } }

#endif
