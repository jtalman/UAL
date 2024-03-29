#include "ual_sxf/buckets/ElemKicker.hh"

// Constructor.
UAL_SXF_ElemKicker::UAL_SXF_ElemKicker(SXF::OStream& out)
  : UAL_SXF_ElemBucket(out, "body", new SXF::ElemMultipoleHash())
{
  m_iMltStatus = 0;
  m_pMultipole = new PacElemMultipole(0);
}

// Destructor.
UAL_SXF_ElemKicker::~UAL_SXF_ElemKicker()
{
  if(m_pMultipole) delete m_pMultipole;
}

// Zero bucket.
void UAL_SXF_ElemKicker::close()
{
  m_pMultipole->order(-1);
  m_pMultipole->order(0);
  m_iMltStatus = 0;
}

// Check the scalar attribute key (KL , KLS) and set its value. 
// Return SXF_TRUE or SXF_FALSE.
int UAL_SXF_ElemKicker::setScalarValue(double v)
{
  int result = SXF_TRUE;

  if(!v) return result;  

  switch (m_iAttribID){
  case SXF::ElemMultipoleHash::KL :
    m_pMultipole->kl(0) = v;
    m_iMltStatus++;
    break;
  case SXF::ElemMultipoleHash::KLS :
    m_pMultipole->ktl(0) = v;
    m_iMltStatus++;
    break;
  default:
    result = SXF_FALSE;
    break;
  };

  return result;
}

// Return 1 because the SXF kicker attributes are represented
// by one SMF Multipole bucket.
int UAL_SXF_ElemKicker::getBodySize() const
{
  return 1;
}

// Get the SMF body bucket selected by the given index (0).
// Return 0, if the bucket is not defined or empty.
PacElemBucket* UAL_SXF_ElemKicker::getBodyBucket(int index) 
{
  if(index == 0)
     if(m_iMltStatus) return m_pMultipole;
  return 0;
}

void UAL_SXF_ElemKicker::write(ostream& out, const PacLattElement& element, const string& tab)
{
  // Get body attributes
  PacElemAttributes* attributes = element.getBody();  
  if(!attributes) return;

  // Check multipole bucket
  PacElemAttributes::iterator it = attributes->find(pacMultipole.key());
  if(!(it != attributes->end())) return;

  *m_pMultipole = (*it);
  int order = m_pMultipole->order();
  double value = 0.0;

  if(order < 0) return;

  // Print it
  out << tab << "body = { ";
  if((value = m_pMultipole->kl(0)) != 0) out << "kl = " << value << " ";
  if((value = m_pMultipole->ktl(0)) != 0) out << "kls = " << value << " ";
  out << endl << tab << "}" << endl;
}

