#include <stdio.h>
#include <conio.h >
#include <stdlib.h>
#include <windows.h>
#include <string.h>



#define MAX_YR  9999
#define MIN_YR  1900
typedef struct Date
 {
  char jour[3];
  char mois[3];
  char annee[5];
 } Date;
 
///////////less structures enrigistrement  ////
typedef struct article
{
char Identifiant[10] ;
char Designation[15] ;
float Prixachat ;
float Prixvente;
float TVA ;
Date Datefab ;
Date Dateexp ;
char Depot[10] ;
int Quantite;
int Seuil;
}typearticle ;

typedef struct client_fournisseurs
{
 char Identifiant[10]; 
 char Nom[15] ;
 char Adress[20] ;
 char Ville[10] ;
 char Telephone[9] ;
 char  type [20] ;
 }typeclient_fournisseurs;
 
typedef struct achat_vente
{
char Identifiant[10] ;
char ID_Article[10] ;
char ID_Client_Fournisseur[10] ;
char Type [20] ;
 Date DATE;
int Quantite ;
}typeachat_vente;




////------------les listes -----------------------------///


///articles //
typedef struct Elemarticle
{
	typearticle Donnee;
	struct Elemarticle * Suivant;
}TypeElemarticle;

typedef struct 
{
	TypeElemarticle * Tete;
	TypeElemarticle * Queue;
	int Taille;		
}Typelistarticle;

//client fournisseurs 

typedef struct Elemclient_fournisseurs
{
	typeclient_fournisseurs Donnee;
	struct Elemclient_fournisseurs * Suivant;
}TypeElemclient_fournisseurs;

typedef struct 
{
	TypeElemclient_fournisseurs * Tete;
	TypeElemclient_fournisseurs * Queue;
	int Taille;		
}Typelistclient_fournisseurs;



//achat vente

typedef struct Elemachat_vente
{
	typeachat_vente Donnee;
	struct Elemachat_vente * Suivant;
}TypeElemachat_vente;

typedef struct 
{
	TypeElemachat_vente * Tete;
	TypeElemachat_vente * Queue;
	int Taille;		
}Typelistachat_vente;





//------------------------------prototypes--------------------------///

/////MENU//
int MENUGESTION();
int MenuArticle();
int Menuachatvente();
int MenuClientsFournisseurs() ;
int alphanumerique(char msg[20]) ;
int numerique (char mess[30]); 
void Color(int couleurDuTexte,int couleurDeFond);
void gotoxy(int x,int y);
int nb_jour_mois(int mois, int annee);
Date saisir_date_initiale();
int unique_article(Typelistarticle L ,char D[10]);
//int unique_ACHAT_VENTES(Typelistachat_vente L,char D[10]);
//int unique_CLINET_FOURNISSEURS(Typelistclient_fournisseurs L,char D[10]);
void AfficheA(Typelistarticle  L, char  D[10]);


//*****************les operations fournisseurs******************* ///
void InitListCF(Typelistclient_fournisseurs * L);
void saisirFC(typeclient_fournisseurs *FC);
void AjoutFC_Fin(Typelistclient_fournisseurs* L , typeclient_fournisseurs D);
 int SupprimerFC(Typelistclient_fournisseurs* L , char D[10]);
 int RechercheFC(Typelistclient_fournisseurs  L , char D[10]);	
void AfficheFC(Typelistclient_fournisseurs  L, char  D[10]);
 int modificationFC(Typelistclient_fournisseurs * L, char  D[10]);
void afficheFCA(Typelistclient_fournisseurs  L,Typelistarticle  AL,char D[10]);



//*******************les operations article***********************///
void InitListA(Typelistarticle * L);
void saisirArticle(typearticle *A,Typelistarticle L);
void AjoutA_Fin(Typelistarticle * L , typearticle A);
int SupprimerA(Typelistarticle * L, char  D[10]);
int modificationA(Typelistarticle L , char D[10]);
void AfficheA(Typelistarticle  L, char  D[10]);
int RechercheA(Typelistarticle L, char  D[10]);
void articlerepture(Typelistarticle L);
void articleperimee(Typelistarticle L);


//************************les operations achat vente**************///
void InitListAV(Typelistachat_vente * L);
void saisirAV(typeachat_vente * A);
void AjoutAV_Fin(Typelistachat_vente * A , typeachat_vente V);
int SupprimerAV(Typelistachat_vente * A , char D[10]);
int  RechercheAV(Typelistachat_vente  A ,char D[10]);
void AfficheAV(Typelistachat_vente  L, char  D[10]);
int modificationAV(Typelistachat_vente * L , char D[10]) ;



         //////////programme principale//////
//***************************************************************///


