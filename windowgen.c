#include <gtk/gtk.h>
#include "main.h"
//#include "windowgen.h"

//static gboolean open_file (GtkSourceBuffer *sBuf, const gchar *filename);

gint mainRows = 0;
gint mainCols = 0;

void drawCell(){}

void drawTable(GArray tableArray, cairo_t *cr)
{
    //Create first row
    gint i;
    gchar* tempStr;
    while(i<tableArray.len)
    {

        tempStr = tableArray.data[i];
        cairo_show_text(cr, tempStr);
        i++;
        cairo_move_to(cr, 0, (i*20));
    }
    //cairo_show_text(cr, contents);
    //Create second row

    //Create additional rows


    /*gint tempRows, tempCols;
    gint rowOffset, colOffset;
    while (tempCols > 0)
    {
        while (tempRows > 0)
        {
            drawCell();
        }

    tempRows--;
    }*/
   /* GtkWidget *cell;
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
        };*/




    //gtk_grid_attach(returnGrid, cell, 0, 0, 1, 1)

}

gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

void do_drawing(cairo_t *cr)
{
  cairo_set_source_rgb(cr, 0, 0, 0);

      //Get buffer contents
    gchar* contents;
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter (textBuffer, &start);
    gtk_text_buffer_get_end_iter (textBuffer, &end);
    contents = gtk_text_buffer_get_text (textBuffer, &start, &end, FALSE);

    //Init array
    GArray *tableArray;
    gint i;
    tableArray = g_array_new(FALSE, FALSE, sizeof(contents));

    //String to array
    char *token = strtok(contents, " ");
    while (token)
    {
        g_array_append_val(tableArray, token);
        token=strtok(NULL, " ");
    }

    //Table drawing
    drawTable(*tableArray, cr);

    /*
        Take input text, space delimited.
        Iterate through text, use a case to call functions
            CREATE: if next is TABLE, call drawTable(table[i]+2: [domain].[name])
                Row 1: table name
                Row 2: Attribute: / Type: / Flags:
                Row 3: [CNbr] /(space: next cell)/ [varchar](7) / (space: next cell) / NOT NULL / (comma: next line)
                etc
            Look if first character of

        Planned features: query display
    */

    //Translate text to usable data
    //textToTable(contents);


  //cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
  //    CAIRO_FONT_WEIGHT_NORMAL);
  //cairo_set_font_size(cr, 12.0);

  //cairo_move_to(cr, 10.0, 50.0);
  //cairo_show_text(cr, contents);
}

void textToTable(gchar* contents)
{
    gint i=strlen(contents);
    while(i>0)
    {
        //g_array_append_val(tableArray, (int)contents[i]);
        i--;
    }

}

void render()
{
    //Legacy
    //GtkWidget *Table1 = makeTable(5,5);

    //Init array




    //Buffer contents to Array
    //tableArray = textToTable(tableArray, contents);


    //Setup window
    GtkWidget *windowGenerated = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *windowBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *drawingArea = gtk_drawing_area_new();

    gtk_container_add(GTK_CONTAINER(windowGenerated), windowBox);
    gtk_box_pack_start(GTK_BOX(windowBox), drawingArea, 1,1,1);

     g_signal_connect(G_OBJECT(drawingArea), "draw",
      G_CALLBACK(on_draw_event), NULL);


    //Legacy
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

    //Window attribs
    gtk_window_set_default_size(GTK_WINDOW(windowGenerated), 500, 300);
    gtk_window_set_title (GTK_WINDOW (windowGenerated), "Rendered SQL");
    gtk_window_set_position (GTK_WINDOW (windowGenerated), GTK_WIN_POS_CENTER);


    //Display window
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
