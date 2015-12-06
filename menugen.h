#ifndef MENUGEN_INCLUDED
#define MENUGEN_INCLUDED

void menugen();

//Widget creation
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *hbox;

  GtkWidget *menubar;
  GtkWidget *fileMenu;
  GtkWidget *fileMi; //fileMenuItem
    GtkWidget *newMi;
    GtkWidget *saveMi;
    GtkWidget *openMi;
    GtkWidget *quitMi; //quitMenuItem
  GtkWidget *actionMenu;
  GtkWidget *actionMi;
    GtkWidget *renderMi;

  GtkWidget *placeholder1;
  GtkWidget *placeholder2;
  GtkWidget *placeholder3;

#endif // MENUGEN_INCLUDED
