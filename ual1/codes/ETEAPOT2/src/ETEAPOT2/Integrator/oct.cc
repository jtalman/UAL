#ifndef ETEAPOT2_OCT_CC
#define ETEAPOT2_OCT_CC

#include <iomanip>
#include <stdlib.h>

#include "SMF/PacElemMultipole.h"
#include "SMF/PacLattice.h"
#include "ETEAPOT/Integrator/MltData.hh"
#include "ETEAPOT/Integrator/BasicTracker.hh"
#include "ETEAPOT2/Integrator/genMethods/Matrices.hh"

#include"ETEAPOT2/Integrator/genMethods/Vectors.h"
#include"ETEAPOT2/Integrator/genMethods/spinExtern"
#include"ETEAPOT2/Integrator/genMethods/designExtern"
#include"ETEAPOT2/Integrator/genMethods/bunchParticleExtern"

namespace ETEAPOT2 {

  class oct : public ETEAPOT::BasicTracker {

  public:

#include"ETEAPOT2/Integrator/octMethods/classMethods"

    inline ETEAPOT::MltData& getMltData();

#include"ETEAPOT2/Integrator/octMethods/propagate.method"
#include"ETEAPOT2/Integrator/genMethods/get_vlcyMKS.method"
#include"ETEAPOT2/Integrator/genMethods/passDrift.method"

    /** Element length */
    // double m_l;

    /** Complexity number */
    double m_ir;

    /** Mlt attributes */
    ETEAPOT::MltData m_mdata;

  };

  inline ETEAPOT::MltData& oct::getMltData()
  {
      return m_mdata;
  }

}

#endif