main ()
{ 
char s[10];
char c[10];
char r[10];

int CHOIX,OPAR,OPFC,OPAV,i;
  typeclient_fournisseurs  D;
  Typelistclient_fournisseurs L;
  Typelistachat_vente AVL;
  typeachat_vente AV;
  Typelistarticle AL;
  typearticle A;
 TypeElemarticle tete;
 Color(5,0);
 gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
 Color(7,0);
 gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
 gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
 
  InitListCF(&L);
  InitListAV(&AVL);
  InitListA(&AL);
 
  CHOIX = MENUGESTION();
system("cls");
  do {
         switch(CHOIX)
            {
             case 1:OPAR=MenuArticle();
                switch(OPAR)
				 {
                  case 1:
				    {
				      system("cls");
				      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                      gotoxy(48,6);printf("ajout d'un article");
				        saisirArticle(&A,AL);
					    AjoutA_Fin(&AL,A);
					  gotoxy(45,28);printf("ajout bien terminee");
					  gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                      getch();
                      system("cls");
                    };break;
      
      
                  case 2:
                    {
                    	
                      system("cls");
                      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                      gotoxy(43,6);printf("supprission d'un article");
                      gotoxy(30,9);
                      printf("Donner l'identifiant d'article que vous voulez supprimer\n");
                         do
                          {
					        gotoxy(53,11);
                            scanf("%s",s);
					      }
                         while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                     
                     SupprimerA(&AL,s);
                     gotoxy(56,26);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		             gotoxy(57,27);printf("%cEntrer%c ",186,186);
		             gotoxy(56,28);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                     getch();
                     system("cls");
                    };break;
                     
                     
                  case 3:
                    {
			           system("cls");
			           gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                       gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                       gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                       gotoxy(47,6);printf("modification d'un article");
                       gotoxy(30,10); printf("Donner l'identifiant d'article que vous voulez modifier \n ");
                         do
                           {
					        gotoxy(53,12);
                            scanf("%s",s);
					       }
                         while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                    
                      modificationA(AL,s); 
                      gotoxy(56,27);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,28);printf("%cEntrer%c ",186,186);
		              gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                      getch();
                      system("cls");
                    };break;
               
               
                  case 4:
                    {
					   system("cls");
                       gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                       gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                       gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                       gotoxy(30,8);printf("Donner l'identifiant d'article que vous voulez chercher");
                         do
                          {
					       gotoxy(53,11);
                           scanf("%s",c); 
					      }
                       while(alphanumerique(c)==0||strlen(c)<=0||strlen(c)>10);
               
                       RechercheA(AL,c);
                       if(RechercheA(AL,c)==1)
                           {
                           	system("cls");
                            gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                            gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                            gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
						    gotoxy(45,7);
						    printf("voici l'article que vous voulez chercher\n");
                            AfficheA(AL,c);
                           }
                        else
                           {
                           	gotoxy(36,14);
                            printf("l'article que vous voulez chercher n'existe pas");
                            gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		                    gotoxy(57,30);printf("%cEntrer%c ",186,186);
		                    gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                           }
                       getch();
                       system("cls"); 
                    };break;
                    
                    
                  case 5:
				    {
					  system("cls");
				      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
              	      articlerepture(AL) ;
              	      gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
              	      getch ();
                      system("cls");
              	    };break;
			  
			      case 6: 
			        { 
			          system("cls");
				      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
			  	      articleperimee(AL);
			  	      gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
			  	      getch();
                      system("cls");
			  	    };break;
			  
	              case 7: 
			        {
			          system ("cls");
              	      MENUGESTION();
              	      getch();
              	      system("cls");
                    };break;
                    
                  case 8:
            	    {
            	    
            	      system("cls");
            	      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                      gotoxy(55,13);
                      printf("AU REVOIR");
                      gotoxy(40,14);
                      printf("vous allez quitter l'application");
                      getch();
            	      system("cls");
				    };break;
				  
				  
                };break;
    
    
             case 2:OPFC=MenuClientsFournisseurs();   
                switch(OPFC)
                 {
                  case 1:
				    {
				      system("cls");
				      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
				      saisirFC(&D); 
				      AjoutFC_Fin(&L,D);
				      gotoxy(45,26);
                      printf("ajout bien terminee");
                      gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                      getch();
                      system("cls");
                    };break;
                    
                  case 2:
                    {
                      system("cls");	
                      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4) ;printf("________________________________________________________________________________________________________________________");	
                      gotoxy(20,9);printf("donner l'identifiant du client fournisseurs que vous voulez supprimer");
                      gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                        gotoxy(50,10);
                          do
                            scanf("%s",s);
                          while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                      SupprimerFC(&L,s);
                      getch();
                      system("cls");
                    };break;
                      
                  case 3:
                    {
                      system("cls");
                      gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                      gotoxy(20,9);printf("donner l'identifiant du client fournisseurs que vous voulez modifier \n ");
                      
                      gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,30);printf("%cEntrer%c ",186,186);
		              gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
					  gotoxy(50,10);
                          do
                            scanf("%s",s);
                          while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                      modificationFC(&L,s);  
                      getch();
                      system("cls");
                    };break;
               
                  case 4:
                    {
                      system("cls");
                      gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(20,9);printf("donner l'identifiant du client fournisseurs que vous voulez chercher");
                      gotoxy(50,10);
                          do
                            scanf("%s",c);
                          while(alphanumerique(c)==0||strlen(c)<=0||strlen(c)>10);
                      RechercheFC(L,c);
                         if(RechercheFC(L,c)==1)
                           {
					          gotoxy(50,11);
							  printf("existe");
                             AfficheFC(L,c);
                           }
                         else
                           {  
                             gotoxy(50,11);
							 printf("n'existe pas ");
                           }
                      gotoxy(56,27);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		              gotoxy(57,28);printf("%cEntrer%c ",186,186);
		              gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                      getch ();
                      system("cls");  
                    };break ;

                  case 5:
			    	{
                      system ("cls");  
                      gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
                      MENUGESTION();
                      system ("cls");  
                    };break;
             
                  case 6:
                	{
              	      system("cls");    
                      gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
			          gotoxy(45,18);
					  printf("au revoir");
			          getch();
			        };break;
				 
                 };break;
              

            case 3: OPAV =Menuachatvente();
               switch(OPAV)
               {
                 case 1:
				      {
                       saisirAV(&AV);
					   AjoutAV_Fin(&AVL,AV);
                        gotoxy(45,22);printf ("ajout bien terminee");
                         gotoxy(56,27);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		             gotoxy(57,28);printf("%cEntrer%c ",186,186);
		             gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
              	   getch ();
                    
                       system("cls");
                      };break;
                 case 2:
				      { 
				      system("cls");
				      
gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
				       gotoxy(19,8);printf("Donner l'identifiant d'achat ou vente que vous voulez supprimer");
                         do
                         {
						 gotoxy(50,10);
                          scanf("%s",s);
						  }
                         while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                       SupprimerAV(&AVL,s);
                         gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		             gotoxy(57,30);printf("%cEntrer%c ",186,186);
		             gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
              	   getch ();
                    
                       system("cls");
                      }; break;
                 case 3:
                 	
                 	  {
                 	  	system("cls");
                 	  	gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
                       	gotoxy(20,7);printf("donner l'identifiant du l'opération que vous voulez modifier \n ");
                do
				{
				 gotoxy(45,9);
                 scanf("%s",s);
				}
                while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                
                modificationFC(&L,s) ;  
                getch ();
                system("cls");
                 	
                
            } ;break;

                 case 4:
				      {
				      	system("cls");
                       gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                       gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                       gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
                       gotoxy(20,7);printf("donner l'identifiant du achat vente que vous voulez chercher");
                        do
                        {
						 gotoxy(45,9);
                          scanf("%s",s);
						  }
                        while(alphanumerique(s)==0||strlen(s)<=0||strlen(s)>10);
                       RechercheAV(AVL,s);
                        if(RechercheAV(AVL,s)==1)
                         {
                          AfficheAV(AVL,s);
                         }
                         else
                         {
                         	 gotoxy(40,11);
                          printf ("n'existe pas ") ;
                         }
                     gotoxy(56,29);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		             gotoxy(57,30);printf("%cEntrer%c ",186,186);
		             gotoxy(56,31);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
                       getch ();
                       system("cls")  ;  
                      };break ;
                      //case 5:
                      case 6:
                    
			    	{
                      system ("cls");  
                      gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
                      MENUGESTION();
                      system ("cls");  
                    };break;
             
                  case 7:
                	{
              	      system("cls");    
                      gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
                      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
                      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
			          gotoxy(45,18);
					  printf("au revoir");
			          getch();
			        };break;
                      		
                      	
              };break ;

           }  
  }while (CHOIX!=4) ;
}


int MENUGESTION()  
{ 
  int choix,i,j,k;
 do
  {
    gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
    gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
    gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
    j=10;
    k=39;
	gotoxy(38,9) ;printf("%c",201);
	gotoxy(86,9) ;printf("%c",187);
	gotoxy(38,18) ;printf("%c",200);
	gotoxy(86,18) ;printf("%c",188);
      for(i=0;i<=46;i++)
	   {
	     gotoxy(k,9) ;
	     printf("%c",205);
	     k++;
	   }
	  
	k=39;
	  for (i=0;i<=46;i++)
	   {
	    gotoxy(k,18) ;
	    printf("%c",205);
	    k++;
	   }
	  for(i=0;i<8;i++)
	   {
	    gotoxy(38,j);
	    printf("%c",186);
	    j++;
	   }
	 
	j=10;
	  for(i=0;i<8;i++)
	  {
	   gotoxy(86,j);
	   printf("%c",186);
	   j++;
	  }
	//**************************************************************************//
	//**************************************************************************//
      gotoxy(53,11);printf( "MENU PRINCIPALE");
      gotoxy(43,13);printf(" 1 : Gestion des articles");
      gotoxy(43,14);printf(" 2 : Gestion des clients fournisseurs");
      gotoxy(43,15);printf(" 3 : Gestion de ventes et d'achat ");
      gotoxy(43,16);printf(" 4 : Quitter");	
      gotoxy(56,26);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
	  gotoxy(57,27);printf("%cEntrer%c ",186,186);
	  gotoxy(56,28);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
	  gotoxy(38,22);printf("D'apres ce menu qu'est ce que vous voulez faire ?\n");
	  gotoxy(60,24);scanf("%d",&choix);
         if(choix<1 && choix>=5) 
          gotoxy(43,22);printf("il faut donner un nombre entre 1 et 4\n");
  }      while (choix<1||choix>=5);
      return(choix);
     system("cls");
}

