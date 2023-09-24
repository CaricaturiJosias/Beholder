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
    virtual ~Beholder_i () {}

    virtual void LogEventAll(const std::string valor, DSMComms::EventEnum event);
    virtual void getValue(const std::string valueId, DSMComms::Value_out toGetValue);
    virtual void shutdown (const std::string password);

private:

};

#endif /* BEHOLDERIMPL_H_  */
