#include <gtk/gtk.h>
#include "main.h"
//#include "windowgen.h"

//static gboolean open_file (GtkSourceBuffer *sBuf, const gchar *filename);

/*GtkWidget makeTable(gint rows, gint cols)
{
    GtkWidget *cell;
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


    //gtk_grid_attach(returnGrid, cell, 0, 0, 1, 1)

}*/

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

static void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);
  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
      CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr, 40.0);

  cairo_move_to(cr, 10.0, 50.0);
  cairo_show_text(cr, "Disziplin ist Macht.");
}

void render()
{
    //GtkWidget *Table1 = makeTable(5,5);

    GtkWidget *windowGenerated = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *windowBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *drawingArea = gtk_drawing_area_new();

    gtk_container_add(GTK_CONTAINER(windowGenerated), windowBox);
    gtk_box_pack_start(GTK_BOX(windowBox), drawingArea, 1,1,1);

     g_signal_connect(G_OBJECT(drawingArea), "draw",
      G_CALLBACK(on_draw_event), NULL);



    /*GdkWindow *windowGenerated;
    GdkWindowAttr attributes;
    gint attributes_mask;
    GMainLoop *mainloop;
    attributes.window_type = GDK_WINDOW_TOPLEVEL;
    attributes.width = 400;
    attributes.height = 400;
    attributes.wclass = GDK_INPUT_OUTPUT;
    //attributes_mask = GDK_WA_COLORMAP;
    windowGenerated = gdk_window_new(NULL, &attributes, attributes_mask);
    gdk_window_show(windowGenerated);
    g_main_run (mainloop);
    */
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 90);
    gtk_window_set_title (GTK_WINDOW (windowGenerated), "Rendered SQL");
    gtk_window_set_position (GTK_WINDOW (windowGenerated), GTK_WIN_POS_CENTER);



    gtk_widget_realize (windowGenerated);
    gtk_widget_show_all (windowGenerated);


    //gdk_cairo_create(GdkWindow(windowGenerated));


}

void windowgen()
{
  //Pack main window
  leftPane = gtk_scrolled_window_new(NULL, NULL);
  rightPane = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  textBuffer = gtk_text_buffer_new(NULL);
  textView = gtk_text_view_new_with_buffer(textBuffer);

  gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
  gtk_box_set_homogeneous(GTK_BOX(hbox), TRUE);

  gtk_box_pack_start(GTK_BOX(hbox), leftPane, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), rightPane, TRUE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(leftPane), textView);
  //gtk_box_pack_end(GTK_BOX(vbox), statusbar, TRUE, TRUE, 0);


}