int MenuArticle()           
{
  int choix,i,j,k;
   do  
 	 { 
	  gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
      gotoxy(2,3 ); printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021    ");
      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
 	 
	   j=8;
	   k=39;
       //****************************cadre du menu ***************************//
       //*********************************************************************//
	  gotoxy(38,7) ;printf("%c",201);
	  gotoxy(38,20) ;printf("%c",200);
	  gotoxy(86,7) ;printf("%c",187);
	  gotoxy(86,20) ;printf("%c",188);
	  
	   for (i=0;i<=46;i++)
   	     {
	       gotoxy(k,7) ;
	       printf("%c",205);
	       k++;
	     }
	    
	   k=39;
		for (i=0;i<=46;i++)
    	 {
	       gotoxy(k,20) ;
	       printf("%c",205);
	       k++;
	     }
	    
	    
	   for(i=0;i<12;i++)
	     {
	       gotoxy(38,j);
	       printf("%c",186);
	       j++;
	     }
	    
	   j=8;
	   for(i=0;i<12;i++)
	     {
	      gotoxy(86,j);
	      printf("%c",186);
	      j++;
	     }
	//***************************************************************//
	//**************************************************************//
		gotoxy(53,9) ;printf(" MENU DES ARTICLES  \n" );
		gotoxy(43,11);printf("  1 : Ajout d'un article \n" );
		gotoxy(43,12);printf("  2 : Suppression d'un article\n");
		gotoxy(43,13);printf("  3 : Modification d'un article \n");
		gotoxy(43,14);printf("  4 : Recherche d'un article \n");
        gotoxy(43,15);printf("  5 : articles en repture de stock\n");
		gotoxy(43,16);printf("  6 : articles p%crim%cs ",130,130);
		gotoxy(43,17);printf("  7 : retour au menu principale ");
		gotoxy(43,18);printf("  8 : Quitter ");
		gotoxy(56,26);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		gotoxy(57,27);printf("%cEntrer%c ",186,186);
		gotoxy(56,28);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
		gotoxy(38,23);printf("D'apres ce menu qu'est ce que vous voulez faire ?\n");
	    gotoxy(60,24);scanf("%d",&choix);
        if(choix<1 || choix>=9)
        printf("il faut donner un nombre entre 1 et 8\n");
      }while (choix<1 || choix>=9);
        return(choix);	
}

