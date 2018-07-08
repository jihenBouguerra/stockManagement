#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
typedef struct
{
    char E[11];
    char CIN[9];
    char ID[11];
    char MDP[6];
    char NUM[9];
}personne;
typedef struct
{
    int code ;
    char libele[40];
    int quantite;
    int prix;



} produit;
GtkWidget*CodeProduit;
GtkWidget* Prix;
 GtkWidget* Qantite;
 GtkWidget*Libelle;
 GtkWidget* Sousse;
 GtkWidget*ph9;
personne p[10];
personne e;
int nc;
int nps, npa,npt,npb;
produit pro;
produit pa[70];
produit ps[70];
produit pt[70];
produit pb[70];
GtkWidget*CodeProduitg=NULL;
GtkWidget* Tunisg=NULL;
GtkWidget*Ariennag =NULL;
GtkWidget*Bardog=NULL;
GtkWidget* Sousseg=NULL;
char code[40]="";
static void Recherchee(GtkWidget* p_Window,gpointer data);
static void Recherche_clicked(GtkWidget* p_Window,gpointer data);
static void Modifier_Clicked(GtkWidget* p_Window,gpointer data);
static void SupprimerProduit_clicked(GtkWidget* p_Window,gpointer data);
static void Supprime_Clicked(GtkWidget* p_Window,gpointer data);
void cb_quit (GtkWidget *p_widget, gpointer user_data);
static void CNC_clicked(GtkWidget* p_Window,gpointer data);
static void button_clicked(GtkWidget* p_Window,gpointer data);
static void NouveauCompte_clicked(GtkWidget* p_Window,gpointer data);
void retourMenue(GtkWidget *pBtn, gpointer data);
static void Affiche_clicked(GtkWidget* p_Window,gpointer data);
int existeDeja ( );
int existeDeja2 ();
static void ModifierProduit_clicked(GtkWidget* p_Window,gpointer data);
static void Connecter_clicked(GtkWidget* p_Window,gpointer data);
char Pv[20];
static void AjouterProduit_clicked(GtkWidget* p_Window,gpointer data);
void ajoutProduit (GtkWidget *pBtn, gpointer data);
void OnValider(GtkWidget *pBtn, gpointer data);
static void quite (GtkWidget* p_Window,gpointer data);

int main(int argc, char **argv)
{

 FILE* f=NULL; int i;
    f=fopen("ID.txt","r");

    if (f!=NULL)
    {
        fread(&nc,sizeof(int),1,f);
        printf("%i\n",nc);
        for (i=0; i<nc; i++)
        {
            fread(&p[i],sizeof(personne),1,f);
            printf("ID=%s\n",p[i].ID);

        }
     }
fclose(f);
//sousse
FILE* fs=NULL;
FILE *fa=NULL;
FILE* ft=NULL;
FILE * fb=NULL;

    fs=fopen("fs.txt","r");
 if(fs!=NULL)
   {   fread(&nps,sizeof(int),1,fs);
        printf("%i\n",nps);
       for (i=0; i<nps; i++)
        {
             fread(&ps[i],sizeof(produit),1,fs);
              printf("%i\n",ps[i].code);
              printf("%s\n",ps[i].libele);
              printf("%i\n",ps[i].quantite);
              printf("%i\n",ps[i].prix);
              printf("\n----------------------\n");

        }

    }
fclose(fs);
printf("\n******\n");
//arienna
    fa=fopen("fa.txt","r");
 if(fa!=NULL)
   {   fread(&npa,sizeof(int),1,fa);
        printf("%i\n",npa);
       for (i=0; i<npa; i++)
        {
             fread(&pa[i],sizeof(produit),1,fa);
              printf("%i\n",pa[i].code);
              printf("%s\n",pa[i].libele);
              printf("%i\n",pa[i].quantite);
              printf("%i\n",pa[i].prix);
              printf("\n----------------------\n");

        }

    }
fclose(fa);
printf("\n******\n");
//tunis
    ft=fopen("ft.txt","r");
 if(ft!=NULL)
   {   fread(&npt,sizeof(int),1,ft);
        printf("%i\n",npt);
       for (i=0; i<npt; i++)
        {
             fread(&pt[i],sizeof(produit),1,ft);
              printf("%i\n",pt[i].code);
              printf("%s\n",pt[i].libele);
              printf("%i\n",pt[i].quantite);
              printf("%i\n",pt[i].prix);
              printf("\n----------------------\n");

        }

    }
fclose(ft);
 printf("\n******\n");
//bardo
    fb=fopen("fb.txt","r");
 if(fb!=NULL)
   {   fread(&npb,sizeof(int),1,fb);
        printf("%i\n",npb);
       for (i=0; i<npb; i++)
        {
             fread(&pb[i],sizeof(produit),1,fb);
              printf("%i\n",pb[i].code);
              printf("%s\n",pb[i].libele);
              printf("%i\n",pb[i].quantite);
              printf("%i\n",pb[i].prix);
              printf("\n----------------------\n");

        }

    }
fclose(fb);
 printf("\n******\n");
// Initialisation de GTK+
gtk_init(&argc, &argv);
loginWindow();
return EXIT_SUCCESS;
}

static void Connecter_clicked(GtkWidget* p_Window,gpointer data)
{
    GList *pList;
    GtkWidget *pTempEntry;
    gchar *sText;
    pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data));

    pList = g_list_next(pList);
    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.ID,sText);
    sText ="";
    pList = g_list_next(pList);

    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.MDP,sText);
    printf("%s", e.ID);
    printf("%s", e.MDP);
  if ( existeDeja2 ()==0)
    {

        pList = g_list_next(pList);
        pList = g_list_next(pList);
        pTempEntry = GTK_WIDGET(pList->data);
        gchar* TexteConverti =NULL;
        if (strcmp(e.ID,"")==0||strcmp(e.MDP,"")==0 )
            gtk_label_set_text(GTK_ENTRY(pTempEntry),"remplir touts les champs ");
        else
            gtk_label_set_text(GTK_ENTRY(pTempEntry),"Mdp ou psodo invalide");




    }
else
{
    //main window
        GtkWidget * Menue = NULL;
        Menue = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        //Proprietes menue window

        //gtk_window_maximize(GTK_WINDOW(Menue));
        gtk_window_set_title(GTK_WINDOW(Menue), "gestion de stock");
        g_signal_connect(G_OBJECT(Menue), "destroy", G_CALLBACK(gtk_main_quit), NULL);

         //Titre 1
        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>gestion de stock</b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //bouton ajouter
        GtkWidget * AjouterProduit= NULL;
        AjouterProduit= gtk_button_new_with_label("Ajouter Produit");
        //boutton modifier
        GtkWidget * Modifier= NULL;
        Modifier= gtk_button_new_with_label("Modifier les Info");
        //bouton supprimer
        GtkWidget * SupprimerProduit= NULL;
        SupprimerProduit= gtk_button_new_with_label("Supprimer un produit");
        //bouton recharche
        GtkWidget * Recherche= NULL;
        Recherche= gtk_button_new_with_label("Recherche");
         //bouton quitter
        GtkWidget *Quitter = NULL;
        Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
        g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), Menue);
        //box
        GtkWidget* b=NULL;
        b= gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(Menue), b);

        gtk_box_pack_start(b,T, TRUE ,TRUE,0);
        gtk_box_pack_start(b,AjouterProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Modifier, TRUE ,TRUE,0);
        gtk_box_pack_start(b,SupprimerProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Recherche, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Quitter, TRUE ,TRUE,0);


        gtk_widget_show_all(Menue);
        gtk_widget_hide(GTK_WINDOW(data));
        g_signal_connect(GTK_WIDGET(AjouterProduit), "clicked", G_CALLBACK(AjouterProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Modifier), "clicked", G_CALLBACK(ModifierProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(SupprimerProduit), "clicked", G_CALLBACK(SupprimerProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Recherche), "clicked", G_CALLBACK(Recherche_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Quitter), "clicked", G_CALLBACK(Recherche_clicked),(GtkWidget*)Menue);
        GtkWidget *pWindow;
        pWindow = gtk_widget_get_toplevel(GTK_WIDGET(data));
        gtk_widget_hide(GTK_WINDOW(pWindow));




}
}



