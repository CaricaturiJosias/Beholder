#ifndef BEHOLDERIMPL_H_
#define BEHOLDERIMPL_H_

#include "../idl/BeholderS.h"
#include <string>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class  Beholder_i  : public virtual POA_DSMComms::POA_Beholder {
public:

    Beholder_i (const std::string& id);
    ~Beholder_i () {}

    void LogEventAll(const char * valor, ::DSMComms::EventEnum event);
    void getValue(const char * valueId, ::DSMComms::Value_out toGetValue, ::DSMComms::DataType type);
    void storeValue(const char * valueId, const ::DSMComms::Value & toGetValue, ::DSMComms::DataType type);
    void shutdown (const std::string password);

private:

};

#endif /* BEHOLDERIMPL_H_  */
