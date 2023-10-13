// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v3.1.0
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:454

#ifndef _TAO_IDL____BEHOLDERS_HCBNC6_H_
#define _TAO_IDL____BEHOLDERS_HCBNC6_H_


#include "BeholderC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Vector_SArgument_T.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:889

  

  template<>
  class SArg_Traits< ::DSMComms::EventEnum>
    : public
        Basic_SArg_Traits_T<
            ::DSMComms::EventEnum,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:889

  

  template<>
  class SArg_Traits< ::DSMComms::DataType>
    : public
        Basic_SArg_Traits_T<
            ::DSMComms::DataType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:931

  

  template<>
  class SArg_Traits< ::DSMComms::Value>
    : public
        Fixed_Size_SArg_Traits_T<
            ::DSMComms::Value,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:671

  

  template<>
  class SArg_Traits< ::DSMComms::ValSeq>
    : public
        Vector_SArg_Traits_T<
            ::DSMComms::ValSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:671

  

  template<>
  class SArg_Traits< ::DSMComms::StringSeq>
    : public
        Vector_SArg_Traits_T<
            ::DSMComms::StringSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:142

  

#if !defined (_DSMCOMMS_POA_BEHOLDER__SARG_TRAITS_)
#define _DSMCOMMS_POA_BEHOLDER__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::DSMComms::POA_Beholder>
    : public Object_SArg_Traits_T<
        ::DSMComms::POA_Beholder_ptr,
        ::DSMComms::POA_Beholder_var,
        ::DSMComms::POA_Beholder_out,
        TAO::Any_Insert_Policy_Stream>
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_sh.cpp:34

namespace POA_DSMComms
{
  

  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_sh.cpp:72

  

  class POA_Beholder;
  typedef POA_Beholder *POA_Beholder_ptr;

  class  POA_Beholder
    : public virtual PortableServer::ServantBase
  {
  protected:
    POA_Beholder ();
  
  public:
    /// Useful for template programming.
    typedef ::DSMComms::POA_Beholder _stub_type;
    typedef ::DSMComms::POA_Beholder_ptr _stub_ptr_type;
    typedef ::DSMComms::POA_Beholder_var _stub_var_type;

    POA_Beholder (const POA_Beholder& rhs);
    virtual ~POA_Beholder () = default;

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    virtual void _dispatch (
        TAO_ServerRequest & req,
        TAO::Portable_Server::Servant_Upcall *servant_upcall);
    
    ::DSMComms::POA_Beholder *_this ();
    
    virtual const char* _interface_repository_id () const;
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_sh.cpp:35

    virtual void LogEventAll (
      const std::string valor,
      ::DSMComms::EventEnum event) = 0;

    static void LogEventAll_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_sh.cpp:35

    virtual void getValue (
      const std::string valueId,
      ::DSMComms::Value_out toGetValue,
      ::DSMComms::DataType type) = 0;

    static void getValue_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_sh.cpp:35

    virtual void storeValue (
      const std::string valueId,
      const ::DSMComms::Value & toGetValue,
      ::DSMComms::DataType type) = 0;

    static void storeValue_skel (
        TAO_ServerRequest &server_request,
        TAO::Portable_Server::Servant_Upcall *servant_upcall,
        TAO_ServantBase *servant);
  };


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_sh.cpp:65

} // module DSMComms

#endif /* ifndef */