// nouveau compte
static void CNC_clicked(GtkWidget* p_Window,gpointer data)
{

    GtkWidget * NouveauCompteWindow = NULL;
    NouveauCompteWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

            //Proprietes page 2
            //gtk_window_maximize(GTK_WINDOW(NouveauCompteWindow));
            gtk_window_set_title(GTK_WINDOW(NouveauCompteWindow), "gestion de stock");
            g_signal_connect(G_OBJECT(NouveauCompteWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

                //Titre 1

                GtkWidget* T = NULL;
                gchar* TexteConverti =NULL;
                TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>gestion de stock</b></span>\n",-1, NULL, NULL, NULL);
                T=gtk_label_new (TexteConverti);
                gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
                g_free(TexteConverti);

                //ph1

                GtkWidget*ph1=NULL;
                ph1= gtk_label_new("le nom de l'entreprise ");
                gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);

                //Nom entreprise
                GtkWidget*Ese=NULL;
                Ese=gtk_entry_new();

                //ph2
                GtkWidget*ph2=NULL;
                ph2= gtk_label_new("Entrer  Votre CIN : ");
                gtk_label_set_justify(ph2, GTK_JUSTIFY_LEFT);

                //CIN
                GtkWidget*CIN=NULL;
                CIN=gtk_entry_new();

                //ph3
                GtkWidget*ph3=NULL;
                ph3= gtk_label_new("entrer le psodo");
                gtk_label_set_justify(ph3, GTK_JUSTIFY_LEFT);
                //ID
                GtkWidget*ID=NULL;
                ID=gtk_entry_new();

                //ph4
                GtkWidget*ph4=NULL;
                ph4= gtk_label_new("Entrer le Mot de passe : ");
                gtk_label_set_justify(ph4, GTK_JUSTIFY_LEFT);

                //MDP
                GtkWidget*Mdp=NULL;
                Mdp=gtk_entry_new();

                //ph5
                GtkWidget*ph5=NULL;
                ph5= gtk_label_new("Num de telephone ");
                gtk_label_set_justify(ph5, GTK_JUSTIFY_LEFT);

                //NUM
                GtkWidget*Num=NULL;
                Num=gtk_entry_new();

                //bouton creer nouveau compte
                 GtkWidget *NouveauCompte= NULL;
                 NouveauCompte= gtk_button_new_with_label("Creer nouveau compte");
                 //bouton quitter
                GtkWidget *Quitter = NULL;
                Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
                g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);



                //boxes
                   //box1
                 GtkWidget* b1=NULL;
                 b1= gtk_vbox_new(TRUE,0);
                 gtk_container_add(GTK_CONTAINER( NouveauCompteWindow ), b1);
                 gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,Ese, TRUE,TRUE,0);
                 gtk_box_pack_start(b1,ph2, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,CIN, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph3, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ID, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph4, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,Mdp, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph5, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,Num, TRUE ,TRUE,0);

                //box2
                 GtkWidget* b2=NULL;
                 b2= gtk_hbox_new(TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), b2, TRUE, TRUE, 0);

                 gtk_box_pack_start(b2,NouveauCompte, TRUE ,TRUE,0);
                 gtk_box_pack_start(b2,Quitter, TRUE ,TRUE,0);



gtk_widget_hide(GTK_WINDOW(data));
gtk_widget_show_all( NouveauCompteWindow );


g_signal_connect(GTK_WIDGET(NouveauCompte), "clicked", G_CALLBACK(NouveauCompte_clicked),(GtkWidget*)b1);




}


int existeDeja ()
{

     int i=0 ,tr=0;
   while (i< nc && tr==0)
    {

        if (strcmp(p[i].ID,e.ID)==0 ||strcmp(e.ID,"")==0 )
            tr=1;
        i++;
    }
    if (tr==1)
      {
           printf("existe deja \n");
           return 0;
      }
    else
    {
            FILE* f=NULL;
            f=fopen("ID.txt","w");

            if (f!=NULL)
                {
                    p[nc]=e;
                    nc++;
                    fwrite(&nc,sizeof(int),1,f);
                        for (i=0; i<nc; i++)
                        fwrite(&p[i],sizeof(personne),1,f);

                    return 1;
                    fclose(f);

                }


    }

}
static void NouveauCompte_clicked(GtkWidget* p_Window,gpointer data)
{
    GList *pList;
    GtkWidget *pTempEntry;
    gchar *sText;
    /* Recuperation de la liste des elements que contient la GtkVBox */
    pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data));

    pList = g_list_next(pList);// title
    pList = g_list_next(pList);// ph Ese
    pTempEntry = GTK_WIDGET(pList->data); //E
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.E,sText);
    sText ="";
    pList = g_list_next(pList);
    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.CIN,sText);
    sText="";
    pList = g_list_next(pList);
    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.ID,sText);
    sText="";
    pList = g_list_next(pList);
    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.MDP,sText);
    sText="";
    pList = g_list_next(pList);
    pList = g_list_next(pList);
    pTempEntry = GTK_WIDGET(pList->data);
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
    strcpy(e.NUM,sText);

if ( existeDeja ()==1)
            {
                GtkWidget * Menue = NULL;
                Menue = gtk_window_new(GTK_WINDOW_TOPLEVEL);


                gtk_window_set_title(GTK_WINDOW(Menue), "gestion de stock");
                g_signal_connect(G_OBJECT(Menue), "destroy", G_CALLBACK(gtk_main_quit),FALSE);



        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>gestion de stock</b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //bouton ajouter
        GtkWidget * AjouterProduit= NULL;
        AjouterProduit= gtk_button_new_with_label("Ajouter Produit");
        //boutton modifier
        GtkWidget * Modifier= NULL;
        Modifier= gtk_button_new_with_label("Modifier les Info");
        //bouton supprimer
        GtkWidget * SupprimerProduit= NULL;
        SupprimerProduit= gtk_button_new_with_label("Supprimer un produit");
        //bouton recharche
        GtkWidget * Recherche= NULL;
        Recherche= gtk_button_new_with_label("Recherche");
         //bouton quitter
        GtkWidget *Quitter = NULL;
        Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
        g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
        //box
        GtkWidget* b=NULL;
        b= gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(Menue), b);

        gtk_box_pack_start(b,T, TRUE ,TRUE,0);
        gtk_box_pack_start(b,AjouterProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Modifier, TRUE ,TRUE,0);
        gtk_box_pack_start(b,SupprimerProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Recherche, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Quitter, TRUE ,TRUE,0);
        g_signal_connect(GTK_WIDGET(AjouterProduit), "clicked", G_CALLBACK(AjouterProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Modifier), "clicked", G_CALLBACK(ModifierProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(SupprimerProduit), "clicked", G_CALLBACK(SupprimerProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Recherche), "clicked", G_CALLBACK(Recherche_clicked),(GtkWidget*)Menue);


         GtkWidget *pWindow;
        pWindow = gtk_widget_get_toplevel(GTK_WIDGET(data));


        gtk_widget_show_all(Menue);
        gtk_widget_hide(GTK_WINDOW(pWindow));



            }
            else
            {
                gchar *sSite;
                 GtkWidget *pAbout;
                 if (strcmp(e.CIN,"")==0||strcmp(e.E,"")==0|| strcmp(e.NUM,"")==0|| strcmp(e.ID,"")==0|| strcmp(e.MDP,"")==0)
                sSite = "Romplir tt les champ";
                else
               {
                sSite = "ID existe deja ";
                GtkWidget *pWindow;
                pWindow = gtk_widget_get_toplevel(GTK_WIDGET(data));


                pAbout = gtk_message_dialog_new (GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,sSite);

                gtk_dialog_run(GTK_DIALOG(pAbout));
                gtk_widget_destroy(pAbout);
               }


                    }
}


