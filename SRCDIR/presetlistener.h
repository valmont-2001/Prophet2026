#ifndef __PRESETLISTENERH__
#define __PRESETLISTENERH__

#include "types.h"

// Interface: ce que doit savoir faire une fenetre qui contient les 12 boutons de selection de preset
class PresetSelectionListener
{
public:
   virtual ~PresetSelectionListener() {}
   virtual void presetSelected(uint8_t preset) = 0;
};

#endif
