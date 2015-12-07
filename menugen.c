#include <gtk/gtk.h>
#include "menugen.h"

void menugen()
{

  //Window Creation
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 700, 500);
  gtk_window_set_title(GTK_WINDOW(window), "IntuBase version 0.7");

  //Create and position boxes
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

  //Creating menubar
  menubar = gtk_menu_bar_new();
  fileMenu = gtk_menu_new();
  actionMenu = gtk_menu_new();
  gtk_container_add(GTK_CONTAINER(window), vbox);

    fileMi = gtk_menu_item_new_with_label("File");
        newMi = gtk_menu_item_new_with_label("New");
        saveMi = gtk_menu_item_new_with_label("Save");
        openMi = gtk_menu_item_new_with_label("Open");
        quitMi = gtk_menu_item_new_with_label("Quit");

    actionMi = gtk_menu_item_new_with_label("Action");
        renderMi = gtk_menu_item_new_with_label("Render");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), newMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), saveMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), openMi);
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(actionMi), actionMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(actionMenu), renderMi);

  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), actionMi);



  //Packing stuff
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);


}
