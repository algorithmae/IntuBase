#ifndef WINDOWGEN_H_INCLUDED
#define WINDOWGEN_H_INCLUDED

//#include <gtkextra/gtksheet.h>

/*
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
*/

void windowgen();

void render();



GtkWidget *leftPane;
GtkWidget *rightPane;
GtkWidget *textView;
GtkTextBuffer *textBuffer;
GtkWidget *statusbar;


#endif // WINDOWGEN_H_INCLUDED
