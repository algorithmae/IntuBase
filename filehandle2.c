#include "filehandle2.h"

void LoadFile()
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Open File",
                                      GTK_WINDOW(window),
                                      action,
                                      ("Cancel"),
                                      GTK_RESPONSE_CANCEL,
                                      ("Open"),
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        //char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);
        OpenFile (filename);
        g_free (filename);

    }

    gtk_widget_destroy (dialog);
}

void OpenFile(char *fname)
{
    gchar* contents;
    g_file_get_contents(fname, &contents, NULL, NULL);

    //GtkTextIter p;
    gtk_text_buffer_set_text(textBuffer, contents, -1);
    g_free(contents);

}

void SaveFileAs()
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Save File",
                                      GTK_WINDOW(window),
                                      action,
                                      ("Cancel"),
                                      GTK_RESPONSE_CANCEL,
                                      ("Save"),
                                      GTK_RESPONSE_ACCEPT,
                                      NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        //char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);
        SaveFile (filename);
        g_free (filename);

    }

    gtk_widget_destroy (dialog);
}

void SaveFile(char *fname)
{
    gchar* contents;
    GtkTextIter start, end;
    //GtkTextIter p;
    gtk_text_buffer_get_start_iter (textBuffer, &start);
    gtk_text_buffer_get_end_iter (textBuffer, &end);
    contents = gtk_text_buffer_get_text (textBuffer, &start, &end, FALSE);

    g_file_set_contents(fname, contents, -1, NULL);
    g_free(contents);
}


void NewFile()
{
    GtkWidget *dialog;
    //GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_message_dialog_new ( GTK_WINDOW(window),
                                      GTK_DIALOG_MODAL,
                                      GTK_MESSAGE_QUESTION,
                                      GTK_BUTTONS_NONE,
                                      "Are you sure? \n \n Unsaved changes will be deleted!"
                                      );
    gtk_dialog_add_buttons (dialog,
                            ("Cancel"),
                            GTK_RESPONSE_CANCEL,
                            ("OK"),
                            GTK_RESPONSE_ACCEPT,
                            NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        //gchar* contents = "";
        //g_file_get_contents(NULL, &contents, NULL, NULL);

    //GtkTextIter p;
        gtk_text_buffer_set_text(textBuffer, "", -1);
        //g_free(contents);

    }

    gtk_widget_destroy (dialog);
}
