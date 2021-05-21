#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

class BaseCodec {
public:
    virtual ~BaseCodec() {}
    virtual std::string encode(const std::string&) = 0;
};

BaseCodec* getCodec(const std::string& name);

#endif
