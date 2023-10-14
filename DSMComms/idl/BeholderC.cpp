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
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:372


#include "BeholderC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Enum_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "tao/AnyTypeCode/Any_Basic_Impl_T.h"
#include "cstring"

#if !defined (__ACE_INLINE__)
#include "BeholderC.inl"
#endif /* !defined INLINE */
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/enum_typecode.cpp:27

static char const * const _tao_enumerators_DSMComms_EventEnum[] =
  {
    "TEST",
    "NONE",
    "HAHA"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_DSMComms_EventEnum (
    "IDL:DSMComms/EventEnum:1.0",
    "EventEnum",
    _tao_enumerators_DSMComms_EventEnum,
    3);
  

namespace DSMComms
{
  ::CORBA::TypeCode_ptr const _tc_EventEnum =
    &_tao_tc_DSMComms_EventEnum;
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/enum_typecode.cpp:27

static char const * const _tao_enumerators_DSMComms_DataType[] =
  {
    "UNKNOWN",
    "ANALOG",
    "DIGITAL"
    
  };

static TAO::TypeCode::Enum<char const *,
                           char const * const *,
                           TAO::Null_RefCount_Policy>
  _tao_tc_DSMComms_DataType (
    "IDL:DSMComms/DataType:1.0",
    "DataType",
    _tao_enumerators_DSMComms_DataType,
    3);
  

namespace DSMComms
{
  ::CORBA::TypeCode_ptr const _tc_DataType =
    &_tao_tc_DSMComms_DataType;
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/struct_typecode.cpp:84

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const 
    _tao_fields_DSMComms_Value[] =
      {
        { "storedValue", &CORBA::_tc_double },
        { "timestamp", &CORBA::_tc_long }
      };
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_DSMComms_Value (
  ::CORBA::tk_struct,
  "IDL:DSMComms/Value:1.0",
  "Value",
  _tao_fields_DSMComms_Value,
  2);


namespace DSMComms
{
  ::CORBA::TypeCode_ptr const _tc_Value =
    &_tao_tc_DSMComms_Value;
}


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/structure_cs.cpp:55

void
DSMComms::Value::_tao_any_destructor (
    void *_tao_void_pointer)
{
  Value *_tao_tmp_pointer =
    static_cast<Value *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_cs.cpp:47


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations for DSMComms::POA_Beholder.

DSMComms::POA_Beholder_ptr
TAO::Objref_Traits<DSMComms::POA_Beholder>::duplicate (DSMComms::POA_Beholder_ptr p)
{
  return DSMComms::POA_Beholder::_duplicate (p);
}

void
TAO::Objref_Traits<DSMComms::POA_Beholder>::release (DSMComms::POA_Beholder_ptr p)
{
  ::CORBA::release (p);
}

DSMComms::POA_Beholder_ptr
TAO::Objref_Traits<DSMComms::POA_Beholder>::nil ()
{
  return DSMComms::POA_Beholder::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<DSMComms::POA_Beholder>::marshal (const DSMComms::POA_Beholder_ptr p,TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_cs.cpp:87

void
DSMComms::POA_Beholder::LogEventAll (
  const std::string valor,
  ::DSMComms::EventEnum event)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< std::string>::in_arg_val _tao_valor (valor);
  TAO::Arg_Traits< ::DSMComms::EventEnum>::in_arg_val _tao_event (event);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      std::addressof(_tao_retval),
      std::addressof(_tao_valor),
      std::addressof(_tao_event)
    };

  TAO::Invocation_Adapter _invocation_call (
      this,
      _the_tao_operation_signature,
      3,
      "LogEventAll",
      11,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _invocation_call.invoke (nullptr, 0);
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_cs.cpp:87

void
DSMComms::POA_Beholder::getValue (
  const std::string valueId,
  ::DSMComms::Value_out toGetValue)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< std::string>::in_arg_val _tao_valueId (valueId);
  TAO::Arg_Traits< ::DSMComms::Value>::out_arg_val _tao_toGetValue (toGetValue);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      std::addressof(_tao_retval),
      std::addressof(_tao_valueId),
      std::addressof(_tao_toGetValue)
    };

  TAO::Invocation_Adapter _invocation_call (
      this,
      _the_tao_operation_signature,
      3,
      "getValue",
      8,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _invocation_call.invoke (nullptr, 0);
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_operation/operation_cs.cpp:87

void
DSMComms::POA_Beholder::storeValue (
  const std::string valueId,
  const ::DSMComms::Value & toSetValue,
  ::DSMComms::DataType type)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< std::string>::in_arg_val _tao_valueId (valueId);
  TAO::Arg_Traits< ::DSMComms::Value>::in_arg_val _tao_toSetValue (toSetValue);
  TAO::Arg_Traits< ::DSMComms::DataType>::in_arg_val _tao_type (type);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      std::addressof(_tao_retval),
      std::addressof(_tao_valueId),
      std::addressof(_tao_toSetValue),
      std::addressof(_tao_type)
    };

  TAO::Invocation_Adapter _invocation_call (
      this,
      _the_tao_operation_signature,
      4,
      "storeValue",
      10,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _invocation_call.invoke (nullptr, 0);
}

DSMComms::POA_Beholder::POA_Beholder ()
{
}
void
DSMComms::POA_Beholder::_tao_any_destructor (void *_tao_void_pointer)
{
  POA_Beholder *_tao_tmp_pointer =
    static_cast<POA_Beholder *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

DSMComms::POA_Beholder_ptr
DSMComms::POA_Beholder::_narrow (::CORBA::Object_ptr _tao_objref)
{
  return TAO::Narrow_Utils<POA_Beholder>::narrow (_tao_objref, "IDL:DSMComms/POA_Beholder:1.0");
}

DSMComms::POA_Beholder_ptr
DSMComms::POA_Beholder::_unchecked_narrow (::CORBA::Object_ptr _tao_objref)
{
  return TAO::Narrow_Utils<POA_Beholder>::unchecked_narrow (_tao_objref);
}

DSMComms::POA_Beholder_ptr
DSMComms::POA_Beholder::_nil ()
{
  return nullptr;
}

DSMComms::POA_Beholder_ptr
DSMComms::POA_Beholder::_duplicate (POA_Beholder_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
DSMComms::POA_Beholder::_tao_release (POA_Beholder_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
DSMComms::POA_Beholder::_is_a (const char *value)
{
  if (
      std::strcmp (value, "IDL:DSMComms/POA_Beholder:1.0") == 0 ||
      std::strcmp (value, "IDL:omg.org/CORBA/Object:1.0") == 0
      )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* DSMComms::POA_Beholder::_interface_repository_id () const
{
  return "IDL:DSMComms/POA_Beholder:1.0";
}

::CORBA::Boolean
DSMComms::POA_Beholder::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_typecode/objref_typecode.cpp:68

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_DSMComms_POA_Beholder (
    ::CORBA::tk_objref,
    "IDL:DSMComms/POA_Beholder:1.0",
    "POA_Beholder");
  

namespace DSMComms
{
  ::CORBA::TypeCode_ptr const _tc_POA_Beholder =
    &_tao_tc_DSMComms_POA_Beholder;
}
// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/any_op_cs.cpp:34


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

void operator<<= (
    ::CORBA::Any &_tao_any,
    DSMComms::EventEnum _tao_elem)
{
  TAO::Any_Basic_Impl_T<DSMComms::EventEnum>::insert (
      _tao_any,
      DSMComms::_tc_EventEnum,
      _tao_elem);
}

::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    DSMComms::EventEnum &_tao_elem)
{
  return
    TAO::Any_Basic_Impl_T<DSMComms::EventEnum>::extract (
        _tao_any,
        DSMComms::_tc_EventEnum,
        _tao_elem);
}
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/any_op_cs.cpp:34


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

void operator<<= (
    ::CORBA::Any &_tao_any,
    DSMComms::DataType _tao_elem)
{
  TAO::Any_Basic_Impl_T<DSMComms::DataType>::insert (
      _tao_any,
      DSMComms::_tc_DataType,
      _tao_elem);
}

::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    DSMComms::DataType &_tao_elem)
{
  return
    TAO::Any_Basic_Impl_T<DSMComms::DataType>::extract (
        _tao_any,
        DSMComms::_tc_DataType,
        _tao_elem);
}
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/any_op_cs.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {

/// Copying insertion.
void operator<<= (
  ::CORBA::Any &_tao_any,
  const ::DSMComms::Value &_tao_elem)
{
  TAO::Any_Dual_Impl_T< ::DSMComms::Value>::insert_copy (
    _tao_any,
    ::DSMComms::Value::_tao_any_destructor,
    DSMComms::_tc_Value,
    _tao_elem);
}

/// Non-copying insertion.
void operator<<= (
  ::CORBA::Any &_tao_any,
  ::DSMComms::Value *_tao_elem)
{
  TAO::Any_Dual_Impl_T< ::DSMComms::Value>::insert (
    _tao_any,
    ::DSMComms::Value::_tao_any_destructor,
    DSMComms::_tc_Value,
    _tao_elem);
}

/// Extraction to const pointer.
::CORBA::Boolean operator>>= (
  const ::CORBA::Any &_tao_any,
  const ::DSMComms::Value *&_tao_elem)
{
  return TAO::Any_Dual_Impl_T< ::DSMComms::Value>::extract (
    _tao_any,
    ::DSMComms::Value::_tao_any_destructor,
    DSMComms::_tc_Value,
    _tao_elem);
}
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/any_op_cs.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<DSMComms::POA_Beholder>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL
namespace CORBA {



/// Copying insertion.
void
operator<<= (
  ::CORBA::Any &_tao_any,
  DSMComms::POA_Beholder_ptr _tao_elem)
{
  DSMComms::POA_Beholder_ptr _tao_objptr =
    DSMComms::POA_Beholder::_duplicate (_tao_elem);
  _tao_any <<= std::addressof(_tao_objptr);
}

/// Non-copying insertion.
void
operator<<= (
  ::CORBA::Any &_tao_any,
  DSMComms::POA_Beholder_ptr *_tao_elem)
{
  TAO::Any_Impl_T<DSMComms::POA_Beholder>::insert (
    _tao_any,
    DSMComms::POA_Beholder::_tao_any_destructor,
    DSMComms::_tc_POA_Beholder,
    *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    DSMComms::POA_Beholder_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<DSMComms::POA_Beholder>::extract (
        _tao_any,
        DSMComms::POA_Beholder::_tao_any_destructor,
        DSMComms::_tc_POA_Beholder,
        _tao_elem);
}

}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_cs.cpp:29


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (TAO_OutputCDR &strm, DSMComms::EventEnum _tao_enumerator)
{
  return strm << static_cast< ::CORBA::ULong> (_tao_enumerator);
}

::CORBA::Boolean operator>> (TAO_InputCDR &strm, DSMComms::EventEnum & _tao_enumerator)
{
  ::CORBA::ULong _tao_temp = 0;
  ::CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<DSMComms::EventEnum> (_tao_temp);
    }
  
  return _tao_success;
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_enum/cdr_op_cs.cpp:29


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (TAO_OutputCDR &strm, DSMComms::DataType _tao_enumerator)
{
  return strm << static_cast< ::CORBA::ULong> (_tao_enumerator);
}

::CORBA::Boolean operator>> (TAO_InputCDR &strm, DSMComms::DataType & _tao_enumerator)
{
  ::CORBA::ULong _tao_temp = 0;
  ::CORBA::Boolean const _tao_success = strm >> _tao_temp;
  
  if (_tao_success)
    {
      _tao_enumerator = static_cast<DSMComms::DataType> (_tao_temp);
    }
  
  return _tao_success;
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_structure/cdr_op_cs.cpp:48


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DSMComms::Value &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.storedValue) &&
    (strm << _tao_aggregate.timestamp);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DSMComms::Value &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.storedValue) &&
    (strm >> _tao_aggregate.timestamp);
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/cezario/Dev/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/cdr_op_cs.cpp:50


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DSMComms::POA_Beholder_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DSMComms::POA_Beholder_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  // Narrow to the right type.
  _tao_objref = TAO::Narrow_Utils< ::DSMComms::POA_Beholder>::unchecked_narrow (obj.in ());

  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



