/* soapRCCServiceSoapService.cpp
   Generated by gSOAP 2.7.10 from generated/prototypes.h
   Copyright(C) 2000-2008, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#include "soapRCCServiceSoapService.h"

RCCServiceSoapService::RCCServiceSoapService()
{	RCCServiceSoapService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

RCCServiceSoapService::RCCServiceSoapService(const struct soap &soap)
{	RCCServiceSoapService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_copy_context(this, &soap);
}

RCCServiceSoapService::RCCServiceSoapService(soap_mode iomode)
{	RCCServiceSoapService_init(iomode, iomode);
}

RCCServiceSoapService::RCCServiceSoapService(soap_mode imode, soap_mode omode)
{	RCCServiceSoapService_init(imode, omode);
}

RCCServiceSoapService::~RCCServiceSoapService()
{ }

void RCCServiceSoapService::RCCServiceSoapService_init(soap_mode imode, soap_mode omode)
{	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns2", "http://roblox.com/RCCServiceSoap", NULL, NULL},
	{"ns1", "http://roblox.com/", NULL, NULL},
	{"ns3", "http://roblox.com/RCCServiceSoap12", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_imode(this, imode);
	soap_omode(this, omode);
	if (!this->namespaces)
		this->namespaces = namespaces;
};

RCCServiceSoapService *RCCServiceSoapService::copy()
{	RCCServiceSoapService *dup = new RCCServiceSoapService();
	soap_copy_context(dup, this);
	return dup;
}

int RCCServiceSoapService::soap_close_socket()
{	return soap_closesock(this);
}

int RCCServiceSoapService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int RCCServiceSoapService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int RCCServiceSoapService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int RCCServiceSoapService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void RCCServiceSoapService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void RCCServiceSoapService::soap_stream_fault(std::ostream& os)
{	return ::soap_stream_fault(this, os);
}

char *RCCServiceSoapService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void RCCServiceSoapService::soap_noheader()
{	header = NULL;
}

int RCCServiceSoapService::run(int port)
{	if (soap_valid_socket(bind(NULL, port, 100)))
	{	for (;;)
		{	if (!soap_valid_socket(accept()))
				return this->error;
			(void)serve();
			soap_destroy(this);
			soap_end(this);
		}
	}
	else
		return this->error;
	return SOAP_OK;
}

SOAP_SOCKET RCCServiceSoapService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET RCCServiceSoapService::accept()
{	return soap_accept(this);
}

int RCCServiceSoapService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{	soap_begin(this);
#ifdef WITH_FASTCGI
		if (FCGI_Accept() < 0)
		{
			this->error = SOAP_EOF;
			return soap_send_fault(this);
		}
#endif

		soap_begin(this);

#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif

		if (soap_begin_recv(this))
		{	if (this->error < SOAP_STOP)
			{
#ifdef WITH_FASTCGI
				soap_send_fault(this);
#else 
				return soap_send_fault(this);
#endif
			}
			soap_closesock(this);

			continue;
		}

		if (soap_envelope_begin_in(this)
		 || soap_recv_header(this)
		 || soap_body_begin_in(this)
		 || dispatch() || (this->fserveloop && this->fserveloop(this)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve___ns2__HelloWorld(RCCServiceSoapService*);
static int serve___ns2__GetVersion(RCCServiceSoapService*);
static int serve___ns2__GetStatus(RCCServiceSoapService*);
static int serve___ns2__OpenJob(RCCServiceSoapService*);
static int serve___ns2__OpenJobEx(RCCServiceSoapService*);
static int serve___ns2__RenewLease(RCCServiceSoapService*);
static int serve___ns2__Execute(RCCServiceSoapService*);
static int serve___ns2__ExecuteEx(RCCServiceSoapService*);
static int serve___ns2__CloseJob(RCCServiceSoapService*);
static int serve___ns2__BatchJob(RCCServiceSoapService*);
static int serve___ns2__BatchJobEx(RCCServiceSoapService*);
static int serve___ns2__GetExpiration(RCCServiceSoapService*);
static int serve___ns2__GetAllJobs(RCCServiceSoapService*);
static int serve___ns2__GetAllJobsEx(RCCServiceSoapService*);
static int serve___ns2__CloseExpiredJobs(RCCServiceSoapService*);
static int serve___ns2__CloseAllJobs(RCCServiceSoapService*);
static int serve___ns2__Diag(RCCServiceSoapService*);
static int serve___ns2__DiagEx(RCCServiceSoapService*);

int RCCServiceSoapService::dispatch()
{	if (soap_peek_element(this))
		return this->error;
	if (!soap_match_tag(this, this->tag, "ns1:HelloWorld"))
		return serve___ns2__HelloWorld(this);
	if (!soap_match_tag(this, this->tag, "ns1:GetVersion"))
		return serve___ns2__GetVersion(this);
	if (!soap_match_tag(this, this->tag, "ns1:GetStatus"))
		return serve___ns2__GetStatus(this);
	if (!soap_match_tag(this, this->tag, "ns1:OpenJob"))
		return serve___ns2__OpenJob(this);
	if (!soap_match_tag(this, this->tag, "ns1:OpenJobEx"))
		return serve___ns2__OpenJobEx(this);
	if (!soap_match_tag(this, this->tag, "ns1:RenewLease"))
		return serve___ns2__RenewLease(this);
	if (!soap_match_tag(this, this->tag, "ns1:Execute"))
		return serve___ns2__Execute(this);
	if (!soap_match_tag(this, this->tag, "ns1:ExecuteEx"))
		return serve___ns2__ExecuteEx(this);
	if (!soap_match_tag(this, this->tag, "ns1:CloseJob"))
		return serve___ns2__CloseJob(this);
	if (!soap_match_tag(this, this->tag, "ns1:BatchJob"))
		return serve___ns2__BatchJob(this);
	if (!soap_match_tag(this, this->tag, "ns1:BatchJobEx"))
		return serve___ns2__BatchJobEx(this);
	if (!soap_match_tag(this, this->tag, "ns1:GetExpiration"))
		return serve___ns2__GetExpiration(this);
	if (!soap_match_tag(this, this->tag, "ns1:GetAllJobs"))
		return serve___ns2__GetAllJobs(this);
	if (!soap_match_tag(this, this->tag, "ns1:GetAllJobsEx"))
		return serve___ns2__GetAllJobsEx(this);
	if (!soap_match_tag(this, this->tag, "ns1:CloseExpiredJobs"))
		return serve___ns2__CloseExpiredJobs(this);
	if (!soap_match_tag(this, this->tag, "ns1:CloseAllJobs"))
		return serve___ns2__CloseAllJobs(this);
	if (!soap_match_tag(this, this->tag, "ns1:Diag"))
		return serve___ns2__Diag(this);
	if (!soap_match_tag(this, this->tag, "ns1:DiagEx"))
		return serve___ns2__DiagEx(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve___ns2__HelloWorld(RCCServiceSoapService *soap)
{	struct __ns2__HelloWorld soap_tmp___ns2__HelloWorld;
	_ns1__HelloWorldResponse ns1__HelloWorldResponse;
	ns1__HelloWorldResponse.soap_default(soap);
	soap_default___ns2__HelloWorld(soap, &soap_tmp___ns2__HelloWorld);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__HelloWorld(soap, &soap_tmp___ns2__HelloWorld, "-ns2:HelloWorld", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->HelloWorld(soap_tmp___ns2__HelloWorld.ns1__HelloWorld, &ns1__HelloWorldResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__HelloWorldResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__HelloWorldResponse.soap_put(soap, "ns1:HelloWorldResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__HelloWorldResponse.soap_put(soap, "ns1:HelloWorldResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__GetVersion(RCCServiceSoapService *soap)
{	struct __ns2__GetVersion soap_tmp___ns2__GetVersion;
	_ns1__GetVersionResponse ns1__GetVersionResponse;
	ns1__GetVersionResponse.soap_default(soap);
	soap_default___ns2__GetVersion(soap, &soap_tmp___ns2__GetVersion);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__GetVersion(soap, &soap_tmp___ns2__GetVersion, "-ns2:GetVersion", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->GetVersion(soap_tmp___ns2__GetVersion.ns1__GetVersion, &ns1__GetVersionResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__GetVersionResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__GetVersionResponse.soap_put(soap, "ns1:GetVersionResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__GetVersionResponse.soap_put(soap, "ns1:GetVersionResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__GetStatus(RCCServiceSoapService *soap)
{	struct __ns2__GetStatus soap_tmp___ns2__GetStatus;
	_ns1__GetStatusResponse ns1__GetStatusResponse;
	ns1__GetStatusResponse.soap_default(soap);
	soap_default___ns2__GetStatus(soap, &soap_tmp___ns2__GetStatus);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__GetStatus(soap, &soap_tmp___ns2__GetStatus, "-ns2:GetStatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->GetStatus(soap_tmp___ns2__GetStatus.ns1__GetStatus, &ns1__GetStatusResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__GetStatusResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__GetStatusResponse.soap_put(soap, "ns1:GetStatusResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__GetStatusResponse.soap_put(soap, "ns1:GetStatusResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__OpenJob(RCCServiceSoapService *soap)
{	struct __ns2__OpenJob soap_tmp___ns2__OpenJob;
	_ns1__OpenJobResponse ns1__OpenJobResponse;
	ns1__OpenJobResponse.soap_default(soap);
	soap_default___ns2__OpenJob(soap, &soap_tmp___ns2__OpenJob);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__OpenJob(soap, &soap_tmp___ns2__OpenJob, "-ns2:OpenJob", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->OpenJob(soap_tmp___ns2__OpenJob.ns1__OpenJob, &ns1__OpenJobResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__OpenJobResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__OpenJobResponse.soap_put(soap, "ns1:OpenJobResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__OpenJobResponse.soap_put(soap, "ns1:OpenJobResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__OpenJobEx(RCCServiceSoapService *soap)
{	struct __ns2__OpenJobEx soap_tmp___ns2__OpenJobEx;
	_ns1__OpenJobExResponse ns1__OpenJobExResponse;
	ns1__OpenJobExResponse.soap_default(soap);
	soap_default___ns2__OpenJobEx(soap, &soap_tmp___ns2__OpenJobEx);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__OpenJobEx(soap, &soap_tmp___ns2__OpenJobEx, "-ns2:OpenJobEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->OpenJobEx(soap_tmp___ns2__OpenJobEx.ns1__OpenJobEx, &ns1__OpenJobExResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__OpenJobExResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__OpenJobExResponse.soap_put(soap, "ns1:OpenJobExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__OpenJobExResponse.soap_put(soap, "ns1:OpenJobExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__RenewLease(RCCServiceSoapService *soap)
{	struct __ns2__RenewLease soap_tmp___ns2__RenewLease;
	_ns1__RenewLeaseResponse ns1__RenewLeaseResponse;
	ns1__RenewLeaseResponse.soap_default(soap);
	soap_default___ns2__RenewLease(soap, &soap_tmp___ns2__RenewLease);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__RenewLease(soap, &soap_tmp___ns2__RenewLease, "-ns2:RenewLease", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->RenewLease(soap_tmp___ns2__RenewLease.ns1__RenewLease, &ns1__RenewLeaseResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__RenewLeaseResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__RenewLeaseResponse.soap_put(soap, "ns1:RenewLeaseResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__RenewLeaseResponse.soap_put(soap, "ns1:RenewLeaseResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__Execute(RCCServiceSoapService *soap)
{	struct __ns2__Execute soap_tmp___ns2__Execute;
	_ns1__ExecuteResponse ns1__ExecuteResponse;
	ns1__ExecuteResponse.soap_default(soap);
	soap_default___ns2__Execute(soap, &soap_tmp___ns2__Execute);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__Execute(soap, &soap_tmp___ns2__Execute, "-ns2:Execute", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->Execute(soap_tmp___ns2__Execute.ns1__Execute, &ns1__ExecuteResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__ExecuteResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__ExecuteResponse.soap_put(soap, "ns1:ExecuteResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__ExecuteResponse.soap_put(soap, "ns1:ExecuteResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__ExecuteEx(RCCServiceSoapService *soap)
{	struct __ns2__ExecuteEx soap_tmp___ns2__ExecuteEx;
	_ns1__ExecuteExResponse ns1__ExecuteExResponse;
	ns1__ExecuteExResponse.soap_default(soap);
	soap_default___ns2__ExecuteEx(soap, &soap_tmp___ns2__ExecuteEx);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__ExecuteEx(soap, &soap_tmp___ns2__ExecuteEx, "-ns2:ExecuteEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->ExecuteEx(soap_tmp___ns2__ExecuteEx.ns1__ExecuteEx, &ns1__ExecuteExResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__ExecuteExResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__ExecuteExResponse.soap_put(soap, "ns1:ExecuteExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__ExecuteExResponse.soap_put(soap, "ns1:ExecuteExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__CloseJob(RCCServiceSoapService *soap)
{	struct __ns2__CloseJob soap_tmp___ns2__CloseJob;
	_ns1__CloseJobResponse ns1__CloseJobResponse;
	ns1__CloseJobResponse.soap_default(soap);
	soap_default___ns2__CloseJob(soap, &soap_tmp___ns2__CloseJob);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__CloseJob(soap, &soap_tmp___ns2__CloseJob, "-ns2:CloseJob", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->CloseJob(soap_tmp___ns2__CloseJob.ns1__CloseJob, &ns1__CloseJobResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__CloseJobResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__CloseJobResponse.soap_put(soap, "ns1:CloseJobResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__CloseJobResponse.soap_put(soap, "ns1:CloseJobResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__BatchJob(RCCServiceSoapService *soap)
{	struct __ns2__BatchJob soap_tmp___ns2__BatchJob;
	_ns1__BatchJobResponse ns1__BatchJobResponse;
	ns1__BatchJobResponse.soap_default(soap);
	soap_default___ns2__BatchJob(soap, &soap_tmp___ns2__BatchJob);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__BatchJob(soap, &soap_tmp___ns2__BatchJob, "-ns2:BatchJob", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->BatchJob(soap_tmp___ns2__BatchJob.ns1__BatchJob, &ns1__BatchJobResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__BatchJobResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__BatchJobResponse.soap_put(soap, "ns1:BatchJobResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__BatchJobResponse.soap_put(soap, "ns1:BatchJobResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__BatchJobEx(RCCServiceSoapService *soap)
{	struct __ns2__BatchJobEx soap_tmp___ns2__BatchJobEx;
	_ns1__BatchJobExResponse ns1__BatchJobExResponse;
	ns1__BatchJobExResponse.soap_default(soap);
	soap_default___ns2__BatchJobEx(soap, &soap_tmp___ns2__BatchJobEx);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__BatchJobEx(soap, &soap_tmp___ns2__BatchJobEx, "-ns2:BatchJobEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->BatchJobEx(soap_tmp___ns2__BatchJobEx.ns1__BatchJobEx, &ns1__BatchJobExResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__BatchJobExResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__BatchJobExResponse.soap_put(soap, "ns1:BatchJobExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__BatchJobExResponse.soap_put(soap, "ns1:BatchJobExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__GetExpiration(RCCServiceSoapService *soap)
{	struct __ns2__GetExpiration soap_tmp___ns2__GetExpiration;
	_ns1__GetExpirationResponse ns1__GetExpirationResponse;
	ns1__GetExpirationResponse.soap_default(soap);
	soap_default___ns2__GetExpiration(soap, &soap_tmp___ns2__GetExpiration);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__GetExpiration(soap, &soap_tmp___ns2__GetExpiration, "-ns2:GetExpiration", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->GetExpiration(soap_tmp___ns2__GetExpiration.ns1__GetExpiration, &ns1__GetExpirationResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__GetExpirationResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__GetExpirationResponse.soap_put(soap, "ns1:GetExpirationResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__GetExpirationResponse.soap_put(soap, "ns1:GetExpirationResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__GetAllJobs(RCCServiceSoapService *soap)
{	struct __ns2__GetAllJobs soap_tmp___ns2__GetAllJobs;
	_ns1__GetAllJobsResponse ns1__GetAllJobsResponse;
	ns1__GetAllJobsResponse.soap_default(soap);
	soap_default___ns2__GetAllJobs(soap, &soap_tmp___ns2__GetAllJobs);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__GetAllJobs(soap, &soap_tmp___ns2__GetAllJobs, "-ns2:GetAllJobs", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->GetAllJobs(soap_tmp___ns2__GetAllJobs.ns1__GetAllJobs, &ns1__GetAllJobsResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__GetAllJobsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__GetAllJobsResponse.soap_put(soap, "ns1:GetAllJobsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__GetAllJobsResponse.soap_put(soap, "ns1:GetAllJobsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__GetAllJobsEx(RCCServiceSoapService *soap)
{	struct __ns2__GetAllJobsEx soap_tmp___ns2__GetAllJobsEx;
	_ns1__GetAllJobsExResponse ns1__GetAllJobsExResponse;
	ns1__GetAllJobsExResponse.soap_default(soap);
	soap_default___ns2__GetAllJobsEx(soap, &soap_tmp___ns2__GetAllJobsEx);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__GetAllJobsEx(soap, &soap_tmp___ns2__GetAllJobsEx, "-ns2:GetAllJobsEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->GetAllJobsEx(soap_tmp___ns2__GetAllJobsEx.ns1__GetAllJobsEx, &ns1__GetAllJobsExResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__GetAllJobsExResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__GetAllJobsExResponse.soap_put(soap, "ns1:GetAllJobsExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__GetAllJobsExResponse.soap_put(soap, "ns1:GetAllJobsExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__CloseExpiredJobs(RCCServiceSoapService *soap)
{	struct __ns2__CloseExpiredJobs soap_tmp___ns2__CloseExpiredJobs;
	_ns1__CloseExpiredJobsResponse ns1__CloseExpiredJobsResponse;
	ns1__CloseExpiredJobsResponse.soap_default(soap);
	soap_default___ns2__CloseExpiredJobs(soap, &soap_tmp___ns2__CloseExpiredJobs);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__CloseExpiredJobs(soap, &soap_tmp___ns2__CloseExpiredJobs, "-ns2:CloseExpiredJobs", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->CloseExpiredJobs(soap_tmp___ns2__CloseExpiredJobs.ns1__CloseExpiredJobs, &ns1__CloseExpiredJobsResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__CloseExpiredJobsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__CloseExpiredJobsResponse.soap_put(soap, "ns1:CloseExpiredJobsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__CloseExpiredJobsResponse.soap_put(soap, "ns1:CloseExpiredJobsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__CloseAllJobs(RCCServiceSoapService *soap)
{	struct __ns2__CloseAllJobs soap_tmp___ns2__CloseAllJobs;
	_ns1__CloseAllJobsResponse ns1__CloseAllJobsResponse;
	ns1__CloseAllJobsResponse.soap_default(soap);
	soap_default___ns2__CloseAllJobs(soap, &soap_tmp___ns2__CloseAllJobs);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__CloseAllJobs(soap, &soap_tmp___ns2__CloseAllJobs, "-ns2:CloseAllJobs", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->CloseAllJobs(soap_tmp___ns2__CloseAllJobs.ns1__CloseAllJobs, &ns1__CloseAllJobsResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__CloseAllJobsResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__CloseAllJobsResponse.soap_put(soap, "ns1:CloseAllJobsResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__CloseAllJobsResponse.soap_put(soap, "ns1:CloseAllJobsResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__Diag(RCCServiceSoapService *soap)
{	struct __ns2__Diag soap_tmp___ns2__Diag;
	_ns1__DiagResponse ns1__DiagResponse;
	ns1__DiagResponse.soap_default(soap);
	soap_default___ns2__Diag(soap, &soap_tmp___ns2__Diag);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__Diag(soap, &soap_tmp___ns2__Diag, "-ns2:Diag", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->Diag(soap_tmp___ns2__Diag.ns1__Diag, &ns1__DiagResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__DiagResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__DiagResponse.soap_put(soap, "ns1:DiagResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__DiagResponse.soap_put(soap, "ns1:DiagResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___ns2__DiagEx(RCCServiceSoapService *soap)
{	struct __ns2__DiagEx soap_tmp___ns2__DiagEx;
	_ns1__DiagExResponse ns1__DiagExResponse;
	ns1__DiagExResponse.soap_default(soap);
	soap_default___ns2__DiagEx(soap, &soap_tmp___ns2__DiagEx);
	soap->encodingStyle = NULL;
	if (!soap_get___ns2__DiagEx(soap, &soap_tmp___ns2__DiagEx, "-ns2:DiagEx", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->DiagEx(soap_tmp___ns2__DiagEx.ns1__DiagEx, &ns1__DiagExResponse);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	ns1__DiagExResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || ns1__DiagExResponse.soap_put(soap, "ns1:DiagExResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || ns1__DiagExResponse.soap_put(soap, "ns1:DiagExResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */