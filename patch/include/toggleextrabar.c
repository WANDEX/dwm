#include "toggleextrabar.h"

void
toggleextrabar(const Arg *arg)
{
	if (selmon->extrabarwin) {
		selmon->showextrabar = !selmon->showextrabar;
		updatebarpos(selmon);
		XMoveResizeWindow(dpy, selmon->extrabarwin, selmon->wx, selmon->eby, selmon->ww, bh);
		arrange(selmon);
	}
}

