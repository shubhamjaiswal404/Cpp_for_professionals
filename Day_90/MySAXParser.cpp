#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>

#include <iostream>

#include "MySAXParser.h"
#include "MySAXHandler.hpp"

using namespace std;
using namespace xercesc;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Usage : MySAXParser < > " << std::endl;
        return 1;
    }

    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch)
    {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Error during initialization ! :\n"
             << message << "\n";
        XMLString::release(&message);
        return 1;
    }

    SAXParser* parser = new SAXParser();
    parser->setValidationScheme(SAXParser::Val_Always);
    parser->setDoNamespaces(true); // optional

    // Customize Document Handler during parseing
    MySAXHandler* docHandler = new MySAXHandler();
    ErrorHandler* errHandler = (ErrorHandler*) docHandler;

    parser->setDocumentHandler(docHandler);
    parser->setErrorHandler(errHandler);

    try {
        // SAX 1.0 Parser Interface's
        // Return is void
        // void parser ( const InputSource & source)
        parser->parse(argv[1]);
    }
    catch (const XMLException& toCatch)
    {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is : \n"
             << message << "\n";
        XMLString::release(&message);
    }

    return 0;
}
