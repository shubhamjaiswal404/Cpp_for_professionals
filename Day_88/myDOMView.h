#include <xercesc/dom/DOM.hpp>

#include <iostream>
#include <string>


using namespace std;
using namespace xercesc;

XERCES_CPP_NAMESPACE_USE

#define toXMLCh(str) XStr(str).unicodeForm()
#define toCh(str) StrX(str).localForm()

static const XMLCh myFeature[] = { chLatin_L, chLatin_S, chNull};

class StrX
{
public:
    StrX(const XMLCh* const toTranscode)
    {
        fLocalForm = XMLString::transcode(toTranscode);
    }

    ~StrX()
    {
        XMLString::release(&fLocalForm);
    }

    const char* localForm() const
    {
        return fLocalForm;
    }

private:
    char* fLocalForm;
};

class XStr
{
public:
    XStr(const char* const toTranscode)
    {
        fUnicodeForm = XMLString::transcode(toTranscode);
    }

    ~XStr()
    {
        XMLString::release(&fUnicodeForm);
    }
    const XMLCh* unicodeForm() const
    {
        return fUnicodeForm;
    }

private:
    XMLCh* fUnicodeForm;
};

inline void view_node(const DOMNode* node)
{
    if( node->hasAttributes())
    {
        std::cout << "<";
        DOMNamedNodeMap *AttrMap = node->getAttributes();
        for( XMLSize_t j = 0; j < AttrMap->getLength(); j++)
        {
            std::cout << toCh(AttrMap->item(j)->getTextContent());
            if(j < AttrMap->getLength() - 1)
            {
                std::cout << ",";
            }
        }
        std::cout << "> ";
    }

    if(node->hasChildNodes())
    {
        DOMNodeList* childList = node->getChildNodes();
        for(XMLSize_t j = 0 ; j < childList->getLength() ; j++)
        {
            view_node(childList->item(j));
        }
    }
    else
    {
        std::cout << toCh(node->getTextContent());
    }
}

inline void cust_view_doc(const DOMDocument* doc)
{
    DOMElement* rootNode = doc->getDocumentElement();
    std::cout << "rootNode Name : "<< toCh(rootNode->getNodeName()) << std::endl;

    DOMNodeList * bookList = doc->getElementsByTagName(toXMLCh("book"));
    std::cout << "Total book Nodes : " << bookList->getLength() <<std::endl;

    for( XMLSize_t i = 0 ; i < bookList->getLength(); i++)
    {
        std::cout << "Book("<< i << ")";
        view_node(bookList->item(i));
    }
}

/*
inline void dom_view_doc(const DOMDocument* doc)
{
    // output doc
    DOMImplementation* impl = DOMImplementationRegistry::getDOMImplementation(
        XMLString::transcode("Core"));

    DOMLSSerializer *theWriter = ((DOMImplementationLS*)impl)->createLSSerializer();
}
*/
