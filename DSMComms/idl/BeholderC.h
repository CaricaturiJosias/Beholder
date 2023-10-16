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
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:148

#ifndef _TAO_IDL____BEHOLDERC_NXQGDI_H_
#define _TAO_IDL____BEHOLDERC_NXQGDI_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include <string>
#include <vector>

#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include "tao/Vector_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 3 || TAO_MINOR_VERSION != 1 || TAO_MICRO_VERSION != 0
#error This file should be regenerated with TAO_IDL
#endif
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_root/root_ch.cpp:155


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:34

namespace DSMComms
{
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/enum_ch.cpp:39

  enum EventEnum
  {
    TEST,
    NONE,
    HAHA
  };

  typedef EventEnum &EventEnum_out;
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

  extern  ::CORBA::TypeCode_ptr const _tc_EventEnum;
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/enum_ch.cpp:39

  enum DataType
  {
    UNKNOWN,
    ANALOG,
    DIGITAL
  };

  typedef DataType &DataType_out;
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

  extern  ::CORBA::TypeCode_ptr const _tc_DataType;
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:257

  

  struct Value;
  using Value_var = ::TAO_Var_Var_T<Value>;
  using Value_out = ::TAO_Out_T<Value>;

  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/structure_ch.cpp:47

  

  struct  Value
  {
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:296

    
    using _var_type = Value_var;
    using _out_type = Value_out;

    static void _tao_any_destructor (void *);
    
    ::TAO::String_Manager id;
    ::CORBA::Double storedValue;
    ::TAO::String_Manager timestamp;
    DSMComms::DataType type;
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

  extern  ::CORBA::TypeCode_ptr const _tc_Value;

  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_sequence/sequence_ch.cpp:98

  

#if !defined (_DSMCOMMS_VALUESEQUENCE_CH_)
#define _DSMCOMMS_VALUESEQUENCE_CH_

  typedef std::vector< Value> ValueSequence;

#endif /* end #if !defined */
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

  extern  ::CORBA::TypeCode_ptr const _tc_ValueSequence;
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:742

  

#if !defined (_DSMCOMMS_POA_BEHOLDER__VAR_OUT_CH_)
#define _DSMCOMMS_POA_BEHOLDER__VAR_OUT_CH_

  class POA_Beholder;
  using POA_Beholder_ptr = POA_Beholder*;
  using POA_Beholder_var = TAO_Objref_Var_T<POA_Beholder>;
  using POA_Beholder_out = TAO_Objref_Out_T<POA_Beholder>;

#endif /* end #if !defined */

  
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39

  

  class  POA_Beholder
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<POA_Beholder>;
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:296

    using _ptr_type = POA_Beholder_ptr;
    using _var_type = POA_Beholder_var;
    using _out_type = POA_Beholder_out;

    static void _tao_any_destructor (void *);

    // The static operations.
    static POA_Beholder_ptr _duplicate (POA_Beholder_ptr obj);

    static void _tao_release (POA_Beholder_ptr obj);

    static POA_Beholder_ptr _narrow (::CORBA::Object_ptr obj);
    static POA_Beholder_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static POA_Beholder_ptr _nil ();

    virtual void LogEventAll (
      const std::string valor,
      ::DSMComms::EventEnum event);

    virtual void getValue (
      ::DSMComms::Value & toGetValue);

    virtual void storeValue (
      const ::DSMComms::Value & toSetValue);

    
    // TAO_IDL - Generated from
    // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

    

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id () const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Concrete interface only.
    POA_Beholder ();

    // Concrete non-local interface only.
    POA_Beholder (::IOP::IOR *ior, TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    POA_Beholder (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = nullptr,
        TAO_ORB_Core *orb_core = nullptr);

    virtual ~POA_Beholder () = default;
  
  private:
    // Private and unimplemented for concrete interfaces.
    POA_Beholder (const POA_Beholder &) = delete;
    POA_Beholder (POA_Beholder &&) = delete;
    POA_Beholder &operator= (const POA_Beholder &) = delete;
    POA_Beholder &operator= (POA_Beholder &&) = delete;
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/typecode_decl.cpp:33

  extern  ::CORBA::TypeCode_ptr const _tc_POA_Beholder;


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:62


} // module DSMComms
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:889

  

