// Library       : TIBETAN
// File          : TIBETAN/Propagator/SectorTracker.hh
// Copyright     : see Copyright file
// Author        : J.Wei
// C++ version   : N.Malitsky 


#ifndef UAL_TIBETAN_SECTOR_TRACKER_HH
#define UAL_TIBETAN_SECTOR_TRACKER_HH

#include "UAL/Common/Def.hh"
#include "UAL/APF/PropagatorComponent.hh"
#include "SMF/PacLattice.h"
#include "Optics/PacTMap.h"
#include "Main/Teapot.h"
#include "TIBETAN/Propagator/BasicPropagator.hh"

namespace TIBETAN {

  /** Sector tracker. */

  class SectorTracker : public BasicPropagator {

  public:

    /** Constructor */
    SectorTracker();

    /** Copy Constructor */
    SectorTracker(const SectorTracker& st);

    /** Destructor */
    ~SectorTracker();

    /** Returns a deep copy of this object (inherited from UAL::PropagatorNode) */
    UAL::PropagatorNode* clone();

    /** Set lattice elements (inherited from UAL::PropagatorNode */
    void setLatticeElements(const UAL::AcceleratorNode& lattice, int i0, int i1, 
			    const UAL::AttributeSet& beamAttributes);

    /** Propagates bunch (inherited from UAL::PropagatorNode) */
    void propagate(UAL::Probe& probe);

  protected:

    /** Defines matrix data */
    void setMap(const PacVTps& vtps);

  private:

    static PacLattice s_lattice;
    static Teapot     s_teapot;

    double m_l;

    double a10, a11, a12, a13, a14, a15, a16;
    double a20, a21, a22, a23, a24, a25, a26;
    double a30, a31, a32, a33, a34, a35, a36;
    double a40, a41, a42, a43, a44, a45, a46;   
    double a50, a51, a52, a53, a54, a55, a56;
    double a60, a61, a62, a63, a64, a65, a66;  

    double a566;


  private:

    void init();
    void copy(const SectorTracker& st);

  };

  class SectorTrackerRegister 
  {
    public:

    SectorTrackerRegister(); 
  };

  

}

#endif
