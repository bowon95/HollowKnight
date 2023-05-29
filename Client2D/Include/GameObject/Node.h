#pragma once

#include "Ref.h"
// #include "../../EditorManager.h"

class CNode :
    public CRef
{
public:
    virtual bool Run() = 0;
};

