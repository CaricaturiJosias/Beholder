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
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:631

#ifndef _TAO_IDL____BEHOLDERS_JXVW0J_CPP_
#define _TAO_IDL____BEHOLDERS_JXVW0J_CPP_


#include "BeholderS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"
#include "cstring"
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:1853

class TAO_DSMComms_POA_Beholder_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len) override;

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len) override;
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: ace_gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_DSMComms_POA_Beholder_Perfect_Hash_OpTable -N lookup */

unsigned int
TAO_DSMComms_POA_Beholder_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static constexpr unsigned char asso_values[] =
    {
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19, 19,  0, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
     19, 19, 19, 19, 19,  0, 19,  0, 19, 19,
      0,  0, 19,  0, 19, 19, 19, 19,  0, 19,
     19, 19, 19, 19, 19,  2,  5, 19, 19, 19,
     19, 19, 19, 19, 19, 19, 19, 19,
    };
  return len + asso_values[static_cast<int>(str[len - 1])] + asso_values[static_cast<int>(str[0])];
}

const TAO_operation_db_entry *
TAO_DSMComms_POA_Beholder_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 8,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 14,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 18,
      HASH_VALUE_RANGE = 14,
      DUPLICATES = 0,
      WORDLIST_SIZE = 13
    };

  static const TAO_operation_db_entry wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_is_a", std::addressof(TAO_ServantBase::_is_a_thru_poa_skel), nullptr},
      {"",0,0},{"",0,0},
      {"getValue", std::addressof(POA_DSMComms::POA_Beholder::getValue_skel), nullptr},
      {"",0,0},
      {"_interface", std::addressof(TAO_ServantBase::_interface_skel), nullptr},
      {"LogEventAll", std::addressof(POA_DSMComms::POA_Beholder::LogEventAll_skel), nullptr},
      {"storeValue", std::addressof(POA_DSMComms::POA_Beholder::storeValue_skel), nullptr},
      {"",0,0},
      {"_repository_id", std::addressof(TAO_ServantBase::_repository_id_thru_poa_skel), nullptr},
      {"_component", std::addressof(TAO_ServantBase::_component_thru_poa_skel), nullptr},
      {"",0,0},{"",0,0},
      {"_non_existent", std::addressof(TAO_ServantBase::_non_existent_thru_poa_skel), nullptr},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int const key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname;

          if (*str == *s && !ACE_OS::strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_DSMComms_POA_Beholder_Perfect_Hash_OpTable tao_DSMComms_POA_Beholder_optable;


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:89



POA_DSMComms::POA_Beholder::POA_Beholder ()
  : TAO_ServantBase ()
{
  this->optable_ = std::addressof(tao_DSMComms_POA_Beholder_optable);
}

POA_DSMComms::POA_Beholder::POA_Beholder (const POA_Beholder& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs)
{
}


namespace POA_DSMComms
{
  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class LogEventAll_POA_Beholder
    : public TAO::Upcall_Command
  {
  public:
    inline LogEventAll_POA_Beholder (
      POA_DSMComms::POA_Beholder * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< std::string>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< std::string> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< ::DSMComms::EventEnum>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg< ::DSMComms::EventEnum> (
          this->operation_details_,
          this->args_,
          2);
        
      this->servant_->LogEventAll (
        arg_1
        , arg_2);
    }
  
  private:
    POA_DSMComms::POA_Beholder * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_DSMComms::POA_Beholder::LogEventAll_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< std::string>::in_arg_val _tao_valor;
  TAO::SArg_Traits< ::DSMComms::EventEnum>::in_arg_val _tao_event;

  TAO::Argument * const args[] =
    {
      std::addressof(retval),
      std::addressof(_tao_valor),
      std::addressof(_tao_event)
    };
  
  POA_DSMComms::POA_Beholder * const impl =
    dynamic_cast<POA_DSMComms::POA_Beholder *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  LogEventAll_POA_Beholder command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 3
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , nullptr
                         , 0
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_DSMComms
{
  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class getValue_POA_Beholder
    : public TAO::Upcall_Command
  {
  public:
    inline getValue_POA_Beholder (
      POA_DSMComms::POA_Beholder * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< std::string>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< std::string> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< ::DSMComms::ValueSequence>::inout_arg_type arg_2 =
        TAO::Portable_Server::get_inout_arg< ::DSMComms::ValueSequence> (
          this->operation_details_,
          this->args_,
          2);
        
      this->servant_->getValue (
        arg_1
        , arg_2);
    }
  
  private:
    POA_DSMComms::POA_Beholder * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_DSMComms::POA_Beholder::getValue_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< std::string>::in_arg_val _tao_valueId;
  TAO::SArg_Traits< ::DSMComms::ValueSequence>::inout_arg_val _tao_toGetValues;

  TAO::Argument * const args[] =
    {
      std::addressof(retval),
      std::addressof(_tao_valueId),
      std::addressof(_tao_toGetValues)
    };
  
  POA_DSMComms::POA_Beholder * const impl =
    dynamic_cast<POA_DSMComms::POA_Beholder *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  getValue_POA_Beholder command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 3
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , nullptr
                         , 0
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_DSMComms
{
  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class storeValue_POA_Beholder
    : public TAO::Upcall_Command
  {
  public:
    inline storeValue_POA_Beholder (
      POA_DSMComms::POA_Beholder * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< ::DSMComms::idSequence>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::DSMComms::idSequence> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< ::DSMComms::ValueSequence>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg< ::DSMComms::ValueSequence> (
          this->operation_details_,
          this->args_,
          2);
        
      this->servant_->storeValue (
        arg_1
        , arg_2);
    }
  
  private:
    POA_DSMComms::POA_Beholder * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_DSMComms::POA_Beholder::storeValue_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< ::DSMComms::idSequence>::in_arg_val _tao_valueId;
  TAO::SArg_Traits< ::DSMComms::ValueSequence>::in_arg_val _tao_toSetValue;

  TAO::Argument * const args[] =
    {
      std::addressof(retval),
      std::addressof(_tao_valueId),
      std::addressof(_tao_toSetValue)
    };
  
  POA_DSMComms::POA_Beholder * const impl =
    dynamic_cast<POA_DSMComms::POA_Beholder *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  storeValue_POA_Beholder command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 3
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , nullptr
                         , 0
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}




// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:155





::CORBA::Boolean POA_DSMComms::POA_Beholder::_is_a (const char* value)
{
  return
    (
      std::strcmp (value, "IDL:DSMComms/POA_Beholder:1.0") == 0 ||
      std::strcmp (value, "IDL:omg.org/CORBA/Object:1.0") == 0
    );
}

const char* POA_DSMComms::POA_Beholder::_interface_repository_id () const
{
  return "IDL:DSMComms/POA_Beholder:1.0";
}


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:403



void POA_DSMComms::POA_Beholder::_dispatch (
  TAO_ServerRequest & req,
  TAO::Portable_Server::Servant_Upcall* servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:354



DSMComms::POA_Beholder *
POA_DSMComms::POA_Beholder::_this ()
{
  TAO_Stub *stub = this->_create_stub ();

  TAO_Stub_Auto_Ptr safe_stub (stub);
  ::CORBA::Object_ptr tmp {};

  ::CORBA::Boolean const _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  
  ACE_NEW_RETURN (
      tmp,
      ::CORBA::Object (stub, _tao_opt_colloc, this),
      nullptr);
  
  ::CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();

  return TAO::Narrow_Utils< ::DSMComms::POA_Beholder>::unchecked_narrow (obj.in ());
}

#endif /* ifndef */