int MenuClientsFournisseurs()
{
  int choix,i,j,k;
	do
	{	
	  gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         ");
      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
	
	 j=8;
	 k=31;
	 //*****************************cadre du menu********************************//
	 //**************************************************************************//
	 gotoxy(30,7) ;printf("%c",201);
	 gotoxy(100,7) ;printf("%c",187);
	 gotoxy(30,19) ;printf("%c",200);
	 gotoxy(100,19) ;printf("%c",188);
	 
	  for (i=0;i<=68;i++)
	   {
	     gotoxy(k,7) ;
	     printf("%c",205);
	     k++;
	   }
	   
	   k=31;
	  for (i=0;i<=68;i++)
	   {
	     gotoxy(k,19) ;
	     printf("%c",205);
	     k++;
	   }
	 
	  for(i=0;i<11;i++)
	   {
	     gotoxy(30,j);
	     printf("%c",186);
	     j++;
	   }
	   
	  j=8;
	  for(i=0;i<11;i++)
	   {
	     gotoxy(100,j);
	     printf("%c",186);
	     j++;
	   }
	//**************************************************************************//
	//**************************************************************************//
	
	

		gotoxy(46,10) ;printf(" MENU DES FOURNISSEURS ET DES CLIENTS ");
		gotoxy(38,12);printf("1: Ajout d'un fournisseur ou d'un client");
	    gotoxy(38,13);printf("2: Suppression d'un fournisseur ou d'un client ");
		gotoxy(38,14);printf("3: Modification d'un fournisseur ou d'un client");
		gotoxy(38,15);printf("4: Recherche d'un fournisseur ou d'un client");
		gotoxy(38,16);printf("5: Retour au menu principale ");
		gotoxy(38,17);printf("6: Quitter ");
		gotoxy(57,26);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		gotoxy(58,27);printf("%cEntrer%c ",186,186);
		gotoxy(57,28);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
		gotoxy(38,23);printf("D'apr%cs ce menu qu'est ce que vous voulez faire ?\n",130);
		gotoxy(62,25);
	    scanf("%d",&choix);
        if(choix<1 || choix>6)
        printf("il faut donner un nombre entre 1 et 7\n");
    } while(choix<1 || choix>6);
   return(choix);
}
 
 
int Menuachatvente()
 {
 int choix,i,j,k;
    
   do 
	{
	  gotoxy(0,1 );printf("________________________________________________________________________________________________________________________");
      gotoxy(2,3 );printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         ");
      gotoxy(0,4 );printf("________________________________________________________________________________________________________________________");
	
	  j=8;
	  k=39;
		//****************************cadre du menu ***************************//
       //********************************************************************//

	 gotoxy(38,7) ;printf("%c",201);
	 gotoxy(86,7) ;printf("%c",187);
	 gotoxy(38,19) ;printf("%c",200);
	 gotoxy(86,19) ;printf("%c",188);
	  for(i=0;i<=46;i++)
	    {
	      gotoxy(k,7) ;
	      printf("%c",205);
	      k++;
	    }
	    
	  k=39;
	  for (i=0;i<=46;i++)
	    {
	      gotoxy(k,19) ;
	      printf("%c",205);
	      k++;
	    }
	   for(i=0;i<11;i++)
	   {
	      gotoxy(38,j);
	      printf("%c",186);
	      j++;
	   }
	   
	   j=8;
	   for(i=0;i<11;i++)
	   {
	      gotoxy(86,j);
	      printf("%c",186);
	      j++;
	   }
	//***************************************************************//
	//**************************************************************//

		gotoxy(49,9); printf(" MENU D'ACHAT ET DE VENTE ");
		gotoxy(45,11);printf("1: Ajout d'une op%cration",130);
		gotoxy(45,12);printf("2: Suppression d'une op%cration",130);
		gotoxy(45,13);printf("3: Modification d'une opération",130);
		gotoxy(45,14);printf("4: Recherche d'une op%cration");
		gotoxy(45,15);printf("5: affiche des totaux.... ");
		gotoxy(45,16);printf("6: retour au menu principale");
		gotoxy(45,17);printf("7:Quitte");
		gotoxy(57,26);printf(" %c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,187);
		gotoxy(58,27);printf("%cEntrer%c ",186,186);
		gotoxy(57,28);printf(" %c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
		gotoxy(38,23);printf("D'apr%cs ce menu qu'est ce que vous voulez faire ?\n",130);
		gotoxy(62,25);
	    scanf("%d",&choix);
        if(choix<1 || choix>7)
        printf("il faut donner un nombre entre 1 et 7");
    }while(choix<1 || choix>7); 
 return(choix);	
}


///******************************************* Les Opération CLIENT_FOURNISSEURS **************************************************///
///********************************************************************************************************************************///


//-------------inisialisatin dun fousnisseur ou dun client --------------
void InitListCF(Typelistclient_fournisseurs * L)
{
		L->Taille=0;			
	    L->Tete=NULL;			
	    L->Queue=NULL;
}
//-------------ajout dun fousnisseur ou dun client --------------
void AjoutFC_Fin(Typelistclient_fournisseurs * L , typeclient_fournisseurs D)
{
	int x,i,k,j,l ;
		TypeElemclient_fournisseurs * Ptr;							
	
/*	 k=33;
		for (i=0;i<=46;i++)
	 {
	  gotoxy(k,2) ;
	  printf("%c",205);
	  k++;
	 }
	  k=33;
	 for (i=0;i<=46;i++)
	 {
	  gotoxy(k,4) ;
	  printf("%c",205);
	  k++;
	 }
	 
	 k=32;
	 for(i=0;i<=2;i++)
	 {
	 	gotoxy(k,3);
	 	printf("%c",186);
	 }	  k=79;
	 for(i=0;i<=2;i++)
	 {
	 	gotoxy(k,3);
	 	printf("%c",186);
	 }*/

	

	Ptr=(TypeElemclient_fournisseurs*)malloc(sizeof(TypeElemclient_fournisseurs ));	
	
	Ptr->Donnee=D;								
	Ptr->Suivant=NULL;						
	
	if (L->Tete==NULL)							
	{
		L->Tete=Ptr;						
		L->Queue=Ptr;
	}	
	else
	{
		L->Queue->Suivant=Ptr;					
		L->Queue=Ptr;							
	}
	L->Taille++;							
}
//-------------saisir dun fousnisseur ou dun client --------------
void saisirFC(typeclient_fournisseurs *FC)
{

	  int x,i,k,j,l ;

	  

	  //***largeur*********
	  k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,7);
	   printf("%c",205); 
	   }
	   else 
	   printf("%c",203);
	   k++;
	 }
	 
	 
	 //***largeur*********
	 
	  k=15;
	  l=9;
 for(j=0;j<=9;j++)
 { if(l%2!=0)
   { k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,l);
	   printf("%c",205);
	    k++;
	   }
	   else 
	   { 
	   printf("%c",206);
	   k++;
	   }
	   
	 } 
	  l++;
   }
   else 
   l++;
  
 }


 k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,20);
	   printf("%c",205); 
	   }
	   else 
	   printf("%c",202);
	   k++;
	 }
  


 k=8;
	 for(i=0;i<=10;i++)
	  {
	  	
	    gotoxy(96,k);
	  	if(k%2==0)
	  	  printf("%c",186);
	  	else 
	  	 {
	  	 	if (k==19)
	  	 	{ 
	  	 	gotoxy(96,19);
	  	 	printf("%c",186);
			}
		   else 
		    {
		     printf("%c",185);  
		     
		    }
		  
		  }
		  k++;
	  }
	  
	  
	  k=8;
	 for(i=0;i<=5;i++)
	  {
	  	
	    gotoxy(61,k);
	  	if(k%2!=0)
	  	 {
	  	 	if (k==19)
	  	 	 {gotoxy(61,19);
	  	 	 printf("%c",186);
			 }
			     
		 }
	  	  
	  	if(k%2==0)
	  	  {
		  printf("%c",186);  
		  k++;
		   }
		k++;
	  }

 gotoxy(14,7); printf("%c",201);
 gotoxy(96,7); printf("%c",187);
 gotoxy(14,20); printf("%c",200);
 gotoxy(96,20); printf("%c",188);
 gotoxy(61,19); printf("%c",186);
 gotoxy(96,19); printf("%c",186);
	//****longueur********* 
	 k=8;
	 for(i=0;i<=11;i++)
	  {
	  	
	    gotoxy(14,k);
	  	if(k%2==0)
	  	{  
	  	  printf("%c",186);
		}
	  	else
	  	{
		  
		  if(k==19)
	  	    {
	  	    gotoxy(14,19);
	  	    printf("%c",186);
		    }
		  else 
		    printf("%c",204); 
		}
		k++;
	  }
	 
  gotoxy(20,8); printf("Donner l'identifiant             :");
  gotoxy(20,10);printf("Donner le nom                    :"); 
  gotoxy(20,12);printf("Donner l''adresse                :");
  gotoxy(20,14);printf("Donner le ville                  :   ");
  gotoxy(20,16);printf("Donner le num%cro de t%cl%cphone    :",130,130,130); 
  gotoxy(20,18);printf("Donner le type  \t\t     :");gotoxy(15,19); printf(" 0:Client 1:Fournisseur 2:Client_Fournisseur");
  gotoxy(15,22);printf("%c Remplir ce formulaire\b",254);
do 
 {
  gotoxy(66,8);
  scanf("%s",FC->Identifiant);
 }
while(alphanumerique(FC->Identifiant)==0||strlen(FC->Identifiant)<=0||strlen(FC->Identifiant)>10 );


do
{
 gotoxy(66,10);
 scanf("%s",FC->Nom);
}
while(alphanumerique(FC->Nom)==0||strlen(FC->Nom)<=0||strlen(FC->Nom)>15);


do
{
  gotoxy(66,12);
  scanf("%s",FC->Adress);
}
 
while(alphanumerique(FC->Adress)==0||strlen(FC->Adress)<=0||strlen(FC->Adress)>20);



do
{
 gotoxy(66,14);
 scanf("%s",FC->Ville);
 }
while(alphanumerique(FC->Ville)==0||strlen(FC->Ville)<=0||strlen(FC->Ville)>10);



do
{
 gotoxy(66,16);
 scanf("%s",FC->Telephone);
}
while(strlen(FC->Telephone)<=0 || numerique(FC->Telephone)==0 || strlen(FC->Telephone)!=8 );


do
{
gotoxy(66,18);
 scanf ("%d",&x) ;
}
   while (x!=0 && x!=1&& x!=2) ;

 if(x==0)
      strcpy(FC->type,"Client");
  else
  {
  if (x==1)
  strcpy(FC->type," Fournisseur");
  else
  strcpy(FC->type," Client et fournisseur");
  }
}
//------------------affichage--------------------------------------

void AfficheFC(Typelistclient_fournisseurs  L, char  D[10])
{
	TypeElemclient_fournisseurs * Ptr;
	Ptr=L.Tete;									
     while (Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0) )  {
	 
		Ptr=Ptr->Suivant;
}
			
 if (Ptr!=NULL)
	{   printf("\n");
		printf ("\n\t\t\t\tIdentifiant    : %s\n",Ptr->Donnee.Identifiant);			
		printf ("\t\t\t\tNom            : %s\n" , Ptr->Donnee.Nom) ;
		printf ("\t\t\t\tAdresse        : %s \n ",Ptr->Donnee.Adress) ;
		printf ("\t\t\t\tVille          : %s \n ",Ptr->Donnee.Ville) ;
		printf ("\t\t\t\tT%cl%cphone      : %s \n ",130,130,Ptr->Donnee.Telephone) ;	
		printf ("\t\t\t\tType           :%s \n ",Ptr->Donnee.type) ;							
	}
	else
	printf ("n'existe pas") ;	
}