int existeDeja2 ()
{

     int i=0 ,tr=0;
   while (i< nc && tr==0)
    {

        if (strcmp(p[i].ID,e.ID)==0 &&strcmp(p[i].MDP,e.MDP)==0)
            tr=1;
        i++;
    }
    if (tr==0)
      {
           printf("Mdp ou psodo invalid \n");
           return 0;
      }
    else
        return 1;


}
static void AjouterProduit_clicked(GtkWidget* p_Window,gpointer data)
{
    //main window
        GtkWidget * AjouterProduitWindow = NULL;
        AjouterProduitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        //Proprietes main window

        gtk_window_maximize(GTK_WINDOW(AjouterProduitWindow));
        gtk_window_set_title(GTK_WINDOW(AjouterProduitWindow), "Ajouter un produit");
        g_signal_connect(G_OBJECT(AjouterProduitWindow), "destroy", G_CALLBACK(gtk_main_quit), TRUE);
        // //Titre

        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>Ajouter Produit</b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //ph1
        GtkWidget*ph1=NULL;
        ph1= gtk_label_new("Point de vante ");
        gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);

        //sousse

        Sousse= gtk_radio_button_new_with_label(NULL, "Sousse");
       //Tunisie
        GtkWidget* Tunisie = NULL;
        Tunisie= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Tunisie");
        //Ariana
        GtkWidget* Ariana = NULL;
        Ariana= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Arienna");
       //Bardo
        GtkWidget* Bardo = NULL;
        Bardo= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Bardo");

        //ph2
        GtkWidget*ph2=NULL;
        ph2= gtk_label_new("Le code du produit ");
        gtk_label_set_justify(ph2, GTK_JUSTIFY_FILL);
        //CODE PRODUIT

        CodeProduit=gtk_entry_new();
        //ph3
        GtkWidget*ph3=NULL;
        ph3= gtk_label_new("Libelle du produit ");
        gtk_label_set_justify(ph3, GTK_JUSTIFY_FILL);
        //libelle

        Libelle=gtk_entry_new();
        //ph4
        GtkWidget*ph4=NULL;
        ph4= gtk_label_new("Quantite Disponible ");
        gtk_label_set_justify(ph4, GTK_JUSTIFY_FILL);
        //Quantite

        Qantite=gtk_entry_new();
        //ph5
        GtkWidget*ph5=NULL;
        ph5= gtk_label_new("Prix du Produit ");
        gtk_label_set_justify(ph5,GTK_JUSTIFY_FILL);
        //l

        ph9= gtk_label_new(" ");
        gtk_label_set_justify(ph9, GTK_JUSTIFY_LEFT);
        //prix

        Prix=gtk_entry_new();
         //bouton quitter
        GtkWidget *Quitter = NULL;
        Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
        g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
        //bouton Retour
        GtkWidget * Retour = NULL;
        Retour= gtk_button_new_with_label("Retour a menue ");

        //bouton Ajouter
        GtkWidget * Ajouter = NULL;
        Ajouter= gtk_button_new_with_label("Ajouter  ");
        //bt Affiche
        GtkWidget * Affiche = NULL;
        Affiche= gtk_button_new_with_label("Affiche");

                    //

        //box1
                 GtkWidget* b1=NULL;
                 b1= gtk_vbox_new(FALSE,0);
                 gtk_container_add(GTK_CONTAINER(AjouterProduitWindow), b1);
                 gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
                 GtkWidget* b=NULL;
                    b= gtk_hbox_new(TRUE,0);
                    gtk_box_pack_start(b,Sousse, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Ariana, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Tunisie, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Bardo, TRUE ,TRUE,0);

                    GtkWidget* a=NULL;
                    a= gtk_vbox_new(FALSE,0);


                 gtk_box_pack_start(GTK_BOX(b1), b,TRUE ,TRUE, 0);
                 gtk_box_pack_start(a,ph2, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,CodeProduit, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph3, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Libelle,TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph4, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Qantite, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph5,TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Prix, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph9, TRUE ,TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), a,TRUE ,TRUE,0);


                 //box2
                 GtkWidget* b2=NULL;
                 b2= gtk_hbox_new(TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), b2,FALSE,FALSE, 0);
               //  gtk_box_pack_start(b2,Valider, TRUE ,TRUE,0);
                 gtk_box_pack_start(b2,Ajouter,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Retour,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Quitter,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Affiche,FALSE,FALSE,0);


gtk_widget_show_all(AjouterProduitWindow);
gtk_widget_hide(GTK_WINDOW(data));
//g_signal_connect(G_OBJECT(Valid), "clicked", G_CALLBACK(OnValider), Sousse);
g_signal_connect(G_OBJECT(Ajouter), "clicked", G_CALLBACK(ajoutProduit), Sousse);
g_signal_connect(G_OBJECT(Retour), "clicked", G_CALLBACK(retourMenue),AjouterProduitWindow);
g_signal_connect(GTK_WIDGET(Affiche), "clicked", G_CALLBACK(Affiche_clicked),NULL);



}
void retourMenue(GtkWidget *pBtn, gpointer data)
{

        GtkWidget * Menue = NULL;
        Menue = gtk_window_new(GTK_WINDOW_TOPLEVEL);



        //gtk_window_maximize(GTK_WINDOW(Menue));
        gtk_window_set_title(GTK_WINDOW(Menue), "gestion de stock");
        g_signal_connect(G_OBJECT(Menue), "destroy", G_CALLBACK(gtk_main_quit),FALSE);

        // //Titre 1

        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>gestion de stock</b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //bouton ajouter
        GtkWidget * AjouterProduit= NULL;
        AjouterProduit= gtk_button_new_with_label("Ajouter Produit");
        //boutton modifier
        GtkWidget * Modifier= NULL;
        Modifier= gtk_button_new_with_label("Modifier les Info");
        //bouton supprimer
        GtkWidget * SupprimerProduit= NULL;
        SupprimerProduit= gtk_button_new_with_label("Supprimer un produit");
        //bouton recharche
        GtkWidget * Recherche= NULL;
        Recherche= gtk_button_new_with_label("Recherche");
         //bouton quitter
        GtkWidget *Quitter = NULL;
        Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
        g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
        //box
        GtkWidget* b=NULL;
        b= gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(Menue), b);

        gtk_box_pack_start(b,T, TRUE ,TRUE,0);
        gtk_box_pack_start(b,AjouterProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Modifier, TRUE ,TRUE,0);
        gtk_box_pack_start(b,SupprimerProduit, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Recherche, TRUE ,TRUE,0);
        gtk_box_pack_start(b,Quitter, TRUE ,TRUE,0);


        gtk_widget_show_all(Menue);
        gtk_widget_hide(GTK_WINDOW(data));
        g_signal_connect(GTK_WIDGET(AjouterProduit), "clicked", G_CALLBACK(AjouterProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Modifier), "clicked", G_CALLBACK(ModifierProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(SupprimerProduit), "clicked", G_CALLBACK(SupprimerProduit_clicked),(GtkWidget*)Menue);
        g_signal_connect(GTK_WIDGET(Recherche), "clicked", G_CALLBACK(Recherche_clicked),(GtkWidget*)Menue);

      //  gtk_widget_hide(GTK_WINDOW(data));


}

