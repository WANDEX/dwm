#pragma once

#include <X11/Xresource.h>


/* Xresources preferences */
enum resource_type {
	STRING = 0,
	INTEGER = 1,
	FLOAT = 2
};

typedef struct {
	char *name;
	enum resource_type type;
	void *dst;
} ResourcePref;

void load_xresources(void);
void resource_load(XrmDatabase db, char *name, enum resource_type rtype, void *dst);
