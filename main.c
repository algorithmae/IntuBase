/* Intubase, for real this time. */
/* Alexander Medrzycki, August-December 2015 */

#include "main.h"



void connect_signals()
{ //Connecting Signals
  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(quitMi), "activate",
        G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(renderMi), "activate",
        G_CALLBACK(render), NULL);

    g_signal_connect(G_OBJECT(saveMi), "activate",
        G_CALLBACK(SaveFile), NULL);
    g_signal_connect(G_OBJECT(openMi), "activate",
        G_CALLBACK(LoadFile), NULL);

}


int main(int argc, char *argv[]) {


  //Window Init
  gtk_init(&argc, &argv);

  //Build menu
  menugen();

  //Build main window
  windowgen();



  connect_signals();

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}