void ajoutProduit (GtkWidget *pBtn, gpointer data)
{

    gchar *sText;

    sText = gtk_entry_get_text(CodeProduit);
    pro.code =atoi(sText);
    sText ="";

    sText = gtk_entry_get_text(GTK_ENTRY(Libelle));
    strcpy(pro.libele,sText);
    sText="";

    sText = gtk_entry_get_text(GTK_ENTRY(Qantite));
    pro.quantite = atoi(sText);
    sText="";

    sText = gtk_entry_get_text(GTK_ENTRY(Prix));
    pro.prix = atoi(sText);
gtk_label_set_text(GTK_ENTRY(ph9), "");



                 /*printf("%i\n",pro.code);
                 printf("%s\n",pro.libele);
                 printf("%i\n",pro.quantite);
                 printf("%i\n",pro.prix);*/


    GSList *pList;
    const gchar *sLabel;


    pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(data));
    while(pList)
    {
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
        {

            sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
            strcpy(Pv,sLabel);

            pList = NULL;
        }
        else
        {

            pList = g_slist_next(pList);
        }
    }


    if (pro.prix==0|| pro.quantite==0|| pro.code ==0 || strcmp(pro.libele,"")==0)
    {
        gtk_label_set_text(GTK_ENTRY(ph9), "Remplir les champs");


    }
    else
    {
        FILE *f=NULL; int j;
    if (strcmp(Pv,"Sousse")==0)
        {

               if (produitExiste(nps,ps,  pro)== -2)
                {
                    f=fopen("fs.txt","w");
                    if (f!=NULL)
                        {

                                ps[nps]=pro;
                                nps++;
                                fwrite(&nps,sizeof(int),1,f);
                                for(j=0; j<nps; j++)
                                fwrite(&ps[j],sizeof(produit),1,f);
                                gtk_label_set_text(GTK_ENTRY(ph9), "Produit Ajoute au pt vante sousse");
                         }
                  fclose(f);

                }
                else
               {
                   gtk_label_set_text(GTK_ENTRY(ph9), "Produit existe Deja");
               }


            }
    else
       {
           if (strcmp(Pv,"Tunisie")==0)
           {
                if (produitExiste(npt,pt,  pro)== -2)
                {
                    f=fopen("ft.txt","w");
                    if (f!=NULL)
                        {

                                pt[npt]=pro;
                                npt++;
                                fwrite(&npt,sizeof(int),1,f);
                                for(j=0; j<npt; j++)
                                fwrite(&pt[j],sizeof(produit),1,f);
                                gtk_label_set_text(GTK_ENTRY(ph9), "Produit Ajoute au pt vante Tunis");
                         }
                  fclose(f);
                }
                else
                gtk_label_set_text(GTK_ENTRY(ph9), "Produit existe Deja");
           }

         else
            {
                if (strcmp(Pv,"Arienna")==0)
                {
                    if (produitExiste(npa,pa,  pro)==-2)
                        {
                            f=fopen("fa.txt","w");
                            if (f!=NULL)
                                {

                                        pa[npa]=pro;
                                        npa++;
                                        fwrite(&npa,sizeof(int),1,f);
                                        for(j=0; j<npa; j++)
                                        fwrite(&pa[j],sizeof(produit),1,f);
                                        gtk_label_set_text(GTK_ENTRY(ph9), "Produit Ajoute au pt vante Arienna");
                                 }
                          fclose(f);
                        }
                        else
                        gtk_label_set_text(GTK_ENTRY(ph9), "Produit existe Deja");
                }


                else
                {
                     if (strcmp(Pv,"Bardo")==0)
                     {
                         if (produitExiste(npb,pb,  pro)==-2)
                        {
                            f=fopen("fb.txt","w");
                            if (f!=NULL)
                                {

                                        pb[npb]=pro;
                                        npb++;
                                        fwrite(&npb,sizeof(int),1,f);
                                        for(j=0; j<npb; j++)
                                        fwrite(&pb[j],sizeof(produit),1,f);
                                        gtk_label_set_text(GTK_ENTRY(ph9), "Produit Ajoute au pt vante Bardo");
                                 }
                          fclose(f);
                        }
                        else
                        gtk_label_set_text( GTK_LABEL(ph9), "Produit existe Deja");
                     }


    }


                }
            }

       }
strcmp(Pv,"");

}
//quit
void cb_quit (GtkWidget *p_widget, gpointer data)
{
  GtkWidget *pQuestion;

    /* Création de la boite de message */
    /* Type : Question -> GTK_MESSAGE_QUESTION */
    /* Boutons : 1 OUI, 1 NON -> GTK_BUTTONS_YES_NO */
    pQuestion = gtk_message_dialog_new (GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_YES_NO,
        "Voulez-vous vraiment\nquitter ce programme?");

    /* Affichage et attente d une réponse */
    switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
    {
        case GTK_RESPONSE_YES:
            /* OUI -> on quitte l application */
            gtk_main_quit();
            break;
        case GTK_RESPONSE_NO:
            /* NON -> on détruit la boite de message */
            gtk_widget_destroy(pQuestion);
            break;
    }



}

