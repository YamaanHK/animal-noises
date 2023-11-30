#pragma once

#include "animal.h"

class Cow : public Animal {
public:
    void speak() const override;
};
