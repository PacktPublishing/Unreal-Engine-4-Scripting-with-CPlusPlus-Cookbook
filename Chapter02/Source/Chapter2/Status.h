#pragma once

#include "Chapter2.h"

UENUM()
enum Status
{
  Stopped UMETA(DisplayName = "Stopped"),
  Moving UMETA(DisplayName = "Moving"),
  Attacking UMETA(DisplayName = "Attacking"),
};