int produitExiste(int n, produit ps[70], produit pro)
{
    int i=0,tr=0;
    while (i<n && tr==0)
    {
        if(pro.code==ps[i].code)
            tr=1;
        i++;
    }
    if (tr==0)
        return -2;
    else
        return i-1;
}
static void ModifierProduit_clicked(GtkWidget* p_Window,gpointer data)
{


//main window
        GtkWidget * ModifirtProduitWindow = NULL;
        ModifirtProduitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        //Proprietes main window

        gtk_window_maximize(GTK_WINDOW(ModifirtProduitWindow));
        gtk_window_set_title(GTK_WINDOW(ModifirtProduitWindow), "Modifier produit");
        g_signal_connect(G_OBJECT(ModifirtProduitWindow), "destroy", G_CALLBACK(gtk_main_quit), TRUE);
        // //Titre

        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>Modifier Produit</b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //ph1
        GtkWidget*ph1=NULL;
        ph1= gtk_label_new("Point de vante ");
        gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);

        //sousse

        Sousse= gtk_radio_button_new_with_label(NULL, "Sousse");
       //Tunisie
        GtkWidget* Tunisie = NULL;
        Tunisie= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Tunisie");
        //Ariana
        GtkWidget* Ariana = NULL;
        Ariana= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Arienna");
       //Bardo
        GtkWidget* Bardo = NULL;
        Bardo= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Bardo");

        //ph2
        GtkWidget*ph2=NULL;
        ph2= gtk_label_new("Le code du produit ");
        gtk_label_set_justify(ph2, GTK_JUSTIFY_FILL);
        //CODE PRODUIT

        CodeProduit=gtk_entry_new();
        //ph3
        GtkWidget*ph3=NULL;
        ph3= gtk_label_new("Libelle du produit ");
        gtk_label_set_justify(ph3, GTK_JUSTIFY_FILL);
        //libelle

        Libelle=gtk_entry_new();
        //ph4
        GtkWidget*ph4=NULL;
        ph4= gtk_label_new("Quantite Disponible ");
        gtk_label_set_justify(ph4, GTK_JUSTIFY_FILL);
        //Quantite

        Qantite=gtk_entry_new();
        //ph5
        GtkWidget*ph5=NULL;
        ph5= gtk_label_new("Prix du Produit ");
        gtk_label_set_justify(ph5,GTK_JUSTIFY_FILL);
        //l

        ph9= gtk_label_new(" ");
        gtk_label_set_justify(ph9, GTK_JUSTIFY_LEFT);
        //prix

        Prix=gtk_entry_new();
         //bouton quitter
        GtkWidget *Quitter = NULL;
        Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
        g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
        //bouton Retour
        GtkWidget * Retour = NULL;
        Retour= gtk_button_new_with_label("Retour a menue ");

        //bouton Modifier
        GtkWidget *Modifier = NULL;
        Modifier= gtk_button_new_with_label("Modifier ");
        //bt Affiche
        GtkWidget * Affiche = NULL;
        Affiche= gtk_button_new_with_label("Affiche");

                    //

        //box1
                 GtkWidget* b1=NULL;
                 b1= gtk_vbox_new(FALSE,0);
                 gtk_container_add(GTK_CONTAINER(ModifirtProduitWindow), b1);
                 gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
                 GtkWidget* b=NULL;
                    b= gtk_hbox_new(TRUE,0);
                    gtk_box_pack_start(b,Sousse, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Ariana, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Tunisie, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Bardo, TRUE ,TRUE,0);

                    GtkWidget* a=NULL;
                    a= gtk_vbox_new(FALSE,0);


                 gtk_box_pack_start(GTK_BOX(b1), b,TRUE ,TRUE, 0);
                 gtk_box_pack_start(a,ph2, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,CodeProduit, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph3, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Libelle,TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph4, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Qantite, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph5,TRUE ,TRUE,0);
                 gtk_box_pack_start(a,Prix, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,ph9, TRUE ,TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), a,TRUE ,TRUE,0);


                 //box2
                 GtkWidget* b2=NULL;
                 b2= gtk_hbox_new(TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), b2,FALSE,FALSE, 0);
               //  gtk_box_pack_start(b2,Valider, TRUE ,TRUE,0);
                 gtk_box_pack_start(b2,Modifier,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Retour,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Quitter,FALSE,FALSE,0);
                 gtk_box_pack_start(b2,Affiche,FALSE,FALSE,0);


gtk_widget_show_all(ModifirtProduitWindow);
gtk_widget_hide(GTK_WINDOW(data));

g_signal_connect(G_OBJECT(Modifier), "clicked", G_CALLBACK(Modifier_Clicked), Sousse);
g_signal_connect(G_OBJECT(Retour), "clicked", G_CALLBACK(retourMenue),ModifirtProduitWindow);
g_signal_connect(GTK_WIDGET(Affiche), "clicked", G_CALLBACK(Affiche_clicked),NULL);
}
static void Modifier_Clicked(GtkWidget* p_Window,gpointer data)
{

    gchar *sText;

    sText = gtk_entry_get_text(CodeProduit);
    pro.code =atoi(sText);
    sText ="";

    sText = gtk_entry_get_text(GTK_ENTRY(Libelle));
    strcpy(pro.libele,sText);
    sText="";

    sText = gtk_entry_get_text(GTK_ENTRY(Qantite));
    pro.quantite = atoi(sText);
    sText="";

    sText = gtk_entry_get_text(GTK_ENTRY(Prix));
    pro.prix = atoi(sText);
gtk_label_set_text(GTK_ENTRY(ph9), "");



                 /*printf("%i\n",pro.code);
                 printf("%s\n",pro.libele);
                 printf("%i\n",pro.quantite);
                 printf("%i\n",pro.prix);*/


    GSList *pList;
    const gchar *sLabel;


    pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(data));
    while(pList)
    {
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
        {

            sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
            strcpy(Pv,sLabel);

            pList = NULL;
        }
        else
        {

            pList = g_slist_next(pList);
        }
    }


    if (pro.prix==0|| pro.quantite==0|| pro.code ==0 || strcmp(pro.libele,"")==0)
    {
        gtk_label_set_text(GTK_ENTRY(ph9), "Remplir les champs");


    }
    else
    {
            FILE *f=NULL; int j;
                if (strcmp(Pv,"Sousse")==0)
                    {

                           if (produitExiste(nps,ps,  pro)!= -2)
                            {
                                f=fopen("fs.txt","w");
                                if (f!=NULL)
                                    {

                                            ps[produitExiste(nps,ps,  pro)]=pro;
                                            fwrite(&nps,sizeof(int),1,f);
                                            for(j=0; j<nps; j++)
                                            fwrite(&ps[j],sizeof(produit),1,f);
                                            gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans sousse");
                                     }
                              fclose(f);
                            }
                            else
                            gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans le pnt vante sousse");


                        }
                else
                   {
                       if (strcmp(Pv,"Tunisie")==0)
                       {
                            if (produitExiste(npt,pt,  pro)!= -2)
                            {
                                f=fopen("ft.txt","w");
                                if (f!=NULL)
                                    {

                                            pt[produitExiste(npt,pt,  pro)]=pro;

                                            fwrite(&npt,sizeof(int),1,f);
                                            for(j=0; j<npt; j++)
                                            fwrite(&pt[j],sizeof(produit),1,f);
                                            gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans Tunis");
                                     }
                              fclose(f);
                            }
                            else
                            gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans le pnt vante Tunis");
                       }

                     else
                        {
                            if (strcmp(Pv,"Arienna")==0)
                            {
                                if (produitExiste(npa,pa,  pro)!=-2)
                                    {
                                        f=fopen("fa.txt","w");
                                        if (f!=NULL)
                                            {

                                                    pa[produitExiste(npa,pa,  pro)]=pro;
                                                    fwrite(&npa,sizeof(int),1,f);
                                                    for(j=0; j<npa; j++)
                                                    fwrite(&pa[j],sizeof(produit),1,f);
                                                    gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans Arriena");
                                             }
                                      fclose(f);
                                    }
                                    else
                                    gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans Arienna");
                            }


                            else
                            {
                                if (produitExiste(npb,pb,  pro)!=-2)
                                    {
                                        f=fopen("fb.txt","w");
                                        if (f!=NULL)
                                            {

                                                    pb[produitExiste(npb,pb,  pro)]=pro;
                                                    fwrite(&npb,sizeof(int),1,f);
                                                    for(j=0; j<npb; j++)
                                                    fwrite(&pb[j],sizeof(produit),1,f);
                                                    gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans Bardo");
                                             }
                                      fclose(f);
                                    }
                                    else
                                    gtk_label_set_text(GTK_ENTRY(ph9), "information modifie dans Bardo");

                            }
                        }

                   }}
