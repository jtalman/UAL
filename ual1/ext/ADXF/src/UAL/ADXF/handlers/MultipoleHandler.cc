
#include <iostream>
#include "xercesc/sax2/Attributes.hpp"

#include "SMF/PacGenElement.h"

#include "UAL/ADXF/Reader.hh"
#include "UAL/ADXF/handlers/MultipoleHandler.hh"

XERCES_CPP_NAMESPACE_USE

UAL::ADXFMultipoleHandler::ADXFMultipoleHandler()
{
}

void UAL::ADXFMultipoleHandler::startElement(const   XMLCh* const    uri,
					     const   XMLCh* const    localname,
					     const   XMLCh* const    qname,
					     const   xercesc::Attributes&     attrs)
{
    char* message = XMLString::transcode(localname);
    // cout << "ADXFMarkerHandler::startElement: saw element: "<< message << endl;
    XMLString::release(&message);

    const XMLCh* xmlName  = attrs.getValue(m_chName);
    char* name    = XMLString::transcode(xmlName);

    PacMultipole genElement(name);

    XMLString::release(&name);

    addAttributes(genElement);
}

void UAL::ADXFMultipoleHandler::endElement(const   XMLCh* const    uri,
					   const   XMLCh* const    localname,
					   const   XMLCh* const    qname)
{
    char* message = XMLString::transcode(localname);
    // cout << "ADXFMarkerHandler::endElement: saw element: "<< message << endl;
    XMLString::release(&message);


    UAL::ADXFReader::getInstance()->getSAX2Reader()->setContentHandler(p_parentHandler);
    UAL::ADXFReader::getInstance()->getSAX2Reader()->setErrorHandler(p_parentHandler);
}

void UAL::ADXFMultipoleHandler::fatalError(const SAXParseException& exception)
{
    char* message = XMLString::transcode(exception.getMessage());
    cout << "ADXFMultipoleHandler: Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << endl;
}

