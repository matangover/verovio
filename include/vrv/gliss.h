/////////////////////////////////////////////////////////////////////////////
// Name:        gliss.h
// Author:      Erwan Geffroy, Matan Gover, Ke Zhang
// Created:     2017
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_GLISS_H__
#define __VRV_GLISS_H__

#include "atts_cmn.h"
#include "controlelement.h"
#include "timeinterface.h"

namespace vrv {

//----------------------------------------------------------------------------
// Gliss
//----------------------------------------------------------------------------

class Gliss : public ControlElement,
                public TimeSpanningInterface,
                public AttColor
	{
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    Gliss();
    virtual ~Gliss();
    virtual void Reset();
    virtual std::string GetClassName() const { return "Gliss"; }
    virtual ClassId GetClassId() const { return GLISS; }
    ///@}

    /**
     * @name Getter to interfaces
     */
    ///@{
    virtual TimePointInterface *GetTimePointInterface() { return dynamic_cast<TimePointInterface *>(this); }
    virtual TimeSpanningInterface *GetTimeSpanningInterface() { return dynamic_cast<TimeSpanningInterface *>(this); }
    ///@}

    //----------//
    // Functors //
    //----------//

protected:
    //
private:
    //
public:
    //
private:
    //
};

} // namespace vrv

#endif
