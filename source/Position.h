//
//  Position.h
//
//  Created by waynewang on 19/4/14.
//  Copyright (c) 2014 waynewang. All rights reserved.
//

#ifndef __Position__
#define __Position__

#include "Public.h"
#include <Eigen/Dense>
#include <vector>

typedef Eigen::Vector2d Pos2d;
typedef Eigen::Vector3d Pos3d;

template <class T>
class PosAndDistance {
public:
   PosAndDistance()
   { }
   PosAndDistance(const T& pos, double dist)
      : m_pos(pos)
      , m_distance(dist)
   {}
   T m_pos;
   double m_distance;
};

typedef PosAndDistance<Pos2d> PosAndDistance2d;
typedef PosAndDistance<Pos3d> PosAndDistance3d;

typedef std::vector<PosAndDistance2d> PosAndDistance2dVec;
typedef std::vector<PosAndDistance3d> PosAndDistance3dVec;

#endif /* defined(__Position__) */
