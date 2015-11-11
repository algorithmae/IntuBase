#include <gtk/gtk.h>
#include "main.h"
//#include "windowgen.h"

//static gboolean open_file (GtkSourceBuffer *sBuf, const gchar *filename);

GtkWidget makeTable(gint rows, gint cols)
{
    /*GtkWidget *cell;
    GtkWidget *returnGrid = gtk_grid_new();
        int i, j;
        for(i=0; i<rows; i++)
        {
            for(j=0; j<cols; j++)
            {
            cell = gtk_text_view_new_with_buffer(textBuffer);
            gtk_grid_attach(returnGrid, cell, j, 0, 1, 1);

            //cells[i][j]= gtk_text_view_new_with_buffer(textBuffer);
            };
        };


    //gtk_grid_attach(returnGrid, cell, 0, 0, 1, 1)*/

}

void render()
{
    //GtkWidget *Table1 = makeTable(5,5);

    GtkWidget *windowGenerated = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *windowBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *scrolledWindow = gtk_scrolled_window_new(NULL, NULL);

    gtk_container_add(GTK_CONTAINER(windowGenerated), windowBox);
    gtk_box_pack_start(GTK_BOX(windowBox), scrolledWindow, 1,1,1);


    gtk_window_set_title (GTK_WINDOW (windowGenerated), "Hello World");
    gtk_window_set_position (GTK_WINDOW (windowGenerated), GTK_WIN_POS_CENTER);
    gtk_widget_realize (windowGenerated);

    gtk_widget_show_all (windowGenerated);


}

void windowgen()
{
  //Pack main window
  leftPane = gtk_scrolled_window_new(NULL, NULL);
  rightPane = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  textView = gtk_text_view_new_with_buffer(textBuffer);

  gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
  gtk_box_set_homogeneous(GTK_BOX(hbox), TRUE);

  gtk_box_pack_start(GTK_BOX(hbox), leftPane, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), rightPane, TRUE, TRUE, 0);

  gtk_container_add(leftPane, textView);
  gtk_box_pack_end(GTK_BOX(vbox), statusbar, TRUE, TRUE, 0);


}
