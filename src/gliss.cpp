/////////////////////////////////////////////////////////////////////////////
// Name:        gliss.cpp
// Author:      Erwan Geffroy, Matan Gover, Ke Zhang
// Created:     2017
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "gliss.h"

//----------------------------------------------------------------------------

namespace vrv {

//----------------------------------------------------------------------------
// Gliss
//----------------------------------------------------------------------------

Gliss::Gliss() : ControlElement("gliss-"), TimeSpanningInterface(), AttColor()
{
    RegisterInterface(TimeSpanningInterface::GetAttClasses(), TimeSpanningInterface::IsInterface());
    RegisterAttClass(ATT_COLOR);

    Reset();
}

Gliss::~Gliss()
{
}

void Gliss::Reset()
{
    ControlElement::Reset();
    TimeSpanningInterface::Reset();
    ResetColor();
}

} // namespace vrv
