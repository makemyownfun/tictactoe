#ifndef FOCUSABLE_H
#define FOCUSABLE_H

#include "UIelement.h"

class Focusable : UIelement {
public:
     virtual void handleEvent(int mouseX, int mouseY, SDL_Event& event) = 0;
};

#endif