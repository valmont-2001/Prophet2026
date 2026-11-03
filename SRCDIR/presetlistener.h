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


// Interface: ce que doit savoir faire une fenetre qui recoit les touches jouees a la souris sur un clavier virtuel
class KeyListener
{
public:
   virtual ~KeyListener() {}
   virtual void keyDown(uint8_t note, uint8_t velocity) = 0;
   virtual void keyUp(uint8_t note, uint8_t velocity) = 0;
};

#endif
