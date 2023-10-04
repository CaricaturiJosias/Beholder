/* soapStub.h
   Generated by gSOAP 2.8.131 for /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h

gSOAP XML Web services tools
Copyright (C) 2000-2023, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/


#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 208131
# error "GSOAP VERSION 208131 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumeration Types                                                          *
 *                                                                            *
\******************************************************************************/


/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:9 */
#ifndef SOAP_TYPE_bhldr__DataType
#define SOAP_TYPE_bhldr__DataType (7)
/* bhldr:DataType */
enum bhldr__DataType {
	UNKNOWN = 0,
	ANALOG = 1,
	DIGITAL = 2
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs and Unions                                                *
 *                                                                            *
\******************************************************************************/

struct bhldr__dataFormat;	/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:11 */
struct bhldr__lookup;	/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:18 */
struct bhldr__registerInfoResponse;	/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:20 */
struct bhldr__registerInfo;	/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:20 */
struct bhldr__updateInfo;	/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:22 */

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:11 */
#ifndef SOAP_TYPE_bhldr__dataFormat
#define SOAP_TYPE_bhldr__dataFormat (8)
/* complex XML schema type 'bhldr:dataFormat': */
struct SOAP_CMAC bhldr__dataFormat {
      public:
        /** Required element 'infoName' of XML schema type 'xsd:string' */
        std::string infoName;
        /** Required element 'value' of XML schema type 'xsd:string' */
        std::string value;
        /** Required element 'timestamp' of XML schema type 'xsd:string' */
        std::string timestamp;
        /** Required element 'dataType' of XML schema type 'bhldr:DataType' */
        enum bhldr__DataType dataType;
      public:
        /** Return unique type id SOAP_TYPE_bhldr__dataFormat */
        long soap_type() const { return SOAP_TYPE_bhldr__dataFormat; }
        /** Constructor with member initializations */
        bhldr__dataFormat() : infoName(), value(), timestamp(), dataType() { }
        /** Friend allocator */
        friend SOAP_FMAC1 bhldr__dataFormat * SOAP_FMAC2 soap_instantiate_bhldr__dataFormat(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:18 */
#ifndef SOAP_TYPE_bhldr__lookup
#define SOAP_TYPE_bhldr__lookup (12)
/* complex XML schema type 'bhldr:lookup': */
struct SOAP_CMAC bhldr__lookup {
      public:
        /** Required element 'infoId' of XML schema type 'xsd:string' */
        std::string infoId;
      public:
        /** Return unique type id SOAP_TYPE_bhldr__lookup */
        long soap_type() const { return SOAP_TYPE_bhldr__lookup; }
        /** Constructor with member initializations */
        bhldr__lookup() : infoId() { }
        /** Friend allocator */
        friend SOAP_FMAC1 bhldr__lookup * SOAP_FMAC2 soap_instantiate_bhldr__lookup(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:20 */
#ifndef SOAP_TYPE_bhldr__registerInfoResponse
#define SOAP_TYPE_bhldr__registerInfoResponse (16)
/* complex XML schema type 'bhldr:registerInfoResponse': */
struct SOAP_CMAC bhldr__registerInfoResponse {
      public:
        /** Required element 'result' of XML schema type 'xsd:boolean' */
        bool result;
      public:
        /** Return unique type id SOAP_TYPE_bhldr__registerInfoResponse */
        long soap_type() const { return SOAP_TYPE_bhldr__registerInfoResponse; }
        /** Constructor with member initializations */
        bhldr__registerInfoResponse() : result() { }
        /** Friend allocator */
        friend SOAP_FMAC1 bhldr__registerInfoResponse * SOAP_FMAC2 soap_instantiate_bhldr__registerInfoResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:20 */
#ifndef SOAP_TYPE_bhldr__registerInfo
#define SOAP_TYPE_bhldr__registerInfo (17)
/* complex XML schema type 'bhldr:registerInfo': */
struct SOAP_CMAC bhldr__registerInfo {
      public:
        /** Required element 'message' of XML schema type 'bhldr:dataFormat' */
        struct bhldr__dataFormat message;
      public:
        /** Return unique type id SOAP_TYPE_bhldr__registerInfo */
        long soap_type() const { return SOAP_TYPE_bhldr__registerInfo; }
        /** Constructor with member initializations */
        bhldr__registerInfo() : message() { }
        /** Friend allocator */
        friend SOAP_FMAC1 bhldr__registerInfo * SOAP_FMAC2 soap_instantiate_bhldr__registerInfo(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:22 */
#ifndef SOAP_TYPE_bhldr__updateInfo
#define SOAP_TYPE_bhldr__updateInfo (20)
/* complex XML schema type 'bhldr:updateInfo': */
struct SOAP_CMAC bhldr__updateInfo {
      public:
        /** Required element 'message' of XML schema type 'bhldr:dataFormat' */
        struct bhldr__dataFormat message;
      public:
        /** Return unique type id SOAP_TYPE_bhldr__updateInfo */
        long soap_type() const { return SOAP_TYPE_bhldr__updateInfo; }
        /** Constructor with member initializations */
        bhldr__updateInfo() : message() { }
        /** Friend allocator */
        friend SOAP_FMAC1 bhldr__updateInfo * SOAP_FMAC2 soap_instantiate_bhldr__updateInfo(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:23 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (21)
/* SOAP_ENV__Header: */
struct SOAP_CMAC SOAP_ENV__Header {
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Header */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Header; }
        /** Constructor with member initializations */
        SOAP_ENV__Header() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:23 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (22)
/* Type SOAP_ENV__Code is a recursive data type, (in)directly referencing itself through its (base or derived class) members */
/* SOAP_ENV__Code: */
struct SOAP_CMAC SOAP_ENV__Code {
      public:
        /** Optional element 'SOAP-ENV:Value' of XML schema type 'xsd:QName' */
        char *SOAP_ENV__Value;
        /** Optional element 'SOAP-ENV:Subcode' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Subcode;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Code */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Code; }
        /** Constructor with member initializations */
        SOAP_ENV__Code() : SOAP_ENV__Value(), SOAP_ENV__Subcode() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:23 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (24)
/* SOAP_ENV__Detail: */
struct SOAP_CMAC SOAP_ENV__Detail {
      public:
        char *__any;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_<typename> assigned to __type */
        /** Do not create a cyclic data structure through this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Detail */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Detail; }
        /** Constructor with member initializations */
        SOAP_ENV__Detail() : __any(), __type(), fault() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:23 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (26)
/* SOAP_ENV__Reason: */
struct SOAP_CMAC SOAP_ENV__Reason {
      public:
        /** Optional element 'SOAP-ENV:Text' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Text;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Reason */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Reason; }
        /** Constructor with member initializations */
        SOAP_ENV__Reason() : SOAP_ENV__Text() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* /home/cezario/Dev/Beholder/CORBA/MsgProcessor/MsgProcessor.h:23 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (27)
/* SOAP_ENV__Fault: */
struct SOAP_CMAC SOAP_ENV__Fault {
      public:
        /** Optional element 'faultcode' of XML schema type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XML schema type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XML schema type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XML schema type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Fault */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Fault; }
        /** Constructor with member initializations */
        SOAP_ENV__Fault() : faultcode(), faultstring(), faultactor(), detail(), SOAP_ENV__Code(), SOAP_ENV__Reason(), SOAP_ENV__Node(), SOAP_ENV__Role(), SOAP_ENV__Detail() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* (built-in):0 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
typedef char *_XML;
#endif

/* (built-in):0 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
typedef char *_QName;
#endif

/******************************************************************************\
 *                                                                            *
 * Serializable Types                                                         *
 *                                                                            *
\******************************************************************************/


/* char has binding name 'byte' for type 'xsd:byte' */
#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif

/* int has binding name 'int' for type 'xsd:int' */
#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif

/* bool has binding name 'bool' for type 'xsd:boolean' */
#ifndef SOAP_TYPE_bool
#define SOAP_TYPE_bool (13)
#endif

/* enum bhldr__DataType has binding name 'bhldr__DataType' for type 'bhldr:DataType' */
#ifndef SOAP_TYPE_bhldr__DataType
#define SOAP_TYPE_bhldr__DataType (7)
#endif

/* std::string has binding name 'std__string' for type 'xsd:string' */
#ifndef SOAP_TYPE_std__string
#define SOAP_TYPE_std__string (9)
#endif

/* struct SOAP_ENV__Fault has binding name 'SOAP_ENV__Fault' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (27)
#endif

/* struct SOAP_ENV__Reason has binding name 'SOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (26)
#endif

/* struct SOAP_ENV__Detail has binding name 'SOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (24)
#endif

/* struct SOAP_ENV__Code has binding name 'SOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (22)
#endif

/* struct SOAP_ENV__Header has binding name 'SOAP_ENV__Header' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (21)
#endif

/* struct bhldr__updateInfo has binding name 'bhldr__updateInfo' for type 'bhldr:updateInfo' */
#ifndef SOAP_TYPE_bhldr__updateInfo
#define SOAP_TYPE_bhldr__updateInfo (20)
#endif

/* struct bhldr__registerInfo has binding name 'bhldr__registerInfo' for type 'bhldr:registerInfo' */
#ifndef SOAP_TYPE_bhldr__registerInfo
#define SOAP_TYPE_bhldr__registerInfo (17)
#endif

/* struct bhldr__registerInfoResponse has binding name 'bhldr__registerInfoResponse' for type 'bhldr:registerInfoResponse' */
#ifndef SOAP_TYPE_bhldr__registerInfoResponse
#define SOAP_TYPE_bhldr__registerInfoResponse (16)
#endif

/* struct bhldr__lookup has binding name 'bhldr__lookup' for type 'bhldr:lookup' */
#ifndef SOAP_TYPE_bhldr__lookup
#define SOAP_TYPE_bhldr__lookup (12)
#endif

/* struct bhldr__dataFormat has binding name 'bhldr__dataFormat' for type 'bhldr:dataFormat' */
#ifndef SOAP_TYPE_bhldr__dataFormat
#define SOAP_TYPE_bhldr__dataFormat (8)
#endif

/* struct SOAP_ENV__Reason * has binding name 'PointerToSOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (29)
#endif

/* struct SOAP_ENV__Detail * has binding name 'PointerToSOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (28)
#endif

/* struct SOAP_ENV__Code * has binding name 'PointerToSOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (23)
#endif

/* _QName has binding name '_QName' for type 'xsd:QName' */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
#endif

/* _XML has binding name '_XML' for type '' */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
#endif

/* char * has binding name 'string' for type 'xsd:string' */
#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stub Functions                                            *
 *                                                                            *
\******************************************************************************/

    
    /** Web service synchronous operation 'soap_call_bhldr__lookup' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_bhldr__lookup(struct soap *soap, const char *soap_endpoint, const char *soap_action, const std::string& infoId, struct bhldr__dataFormat &data);
    /** Web service asynchronous operation 'soap_send_bhldr__lookup' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__lookup(struct soap *soap, const char *soap_endpoint, const char *soap_action, const std::string& infoId);
    /** Web service asynchronous operation 'soap_recv_bhldr__lookup' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__lookup(struct soap *soap, struct bhldr__dataFormat &data);
    
    /** Web service synchronous operation 'soap_call_bhldr__registerInfo' to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_call_bhldr__registerInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, const struct bhldr__dataFormat& message, bool &result);
    /** Web service asynchronous operation 'soap_send_bhldr__registerInfo' to send a request message to the specified endpoint and SOAP Action header, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__registerInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, const struct bhldr__dataFormat& message);
    /** Web service asynchronous operation 'soap_recv_bhldr__registerInfo' to receive a response message from the connected endpoint, returns SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__registerInfo(struct soap *soap, bool &result);
    /** Web service one-way asynchronous operation 'soap_send_bhldr__updateInfo' */
    SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__updateInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, const struct bhldr__dataFormat& message);
    /** Web service one-way asynchronous operation 'soap_recv_bhldr__updateInfo' */
    SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__updateInfo(struct soap *soap, struct bhldr__updateInfo *_param_1);

/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/

    /** Web service operation 'bhldr__lookup' implementation, should return SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 bhldr__lookup(struct soap*, std::string infoId, struct bhldr__dataFormat &data);
    /** Web service operation 'bhldr__registerInfo' implementation, should return SOAP_OK or error code */
    SOAP_FMAC5 int SOAP_FMAC6 bhldr__registerInfo(struct soap*, struct bhldr__dataFormat message, bool &result);
    /** Web service one-way operation 'bhldr__updateInfo' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
    SOAP_FMAC5 int SOAP_FMAC6 bhldr__updateInfo(struct soap*, struct bhldr__dataFormat message);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__lookup(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__registerInfo(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__updateInfo(struct soap*);

#endif

/* End of soapStub.h */
