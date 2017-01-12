#pragma once
#include "Body.h"
class CSolidBody :
    public CBody
{
public:
    

    double GetRadius() const;
private:
    CSolidBody(const std::string & type, double radius);

};

