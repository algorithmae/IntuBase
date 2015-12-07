#ifndef WINDOWGEN_H_INCLUDED
#define WINDOWGEN_H_INCLUDED

//#include <gtkextra/gtksheet.h>

/*
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
*/

void updateEditBuffer();
void drawCell();
void drawTable(GQueue *tableQ, cairo_t *cr);
void textToTable(gchar* contents);

gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
    gpointer user_data);

void do_drawing(cairo_t *);

void windowgen();

void render();

GtkTextBuffer *editBuffer;

GtkWidget *leftPane;
GtkWidget *rightPane;
GtkWidget *textView;
GtkWidget *textView2;
GtkTextBuffer *textBuffer;
GtkWidget *statusbar;
GQueue *tableQ;


#endif // WINDOWGEN_H_INCLUDED
