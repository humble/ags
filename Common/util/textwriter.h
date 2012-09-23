
//=============================================================================
//
// Specialized interface for writing plain text to the underlying source
//
//=============================================================================
#ifndef __AGS_CN_UTIL__TEXTWRITER_H
#define __AGS_CN_UTIL__TEXTWRITER_H

#include "util/string.h"

namespace AGS
{
namespace Common
{

class TextWriter
{
public:
    virtual ~TextWriter(){}

    virtual bool    IsValid() const                         = 0;

    // Write single character
    virtual void    WriteChar(char c)                       = 0;
    // Write string as a plain text (without null-terminator)
    virtual void    WriteString(const String &str)         = 0;
    // Write string and add line break at the end
    virtual void    WriteLine(const String &str)           = 0;
    // Write formatted string (see *printf)
    virtual void    WriteFormat(const String &fmt, ...)    = 0;
    virtual void    WriteLineBreak()                        = 0;
};

} // namespace Common
} // namespace AGS

#endif // __AGS_CN_UTIL__TEXTWRITER_H