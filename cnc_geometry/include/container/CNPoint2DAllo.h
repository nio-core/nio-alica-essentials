/*
 * CNPoint2DAllo.h
 *
 *  Created on: 07.11.2016
 *      Author: Philipp Mandler
 */

#ifndef CNC_GEOMETRY_CONTAINER_CNPOINT2DALLO_H_
#define CNC_GEOMETRY_CONTAINER_CNPOINT2DALLO_H_

#include "container/CNPoint2DTemplate.h"

namespace geometry
{

class CNPoint2DEgo;
class CNPositionAllo;

class CNPoint2DAllo : public CNPoint2DTemplate<CNPoint2DAllo>
{
  public:
	CNPoint2DAllo() : CNPoint2DAllo(0, 0) {};
	CNPoint2DAllo(double x, double y);
    virtual ~CNPoint2DAllo();

    string toString();

    shared_ptr<CNPoint2DEgo> toEgo(CNPositionAllo &origin);
};

} /* namespace geometry */

#endif /* CNC_GEOMETRY_CONTAINER_CNPOINT2DALLO_H_ */