//-------------suppression dun fousnisseur ou dun client --------------
 int SupprimerFC(Typelistclient_fournisseurs * L , char D[10])
{
	   TypeElemclient_fournisseurs * Ptr, * Pred;
	Ptr=L->Tete;
	Pred=NULL;
	  while(Ptr!=NULL && strcmp(Ptr->Donnee.Identifiant,D)!=0)		
	   {
		Pred=Ptr;								
	    Ptr=Ptr->Suivant;						
       }
	if(Ptr!=NULL)							
	{
	  if (Pred!=NULL)							
		Pred->Suivant=Ptr->Suivant;			
		
	  if(Ptr==L->Queue)						
		L->Queue=Pred;	
								
	  if(Ptr==L->Tete)						
	    L->Tete=Ptr->Suivant;			
			
	 	  free(Ptr);											
		  L->Taille--;						
	
		printf("\tsupression bien termin%ce",130);	
			return 1;							
	}
	else
	{
	 gotoxy(45,11);
	 printf("\tn'existe pas"); 
	 return 0;
	}	
								
}
//-------------recherche dun fousnisseur ou dun client --------------


int  RechercheFC(Typelistclient_fournisseurs L ,char D[10])
{
	    int Pos=0;
		TypeElemclient_fournisseurs*Ptr;
	    Ptr=L.Tete;
  while(Ptr!=NULL && strcmp(Ptr->Donnee.Identifiant,D)!=0)			
	{
	 Ptr=Ptr->Suivant;					
	 Pos++;								
	}
	
	if (Ptr!=NULL)							
		return 1;
	else
		return-1;
}

//-------------affichage dun fousnisseur ou dun client --------------
void afficheFCA(Typelistclient_fournisseurs  L,Typelistarticle  AL,char D[10]) 
{
	TypeElemclient_fournisseurs * Ptr;							
	Ptr=L.Tete;								
    TypeElemarticle * Temp;						
	Temp=AL.Tete;	

     while (Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0) && strcmp(Temp->Donnee.Identifiant , D)!=0 ) 
	  {
	   Ptr=Ptr->Suivant;
	   Temp=Temp->Suivant;
      }
	 if(Ptr!=NULL)
	  {
	   AfficheFC(L,Ptr->Donnee.Identifiant );
	  } 
	else 
	  {
	  gotoxy(50,11);
	  printf("n'existe pas un fournisseur ou un client par cette  ID article");	
	  }	
}

//-------------modification d'un fousnisseur ou dun client --------------


 int modificationFC(Typelistclient_fournisseurs * L, char D[10])
{
       TypeElemclient_fournisseurs * Ptr;
       Ptr=L->Tete;
    while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant,D)!=0)) 
       {
        Ptr=Ptr->Suivant; 
       }
   if(Ptr!=NULL) 
     {
     gotoxy(45,6);printf ("Donner les nouvelles informations \n\n") ;
     saisirFC(&Ptr->Donnee) ;
    gotoxy(50,25); printf ("votre type est bien modifier") ;
     return 1; 
     }
   else
     {
     gotoxy(50,11);printf ("cette Identifiant n'existe pas") ;
     return 0; 
     }
}

///******************************************** Les Opération d'achat et vente ****************************************************///
///********************************************************************************************************************************///

//-------------inisialisatin d'un achat et vente --------------
void InitListarticle(Typelistarticle * L)
{
 L->Taille=0;			
  L->Tete=NULL;			
  L->Queue=NULL;	
}

//-------------saisir d'un achat et vente --------------
void InitListAV(Typelistachat_vente * L)
{
  L->Taille=0;			
  L->Tete=NULL;			
  L->Queue=NULL;
}
void saisirAV(typeachat_vente *AV)
{
	int x,status=0;
		int M,i,k,j,l ;
	system("cls");
	 k=33;
		for (i=0;i<=46;i++)
	 {
	  gotoxy(k,2) ;
	  printf("%c",205);
	  k++;
	 }
	  k=33;
	 for (i=0;i<=46;i++)
	 {
	  gotoxy(k,4) ;
	  printf("%c",205);
	  k++;
	 }
	 
	 k=32;
	 for(i=0;i<=2;i++)
	 {
	 	gotoxy(k,3);
	 	printf("%c",186);
	 }
	gotoxy(32,2);printf("%c",201);
	gotoxy(32,4);printf("%c",200);
	gotoxy(79,4);printf("%c",188);
	gotoxy(79,2);printf("%c",187);
	gotoxy(40,3); printf("ajout d'une op%cartion d'achat vente",130);
	  
	  k=79;
	 for(i=0;i<=2;i++)
	 {
	 	gotoxy(k,3);
	 	printf("%c",186);
	 }
	  
	  //***largeur*********
	  k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,7);
	   printf("%c",205); 
	   }
	   else 
	   printf("%c",203);
	   k++;
	 }
	 
	 
	 //***largeur*********
	 
	  k=15;
	  l=9;
 for(j=0;j<=9;j++)
 { if(l%2!=0)
   { k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,l);
	   printf("%c",205);
	    k++;
	   }
	   else 
	   { 
	   printf("%c",206);
	   k++;
	   }
	   
	 } 
	  l++;
   }
   else 
   l++;
  
 }


 k=15;
	 for (i=0;i<=81;i++)
	 { 
	   if (k!=61)
	   {
	   gotoxy(k,20);
	   printf("%c",205); 
	   }
	   else 
	   printf("%c",202);
	   k++;
	 }
  


 k=8;
	 for(i=0;i<=10;i++)
	  {
	  	
	    gotoxy(96,k);
	  	if(k%2==0)
	  	  printf("%c",186);
	  	else 
	  	 {
	  	 	if (k==19)
	  	 	{ 
	  	 	gotoxy(96,19);
	  	 	printf("%c",186);
			}
		   else 
		    {
		     printf("%c",185);  
		     
		    }
		  
		  }
		  k++;
	  }
	  
	  
	  k=8;
	 for(i=0;i<=5;i++)
	  {
	  	
	    gotoxy(61,k);
	  	if(k%2!=0)
	  	 {
	  	 	if (k==19)
	  	 	 {gotoxy(61,19);
	  	 	 printf("%c",186);
			 }
			     
		 }
	  	  
	  	if(k%2==0)
	  	  {
		  printf("%c",186);  
		  k++;
		   }
		k++;
	  }

 gotoxy(14,7); printf("%c",201);
 gotoxy(96,7); printf("%c",187);
 gotoxy(14,20); printf("%c",200);
 gotoxy(96,20); printf("%c",188);
 gotoxy(61,19); printf("%c",186);
 gotoxy(96,19); printf("%c",186);
	//****longueur********* 
	 k=8;
	 for(i=0;i<=11;i++)
	  {
	  	
	    gotoxy(14,k);
	  	if(k%2==0)
	  	{  
	  	  printf("%c",186);
		}
	  	else
	  	{
		  
		  if(k==19)
	  	    {
	  	    gotoxy(14,19);
	  	    printf("%c",186);
		    }
		  else 
		    printf("%c",204); 
		}
		k++;
	  }
	 
	
 gotoxy(20,8);printf("Donner l'identifiant               :");
 gotoxy(20,10);printf("Donner l'identifiant de l'article  :"); 
 gotoxy(20,12);printf("Donner la quantit%c                 :",130) ;
 gotoxy(20,14);printf("Donner la date                     : ");
 gotoxy(20,16);printf("Donner le type 0:achat/1:vente     :") ;
 gotoxy(20,18);printf("Donner l'identifinat du client ou \n                      du fornisseurs  :"); 
 gotoxy(14,19);printf("%c",186);
