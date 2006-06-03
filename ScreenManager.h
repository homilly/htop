/* Do not edit this file. It was automatically genarated. */

#ifndef HEADER_ScreenManager
#define HEADER_ScreenManager
/*
htop
(C) 2004-2006 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Panel.h"
#include "Object.h"
#include "Vector.h"
#include "FunctionBar.h"

#include "debug.h"
#include <assert.h>

#include <stdbool.h>


typedef enum Orientation_ {
   VERTICAL,
   HORIZONTAL
} Orientation;

typedef struct ScreenManager_ {
   int x1;
   int y1;
   int x2;
   int y2;
   Orientation orientation;
   Vector* items;
   int itemCount;
   FunctionBar* fuBar;
   Vector* fuBars;
   bool owner;
} ScreenManager;


ScreenManager* ScreenManager_new(int x1, int y1, int x2, int y2, Orientation orientation, bool owner);

void ScreenManager_delete(ScreenManager* this);

inline int ScreenManager_size(ScreenManager* this);

void ScreenManager_add(ScreenManager* this, Panel* item, FunctionBar* fuBar, int size);

Panel* ScreenManager_remove(ScreenManager* this, int index);

void ScreenManager_setFunctionBar(ScreenManager* this, FunctionBar* fuBar);

void ScreenManager_resize(ScreenManager* this, int x1, int y1, int x2, int y2);

void ScreenManager_run(ScreenManager* this, Panel** lastFocus, int* lastKey);

#endif