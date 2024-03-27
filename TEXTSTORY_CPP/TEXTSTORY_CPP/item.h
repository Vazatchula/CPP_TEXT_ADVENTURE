#pragma once
#include "map.h"
class item : public map
{
public:
    item();
    ~item();

    void inventoryKey();
    void inventoryToast();
    void inventoryDonuts();
    void magicUse(const char* input);

  



};