do
{
 gotoxy(70,8);
 scanf("%s",AV->Identifiant);}
while(alphanumerique(AV->Identifiant)==0||strlen(AV->Identifiant)<=0||strlen(AV->Identifiant)>10);


do
{
 gotoxy(70,10);
 scanf("%s",AV->ID_Article);}
while(alphanumerique(AV->ID_Article)==0||strlen(AV->ID_Article)<=0||strlen(AV->ID_Article)>15);
 

do
{
gotoxy(70,12);
 scanf ("%d",&AV->Quantite);}
while (AV->Quantite<0);


 gotoxy(70,14);
      AV->DATE = saisir_date_initiale();
      
do
{
 gotoxy(70,16);
 scanf ("%d",&x) ;
 }
while (x!=0 && x!=1);
 	
	if(x==0)
      strcpy(AV->Type, " achat");
   else
     strcpy(AV->Type, " vente");
     
     
 
do
{
 gotoxy(70,18);
 scanf("%s",AV->ID_Client_Fournisseur);}
while(alphanumerique(AV->ID_Client_Fournisseur)==0||strlen(AV->ID_Client_Fournisseur)<=0||strlen(AV->ID_Client_Fournisseur)>20);
}

//-------------ajout d'un achat et vente --------------
void AjoutAV_Fin(Typelistachat_vente * A , typeachat_vente V)
{
	TypeElemachat_vente * Ptr;							
	Ptr=(TypeElemachat_vente *)malloc(sizeof(TypeElemachat_vente));	
	
	Ptr->Donnee=V;								
	Ptr->Suivant=NULL;						
	
	if (A->Tete==NULL)							
	{
		A->Tete=Ptr;						
		A->Queue=Ptr;
	}	
	else
	{
		A->Queue->Suivant=Ptr;					
		A->Queue=Ptr;							
	}
	A->Taille++;							
}
//-------------suppression d'un achat et vente --------------
    int SupprimerAV(Typelistachat_vente * L, char  D[10])
{
           TypeElemachat_vente * Ptr, * Pred;
   Ptr=L->Tete;
   Pred=NULL;
  while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0))
   {
    Pred=Ptr;
    Ptr=Ptr->Suivant; 
   }

 if(Ptr!=NULL) 
   {
    if (Pred!=NULL) 
      Pred->Suivant=Ptr->Suivant;
    if(Ptr==L->Queue) 
      L->Queue=Pred; 
    if(Ptr==L->Tete) 
      L->Tete=Ptr->Suivant; 

    free(Ptr); 
   L->Taille--; 
      gotoxy(25,14);printf ("votre type est bien supprimer") ;
      return 1; 
   }
 else
   {
  gotoxy(40,14);printf ("cette op%cration n'existe pas",130) ;
  return 0; 
   }
}

//-------------recherche d'un achat et vente --------------
int RechercheAV(Typelistachat_vente L, char  D[10])
{
TypeElemachat_vente * Ptr ;
Ptr=L.Tete;

while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant,D)!=0)) 
 {
Ptr=Ptr->Suivant; 
 }
  if (Ptr!=NULL) 
    return 1;
  else
    return -1;
}
//-------------affichge d'un achat et vente --------------
void AfficheAV(Typelistachat_vente  L, char  D[10])
{
	TypeElemachat_vente * Ptr;							// D?claration du pointeur qui pointe sur un ?l?ment de la liste
	Ptr=L.Tete;									// On met le pointeur sur la t?te de la liste
	

while (Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0) )

{
	
		Ptr=Ptr->Suivant;
}		
				
 if (Ptr!=NULL)
	{
	 
		printf("\n\t\tIdentifiant                               : %s \n",Ptr->Donnee.Identifiant);
		printf ("\t\tidentifiant de l'article                   : %s \n" , Ptr->Donnee.ID_Article);
		printf ("\t\tl'identifinat du client ou du fornisseurs  : %s \n",Ptr->Donnee.ID_Client_Fournisseur);
		printf ("\t\ttype                                       : %s \n",Ptr->Donnee.Type); 	
		printf("\t\tLa date est                                 : %s \n",  Ptr->Donnee.DATE.jour,  Ptr->Donnee.DATE.mois,  Ptr->Donnee.DATE.annee);
		printf ("\t\tla Quantit%c                                : %d\n",130 , Ptr->Donnee.Quantite);						
	}
	else 
	gotoxy(30,8);
	printf ("n'existe pas") ;
		
}


int modificationAV(Typelistachat_vente * L , char D[10])
{
	TypeElemachat_vente * Ptr;			 
	
	Ptr=L->Tete;
	
	while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0))			// Tant que la liste n'est pas termin?e et on n'a pas trouv? l'?l?ment
	{
		
		Ptr=Ptr->Suivant;						// Passer ? l'?l?ment suivant
	}

	if(Ptr!=NULL)								// Si l'?l?ment existe
	{
		printf ("donner les nouvelles informations \n\n");
		saisirAV(&Ptr->Donnee) ;
		printf ("votre type est bien modifier");
		return 1;								// L'?l?ment a ?t? supprim?
	}
	else
	{
	gotoxy(15,8);
	printf ("cette Identifiant n'existe pas");
		return 0;								// L'?l?ment n'exsite pas
	}
			
 	
 }
///******************************************** Les Opération d'article ****************************************************///
///************************************************************************************************************************///


