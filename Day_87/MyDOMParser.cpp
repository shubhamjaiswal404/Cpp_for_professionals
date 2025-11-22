#include <iostream>
#include <string>


#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>



/*
 * class XercesDOMParser
 * In Order to use Xerces-C++ to parse XML file using DOM , you can create  an instance
 * of the XercesDOMParser class.
 * http://xerces.apache.org/xerces-c/apiDocs-3/classXercesDOMParser.html
 *
 * Xerces-C++ Program Pattern
 *
 * {
 *      XMLPlatformUtils::Initialize();
 *
 *      do something
 *
 *      XMLPlatformUtils::Terminate();
 *  }
 *
 */

using namespace std;
using namespace xercesc;


int main(int argc, char* argv[])
{
    int rc = 0;
    if( argc != 2)
    {
        std::cout << "Usage : MyDOMParser <XML file-name> " << std::endl;
        return 1;
    }

    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& ec)
    {
        char* message = XMLString::transcode(ec.getMessage());
        cout << "Error during initialization ! :\n"
             << message <<"\n";
        XMLString::release(&message);
        return 1;
    }

    /*
     * gValScheme = XercesDOMParser::Val_Never;
     * gValScheme = XercesDOMParser::Val_Auto;
     * gValScheme = XercesDOMParser::Val_Always;
     */

    XercesDOMParser* parser = new XercesDOMParser();
    parser->setValidationScheme(XercesDOMParser::Val_Always);
    parser->setDoNamespaces(true);    //optional

    /*
     * parser->setDoSchema(false);
     * parser->setHandleMultipleImports(true);
     * parser->setValidationSchemaFullChecking(true);
     * parser->serCreateEntityReferenceNode(false);
     */

    ErrorHandler* errHandler = (ErrorHandler*) new HandlerBase();
    parser->setErrorHandler(errHandler);

    try
    {
        parser->parse(argv[1]);
    } 
    catch (const XMLException& ec)
    {
        std::cout << "XMLException : " << std::endl;
        std::cout << " File : " << ec.getSrcFile()
                  << " -> Line : "<< ec.getSrcLine()
                  << " Error Message "<<XMLString::transcode(ec.getMessage()) << std::endl;

        rc = -1;
    }
    catch(const DOMException& ec)
    {
        std::cout << "DOMException : " << std::endl;
        std::cout << "File : "<< argv[1]
                  <<"Error : "<<XMLString::transcode(ec.msg)
                  <<"--"<<XMLString::transcode(ec.getMessage())
                  <<std::endl;

        rc = -1;
    }
    catch(const SAXParseException &ec)
    {
        std::cout << "SAXParseException during Parsing \n" ;
        std::cout << "File : "<<argv[1]
                  <<" -> Line : "<< ec.getLineNumber()
                  <<" Column : "<< ec.getColumnNumber() << " Error Message : "
                  <<XMLString::transcode(ec.getMessage()) << std::endl;

        rc = -1;
    }
    catch(...)
    {
        std::cout <<"Unexpected Exception During Parsing \n "<< std::endl;
        rc = -1;
    }

    if( rc == 0 )
    {
        std::cout << " XML File : " << argv[1] << " <- parse OK " <<std::endl;
    }

    delete parser;
    delete errHandler;

    XMLPlatformUtils::Terminate();

    return 0;
}





















