#pragma once
#include "Python.h"

#if !defined(HAVE_LONG_LONG)
#error "This module requires long longs!"
#endif

#include <torch/extension.h>
#include <c10/cuda/CUDACachingAllocator.h>

PY_LONG_LONG
hpTimer(void)
{
        return c10::cuda::CUDACachingAllocator::getDeviceStats(0).allocated_bytes[0].current;
        //return c10::cuda::CUDACachingAllocator::getDeviceStats(0).reserved_bytes[0].current;
}

double
hpTimerUnit(void)
{
        return 0.000001;
}