strcmp(Pv,"");
}
static void SupprimerProduit_clicked(GtkWidget* p_Window,gpointer data)
{
    //main window
        GtkWidget * SupprimerProduitWindow = NULL;
         SupprimerProduitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        //Proprietes main window

       // gtk_window_maximize(GTK_WINDOW(SupprimerProduitWindow));
        gtk_window_set_title(GTK_WINDOW( SupprimerProduitWindow), "Supprimer un produit ");
        g_signal_connect(G_OBJECT( SupprimerProduitWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_default_size(GTK_WINDOW(SupprimerProduitWindow),400,500);
        // //Titre

        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>supprimer un produit </b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);
        //ph1
        GtkWidget*ph1=NULL;
        ph1= gtk_label_new("Point de vante ");
        gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);

        //sousse
        GtkWidget* Sousse = NULL;
        Sousse= gtk_radio_button_new_with_label(NULL, "Sousse");
       //Tunisie
        GtkWidget* Tunisie = NULL;
        Tunisie= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Tunisie");
        //Ariana
        GtkWidget* Ariana = NULL;
        Ariana= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Arienna");
       //Bardo
        GtkWidget* Bardo = NULL;
        Bardo= gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (Sousse), "Bardo");

        //ph2
        GtkWidget*ph2=NULL;
        ph2= gtk_label_new("Le code du produit ");
        gtk_label_set_justify(ph2, GTK_JUSTIFY_LEFT);
        //CODE PRODUIT


        CodeProduit=gtk_entry_new();
        ph9= gtk_label_new(" ");

        //bouton Retour
        GtkWidget * Retour = NULL;
        Retour= gtk_button_new_with_label("Retour a menue ");
   GtkWidget *Quitter = NULL;
                Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
                g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
        //bouton supprimer
        GtkWidget * Supprimer = NULL;
       Supprimer = gtk_button_new_with_label("Supprimer");
       //bt Affiche
        GtkWidget * Affiche = NULL;
        Affiche= gtk_button_new_with_label("Affiche");

        //box1
                 GtkWidget* b1=NULL;
                 b1= gtk_vbox_new(TRUE,0);
                 gtk_container_add(GTK_CONTAINER(SupprimerProduitWindow), b1);
                 gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
                 GtkWidget* b=NULL;
                    b= gtk_hbox_new(TRUE,0);
                    gtk_box_pack_start(b,Sousse, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Ariana, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Tunisie, TRUE ,TRUE,0);
                    gtk_box_pack_start(b,Bardo, TRUE ,TRUE,0);

                    //
                    GtkWidget* a=NULL;
                    a= gtk_vbox_new(TRUE,0);


                 gtk_box_pack_start(GTK_BOX(b1), b, TRUE, TRUE, 0);
                 gtk_box_pack_start(a,ph2, TRUE ,TRUE,0);
                 gtk_box_pack_start(a,CodeProduit, TRUE ,TRUE,0);

                 gtk_box_pack_start(a,ph9, TRUE ,TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), a, TRUE, TRUE, 0);


                 //box2
                 GtkWidget* b2=NULL;
                 b2= gtk_hbox_new(TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), b2, TRUE, TRUE, 0);

                 gtk_box_pack_start(b2,Supprimer, FALSE ,FALSE,0);
                 gtk_box_pack_start(b2,Retour, FALSE ,FALSE,0);
                 gtk_box_pack_start(b2,Quitter, FALSE ,FALSE,0);
                  gtk_box_pack_start(b2,Affiche, FALSE ,FALSE,0);


        gtk_widget_show_all(SupprimerProduitWindow);
        gtk_widget_hide(GTK_WINDOW(data));

      g_signal_connect(G_OBJECT(Supprimer), "clicked", G_CALLBACK(Supprime_Clicked), Sousse);
g_signal_connect(GTK_WIDGET(Affiche), "clicked", G_CALLBACK(Affiche_clicked),NULL);
g_signal_connect(G_OBJECT(Retour), "clicked", G_CALLBACK(retourMenue),SupprimerProduitWindow);
}