  template<>
  class Arg_Traits< ::DSMComms::EventEnum>
    : public
        Basic_Arg_Traits_T<
            ::DSMComms::EventEnum,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:889

  

  template<>
  class Arg_Traits< ::DSMComms::DataType>
    : public
        Basic_Arg_Traits_T<
            ::DSMComms::DataType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:931

  

  template<>
  class Arg_Traits< ::DSMComms::Value>
    : public
        Var_Size_Arg_Traits_T<
            ::DSMComms::Value,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:671

  

  template<>
  class Arg_Traits< ::DSMComms::ValueSequence>
    : public
        Vector_Arg_Traits_T<
            ::DSMComms::ValueSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
  // TAO_IDL - Generated from
  // /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:142

  

#if !defined (_DSMCOMMS_POA_BEHOLDER__ARG_TRAITS_)
#define _DSMCOMMS_POA_BEHOLDER__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::DSMComms::POA_Beholder>
    : public Object_Arg_Traits_T<
        ::DSMComms::POA_Beholder_ptr,
        ::DSMComms::POA_Beholder_var,
        ::DSMComms::POA_Beholder_out,
        TAO::Objref_Traits<DSMComms::POA_Beholder>,
        TAO::Any_Insert_Policy_Stream>
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_traits.cpp:58



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_DSMCOMMS_POA_BEHOLDER__TRAITS_)
#define _DSMCOMMS_POA_BEHOLDER__TRAITS_

  template<>
  struct  Objref_Traits< ::DSMComms::POA_Beholder>
  {
    static ::DSMComms::POA_Beholder_ptr duplicate (::DSMComms::POA_Beholder_ptr p);
    static void release (::DSMComms::POA_Beholder_ptr p);
    static ::DSMComms::POA_Beholder_ptr nil ();
    static ::CORBA::Boolean marshal (const ::DSMComms::POA_Beholder_ptr p,TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/any_op_ch.cpp:31


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {



 void operator<<= (::CORBA::Any &, DSMComms::EventEnum);
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DSMComms::EventEnum &);
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/any_op_ch.cpp:31


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {



 void operator<<= (::CORBA::Any &, DSMComms::DataType);
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DSMComms::DataType &);
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/any_op_ch.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

 void operator<<= (::CORBA::Any &, const ::DSMComms::Value &); // copying version
 void operator<<= (::CORBA::Any &, ::DSMComms::Value*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::DSMComms::Value *&);
}
TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_sequence/any_op_ch.cpp:46




TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

 void operator<<= (::CORBA::Any &, const ::std::vector< ::DSMComms::Value> &); // copying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::std::vector< ::DSMComms::Value> *&);
}
TAO_END_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/any_op_ch.cpp:40




TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

 void operator<<= (::CORBA::Any &, DSMComms::POA_Beholder_ptr); // copying
 void operator<<= (::CORBA::Any &, DSMComms::POA_Beholder_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, DSMComms::POA_Beholder_ptr &);
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_ch.cpp:33


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, DSMComms::EventEnum _tao_enumerator);
 ::CORBA::Boolean operator>> (TAO_InputCDR &strm, DSMComms::EventEnum &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_ch.cpp:33


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, DSMComms::DataType _tao_enumerator);
 ::CORBA::Boolean operator>> (TAO_InputCDR &strm, DSMComms::DataType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/cdr_op_ch.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DSMComms::Value &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, DSMComms::Value &);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_sequence/cdr_op_ch.cpp:64



#if !defined _TAO_CDR_OP_DSMComms_ValueSequence_H_
#define _TAO_CDR_OP_DSMComms_ValueSequence_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const std::vector<DSMComms::Value> &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    std::vector<DSMComms::Value> &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_DSMComms_ValueSequence_H_ */


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/cdr_op_ch.cpp:40



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DSMComms::POA_Beholder_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, DSMComms::POA_Beholder_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1648

#if defined (__ACE_INLINE__)
#include "BeholderC.inl"
#endif /* defined INLINE */

#endif /* ifndef */
