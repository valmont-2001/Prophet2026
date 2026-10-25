# Assainissement du code (étapes 1 à 3)

Objectif: repartir d'un squelette simple, sans code inachevé ni variantes mortes, avant toute nouvelle fonctionnalité.
Chaque étape correspond à un commit (voir `git log`), donc rien n'est perdu.

## Étape 1 – Code mort et variantes de compilation
- 625 lignes de blocs `#if 0` supprimées (le code du `#else` actif est conservé).
- Variantes de compilation jamais activées retirées: console, debug, `__DEACTIVATE_PARAM`, `DADSR_LINEAR`, `MICROE_MMB32`…
- Le choix du backend MIDI se faisait par des réglages de projet perdus (`USE_RTMIDI`, `USE_PORTMIDI`, `USE_MSSMIDI`,
  `USE_CSERIAL`, `USE_CURLSERIAL`). Il ne reste plus que **RtMidi**.

## Étape 2 – Matériel « burst » et fichiers morts
- Supprimés: `Serial.*`, `CurlSerial.*`, `mss.*` (anciens backends MIDI / liaison série propriétaire),
  `midithread.*` et `presetpanel_org.*` (jamais utilisés).
- Retirés: tous les réglages « Burst Interface » (fenêtre de configuration, protocole dans `proph2000.cpp`).
- `midi.cpp` / `midi.h` réécrits (700 → 280 lignes). Correction d'un défaut: notes, contrôleurs et program change
  étaient envoyés **deux fois**.
- Le fichier de configuration garde exactement le même format (6 octets MIDI) → compatible avec l'ancienne version.

## Étape 3 – Portabilité
- `types.h` utilise `<stdint.h>` (l'ancien fichier redéfinissait les types standard, refusé par les compilateurs actuels).
- Casse des `#include` corrigée (`MIDI.h`, `DCOset.h`), `windows.h` uniquement sous Windows.

## Étape 4 – Suppression du générateur de sons (WaveGen)
- Supprimés: tout le dossier `wavegen/` (moteur de synthèse DCO/DADSR, fenêtre « Wave Generator », clavier associé).
- Retirés de l'interface: les 16 boutons « Generate » de l'onglet Samples, les 17 entrées de menu « Wave Generator »,
  les panneaux `SynthModel` et `DCOSetPanel`.
- Conservé volontairement: `soundsynthpanel.*` – c'est le panneau des paramètres du Prophet lui-même (filtre, enveloppes, LFO).
- Les réglages WaveGen n'existent plus dans le fichier de configuration (ils étaient écrits en dernier).
- `Prophet2012Layout.fbp` (fichier de wxFormBuilder) est désormais **obsolète** par rapport à `GUILayout.*`:
  ne pas régénérer le code depuis ce fichier.

## Étape 5 – Build
- `CMakeLists.txt`: sous Windows, wxWidgets 3.2, RtMidi, PortAudio et libsamplerate sont téléchargés et compilés en statique
  → un seul `Prophet2026.exe` autonome. Sous Linux, ce sont les paquets du système.
- `.github/workflows/build-windows.yml`: compile l'exécutable Windows sur GitHub (onglet Actions → artefact « Prophet2026-windows »).
- Corrections wxWidgets 3: barre d'état utilisée avant sa création, sélection d'un périphérique inexistant dans la configuration.
- Inclusion `wx/xrc` inutile retirée.
- Test réalisé: compilation complète + lancement sous Linux (écran virtuel), sans erreur. Le build Windows n'a pas encore tourné.

## Vérification effectuée
Contrôle de syntaxe (`g++ -fsyntax-only`, wxWidgets 3.2) sur les 40 fichiers C++ restants: **tous passent**.
Aucun exécutable n'a été produit ni testé.

## Dépendances à fournir au build
wxWidgets 3.x, RtMidi (≥ 5), PortAudio, libsamplerate. (`libcurl` n'est plus nécessaire.)

## À décider (modules facultatifs)
- Import SoundFont (`soundfont*`), clavier MIDI virtuel, comparaison de fichiers, mode stéréo.
- Éditeur de boucles actuel (`soundlooppanel.*`): à remplacer par la nouvelle version simplifiée.
