#ifndef __SOFTPROPHETADAPTERH__
#define __SOFTPROPHETADAPTERH__

#include "softprophet.h"

class Proph2000;

// Construit, a partir des donnees de l'editeur (samples, sons, maps, preset), le "patch" que joue le faux Prophet.
// nb_sounds recoit le nombre de sons effectivement utilisables dans ce preset.
std::shared_ptr<softprophet::Patch> softProphetBuildPatch(Proph2000 *proph, uint8_t preset, int *nb_sounds);

#endif
