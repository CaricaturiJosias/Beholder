/* soapClient.cpp
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

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.131 2023-10-17 19:24:31 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_bhldr__lookup(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<std::string> infoId, std::vector<std::string> timestamp, std::vector<struct bhldr__dataFormat> &data)
{	if (soap_send_bhldr__lookup(soap, soap_endpoint, soap_action, infoId, timestamp) || soap_recv_bhldr__lookup(soap, data))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__lookup(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<std::string> infoId, std::vector<std::string> timestamp)
{	struct bhldr__lookup soap_tmp_bhldr__lookup;
	soap_tmp_bhldr__lookup.infoId = infoId;
	soap_tmp_bhldr__lookup.timestamp = timestamp;
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_bhldr__lookup(soap, &soap_tmp_bhldr__lookup);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_bhldr__lookup(soap, &soap_tmp_bhldr__lookup, "bhldr:lookup", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_bhldr__lookup(soap, &soap_tmp_bhldr__lookup, "bhldr:lookup", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__lookup(struct soap *soap, std::vector<struct bhldr__dataFormat> &data)
{
	struct bhldr__lookupResponse *soap_tmp_bhldr__lookupResponse;
	soap_default_std__vectorTemplateOfbhldr__dataFormat(soap, &data);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_bhldr__lookupResponse = soap_get_bhldr__lookupResponse(soap, NULL, "bhldr:lookupResponse", NULL);
	if (!soap_tmp_bhldr__lookupResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	data = soap_tmp_bhldr__lookupResponse->data;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_bhldr__registerInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<struct bhldr__dataFormat> inputInfo, bool &result)
{	if (soap_send_bhldr__registerInfo(soap, soap_endpoint, soap_action, inputInfo) || soap_recv_bhldr__registerInfo(soap, result))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__registerInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<struct bhldr__dataFormat> inputInfo)
{	struct bhldr__registerInfo soap_tmp_bhldr__registerInfo;
	soap_tmp_bhldr__registerInfo.inputInfo = inputInfo;
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_bhldr__registerInfo(soap, &soap_tmp_bhldr__registerInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_bhldr__registerInfo(soap, &soap_tmp_bhldr__registerInfo, "bhldr:registerInfo", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_bhldr__registerInfo(soap, &soap_tmp_bhldr__registerInfo, "bhldr:registerInfo", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__registerInfo(struct soap *soap, bool &result)
{
	struct bhldr__registerInfoResponse *soap_tmp_bhldr__registerInfoResponse;
	soap_default_bool(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_bhldr__registerInfoResponse = soap_get_bhldr__registerInfoResponse(soap, NULL, "bhldr:registerInfoResponse", NULL);
	if (!soap_tmp_bhldr__registerInfoResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_bhldr__registerInfoResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send_bhldr__updateInfo(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::vector<struct bhldr__dataFormat> message)
{	struct bhldr__updateInfo soap_tmp_bhldr__updateInfo;
	soap_tmp_bhldr__updateInfo.message = message;
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_bhldr__updateInfo(soap, &soap_tmp_bhldr__updateInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_bhldr__updateInfo(soap, &soap_tmp_bhldr__updateInfo, "bhldr:updateInfo", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_bhldr__updateInfo(soap, &soap_tmp_bhldr__updateInfo, "bhldr:updateInfo", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_bhldr__updateInfo(struct soap *soap, struct bhldr__updateInfo *_param_1)
{
	soap_default_bhldr__updateInfo(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_bhldr__updateInfo(soap, _param_1, "bhldr:updateInfo", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */
