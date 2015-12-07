#include <gtk/gtk.h>
#include "main.h"

void updateEditBuffer()
{
    gchar *tempStr;
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter (textBuffer, &start);
    gtk_text_buffer_get_end_iter (textBuffer, &end);
    tempStr = gtk_text_buffer_get_text (textBuffer, &start, &end, FALSE);
    gtk_text_buffer_set_text(editBuffer, tempStr, -1);
    g_free(tempStr);
}

//void drawCell(){}

/*void drawTable(gchar* inputStr, cairo_t *cr)
{
    //Create first row
    //guint i;
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
      CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size(cr, 12.0);
    cairo_set_source_rgb(cr, 0, 0, 0);
        //Create first row
    //guint i;
    //gchar* tempStr;
    //>>>>>>tempStr = g_queue_pop_head(tableQ);
    cairo_show_text(cr, inputStr);


    //gchar* tempStr;
    /*while(i<g_queue_get_length(tableQ))
    {

        tempStr = g_queue_pop_head(tableQ);
        cairo_show_text(cr, tempStr);
        i++;
        cairo_move_to(cr, 0, (i*20));
    }*/
    //cairo_show_text(cr, contents);
    //Create second row

    //Create additional rows

//}

gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
    gpointer user_data)
{
  do_drawing(cr);

  return FALSE;
}

void do_drawing(cairo_t *cr)
{

    struct tableStr
    {
        gchar* tableName;
        gchar* tableVar1;
        gchar* tableVar2;
    } tableStr1;
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
        CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 12.0);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_move_to(cr, 0.0, 0.0);
    //cairo_show_text(cr, "Test");

    gint tableNumber=0;
    gchar *tempStr;
    GtkTextIter start, end, counter;
    gtk_text_buffer_get_start_iter (editBuffer, &start);
    gtk_text_buffer_get_start_iter (editBuffer, &counter);
    gtk_text_buffer_get_end_iter (editBuffer, &end);


        gtk_text_iter_forward_word_end(&counter);
        tempStr=gtk_text_buffer_get_text(editBuffer, &start, &counter, FALSE);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);
        if (strcmp(tempStr, "CREATE")==0)
        {

            gtk_text_buffer_delete(editBuffer, &start, &counter);
            gtk_text_buffer_get_start_iter (editBuffer, &start);
            gtk_text_buffer_get_end_iter (editBuffer, &end);
            gtk_text_iter_forward_word_end(&counter);
            gtk_text_iter_forward_word_end(&counter);
            tempStr=gtk_text_buffer_get_text(editBuffer, &start, &counter, FALSE);
            tableStr1.tableName = tempStr;
            //gtk_text_buffer_delete(editBuffer, &start, &counter);

                gtk_text_buffer_get_start_iter (editBuffer, &start);
                gtk_text_buffer_get_end_iter (editBuffer, &end);

                cairo_set_source_rgb(cr, 1, 1, 1);
                cairo_rectangle(cr, 0.0, (tableNumber*120), 100.0, 100.0);
                cairo_stroke_preserve(cr);
                cairo_fill(cr);
                cairo_set_source_rgb(cr, 0, 0, 0);
                cairo_move_to(cr, 2.0, (tableNumber*120)+15.0);
                cairo_show_text(cr, tableStr1.tableName);
                tableNumber++;


            }

            //gtk_text_iter_forward_word_end(&counter);
            gtk_text_buffer_get_start_iter (editBuffer, &start);
            gtk_text_buffer_get_end_iter (editBuffer, &end);
            //gtk_text_buffer_delete(editBuffer, &start, &counter);
            gtk_text_buffer_get_start_iter (editBuffer, &start);
            gtk_text_buffer_get_end_iter (editBuffer, &end);
            //gtk_text_iter_forward_word_end(&counter);
        tempStr=gtk_text_buffer_get_text(editBuffer, &start, &counter, FALSE);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);


    while(!gtk_text_iter_equal(&counter, &end))
    {




        //(tableQ, *tempStr);

        //>>>>>>gtk_text_buffer_delete(editBuffer, &start, &counter);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);

        //counterChar = gtk_text_iter_get_char (&counter);
        /*if(&counterChar==" ")
        {
            tempStr = gtk_text_iter_get_text(&start, &counter);
            gtk_text_buffer_delete(editBuffer, &start, &counter);
            g_queue_push_head(tableQ, *tempStr);
        }
        gtk_text_iter_forward_char(&counter);*/
    }

    //DRAW STUFF



        //Create first row
    //guint i;
    //gchar* tempStr;
    //>>>>>>tempStr = g_queue_pop_head(tableQ);
    //>>>>>>cairo_show_text(cr, tempStr);
    /*while(i<g_queue_get_length(tableQ))
    {

        tempStr = g_queue_pop_head(tableQ);
        cairo_show_text(cr, tempStr);
        i++;
        cairo_move_to(cr, 0, (i*20));
    }*/
    //drawTable(tableQ);

      //Get buffer contents
      //updateEditBuffer();
    //editBuffer = textBuffer;
    //gchar* contents;




    //Table drawing
//    drawTable(tableQ, cr);

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
    updateEditBuffer();



    /*while(i<g_queue_get_length(tableQ))
    {
        gchar *tempStr2;
        tempStr2=g_queue_pop_head_link(tableQ);
        gtk_text_buffer_set_text(editBuffer, tempStr2, -1);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);
        //gtk_text_buffer_set_text(editBuffer, &tempStr2, -1);
        //gtk_text_buffer_insert(editBuffer, &end, &tempStr2, -1);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);
        //gtk_text_buffer_insert(editBuffer, &end, "\n", -1);
        gtk_text_buffer_get_start_iter (editBuffer, &start);
        gtk_text_buffer_get_end_iter (editBuffer, &end);
        i++;
    }*/



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
    /*GdkWindow *windowGenerated;    */

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
  rightPane = gtk_scrolled_window_new(NULL, NULL);
  textBuffer = gtk_text_buffer_new(NULL);
  editBuffer = gtk_text_buffer_new(NULL);
  textView = gtk_text_view_new_with_buffer(textBuffer);
  textView2 = gtk_text_view_new_with_buffer(editBuffer);

  gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
  gtk_box_set_homogeneous(GTK_BOX(hbox), TRUE);

  gtk_box_pack_start(GTK_BOX(hbox), leftPane, TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(hbox), rightPane, TRUE, TRUE, 1);

  gtk_container_add(GTK_CONTAINER(leftPane), textView);
  gtk_container_add(GTK_CONTAINER(rightPane), textView2);
  //gtk_box_pack_end(GTK_BOX(vbox), statusbar, TRUE, TRUE, 0);


}
