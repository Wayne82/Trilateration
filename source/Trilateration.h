//
//  Trilateration.h
//
//  Created by waynewang on 19/4/14.
//  Copyright (c) 2014 waynewang. All rights reserved.
//

#ifndef __Trilateration__
#define __Trilateration__

#include "Public.h"
#include "Position.h"

class EXPORT_API Trilateration
{
public:
    bool CalculateLocation2d(const PosAndDistance2dVec& beacons, Pos2d& location);
    bool CalculateLocation3d(const PosAndDistance3dVec& beacons, Pos3d& location);
};

#endif /* defined(__Trilateration__) */
