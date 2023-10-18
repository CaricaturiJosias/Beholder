/* soapServer.cpp
   Generated by gSOAP 2.8.131 for /home/cezario/Dev/Beholder/DSMComms/cliente/MsgProcessor.h

gSOAP XML Web services tools
Copyright (C) 2000-2023, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapServer.cpp ver 2.8.131 2023-10-18 05:05:31 GMT")
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	soap->keep_alive = soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->keep_alive > 0 && soap->max_keep_alive > 0)
			soap->keep_alive--;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if ((soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap))) && soap->error && soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	(void)soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "bhldr:lookup"))
		return soap_serve_bhldr__lookup(soap);
	if (!soap_match_tag(soap, soap->tag, "bhldr:registerInfo"))
		return soap_serve_bhldr__registerInfo(soap);
	if (!soap_match_tag(soap, soap->tag, "bhldr:updateInfo"))
		return soap_serve_bhldr__updateInfo(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__lookup(struct soap *soap)
{	struct bhldr__lookup soap_tmp_bhldr__lookup;
	struct bhldr__lookupResponse soap_tmp_bhldr__lookupResponse;
	soap_default_bhldr__lookupResponse(soap, &soap_tmp_bhldr__lookupResponse);
	soap_default_bhldr__lookup(soap, &soap_tmp_bhldr__lookup);
	if (!soap_get_bhldr__lookup(soap, &soap_tmp_bhldr__lookup, "bhldr:lookup", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = bhldr__lookup(soap, soap_tmp_bhldr__lookup.input, soap_tmp_bhldr__lookupResponse.data);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_bhldr__lookupResponse(soap, &soap_tmp_bhldr__lookupResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_bhldr__lookupResponse(soap, &soap_tmp_bhldr__lookupResponse, "bhldr:lookupResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_bhldr__lookupResponse(soap, &soap_tmp_bhldr__lookupResponse, "bhldr:lookupResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__registerInfo(struct soap *soap)
{	struct bhldr__registerInfo soap_tmp_bhldr__registerInfo;
	struct bhldr__registerInfoResponse soap_tmp_bhldr__registerInfoResponse;
	soap_default_bhldr__registerInfoResponse(soap, &soap_tmp_bhldr__registerInfoResponse);
	soap_default_bhldr__registerInfo(soap, &soap_tmp_bhldr__registerInfo);
	if (!soap_get_bhldr__registerInfo(soap, &soap_tmp_bhldr__registerInfo, "bhldr:registerInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = bhldr__registerInfo(soap, soap_tmp_bhldr__registerInfo.inputInfo, soap_tmp_bhldr__registerInfoResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_bhldr__registerInfoResponse(soap, &soap_tmp_bhldr__registerInfoResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_bhldr__registerInfoResponse(soap, &soap_tmp_bhldr__registerInfoResponse, "bhldr:registerInfoResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_bhldr__registerInfoResponse(soap, &soap_tmp_bhldr__registerInfoResponse, "bhldr:registerInfoResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_bhldr__updateInfo(struct soap *soap)
{	struct bhldr__updateInfo soap_tmp_bhldr__updateInfo;
	soap_default_bhldr__updateInfo(soap, &soap_tmp_bhldr__updateInfo);
	if (!soap_get_bhldr__updateInfo(soap, &soap_tmp_bhldr__updateInfo, "bhldr:updateInfo", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = bhldr__updateInfo(soap, soap_tmp_bhldr__updateInfo.message);
	if (soap->error)
		return soap->error;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.cpp */
