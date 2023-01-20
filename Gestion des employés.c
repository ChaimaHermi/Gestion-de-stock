#include <stdio.h>
#include <conio.h >
#include <stdlib.h>
#include <windows.h>



void Color(int couleurDuTexte,int couleurDeFond);
void gotoxy(int x,int y);

struct employe
   {
   	int identifiant;
   	char prenom[15];
   	char nom[15];
   	char direction[15];
   	char poste[15] ;
   	float salaire ;
   	int ChargeHoraireParSemaine;
   };
  
 main()
 { 
 /*-----------------------déclaration------------------------*/

  struct employe tabemploye[100];
  int i,j,ID,N,Nbr,x,trouve,modifier,afficher,supp,txt,fond;
  Color(5,0); 
  /*-------------------presentation-------------------------*/
do
   { 
  printf("\n");
  printf("\n");
   gotoxy(49,5); printf("gestion des employ%cs\n",130);
   Color(7,0);
   gotoxy(42,6);printf("*********************************\n ");
   gotoxy(45,7); printf("***************************\n ");
   gotoxy(49,8);printf("*******************");
  
/*-----------------------menu--------------------------------*/
  
		
	 do
	  { 
	   Color(5,0);
	   
	   gotoxy(42,11);printf("_____________________________\n");
       gotoxy(41,12);printf("|");
       gotoxy(41,13);printf("|");
       gotoxy(41,14);printf("|");
       gotoxy(41,15);printf("|");
       gotoxy(41,16);printf("|");
       gotoxy(41,17);printf("|");
       gotoxy(41,18);printf("|");
       gotoxy(41,19);printf("|");
       gotoxy(41,20);printf("|");
       gotoxy(41,21);printf("|");
       gotoxy(70,12);printf(" |");
       gotoxy(70,13);printf(" |");
       gotoxy(70,14);printf(" |");
       gotoxy(70,15);printf(" |");
       gotoxy(70,16);printf(" |");
       gotoxy(70,17);printf(" |");
       gotoxy(70,18);printf(" |");
       gotoxy(70,19);printf(" |");
       gotoxy(70,20);printf(" |");
       gotoxy(41,21);printf("|_____________________________|");
       Color(7,0);
	   gotoxy(55,13);printf("MENU\n");  
	   Color(5,0); 
	   gotoxy(53,14);printf("********");
	   Color(7,0);
	   gotoxy(43,15);printf(" 1: Ajouter un employ%c   ",130); 
	   gotoxy(43,16);printf(" 2: Supprimer un employ%c ",130);
	   gotoxy(43,17);printf(" 3: Modofier un employ%c  ",130);
	   gotoxy(43,18);printf(" 4: Afficher un employ%c  ",130);
	   gotoxy(43,19);printf(" 5: Cherher un employ%c   ",130);
	   gotoxy(43,20);printf(" 6: Quitter         ");
	  
	     
       
        printf("\n");
        printf("\n");
        printf("\n");
        Color(7,0);  
        printf("\t\t\t\tD'apr%cs ce menu qu'est-ce que vous voulez faire ?\n\t\t\t\t Donner un nombre entre 1 et 6: ",130); 
        scanf("%d",&Nbr);
      }   
	 while (Nbr<1 || Nbr>6);
     system("cls"); 
/*--------------------------------------------------------------------------------------*/
 switch (Nbr) 
    {
     case 1: /*ajout d'un emplyer */
        {
		printf("\n");
       printf("\n");
       printf("\n");
       Color(5,0);
	   printf("\t\t\t     *******************");
	   Color(5,7);
	   printf("l'ajout d'un employ%c",130);
	   Color(5,0);
	   printf("*******************\n");
	   Color(7,0);
	   printf("\n");
       printf("\n");
       printf("\n");  
        Color(5,7);
	   printf("\t\t\tÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	   printf("\t\t\t³Donner l'identifiant                 :³                              ³\n");
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("\t\t\t³Donner le pr%cnom                     :³                              ³\n",130);
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("\t\t\t³Donner le nom                        :³                              ³\n");
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
       printf("\t\t\t³Donner la direction                  :³                              ³\n");
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("\t\t\t³Donner le poste                      :³                              ³\n"); 
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("\t\t\t³Donner le salaire                    :³                              ³\n");
	   printf("\t\t\tÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("\t\t\t³Donner le Charge horaire par semaine :³                              ³\n");
	   printf("\t\t\tÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
 	    gotoxy(65,8 ); scanf("%d",&tabemploye[N].identifiant);
 	    gotoxy(65,10);scanf("%s",&tabemploye[N].prenom);
 	    gotoxy(65,12);scanf("%s",&tabemploye[N].nom);
 	    gotoxy(65,14);scanf("%s",&tabemploye[N].direction);
 	    gotoxy(65,16);scanf("%s",&tabemploye[N].poste);
 	    gotoxy(65,18);scanf("%f",&tabemploye[N].salaire);
 	    gotoxy(65,20);scanf("%d",&tabemploye[N].ChargeHoraireParSemaine);
	   N=N+1;
	   
	   Color(5,0);
	    gotoxy(35,24);printf("l'ajout de ce employ%c est bien termin%c",130,130);
	   }
	   
	   {
	     Color(7,0);
	     gotoxy(38,26);printf("Appuyez sur z%cro pour continuer ",130);
	     scanf("%d",&x);
	     if (x==0)
	     system("cls");
	     Color(5,0); 
	   }
       break;
        /*-------------------------------------------------------------------------------------------------------------------------------*/
       case 2:
             { 
			  printf("\n"); /* suppresson d'un employe*/
              printf("\n");
              printf("\n");
	          Color(5,0);
	          printf("\t\t\t     *******************");
	          Color(5,7);
	          printf("suppression d'un employ%c",130);
	          Color(5,0);
	          printf("*******************\n");
	          Color(7,0);
	          printf("\n");
              printf("\n");
              printf("\n");  
              printf("\t\t\t\t Donner l'identifiant de l'employ%c que vous voulez supprimer :",130);
			  printf("\n");
			  printf("\n");
			  Color(5,0);
	   	     gotoxy(48,9);printf("  _____________________________\n");
             gotoxy(49,10);printf("|");gotoxy(49,11);printf("|");gotoxy(49,12);printf("|");
             gotoxy(79,10);printf("|");gotoxy(79,11);printf("|");gotoxy(79,12);printf("|");
             gotoxy(50,12);printf("_____________________________\n");
             Color(7,0);
              gotoxy(52,11);printf("ID = ");
	   	      gotoxy(57,11);scanf("%d",&ID);
	   	      //////////supp////////////
	   	       
	   	       supp=0;
	   	        while(i<N && supp==0)
	   	           {
	   	         	if (tabemploye[i].identifiant==ID)
	   	         	supp=1;
	   	         	else 
	   	         	i++;
					}
					if (supp==0)
					{ Color(5,0);
			   	     printf("\n");
			   	     gotoxy(40,16);
			   	     printf("l'employ%c que vous voulez supprimer n'existe pas\n ",130);
			   	     Color(7,0);
			   	      gotoxy(45,18);
	                	printf("  Appuez sur z%cro pour continuer  ",130);
	                 	scanf("%d",&x);
	                    if (x==0)
	                    system("cls");
	                    Color(5,0);
					}
					else if (supp==1) 
					{
					 for (j==i;j<=N-1;j++)	
					 tabemploye[j]=tabemploye[j+1];
					  Color(5,0); 
				      gotoxy(39,15);
			       	   printf("suppression termin%ce ",130);
			       	   N--;
			       	    Color(7,0);
			       	   gotoxy(42,17); 	printf(" Appuez sur z%cro pour continuer  ",130);
	                	scanf("%d",&x);
	                    if (x==0)
	                   system("cls");
	                    Color(5,0);
					}
		  break;
	   
	   case 3:
	   	{
	    printf("\n");
        printf("\n");
        printf("\n");
	   	Color(5,0);
	    printf("\t\t\t     *******************");
	    Color(5,7);
	    printf("modification d'un employ%c",130);
        Color(5,0);
	    printf("*******************\n");
	    Color(7,0);
  	    printf("\n");
	    printf("\n");
	     printf("\n");
	   	printf("\t\t\t\t  Donner l'identifiant de l'employ%c que vous voulez modifier\n ",130);
	   	printf("\n");
		printf("\n");
		 Color(5,0);
	   	     gotoxy(48,9);printf("  _____________________________\n");
             gotoxy(49,10);printf("|");gotoxy(49,11);printf("|");gotoxy(49,12);printf("|");
             gotoxy(79,10);printf("|");gotoxy(79,11);printf("|");gotoxy(79,12);printf("|");
             gotoxy(50,12);printf("_____________________________\n");
	   	      Color(7,0);
	    gotoxy(52,11);printf("ID = ");
	   	      gotoxy(57,11);scanf("%d",&ID);
		 modifier=0;
	   	        while(i<N && modifier==0)
	   	           {
	   	         	if (tabemploye[i].identifiant==ID)
	   	         	modifier=1;
	   	         	else 
	   	         	i++;
					}
	
		 if (modifier==1) 
	   	{
			 Color(7,0);
	   gotoxy(42,5);printf(    "modification de l'employ%c",130);
	   printf("\n");
	    printf("\n");
	   Color(5,0);
	   printf("                  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
	   printf("                  ³Donner le nouveau pr%cnom                     :³                               ³\n",130);
	   printf("                  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("                  ³Donner le nouveau nom                        :³                               ³\n");
	   printf("                  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
       printf("                  ³Donner la nouveau direction                  :³                               ³\n");
	   printf("                  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("                  ³Donner le nouveau poste                      :³                               ³\n"); 
	   printf("                  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("                  ³Donner le nouveau salaire                    :³                               ³\n");
	   printf("                  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
	   printf("                  ³Donner le nouveau Charge horaire par semaine :³                               ³\n");
	   printf("                  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
	   Color(7,0);
 	    gotoxy(66,8);scanf("%s",&tabemploye[i].prenom);
 	    gotoxy(66,10);scanf("%s",&tabemploye[i].nom);
 	    gotoxy(66,12);scanf("%s",&tabemploye[i].direction);
 	    gotoxy(66,14);scanf("%s",&tabemploye[i].poste);
 	    gotoxy(66,16);scanf("%f",&tabemploye[i].salaire);
 	    gotoxy(66,18);scanf("%d",&tabemploye[i].ChargeHoraireParSemaine);
 	     Color(5,0);gotoxy(42,22);printf("modification termin%ce\n\n",130);
 	     Color(7,0);
		             gotoxy(44,24);printf(" Appuez sur z%cro pour continuer  ",130);
		            scanf("%d",&x);
	               if (x==0)
	               system("cls");
		 }
		
	  
	    else 
				  if (modifier==0)
			   	    {
					 Color(5,0); 
			    	 gotoxy(39,15);printf("l'employ%c que vous voulez modifier n'existe pas\n ",130);
			    	  Color(7,0);
		             gotoxy(39,17);printf(" Appuez sur z%cro pour continuer  ",130);
		            scanf("%d",&x);
	               if (x==0)
	               system("cls");
	               Color(5,0); 
				    } 
	
		 }
 	 
		break;

	   case 4:
	   	{
		  
	    printf("\n");
        printf("\n");
        printf("\n");
	   	Color(5,0);
	    printf("\t\t\t     *******************");
	    Color(5,7);
	    printf("affichage d'un employ%c",130);
        Color(5,0);
	    printf("*******************\n");
	    Color(7,0);
  	    Color(7,0);
  	    printf("\n");
	    printf("\n");
	     printf("\n");
	   	printf("\t\t\t\t  Donner l'identifiant de l'employ%c que vous voulez afficher\n ",130);
	   	printf("\n");
		printf("\n");
		 Color(5,0);
	   	     gotoxy(48,9);printf("  _____________________________\n");
             gotoxy(49,10);printf("|");gotoxy(49,11);printf("|");gotoxy(49,12);printf("|");
             gotoxy(79,10);printf("|");gotoxy(79,11);printf("|");gotoxy(79,12);printf("|");
             gotoxy(50,12);printf("_____________________________\n");
	   	     Color(7,0);
	         gotoxy(52,11);printf("ID = ");
	   	     gotoxy(57,11);scanf("%d",&ID);
	   	   
	 
	   	       afficher=0;
	   	        while(i<N && afficher==0)
	   	           {
	   	         	if (tabemploye[i].identifiant==ID)
	   	         	afficher=1;
	   	         	else 
	   	         	i++;
					}
		   if (afficher==1)
	        {   
	          gotoxy(42,14); printf("voici l'employ%c que vous voulez affichier\n ",130);
              printf("\n");
              Color(5,0);     
	      gotoxy(39,16);printf(" ________________________________________________ \n");
          gotoxy(39,17);printf("|                       |                        |\n");
          gotoxy(39,18);printf("|   le pr%cnom   :       |                        |\n",130);
          gotoxy(39,19);printf("|_______________________|________________________|\n");
          gotoxy(39,20);printf("|                       |                        |\n");
          gotoxy(39,21);printf("|   le nom      :       |                        |\n");
          gotoxy(39,22);printf("|_______________________|________________________|\n");
          gotoxy(39,23);printf("|                       |                        |\n");
          gotoxy(39,24);printf("|   le direction:       |                        |\n");
          gotoxy(39,25);printf("|_______________________|________________________|\n");
          gotoxy(39,26);printf("|                       |                        |\n");
          gotoxy(39,27);printf("|  le poste    :        |                        |\n");
          gotoxy(39,28);printf("|_______________________|________________________|\n");
          gotoxy(39,29);printf("|                       |                        |\n");
          gotoxy(39,30);printf("|  le salaire  :        |                        |\n");
          gotoxy(39,31);printf("|_______________________|________________________|\n");
          gotoxy(39,32);printf("|  charge horaire       |                        |\n");
          gotoxy(39,33);printf("|   par semaine :       |                        |\n");
          gotoxy(39,34);printf("|_______________________|________________________|\n"); 
          Color(7,0);
          gotoxy(65,18);printf("%s",tabemploye[i].prenom);
          gotoxy(65,21);printf("%s",tabemploye[i].nom);
          gotoxy(65,24);printf("%s",tabemploye[i].direction);
          gotoxy(65,27);printf("%s",tabemploye[i].poste);
          gotoxy(65,30);printf("%f",tabemploye[i].salaire);
          gotoxy(65,33);printf("%d",tabemploye[i].ChargeHoraireParSemaine);
          
        
	  
					gotoxy(42,36); Color(7,0);printf("Appuez sur z%cro pour continuer  ",130);
	         	    scanf("%d",&x);
	                if (x==0)
	                system("cls");
	                Color(5,0); 
	          
	        }
		 
		    else if (afficher==0)
				
			   	      {
					   	 Color(5,0); 
				    gotoxy(39,15);printf("l'employ%c que vous voulez affichier n'existe pas\n ",130);
				    Color(7,0);
					gotoxy(42,17);printf("Appuez sur z%cro pour continuer  ",130);
	         	    scanf("%d",&x);
	                if (x==0)
	                system("cls");
	                Color(5,0); 
				      }
	    } 
	   
	  
	
	    break;
        
	  case 5:
	  	
	  	{
		  
	         printf("\n");
            printf("\n");
            printf("\n");
	   	    Color(5,0);
	        printf("\t\t\t     *******************");
	        Color(5,7);
	        printf("recherche d'un employ%c",130);
	        Color(5,0);
	        printf("*******************\n");
	        Color(7,0);
	        printf("\n");
            printf("\n"); 
	      	printf("\t\t\t\tDonner l'identifiant de l'employ%c que vous voulez chercher\n ",130);
	        printf("\n");
			  Color(5,0);
	   	     gotoxy(48,9);printf("  _____________________________\n");
             gotoxy(49,10);printf("|");gotoxy(49,11);printf("|");gotoxy(49,12);printf("|");
             gotoxy(79,10);printf("|");gotoxy(79,11);printf("|");gotoxy(79,12);printf("|");
             gotoxy(50,12);printf("_____________________________\n");
	   	     Color(7,0);
	         gotoxy(52,11);printf("ID = ");
	   	     gotoxy(57,11);scanf("%d",&ID);
	   	     trouve=0;
	   	     while (i<N && trouve==0)
	   	     {if (tabemploye[i].identifiant==ID)
	   	     trouve=1;
	   	     else 
	   	     i++;
				}
	           if (trouve==0)
			   	      {
                       Color(5,0); 
				       gotoxy(39,15);printf("l'employ%c que vous voulez chercher n'existe pas\n ",130);
				       {Color(7,0);
	               	    gotoxy(42,17);printf("Appuez sur z%cro pour continuer  ",130);
		                scanf("%d",&x);
	                    if (x==0)
	                    system("cls");
	                    Color(5,0); 
				      }}
				 else if(trouve==1)
	   	        { 
                 gotoxy(42,14);printf("voici l'employ%c que vous voulez chercher\n\n ",130);
                 
           Color(5,0);     
	      gotoxy(39,16);printf(" ________________________________________________ \n");
          gotoxy(39,17);printf("|                       |                        |\n");
          gotoxy(39,18);printf("|   le pr%cnom   :       |                        |\n",130);
          gotoxy(39,19);printf("|_______________________|________________________|\n");
          gotoxy(39,20);printf("|                       |                        |\n");
          gotoxy(39,21);printf("|   le nom      :       |                        |\n");
          gotoxy(39,22);printf("|_______________________|________________________|\n");
          gotoxy(39,23);printf("|                       |                        |\n");
          gotoxy(39,24);printf("|   le direction:       |                        |\n");
          gotoxy(39,25);printf("|_______________________|________________________|\n");
          gotoxy(39,26);printf("|                       |                        |\n");
          gotoxy(39,27);printf("|  le poste    :        |                        |\n");
          gotoxy(39,28);printf("|_______________________|________________________|\n");
          gotoxy(39,29);printf("|                       |                        |\n");
          gotoxy(39,30);printf("|  le salaire  :        |                        |\n");
          gotoxy(39,31);printf("|_______________________|________________________|\n");
          gotoxy(39,32);printf("|  charge horaire       |                        |\n");
          gotoxy(39,33);printf("|   par semaine :       |                        |\n");
          gotoxy(39,34);printf("|_______________________|________________________|\n"); 
          Color(7,0);
          gotoxy(65,18);printf("%s",tabemploye[i].prenom);
          gotoxy(65,21);printf("%s",tabemploye[i].nom);
          gotoxy(65,24);printf("%s",tabemploye[i].direction);
          gotoxy(65,27);printf("%s",tabemploye[i].poste);
          gotoxy(65,30);printf("%f",tabemploye[i].salaire);
          gotoxy(65,33);printf("%d",tabemploye[i].ChargeHoraireParSemaine);
          Color(7,0);
		gotoxy(42,50);printf("Appuez sur z%cro pour continuer  ",130);
		scanf("%d",&x);
	    if (x==0)
	    system("cls");
	    Color(5,0); 
	      }    
	        

	   break;  	

	   case 6:
	   	{
		  
	   	printf("\n");
	    printf("\n");
	   	printf("\n");
	   	printf("\n");
	   	printf("\n");
	    printf("\n");
		printf("\n");
	    printf("\n");
	    Color(7,0);
		printf("\t\t\t\t\t  *********************************\n");
		printf("\t\t\t\t\t  * ***************************** *\n");
		printf("\t\t\t\t\t  * *                           * *\n");
		printf("\t\t\t\t\t  * *                           * *\n");
	    printf("\t\t\t\t\t  * *                           * *\n");
	    printf("\t\t\t\t\t  * ***************************** *\n"); 
		printf("\t\t\t\t\t  *********************************\n"); 
	Color(5,0);
	 gotoxy(54,11);printf("AU REVOIR ");
		printf("\n");
	   	printf("\n");
	   	printf("\n");
	   	printf("\n");
	    printf("\n");
	    Color(7,0);
		  }
	}
  }}}
 while (Nbr!=6);
}

  void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

 void gotoxy(int x,int y)  /*scanf**************************************/
{ 
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos={x,y};
	SetConsoleCursorPosition(hConsole,Pos);
}