//-------------inistialisation d'un article --------------
void InitListA(Typelistarticle * L)
{
L->Taille=0;
L->Tete=NULL;
L->Queue=NULL;
}
//-------------saisir d'un article --------------
void saisirArticle(typearticle *A,Typelistarticle L) 
{
 	int M,i,k,j,l ;
      
   //************************************interface************************************************************************
	  k=15;
	     for (i=0;i<=81;i++)
	      { 
	         if(k!=61)
	            {
	             gotoxy(k,7);
	             printf("%c",205); 
	            }
	         else 
	           printf("%c",203);
	         k++;
	      }
	
	 //***largeur*********
	 
	    k=15;
	    l=9;
         for(j=0;j<=19;j++)
            {
			 if(l%2!=0)
               {
               k=15;
	           for (i=0;i<=80;i++)
	            { 
	             if (k!=61)
	              {
	                gotoxy(k,l);
	                printf("%c",205);
	                k++;
	              }
	             else 
	              { 
	               printf("%c",206);
	               k++;
	              } 
	            } 
	           l++;
               }
             else 
             l++;
            }
 
        k=8;
	    for(i=0;i<=18;i++)
	  {
	    gotoxy(96,k);
	  	if(k%2==0)
	  	  printf("%c",186);
	  	else 
	  	 {
		    printf("%c",185);  
		 }
		  k++;
	  }
	  
	  
	  k=8;
	 for(i=0;i<=9;i++)
	  {
	  	
	    gotoxy(61,k);
	  	if(k%2!=0)
	  	 {
	  	 	if (k==27)
	  	 	 {gotoxy(61,27);
	  	 	 printf("%c",186);
			 }
			     
		 }
	  	  
	  	if(k%2==0)
	  	  {
		  printf("%c",186);  
		  k++;
		   }
		k++;
	  }

 
	//****longueur********* 
	 k=8;
	 for(i=0;i<=18;i++)
	  {
	  	
	    gotoxy(14,k);
	  	if(k%2==0)
	  	{  
	  	  printf("%c",186);
		}
	  	else
		    printf("%c",204); 
		
		k++;
	}	
 gotoxy(14,7) ;printf("%c",201);
 gotoxy(14,27);printf("%c",200);
 gotoxy(96,7) ;printf("%c",187);
 gotoxy(96,27);printf("%c",188);
 gotoxy(61,7) ;printf("%c",203);
 gotoxy(61,27);printf("%c",202);

//*************************************************************************************************************************
   gotoxy(20,8);printf("Donner l'identifiant :"); 
   gotoxy(20,10);printf("Donner D%csignation :",130); 
   gotoxy(20,12);printf("Donner le prix d'achat HT :");
   gotoxy(20,14);printf("Donner le prix de vente HT :");
   gotoxy(20,16);printf("Donner le TVA :");
   gotoxy(20,18);printf("Donner la date de fabrication \n");
   gotoxy(20,20);printf("Donner la date d'%cxpiration \n",130);
   gotoxy(20,22);printf("Donner le d%cpot",130);
   gotoxy(20,24);printf("Donner la Quantit%c :",130) ;
   gotoxy(20,26);printf("Donner le seuil de rupture:");
   gotoxy(15,28);printf("%c Remplir ce formulaire\b",254);
do
  {
  	gotoxy(65,8 );
    scanf("%s",A->Identifiant);
  }
while(alphanumerique(A->Identifiant)==0||strlen(A->Identifiant)<=0||strlen(A->Identifiant)>10);
  
do
  {
    gotoxy(65,10);
    scanf("%s",A->Designation);
  }
while(alphanumerique(A->Designation)==0||strlen(A->Designation)<=0||strlen(A->Designation)>15);

do
  {
    gotoxy(65,12);
    scanf("%f",&A->Prixachat);
  }
while (A->Prixachat<0);

do
  {
    gotoxy(65,14);
    scanf ("%f",&A->Prixvente);
  }
while (A->Prixvente<0) ;

do
  {
    gotoxy(65,16);
    scanf ("%f",&A->TVA);
 }
while (A->TVA<0 || A->TVA>100);

 
 gotoxy(65,18);
 A->Datefab = saisir_date_initiale();
 gotoxy(65,18);
do 
  {  
   gotoxy(65,20);
   A->Dateexp = saisir_date_initiale();
  }while(verifex(A->Datefab,A->Dateexp)==0);	 
 
 do
  {
 	gotoxy(65,22);
   scanf("%s",A->Depot);
  }
while(alphanumerique(A->Depot)==0||strlen(A->Depot)<=0||strlen(A->Depot)>10);

do 
  { 
    gotoxy(65,24);
    scanf("%d",&A->Quantite) ;
  }
while (A->Quantite<0) ;


do 
  { 
    gotoxy(65,26);
    scanf("%d",&A->Seuil) ;
  }
while (A->Seuil<0) ;

 }

//------------- ajout d'un article --------------
void AjoutA_Fin(Typelistarticle * L , typearticle A)
 {
 	
    TypeElemarticle * Ptr;
     Ptr=(TypeElemarticle *)malloc(sizeof(TypeElemarticle));
          gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
          gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
          gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
   Ptr->Donnee=A;
   Ptr->Suivant=NULL;

      if(L->Tete==NULL)
         {
           L->Tete=Ptr;
           L->Queue=Ptr;
         }
      else
         {
           L->Queue->Suivant=Ptr;
           L->Queue=Ptr;
         }
    L->Taille++;
 }
//-------------suppression d'un article --------------
int SupprimerA(Typelistarticle * L, char  D[10])
  {
         TypeElemarticle * Ptr, * Pred;


     Ptr=L->Tete;
     Pred=NULL;
        while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0)) 
           {
            Pred=Ptr; 
            Ptr=Ptr->Suivant; 
           }
       if(Ptr!=NULL) 
           { 
           if(Pred!=NULL) 
              Pred->Suivant=Ptr->Suivant; 
           if(Ptr==L->Queue) 
              L->Queue=Pred; 
           if(Ptr==L->Tete) 
              L->Tete=Ptr->Suivant; 

            free(Ptr); 
            L->Taille--; 
             gotoxy(60,13);
            printf ("votre article est bien supprimer");
            return 1; 
           }
        else
           { 
            gotoxy(70,13);
			printf("cet article n'existe pas") ;
            return 0;
           }
  }
//-------------modification d'un article --------------
int modificationA(Typelistarticle L,char D[10])
{
TypeElemarticle*Ptr;
        gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
        gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
        gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
          Ptr=L.Tete;
 while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant,D)!=0))
     {
      Ptr=Ptr->Suivant; 
     }
 if(Ptr!=NULL)  
    {
    	 system("cls");
            gotoxy(0,1);printf("________________________________________________________________________________________________________________________");
            gotoxy(2,3);printf(" GESTION DE STOCK                                MALLADEAL                                    date : 22/03/2021         "); 
            gotoxy(0,4);printf("________________________________________________________________________________________________________________________");
    gotoxy(45,6);printf ("Donner les nouvelles informations") ;
    saisirArticle(&Ptr->Donnee,L) ;
    gotoxy(45,29);printf ("votre article est bien modifier ") ;
     return 1;
    }
 else
    { 
    gotoxy(45,15);
    printf ("cet article n'existe pas ") ;
    return 0; 
    }
}
//---------------
void articleperimee(Typelistarticle L)
{
	TypeElemarticle * Ptr ;
	Ptr=L.Tete;
	Date NOW ;
	int verif ; 
	
	gotoxy(40,8);
	printf("Donner la date d'aujourd'hui :");
	 gotoxy(50,9);NOW= saisir_date_initiale();
	
  while (Ptr!=NULL)
	{	
		  verif=verifex( NOW ,Ptr->Donnee.Dateexp ) ;
		  if (verif==0)
		  {
		  	AfficheA(L, Ptr->Donnee.Identifiant) ;
		  }
		 
		Ptr=Ptr->Suivant;	
    }
	if(Ptr==NULL)
	{
		gotoxy(45,12);
		printf("aucun article est p%crim%c",130,130);
		}	
}
 
//-------------recherche d'un article --------------
int RechercheA(Typelistarticle L, char  D[10])
{
   TypeElemarticle * Ptr ;
   Ptr=L.Tete;

while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0)) 
   {
    Ptr=Ptr->Suivant; 
   }
   
  if(Ptr!=NULL)
     return 1;
  else
     return -1;
}
//-------------affichage d'un article --------------

