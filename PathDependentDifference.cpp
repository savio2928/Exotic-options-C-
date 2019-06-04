//
//
//
//                    PathDependentDifference.cpp
//
//

#include "PathDependentDifference.h"

PathDependentDifference::PathDependentDifference(const MJArray& LookAtTimes_,
                                       double DeliveryTime_,
                                       const PayOffBridge& ThePayOff1_,
                                       const PayOffBridge& ThePayOff2_)

                                       :
                                        PathDependent(LookAtTimes_),
                                        DeliveryTime(DeliveryTime_),
                                        ThePayOff1(ThePayOff1_),
                                        ThePayOff2(ThePayOff2_),
                                        NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PathDependentDifference::MaxNumberOfCashFlows() const
{
     return 1UL;
}

MJArray PathDependentDifference::PossibleCashFlowTimes() const
{
    MJArray tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

unsigned long PathDependentDifference::CashFlows(const MJArray& SpotValues,
                                    std::vector<CashFlow>& GeneratedFlows) const
{
    double sum = SpotValues.sum();
    double mean = sum/NumberOfTimes;

    double pay1=ThePayOff1(mean);
    double pay2=ThePayOff2(mean);


    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = (pay1-pay2);

    return 1UL;
}

PathDependent* PathDependentDifference::clone() const
{
    return new PathDependentDifference(*this);
}

/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/

