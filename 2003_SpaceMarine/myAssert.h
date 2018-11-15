//-------------------------------------------------
// myAssert.h

#ifndef MYASSERT_H
#define MYASSERT_H

#include <sstream>
#include <stdexcept>
#include <string>

inline
void myAssertImpl(bool trueAssertion, const std::string& assertion,
				  const std::string& file, int line)
{
	std::ostringstream msg;
	msg << "Assertion failed: " << assertion << ", file: " << file << ", line: " << line;
	if(!trueAssertion) throw std::domain_error(msg.str());
}

#define releaseAssert(trueAssertion) \
	myAssertImpl(trueAssertion, #trueAssertion, __FILE__, __LINE__)

#ifndef NDEBUG
#define debugAssert(trueAssertion) \
	myAssertImpl(trueAssertion, #trueAssertion, __FILE__, __LINE__)
#else
#define debugAssert(trueAssertion)
#endif

#ifndef NDEBUG
#define debugStatement(statement) statement
#else
#define debugStatement(statement)
#endif

#endif
//-------------------------------------------------