void articlerepture(Typelistarticle L) 
{ 
			TypeElemarticle * Ptr;
			
	 Ptr=L.Tete;									
  while (Ptr!=NULL )
    {
	  if(Ptr->Donnee.Quantite<Ptr->Donnee.Seuil)
	   {
		gotoxy(50,10);	printf ("Voici les Articles qui sont en repture de stock \n \n  ") ;
	    AfficheA(L,Ptr->Donnee.Identifiant) ; 
	   }
	  Ptr=Ptr->Suivant;	
    }

}
void AfficheA(Typelistarticle  L, char  D[10])
{
	TypeElemarticle * Ptr;							
	Ptr=L.Tete;	
		int M,i,k,j,l ;
      
   //************************************interface*************************************************************************

	

/*	  k=15;
	     for (i=0;i<=81;i++)
	      { 
	         if(k!=61)
	            {
	             gotoxy(k,7);
	             printf("%c",205); 
	            }
	         else 
	           printf("%c",203);
	         k++;
	      }
	
	 //***largeur*********
	 
	    k=15;
	    l=9;
         for(j=0;j<=19;j++)
            {
			 if(l%2!=0)
               {
               k=15;
	           for (i=0;i<=80;i++)
	            { 
	             if (k!=61)
	              {
	                gotoxy(k,l);
	                printf("%c",205);
	                k++;
	              }
	             else 
	              { 
	               printf("%c",206);
	               k++;
	              } 
	            } 
	           l++;
               }
             else 
             l++;
            }
 
        k=8;
	    for(i=0;i<=18;i++)
	  {
	    gotoxy(96,k);
	  	if(k%2==0)
	  	  printf("%c",186);
	  	else 
	  	 {
		    printf("%c",185);  
		 }
		  k++;
	  }
	  
	  
	  k=8;
	 for(i=0;i<=9;i++)
	  {
	  	
	    gotoxy(61,k);
	  	if(k%2!=0)
	  	 {
	  	 	if (k==27)
	  	 	 {gotoxy(61,27);
	  	 	 printf("%c",186);
			 }
			     
		 }
	  	  
	  	if(k%2==0)
	  	  {
		  printf("%c",186);  
		  k++;
		   }
		k++;
	  }

 
	//****longueur********* 
	 k=8;
	 for(i=0;i<=18;i++)
	  {
	  	
	    gotoxy(14,k);
	  	if(k%2==0)
	  	{  
	  	  printf("%c",186);
		}
	  	else
		    printf("%c",204); 
		
		k++;
	}
	
 gotoxy(14,7);  printf("%c",201);
 gotoxy(14,27); printf("%c",200);
 
 gotoxy(96,7); printf("%c",187);
 gotoxy(96,27); printf("%c",188);
 
 gotoxy(61,7); printf("%c",203);
 gotoxy(61,27); printf("%c",202);*/

//*************************************************************************************************************************
while (Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant , D)!=0) )
{	
		Ptr=Ptr->Suivant;
}		
 if (Ptr!=NULL )
	{

	    printf("\n\n\t\t\t\tIdentifiant                :\t%s\n",Ptr->Donnee.Identifiant);		
	    printf ("\t\t\t\tla d%csignation             :\t%s\n" , 130,Ptr->Donnee.Designation) ;
        printf ("\t\t\t\tPrix d'achat HT            :\t%f\n",Ptr->Donnee.Prixachat) ;
	    printf ("\t\t\t\tPrix de vente HT           :\t%f\n",Ptr->Donnee.Prixvente) ;
	    printf ("\t\t\t\tTVA                        :\t%f\n",Ptr->Donnee.TVA) ; 	
		printf ("\t\t\t\tLa date de fabrication est :\t%s\n",Ptr->Donnee.Datefab.jour,  Ptr->Donnee.Datefab.mois,  Ptr->Donnee.Datefab.annee);
		printf ("\t\t\t\tLa date d'expiration est   :\t%s\n",Ptr->Donnee.Dateexp.jour,  Ptr->Donnee.Dateexp.mois,  Ptr->Donnee.Dateexp.annee);
		printf ("\t\t\t\tLe d%cpot                   :\t%s\n",130,Ptr->Donnee.Depot) ;
		printf ("\t\t\t\tla Quantit%c                :\t%d\n",130,Ptr->Donnee.Quantite) ;
	    printf ("\t\t\t\tLe seuil de r%cpture est    :\t%d\n",130,Ptr->Donnee.Seuil);	
		
								
	}
	else 
	printf ("n'existe pas") ;		
}
//-----------------------------unicité de l'article-------------------------------
int unique_article(Typelistarticle L ,char D[10])
{
TypeElemarticle * Ptr ;
Ptr=L.Tete;

while(Ptr!=NULL && (strcmp(Ptr->Donnee.Identifiant,D)!=0)) 
 {
  Ptr=Ptr->Suivant; 
 }
  if(Ptr!=NULL) 
    return 1;
  else
    return-1;
}

 
///------------------------------interface----------------------------
///*******************************************************************
 void Color(int couleurDuTexte,int couleurDeFond) 
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

 void gotoxy(int x,int y) 
{ 
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos={x,y};
	SetConsoleCursorPosition(hConsole,Pos);
}



///-------------------contrainte de saisie-------------------------------------
///******************************************************************
 int alphanumerique(char msg[20])
 { 
  int i=0 ;
    while(i<strlen(msg) && (msg[i]>=97 && msg[i]<=122 || msg[i]>=65 && msg[i]<=90 || msg[i]>=48 && msg[i]<=57))
     i++;
  if (i==strlen(msg))
     return 1;
  else 
     return(0); 
 }


 int numerique (char mess[30])
{
   int i=0 ;
     while(i<strlen(mess)&& mess[i]>=48 && mess[i]<=57)
        i++;
     if (i==strlen(mess))
        return 1;
     else   
        return 0;
}
///************************************DATE***********************************/
int nb_jour_mois(int mois, int annee)
{
switch(mois)
{ case 1:case 3:case 5:case 7:case 8:case 10:case 12: return(31);
break;
case 4:case 6:case 9:case 11: return(30); break;
case 2: if(annee%4==0)
return(29);
else
return(28);
}}

 Date saisir_date_initiale()
{
Date t;
int j,m,a;

do
{
  scanf("%s/%s/%s",t.jour,t.mois,t.annee) ;
  a=atoi(t.annee);
  m=atoi(t.mois);
  j=atoi(t.jour);
}
 while ((a<0)||(m<0||m>12)||((j<0)||(j>nb_jour_mois(m,a)))|| strlen(t.jour)<2 || strlen(t.mois)<2 ||strlen(t.annee)<4 );
    return (t) ;
}





int verifex( Date datefab , Date dateexp)
{
  int jf,je,mf,me,af,ae;
  af=atoi(datefab.annee);
  ae=atoi(dateexp.annee);
  jf=atoi(datefab.jour);
  je=atoi(dateexp.jour);
  mf=atoi(datefab.mois);
  me=atoi(dateexp.mois);
  
	if (af<ae) 
			return 1 ;	
       else
       {
         if(af>ae) 
            return 0;
               else 
		       { 
			     if(mf<me) 
				   return 1;
			     else
				 {
				   if(mf>me) 
			     	return 0;
			       else 
			       {
			       	if(jf<je)
			       	  return 1;
			       	   else 
			       	    {
			       	   	if(jf>=je)
			       	   	  return 0;
					    }
				   }
			     
				} 
		      }
	   }
}