static void Supprime_Clicked(GtkWidget* p_Window,gpointer data)
{
    gchar *sText;
    sText = gtk_entry_get_text(CodeProduit);
    pro.code =atoi(sText);

     GSList *pList;
    const gchar *sLabel;


    pList = gtk_radio_button_get_group(GTK_RADIO_BUTTON(data));
    while(pList)
    {
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(pList->data)))
        {

            sLabel = gtk_button_get_label(GTK_BUTTON(pList->data));
            strcpy(Pv,sLabel);

            pList = NULL;
        }
        else
        {

            pList = g_slist_next(pList);
        }
    }



    if (pro.code==0)
    {

        gtk_label_set_text(GTK_LABEL(ph9), "Remplir le code ");

    }
    else
    {
        FILE *f=NULL; int j;
    if (strcmp(Pv,"Sousse")==0)
        {

               if (produitExiste(nps,ps,  pro)!= -2)
                {
                    f=fopen("fs.txt","w");
                    if (f!=NULL)
                        {

                                ps[produitExiste(nps,ps,  pro)]=ps[nps-1];
                                nps--;
                                fwrite(&nps,sizeof(int),1,f);
                                for(j=0; j<nps; j++)
                                fwrite(&ps[j],sizeof(produit),1,f);
                                gtk_label_set_text(GTK_ENTRY(ph9), "suppretion de sousse");
                         }
                  fclose(f);
                }
                else
                gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans sousse");


            }
    else
       {
           if (strcmp(Pv,"Tunisie")==0)
           {
                if (produitExiste(npt,pt,  pro)!= -2)
                {
                    f=fopen("ft.txt","w");
                    if (f!=NULL)
                        {

                                pt[produitExiste(npt,pt,  pro)]=pt[npt-1];
                                npt--;
                                fwrite(&npt,sizeof(int),1,f);
                                for(j=0; j<npt; j++)
                                fwrite(&pt[j],sizeof(produit),1,f);
                                gtk_label_set_text(GTK_ENTRY(ph9), "suppretion de Tunis");
                         }
                  fclose(f);
                }
                else
                gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans Tunis");
           }

         else
            {
                if (strcmp(Pv,"Arienna")==0)
                {
                    if (produitExiste(npa,pa,  pro)!=-2)
                        {
                            f=fopen("fa.txt","w");
                            if (f!=NULL)
                                {

                                        pa[produitExiste(npa,pa,  pro)]=pa[npa-1];
                                        npa--;
                                        fwrite(&npa,sizeof(int),1,f);
                                        for(j=0; j<npa; j++)
                                        fwrite(&pa[j],sizeof(produit),1,f);
                                        gtk_label_set_text(GTK_ENTRY(ph9), "suppretion de Arienna");
                                 }
                          fclose(f);
                        }
                        else
                        gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans Arienna");
                }


                else
                {
                    if (produitExiste(npb,pb,  pro)!=-2)
                        {
                            f=fopen("fb.txt","w");
                            if (f!=NULL)
                                {

                                        pb[produitExiste(npb,pb,  pro)]=pb[npb-1];
                                        npb--;
                                        fwrite(&npb,sizeof(int),1,f);
                                        for(j=0; j<npb; j++)
                                        fwrite(&pb[j],sizeof(produit),1,f);
                                        gtk_label_set_text(GTK_ENTRY(ph9), "suppretion de Bardo");
                                 }
                          fclose(f);
                        }
                        else
                        gtk_label_set_text(GTK_ENTRY(ph9), "Produit n'existe pas dans Bardo");

                }
            }

       }
strcmp(Pv,"");
    }

}
static void Recherche_clicked(GtkWidget* p_Window,gpointer data)
{
        //main window
          GtkWidget * RechercheProduitWindow = NULL;
          RechercheProduitWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        //Proprietes main window
        g_signal_connect(G_OBJECT(RechercheProduitWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

        gtk_window_maximize(GTK_WINDOW( RechercheProduitWindow));
        gtk_window_set_title(GTK_WINDOW( RechercheProduitWindow), "Recherche ");

        // //Titre

        GtkWidget* T = NULL;
        gchar* TexteConverti =NULL;
        TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#73b5ff\" size=\"xx-large\"><b>Recherche </b></span>\n",-1, NULL, NULL, NULL);
        T=gtk_label_new (TexteConverti);
        gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
        g_free(TexteConverti);


        GtkWidget*ph1=NULL;
        ph1= gtk_label_new("Le code du produit ");
        gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);
        //CODE PRODUIT

        CodeProduitg=gtk_entry_new();

         //Tunis
        GtkWidget*ph2=NULL;
        ph2= gtk_label_new("Tunis");
        gtk_label_set_justify(ph2, GTK_JUSTIFY_LEFT);
         //Bardo
        GtkWidget*ph3=NULL;
        ph3= gtk_label_new("Bardo");
        gtk_label_set_justify(ph3, GTK_JUSTIFY_LEFT);
         //Sousse
        GtkWidget*ph4=NULL;
        ph4= gtk_label_new("Sousse");
        gtk_label_set_justify(ph4, GTK_JUSTIFY_LEFT);
        //Arienna
        GtkWidget*ph5=NULL;
        ph5= gtk_label_new("Arienna");
        gtk_label_set_justify(ph5, GTK_JUSTIFY_LEFT);


        //Tunis

        Tunisg= gtk_label_new("");
        gtk_label_set_justify(Tunisg, GTK_JUSTIFY_LEFT);
         //Bardo

        Bardog= gtk_label_new("");
        gtk_label_set_justify(Bardog, GTK_JUSTIFY_LEFT);
         //Sousse

        Sousseg= gtk_label_new("");
        gtk_label_set_justify(Sousseg, GTK_JUSTIFY_LEFT);
        //Arienna

        Ariennag= gtk_label_new("");
        gtk_label_set_justify(Ariennag, GTK_JUSTIFY_LEFT);
        //box1
        GtkWidget* b1=NULL;
        b1= gtk_vbox_new(TRUE,0);
        gtk_container_add(GTK_CONTAINER(RechercheProduitWindow), b1);
        gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
        gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
        gtk_box_pack_start(b1,CodeProduitg, TRUE ,TRUE,0);
        //box2
        GtkWidget* b2=NULL;
        b2= gtk_hbox_new(TRUE,0);
        gtk_box_pack_start(b2,ph2, TRUE ,TRUE,0);
        gtk_box_pack_start(b2,ph3, TRUE ,TRUE,0);
        gtk_box_pack_start(b2,ph4, TRUE ,TRUE,0);
        gtk_box_pack_start(b2,ph5, TRUE ,TRUE,0);
        gtk_container_add(GTK_CONTAINER(b1), b2);
        //box3
        GtkWidget* b3=NULL;
        b3= gtk_hbox_new(TRUE,0);
        gtk_box_pack_start(b3,Tunisg, TRUE ,TRUE,0);
        gtk_box_pack_start(b3, Bardog, TRUE ,TRUE,0);
        gtk_box_pack_start(b3,Sousseg, TRUE ,TRUE,0);
        gtk_box_pack_start(b3,Ariennag, TRUE ,TRUE,0);
        gtk_container_add(GTK_CONTAINER(b1), b3);

        //bouton Recherche
        GtkWidget * Recherche = NULL;
        Recherche= gtk_button_new_with_label("Recherche");
        gtk_box_pack_start(b1,Recherche, FALSE ,FALSE,0);
       //bouton rETOUR menu
        GtkWidget * Retour = NULL;
        Retour= gtk_button_new_with_label("Retour");
        gtk_box_pack_start(b1,Retour, FALSE ,FALSE,0);
 gtk_widget_show_all(RechercheProduitWindow);
 gtk_widget_hide(GTK_WINDOW(data));

g_signal_connect(G_OBJECT(Recherche), "clicked", G_CALLBACK(Recherchee),RechercheProduitWindow);
g_signal_connect(G_OBJECT(Retour), "clicked", G_CALLBACK(retourMenue),RechercheProduitWindow);

}
static void Recherchee(GtkWidget* p_Window,gpointer data)
{
    strcpy(code, gtk_entry_get_text(GTK_ENTRY(CodeProduitg)));

    produit ppp;

    ppp.code=atoi(code);
    if (ppp.code!=0)
    {

        if( produitExiste(nps, ps, ppp)==-2)
        {
            printf("n'existe pas");
            gtk_label_set_text(GTK_LABEL(Sousseg), "n'existe pas");

        }
        else
        {
            char phrase[90]="";
            strcat(phrase,"Le code : ");
            strcat(phrase,code);
            strcat(phrase,"\n");
            strcat(phrase,"La libelle : ");
            strcat(phrase,ps[ produitExiste(nps, ps, ppp)].libele);
            strcat(phrase,"\n");
            char q[20];
            sprintf(q, "%d", ps[ produitExiste(nps, ps, ppp)].quantite);
            strcat(phrase,"La quantite ");
            strcat(phrase,q);
            strcat(phrase,"\n");
            char pr[20];
            sprintf(pr, "%d", ps[ produitExiste(nps, ps, ppp)].prix);
            strcat(phrase,"Le prix : ");
            strcat(phrase,pr);
            strcat(phrase,"\n");
            gtk_label_set_text(GTK_LABEL(Sousseg), phrase );


        }

if( produitExiste(npb, pb, ppp)==-2)
    {
        printf("n'existe pas");
        gtk_label_set_text(GTK_LABEL(Bardog), "n'existe pas");

    }
    else
    {
        char phrase[90]="";
        strcat(phrase,"Le code : ");
        strcat(phrase,code);
        strcat(phrase,"\n");
        strcat(phrase,"La libelle : ");
        strcat(phrase,pb[ produitExiste(npb, pb, ppp)].libele);
        strcat(phrase,"\n");
        char q[20];
        sprintf(q, "%d", pb[ produitExiste(npb, pb, ppp)].quantite);
        strcat(phrase,"La quantite ");
        strcat(phrase,q);
        strcat(phrase,"\n");
        char pr[20];
        sprintf(pr, "%d", pb[ produitExiste(npb, pb, ppp)].prix);
        strcat(phrase,"Le prix : ");
        strcat(phrase,pr);
        strcat(phrase,"\n");
        gtk_label_set_text(GTK_LABEL(Bardog), phrase );


    }

    if( produitExiste(npt, pt, ppp)==-2)
    {
        printf("n'existe pas");
        gtk_label_set_text(GTK_LABEL(Tunisg), "n'existe pas");

    }
    else
    {
        char phrase[90]="";
        strcat(phrase,"Le code : ");
        strcat(phrase,code);
        strcat(phrase,"\n");
        strcat(phrase,"La libelle : ");
        strcat(phrase,pt[ produitExiste(npt, pt, ppp)].libele);
        strcat(phrase,"\n");
        char q[20];
        sprintf(q, "%d", pt[ produitExiste(npt, pt, ppp)].quantite);
        strcat(phrase,"La quantite ");
        strcat(phrase,q);
        strcat(phrase,"\n");
        char pr[20];
        sprintf(pr, "%d", pt[ produitExiste(npt, pt, ppp)].prix);
        strcat(phrase,"Le prix : ");
        strcat(phrase,pr);
        strcat(phrase,"\n");
        gtk_label_set_text(GTK_LABEL(Tunisg), phrase );}



if( produitExiste(npa, pa, ppp)== -2)
    {
        gtk_label_set_text(GTK_LABEL(Ariennag), "n'existe pas");
    }
    else
    {
        char phrase[90]="";
        strcat(phrase,"Le code : ");
        strcat(phrase,code);
        strcat(phrase,"\n");
        strcat(phrase,"La libelle : ");
        strcat(phrase,pa[ produitExiste(npa, pa, ppp)].libele);
        strcat(phrase,"\n");
        char q[20];
        sprintf(q, "%d", pa[ produitExiste(npa, pa, ppp)].quantite);
        strcat(phrase,"La quantite ");
        strcat(phrase,q);
        strcat(phrase,"\n");
        char pr[20];
        sprintf(pr, "%d", pa[ produitExiste(npa, pa, ppp)].prix);
        strcat(phrase,"Le prix : ");
        strcat(phrase,pr);
        strcat(phrase,"\n");
        gtk_label_set_text(GTK_LABEL(Ariennag), phrase );

    }




    }
    else
    {
                gchar *sSite;
                GtkWidget *pAbout;

                sSite = "tapper le code";

                GtkWidget *pWindow;
                pWindow = gtk_widget_get_toplevel(GTK_WIDGET(data));


                pAbout = gtk_message_dialog_new (GTK_WINDOW(pWindow),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,sSite);

                gtk_dialog_run(GTK_DIALOG(pAbout));
                gtk_widget_destroy(pAbout);

    }




}


loginWindow()
{
    //main window
    GtkWidget * MainWindow = NULL;
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

            //Proprietes main window

           gtk_window_set_default_size(GTK_WINDOW(MainWindow),400,500);
            gtk_window_set_title(GTK_WINDOW(MainWindow), "gestion de stock");
            g_signal_connect(G_OBJECT(MainWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);



                //Titre 1

                GtkWidget* T = NULL;
                gchar* TexteConverti =NULL;
                TexteConverti = g_locale_to_utf8("<span face=\"Verdana\"foreground=\"#85c9ed\" size=\"xx-large\"><b>gestion de stock</b></span>\n",-1, NULL, NULL, NULL);
                T=gtk_label_new (TexteConverti);
                gtk_label_set_markup(GTK_LABEL(T), TexteConverti);
                g_free(TexteConverti);

                //ph1
                GtkWidget*ph1=NULL;
                ph1= gtk_label_new("Entrer votre psodo : ");
                gtk_label_set_justify(ph1, GTK_JUSTIFY_LEFT);
                //ID
                GtkWidget*ID=NULL;
                ID=gtk_entry_new();
                //ph2
                GtkWidget*ph2=NULL;
                ph2= gtk_label_new("Entrer le code : ");
                gtk_label_set_justify(ph2, GTK_JUSTIFY_LEFT);
                //MDP
                GtkWidget*Mdp=NULL;
                Mdp=gtk_entry_new();
                gtk_entry_set_visibility(Mdp, FALSE);

                //bouton creer nouveau compte
                 GtkWidget *CNC = NULL;
                 CNC= gtk_button_new_with_label("Creer nouveau compte ");
                 //bouton connection
                 GtkWidget *Connecter= NULL;
                 Connecter= gtk_button_new_with_label("Connecter");
                 //affiche
                    GtkWidget*ph3=NULL;
                    ph3= gtk_label_new("");
                    gtk_label_set_justify(ph3, GTK_JUSTIFY_LEFT);
                  //bouton quitter
                GtkWidget *Quitter = NULL;
                Quitter= gtk_button_new_from_stock (GTK_STOCK_QUIT);
                g_signal_connect (G_OBJECT (Quitter), "clicked", G_CALLBACK (cb_quit), NULL);
                //box1
                 GtkWidget* b1=NULL;
                 b1= gtk_vbox_new(TRUE,0);
                 gtk_container_add(GTK_CONTAINER(MainWindow), b1);
                 gtk_box_pack_start(b1,T, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph1, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ID, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph2, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,Mdp, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,CNC, TRUE ,TRUE,0);
                 gtk_box_pack_start(b1,ph3, TRUE ,TRUE,0);
                 //box2
                 GtkWidget* b2=NULL;
                 b2= gtk_hbox_new(TRUE,0);
                 gtk_box_pack_start(GTK_BOX(b1), b2, TRUE, TRUE, 0);
                 gtk_box_pack_start(b2,Connecter, TRUE ,TRUE,0);

                 gtk_box_pack_start(b2,Quitter, TRUE ,TRUE,0);



gtk_widget_show_all(MainWindow);
g_signal_connect(GTK_WIDGET(CNC), "clicked", G_CALLBACK(CNC_clicked),(GtkWidget*)MainWindow);
g_signal_connect(GTK_WIDGET(Connecter), "clicked", G_CALLBACK(Connecter_clicked),(GtkWidget*)b1);

gtk_main();

}
static void Affiche_clicked(GtkWidget* p_Window,gpointer data)
{
    GtkWidget *mafenetre;
    GtkWidget *montexte;
    GtkWidget *barrededefilement;
    char c[10000], ch[10000];
    strcpy(ch,"");
    strcpy(c,"");


strcat(ch,"*pts de vante Tunis : \n\n\n");
    int i;
    for (i=0; i<npt; i++)
    {

        sprintf(c,"-le code\t%i \n-la libellet\t %s\n-le prix \t %i \n-La quantite\t %i \n\n" ,pt[i].code,pt[i].libele,pt[i].prix, pt[i].quantite);
        strcat(ch,c);
    }


    strcat(ch,"*pts de vante Sousse : \n\n\n");
    for (i=0; i<nps; i++)
    {

        sprintf(c,"-le code\t%i \n-la libellet\t %s\n-le prix \t %i \n-La quantite\t %i \n\n" ,ps[i].code,ps[i].libele,ps[i].prix, ps[i].quantite);
        strcat(ch,c);
    }
    strcat(ch,"*pts de vante Bardo : \n\n\n");
   for (i=0; i<npb; i++)
    {

        sprintf(c,"-le code\t%i \n-la libellet\t %s\n-le prix \t %i \n-La quantite\t %i \n\n" ,pb[i].code,pb[i].libele,pb[i].prix, pb[i].quantite);
        strcat(ch,c);
    }
     strcat(ch,"*pts de vante Arienna \n");
   for (i=0; i<npa; i++)
    {

        sprintf(c,"le code\t%i \n la libellet\t %s\nle prix \t %i \nLa quantite\t %i \n\n" ,pa[i].code,pa[i].libele,pa[i].prix, pa[i].quantite);
        strcat(ch,c);
    }


    mafenetre=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(mafenetre), "Les produit");
    gtk_window_set_position(GTK_WINDOW(mafenetre), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(mafenetre), 500, 500);


    montexte=gtk_label_new(ch);

    barrededefilement = gtk_scrolled_window_new(NULL, NULL);

    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(barrededefilement), montexte);

    gtk_container_add(GTK_CONTAINER(mafenetre),GTK_SCROLLED_WINDOW(barrededefilement));
 g_signal_connect(G_OBJECT(mafenetre), "destroy", G_CALLBACK(quite), mafenetre);

    gtk_widget_show_all(mafenetre);
}
static void quite (GtkWidget* p_Window,gpointer data)
{
    gtk_widget_hide(GTK_WINDOW(data));
}
