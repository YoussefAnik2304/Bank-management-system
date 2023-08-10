#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
FILE *f;
int i,j;
int menu_sortie;
void menu();
void sortie();
void menuAdmion();
void menugenenrale();
typedef struct {

int id ;
char password [20];



}admin;
int testa(){
	int annee;

	printf("\n\t\t\t\t\t\tANNEE : ");
	scanf("%d",&annee);
	if(annee<1900 )
	{
		printf("ANNEE DE NAISSANCE INVALIDE ");
		testa();
	}
	else if (annee>2004){
		printf("VOUS DEVEZ ETRE AG%cE DE 18 ANS POUR CREER UN COMPTE BANCAIRE",144);
		testa();
	}
	return annee;
}
int testm(){
	int mois ;
	printf("\n\t\t\t\t\t\tMOIS : ");
	scanf("%d",&mois);
	if(mois<1 || mois>12){
		printf("SASIE DE MOIS IMPOSSIBLE SASIR UN MOIS ENTRE 1 ET 12 :\n");
		testm();
	}
	return mois ;
}
int testj(int a,int m ){
	int jour;
	printf("\n\t\t\t\t\t\tJOUR : ");
	scanf("%d",&jour);
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	{
		if(jour>31 || jour <0){
			printf("SAISIE INVALIDE ");
			testj(a,m);
		}
	}
	else if (m==4||m==6||m==9||m==11){
		if(jour>30 || jour <0){
			printf("SAISIE INVALIDE ");
			testj(a,m);
		}
	}
	else if (m==2){
		if((a%4==0 && a%100!=0) || (a%400==0)){
			if(jour>29 || jour <0){
			printf("SAISIE INVALIDE ");
			testj(a,m);
			}
		}
		else{
			if(jour>28 || jour <0){
			printf("SAISIE INVALIDE ");
			testj(a,m);
			}
		}
	}
	return jour;
}
char testpass(char  pass[20]){
	int i;
	int cmp=0;
	printf("\n\t\t\t\t\tSASIR UN MOT DE PASS : ");
 	scanf("%s",pass);
 	if(strlen(pass)<5){
 		printf("VOTRE MOT DE PASS EST TRES COURT UN MOT DE PASS SECURIS%c DOIT CONTENIR AU MOINS 5 CHARACTERES",144);
 		testpass(pass);
	 }
	else{
		for(i=0;pass[i]!='\0';i++){
			if(isdigit(pass[i])!=0)
				cmp++;
		}
		if(cmp==0)
		{
			printf("UN MOT DE PASS FORT DOIT CONTENIR AU MOINS UN CHIFFRE ");
			testpass(pass);
		}
	}
	return *pass;
}
void sortie (){

     printf("\n\n\t\t\t\t%c%c%c%c%c%c MERCI DE VOTRE VISITE  %c%c%c%c%c%c",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
}
 typedef struct date{
    int jour,mois,annee;
    }date;
typedef struct{
    int id ;
    char nom [20] ,prenom[20];
    char adresse [100] ,cin[20];
    int tel;
    date date_naissance;
    float  solde ;
    char password[50];
}infos;
typedef struct {
    char typeop[30];
    float nbr;
}registre;
void creation (){
    char CinN [20];
    char pass[50];
    Client a;
    FILE *f;
    FILE *p ;
    p=fopen("record.dat","a");
    registre registre ;
    int idN;
    idN=1;
	f=fopen("projetD.dat","r");
	system("cls");
    printf("\n\t\t\t\t\tSASIR VOTRE CIN :");
    scanf("%s",CinN);
    int cmp =0 ;
    while (fread(&a,sizeof(Client),1,f )>0)
    {
    	idN=a.getid();
         if (strcmp(CinN,Client.cin)==0)
            cmp=1;
    }
    fclose(f);
    if (cmp!=0)
    {
    	test:
        printf("\n\t\t\t\tCE COMPTE EXISTE DEJA  \n");
        printf("\n\t\t\t\t[1] POUR REASAYER \n\t\t\t\t[2]POUR REVENIR AU MENU INITIAL  \n\t\t\t\t[0] POUR SORTIR \n");
            printf("\n\t\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                creation();
            else if(menu_sortie==2)
            	menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto test;
            }
    }
    else{
        f = fopen("projetD.dat","a");
        strcpy(personne.cin,CinN);
        personne.id=idN+1;
        printf("\n\t\t\t\t\tSASIR VOTRE NOM : ");
        scanf("%s",personne.nom);
        printf("\n\t\t\t\t\tSAISIR VOTRE PRENOM: ");
        scanf("%s",personne.prenom);
        printf("\n\t\t\t\t\tSASIR VOTRE ADRESSE COMPLETE : ");
        fflush(stdin);
        gets(personne.adresse);
        printf("\n\t\t\t\t\tSASIR VOTRE NUMERO DE TELEPHONE MOBILE : 0");
        scanf("%d",&personne.tel);
        printf("\n\t\t\t\t\tSASIR VOTRE DATE DE NAISSANCE JJ/MM/AAAA: \n");
        personne.date_naissance.annee=testa();
        personne.date_naissance.mois=testm();
        personne.date_naissance.jour=testj(personne.date_naissance.annee,personne.date_naissance.mois);
        printf("\n\t\t\t\t\tSASIR LA MONTANT DE L INSCRIPTION : ");
        scanf("%f",&personne.solde);
        testpass(personne.password);
        strcpy(pass,personne.password);
        fwrite(&personne,sizeof(personne),1,f );
        fclose(f);
        strcpy(registre.typeop,"Creation ");
        registre.nbr=1;
        fwrite(&registre,sizeof(registre),1,p);
        fclose(p);
        system("cls");
        printf("\n\n\n\n\t\t\t VOTRE COMPTE EST CR%cER AVEC SUCCES !\n",144);
        printf("\n\t\t\t VOTRE NUMERO DE COMPTE EST : %d\n",idN+1);
        printf("\t\t\t VOTRE MOT DE PASS EST :%s\n",pass);
            test2:
            printf("\n\t\t\t\t[1] POUR REVENIR AU MENUE INITIAL  \n\t\t\t\t[0] POUR SORTIR  \n");
            printf("\n\t\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto test2;
            }
    }
}
void creation1 (){
    char CinN [20];
    char pass[50];
    infos personne ;
    FILE *f;
    FILE *p;
    p=fopen("registre.txt","a");
    registre registre ;
    int idN;
    idN=1;
	f=fopen("projetD.dat","r");
	system("cls");
    printf("\n\t\t\t\t\tSASIR VOTRE CIN :");
    scanf("%s",CinN);
    int cmp =0 ;
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
    	idN=personne.id;
         if (strcmp(CinN,personne.cin)==0)
            cmp=1;
    }
    fclose(f);
    if (cmp!=0)
    {
    	test:
        printf("CE COMPTE EXISTE DEJA  \n");
        printf("\n\t\t\t\t[1] POUR REASAYER \n\t\t\t\t[2]POUR REVENIR AU MENU INITIAL  \n\t\t\t\t[0] POUR SORTIR \n");
            printf("\n\t\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                creation();
            else if(menu_sortie==2)
            	menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto test;
            }
    }
    else{
        f = fopen("projetD.dat","a");
        strcpy(personne.cin,CinN);
        personne.id=idN+1;
        printf("\n\t\t\t\t\tSASIR VOTRE NOM : ");
        scanf("%s",personne.nom);
        printf("\n\t\t\t\t\tSAISIR VOTRE PRENOM: ");
        scanf("%s",personne.prenom);
        printf("\n\t\t\t\t\tSASIR VOTRE ADRESSE COMPLETE : ");
        fflush(stdin);
        gets(personne.adresse);
        printf("\n\t\t\t\t\tSASIR VOTRE NUMERO DE TELEPHONE MOBILE : 0");
        scanf("%d",&personne.tel);
        printf("\n\t\t\t\t\tSASIR VOTRE DATE DE NAISSANCE JJ/MM/AAAA: \n");
        personne.date_naissance.annee=testa();
        personne.date_naissance.mois=testm();
        personne.date_naissance.jour=testj(personne.date_naissance.annee,personne.date_naissance.mois);
        printf("\n\t\t\t\t\tSASIR LA MONTANT DE L INSCRIPTION : ");
        scanf("%f",&personne.solde);
        testpass(personne.password);
        strcpy(pass,personne.password);
        fwrite(&personne,sizeof(personne),1,f );
        fclose(f);
        strcpy(registre.typeop,"Creation ");
        registre.nbr=1;
        fwrite(&registre,sizeof(registre),1,p);
        fclose(p);
        system("cls");
        printf("\n\n\n\n\t\t\t VOTRE COMPTE EST CR%cER AVEC SUCCES !\n",144);
        printf("\n\t\t\t VOTRE NUMERO DE COMPTE EST : %d\n",idN+1);
        printf("\t\t\t VOTRE MOT DE PASS EST :%s\n",pass);
            test2:
            printf("\n\t\t\t\t[1] POUR REVENIR AU MENUE INITIAL  \n\t\t\t\t[0] POUR SORTIR  \n");
            printf("\n\t\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\t\t\tInvalide!\a");
                goto test2;
            }
    }
}
void modification(){
    FILE *modif;
    FILE *f;
    infos personne ;

    char cinN[15];
    char pass[20];
    char passwordN[50],adressN[50];
    FILE *p ;
    p=open("registre.txt","a");
    registre registre ;
    test6:
	modif=fopen("newupd.dat","w");
    f=fopen("projetD.dat","r");
    printf("\n\n\t\t\t\tENTRER VOTRE CIN : ");
    scanf("%s",cinN);
    printf("\n\t\t\t\tENTRER VOTRE MOT DE PASS : ");
    scanf("%s",passwordN);
    int cmp ;
        while (fread(&personne,sizeof(personne),1,f )>0)
   		 {
            if(strcmp(cinN,personne.cin)==0 && strcmp(passwordN,personne.password)==0)
            	{
	                cmp=1;
	                test5:
	                system("cls");
	                printf("\n\t\t\t\tQUELLE INFORMATIONS VOUS VOULEZ MODIFIER ?\n\n\t\t\t\t[1]ADRESSE\n\t\t\t\t[2] NUMERO DE TELEPHONE\n\t\t\t\t[3] MOT DE PASS\n ");
	                int choix ;
	                printf("\n\n\t\t\t\tENTRER VOTRE CHOIX :");
	                scanf("%d",&choix);
	                if(choix==1)
	                	{
	                		system("cls");
		                    printf("\n\n\t\t\t\tSASIR LA NOUVELLE ADRESSE  : ");
		                    fflush(stdin);
		                    gets(personne.adresse);
		                    fwrite(&personne,sizeof(personne),1,modif);
						}
	                else if(choix==2)
	                {
	                	system("cls");
		                    printf("\n\n\t\t\t\tSASIR VOTRE NOUVEAU NUMERO DE TELEPHONE : ");
		                    scanf("%d",&personne.tel);
		                    fwrite(&personne,sizeof(personne),1,modif );
	                }
	                else if(choix==3)
	                {
	                	system("cls");
	                		modp:
		                    testpass(personne.password);
        					strcpy(pass,personne.password);
		                    fwrite(&personne,sizeof(personne),1,modif );
       						/*printf("\n\n\t\t\t\tCONFIRMER VOTRE MOT DE PASS :");
       						scanf("%s",pass);
       						if((strcmp(pass,personne.password))==0){
		                    	fwrite(&personne,sizeof(personne),1,modif );
							}

								printf("\n\n\t\t\t[1]:pour ressaye\n\t\t\t[0]:pour sortie");
								printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
								scanf("%d",&menu_sortie);
								if(menu_sortie==1)
									goto modp;
								else if(menu_sortie==0)
									sortie();
								else
									goto tst;
							*/
	                }

	                else goto test5;
            	}
            else
                fwrite(&personne,sizeof(personne),1,modif);
        }
        fclose(f);
        fclose(modif);
		remove("projetD.dat");
        rename("newupd.dat","projetD.dat");
        if(cmp!=1){
        	system("cls");
            printf("\n\t\t\tCIN INCORRECT OU COMPTE N\'EXISTE PAS  !!!");
            test7:
            printf("\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto test6;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\t\t\tINVALIDE SAISIE !\a");
                goto test7;
            }
        }

			else{

				MODIF1:
	            	printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
	            	printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	                menu();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\n\t\t\tINVALIDE SAISIE!\a");
	                goto MODIF1;
	            }
			}

}
void modification1(){
    FILE *modif;
    FILE *f;
    infos personne ;

    char cinN[15];
    char pass[20];
    char passwordN[50],adressN[50];
    test6:
	modif=fopen("newupd1.dat","w");
    f=fopen("projetD.dat","r");
    printf("\n\n\t\t\t\tENTRER VOTRE CIN DU CLIENT : ");
    scanf("%s",cinN);

    int cmp ;
        while (fread(&personne,sizeof(personne),1,f )>0)
   		 {
            if(strcmp(cinN,personne.cin)==0 )
            	{
	                cmp=1;
	                test5:
	                system("cls");
	                printf("\n\t\t\t\tQUELLE INFORMATIONS VOUS VOULEZ MODIFIER ?\n\n\t\t\t\t[1]ADRESSE\n\t\t\t\t[2] NUMERO DE TELEPHONE\n\t\t\t\t[3] MOT DE PASS\n ");
	                int choix ;
	                printf("\n\n\t\t\t\tENTRER VOTRE CHOIX :");
	                scanf("%d",&choix);
	                if(choix==1)
	                	{
	                		system("cls");
		                    printf("\n\n\t\t\t\tSASIR LA NOUVELLE ADRESSE  : ");
		                    fflush(stdin);
		                    gets(personne.adresse);
		                    fwrite(&personne,sizeof(personne),1,modif);
						}
	                else if(choix==2)
	                {
	                	system("cls");
		                    printf("\n\n\t\t\t\tSASIR VOTRE NOUVEAU NUMERO DE TELEPHONE : ");
		                    scanf("%d",&personne.tel);
		                    fwrite(&personne,sizeof(personne),1,modif );
	                }
	                else if(choix==3)
	                {
	                	system("cls");
	                		modp:
		                    testpass(personne.password);
        					strcpy(pass,personne.password);
		                    fwrite(&personne,sizeof(personne),1,modif );
       						/*printf("\n\n\t\t\t\tCONFIRMER VOTRE MOT DE PASS :");
       						scanf("%s",pass);
       						if((strcmp(pass,personne.password))==0){
		                    	fwrite(&personne,sizeof(personne),1,modif );
							}

								printf("\n\n\t\t\t[1]:pour ressaye\n\t\t\t[0]:pour sortie");
								printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
								scanf("%d",&menu_sortie);
								if(menu_sortie==1)
									goto modp;
								else if(menu_sortie==0)
									sortie();
								else
									goto tst;
							*/
	                }

	                else goto test5;
            	}
            else
                fwrite(&personne,sizeof(personne),1,modif);
        }
        fclose(f);
        fclose(modif);
		remove("projetD.dat");
        rename("newupd1.dat","projetD.dat");
        if(cmp!=1){
        	system("cls");
            printf("CIN INCORRECT OU COMPTE N\'EXISTE PAS  !!!");
            test7:
            printf("\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto test6;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\t\t\tINVALIDE SAISIE !\a");
                goto test7;
            }
        }

			else{

				MODIF1:
	            	printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
	            	printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	                menuAdmin();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\n\t\t\tINVALIDE SAISIE!\a");
	                goto MODIF1;
	            }
			}

}
void affichage(){
    FILE *f;

    infos personne;
    char cinN[10],passwordN[50];
    int cmp;
    entrer:
	f=fopen("projetD.dat","r");
    printf("\n\t\t\t\tENTRER VOTRE  CIN : ");
    scanf("%s",cinN);
    printf("\n\t\t\t\tENTRER VOTRE PASSWORD : ");
    scanf("%s",passwordN);
    cmp=0;
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
       if(strcmp(cinN,personne.cin)==0)
        {
            cmp=1;
            if(strcmp(passwordN,personne.password)==0)
            {
            	system("cls");
                printf("\n\n\t\t\t\tLES   INFORMATIONS   DE    %s    %s  SONT :",personne.nom,personne.prenom);

                printf("\n\n\t\t\t\t\tID : %d",personne.id);
                printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tDATE DE NAISSANCE : %d/%d/%d",personne.date_naissance.jour,personne.date_naissance.mois,personne.date_naissance.annee);
                printf("\n\n\t\t\t\t\t----------------------------------------");
				printf("\n\t\t\t\t\tNUMERO DE TELEPHONE : 0%d",personne.tel);
				printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tADRESSE : %s",personne.adresse);
                printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tSOLDE : %f",personne.solde);
           fclose(f);
            }
            else {
            		fclose(f);
                    printf("\n\t\t\tMOT DE PASS INCORRECT !!!!");
            		revenir:
            		printf("\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            		printf("\n\t\t\tVOTRE CHOIX : ");
            		scanf("%d",&menu_sortie);
            		system("cls");
            		if (menu_sortie==1)
            	 	    goto entrer ;
            		else if(menu_sortie==2)
              			menu();
           			 else if(menu_sortie==0)
           			    sortie();
            		else
           			 {
            		    printf("\n\t\t\tINVALIDE!\a");
            		    goto revenir ;
            		}
        		}
    }
	}
    if(cmp==0){
        printf("\n\t\t\tCIN INCORRECT OU COMPTE N\'EXISTE PAS  !!!");
            revenir2:
            printf("\n\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\t\t\tENTRER VOTRE CHOIX : ");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto entrer ;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\t\t\tInvalide!\a");
                goto revenir2;
            }
    }
    AFFICH:
            printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto AFFICH;
            }
}
void affichage2(){
    FILE *f;

    infos personne;
    char cinN[10],passwordN[50];
    int cmp =0;
    entrer:
	f=fopen("projetD.dat","rb");
    printf("\n\t\t\t\tENTRER   CIN DU CLIENT : ");
    scanf("%s",cinN);

    cmp=0;
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
       if(strcmp(cinN,personne.cin)==0)
        {
            cmp=1;

            	system("cls");
                printf("\n\n\t\t\t\tLES   INFORMATIONS   DE    %s    %s  SONT :",personne.nom,personne.prenom);

                printf("\n\n\t\t\t\t\tID : %d",personne.id);
                printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tDATE DE NAISSANCE : %d/%d/%d",personne.date_naissance.jour,personne.date_naissance.mois,personne.date_naissance.annee);
                printf("\n\n\t\t\t\t\t----------------------------------------");
				printf("\n\t\t\t\t\tNUMERO DE TELEPHONE : 0%d",personne.tel);
				printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tADRESSE : %s",personne.adresse);
                printf("\n\n\t\t\t\t\t----------------------------------------");
                printf("\n\t\t\t\t\tSOLDE : %f",personne.solde);


    }

	}
	fclose(f);
    if(cmp==0){
        printf("\n\t\t\tCIN INCORRECT OU COMPTE N\'EXISTE PAS  !!!");
            revenir2:
            printf("\n\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\t\t\tVOTRE CHOIX : ");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto entrer ;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\n\t\t\tInvalide!\a");
                goto revenir2;
            }
    }
    AFFICH:
            printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\t\t\tVOTRE CHOIX : ");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\n\t\t\tInvalide!\a");
                goto AFFICH;
            }
}
void tirer(){


    infos personne ;

    FILE *f;
    FILE *tmp;
    char cinN[15];

    float mont;

	tmp=fopen("temptirz.dat","wb");
    f=fopen("projetD.dat","rb");
    printf("entre votre cin ");
    scanf("%s",cinN);
//    printf("entrer votre password : ");
//    scanf("%s",passwordN);
    int cmp =0 ;
        while (fread(&personne,sizeof(personne),1,f )>0)
    	{
            if(strcmp(cinN,personne.cin)==0)
            {
                cmp++;
                do {
                printf("entrer le montant que vous vouler tirer : ");
                scanf("%f",&mont);
                }while(mont>personne.solde-100 || mont<100);
                personne.solde-=mont;
                fwrite(&personne,sizeof(personne),1,tmp);
				printf("votre nouveau solde est : %.2f",personne.solde);
       		 }
            else fwrite(&personne,sizeof(personne),1,tmp);
 		 }

 		fclose(f);

        fclose(tmp);
        remove("projetD.dat");
        rename("temptirz.dat","projetD.dat");
        if(cmp==0){
            printf("CIN incorrect ou compte n existe pas !!!");
            test11:
            printf("\n\n\n\t\tEntrer :\n[1] Pour resayez  \n[2] Pour revenir au menu initial  \n[0] Pour sortir \n");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                tirer();
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto test11;
            }
        }


        TIRER:
            printf("\n\n\n\t\n\n[1] Pour revenir au menu initial  \n[0] Pour sortir \nENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto TIRER;
            }
}

void solde(){
    infos personne ;
    FILE *f;

    char cinN[15];
    char passwordN[50];
    SOLDE:
	f=fopen("projetD.dat","r");
    printf("\n\t\t\t\tCIN : ");
    scanf("%s",cinN);
    printf("\n\t\t\t\tMOT DE PASS : ");
    scanf("%s",passwordN);
    int cmp ;
        while (fread(&personne,sizeof(personne),1,f )>0)
    	{
            if(strcmp(cinN,personne.cin)==0 && strcmp(passwordN,personne.password)==0)
            {
                cmp=1;
                system("cls");
                printf("\n\n\n\t\t\t\tSOLDE : %.2f",personne.solde);
            }
		}
	fclose(f);

        if(cmp!=1){
        	system("cls");
            printf("CIN INCORRECT OU COMPTE N EXISTE PAS  !!!");
            SOLDE1:
            printf("\n\n\t\t\t[1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");

            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto SOLDE;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto SOLDE1;
            }
        }
        SOLDE2:
            printf("\n\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !\a");
                goto SOLDE2;
            }
}
void solde1(){
    infos personne ;
    FILE *f;

    char cinN[15];

    SOLDE:
	f=fopen("projetD.dat","r");
    printf("\n\t\t\t\tCIN : ");
    scanf("%s",cinN);

    int cmp ;
        while (fread(&personne,sizeof(personne),1,f )>0)
    	{
            if(strcmp(cinN,personne.cin)==0 )
            {
                cmp=1;
                system("cls");
                printf("\n\n\n\t\t\t\tSOLDE : %.2f",personne.solde);
            }
		}
	fclose(f);

        if(cmp!=1){
        	system("cls");
            printf("CIN INCORRECT OU COMPTE N EXISTE PAS  !!!");
            SOLDE1:
            printf("\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");

            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto SOLDE;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto SOLDE1;
            }
        }
        SOLDE2:
            printf("\n\n\n\t\t\t[1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if(menu_sortie==1)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !\a");
                goto SOLDE2;
            }
}
void verserclient(){
    infos personne ;
    FILE *f;
    FILE *tmp;
    char cinN[15],cin[15];

    float mont;

	int cmp1;

    VERSER:
	cmp1=0 ;

    printf("\n\n\t\t\tSAISIR LE CIN DU COMPTE DU CLIENT  :");
    scanf("%s",cin);

	f=fopen("projetD.dat","rb");
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
            if(strcmp(cin,personne.cin)==0 )
            	cmp1++; }

        fclose (f);
        if(cmp1==1 )
        {

        	f=fopen("projetD.dat","rb");
        	tmp=fopen("verseradmin.dat","wb");
			mont:
			rewind(f);
			system("cls");
			printf("\n\n\t\t\tSAISIR LE MONTANT QUE VOUS VOULEZ VERSER : ");
            scanf("%f",&mont);
            while (fread(&personne,sizeof(personne),1,f )>0)
    		{
              	  if(strcmp(cin,personne.cin)==0 )
                {personne.solde+=mont;
                    fwrite(&personne,sizeof(personne),1,tmp);
				}

            	else
            		fwrite(&personne,sizeof(personne),1,tmp);
        	}
        	fclose(f);
        fclose(tmp);

        	remove("projetD.dat");

        	rename("verseradmin.dat","projetD.dat");
        	system("cls");
        	printf("\n\n\t\t\t\tVERSEMENT EFFECTUER AVEC SUCCES \n");

        	VERSER3:
	            printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            	printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	                menuAdmin();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\nINVALIDE INPUT !!!!\a");
	                goto VERSER3;
	            }
    	}
        else if(cmp1==0){
            printf("LE COMPTE SOURCE N EXISTE PAS OU CIN/MOT DE PASS INCORRECT  !!!");
            VERSER1:
            printf("\n\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto VERSER;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !!!\a");
                goto VERSER1;
            }
        }


}


void recuperer(){
	infos personne ;
    FILE *f;
    char cinN[15];
    int telN;
	rec :
    printf("\n\n\t\t\tSAISIR VOTRE  CIN  :");
    scanf("%s",cinN);
    printf("\n\n\t\t\tVOTRE NEMURO DE TELEPHONE  : 0");
    scanf("%d",&telN);
    f=fopen("projetD.dat","rb");
    int cmp;
    cmp=0;
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
    	if(strcmp(cinN,personne.cin)==0  && telN==personne.tel ){cmp++;
    		printf("\n\n\t\t\t\tVOTRE MOT DE PASS EST : %s",personne.password);}

	}
	fclose(f);
	 if(cmp==0)
        {
			printf("LE COMPTE  N EXISTE PAS !!!");
rec2:
            printf("\n\n\n\t\t\t[1]: REESAYER  \n\t\t\t [2]: REVENIR AU MENU INITIAL   \n\t\t\t [0]: SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto rec ;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !!!\a");
                goto rec2;
            }

	}
	else
        {
			rec1:

            printf("\n\n\n\t\t\t  [1]: REVENIR AU MENU INITIAL   \n\t\t\t [0]: SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");

          if(menu_sortie==1)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !!!\a");
                goto rec1;
            }

	}
}
void verser(){
    infos personne ;
    FILE *f;
    FILE *tmp;
    char cinN[15],cin[15];
    char passwordN[50];
    float mont;
    float solde ;
	int cmp1;
	int cmp2;
    VERSER:
	cmp1=0 ;
	cmp2=0 ;
    printf("\n\n\t\t\tSAISIR LE CIN DU COMPTE SOURCE :");
    scanf("%s",cin);
    printf("\n\n\t\t\tMOT DE PASS : ");
    scanf("%s",passwordN);
    printf("\n\n\t\t\tSAISIR LE CIN DU COMPTE CIBLE : ");
    scanf("%s",cinN);
	f=fopen("projetD.dat","rb");
    while (fread(&personne,sizeof(personne),1,f )>0)
    {
            if(strcmp(cin,personne.cin)==0  && strcmp(passwordN,personne.password)==0)
            	cmp1++;
            else if (strcmp(cinN,personne.cin)==0)
            	cmp2++;
        }
        fclose (f);
        if(cmp1==1 && cmp2 ==1)
        {

        	f=fopen("projetD.dat","rb");
        	tmp=fopen("verserA.dat","wb");
			mont:
			rewind(f);
			system("cls");
			printf("\n\n\t\t\tSAISIR LE MONTANT QUE VOUS VOULEZ VERSER : ");
            scanf("%f",&mont);
            while (fread(&personne,sizeof(personne),1,f )>0)
    		{
              	  if(strcmp(cin,personne.cin)==0 )
                {
                	if(mont>personne.solde)
                		goto  mont;
                    else {
					personne.solde-=mont;
					solde=personne.solde;
                    fwrite(&personne,sizeof(personne),1,tmp);
					}
				}
				else if (strcmp(cinN,personne.cin)==0){
					personne.solde+=mont;
                    fwrite(&personne,sizeof(personne),1,tmp);
            	}
            	else
            		fwrite(&personne,sizeof(personne),1,tmp);
        	}
        	fclose(f);
        	fclose(tmp);
			remove("projetD.dat");


        	rename("verserA.dat","projetD.dat");
        	system("cls");
        	printf("\n\n\t\t\t\tVERSEMENT EFFECTUER AVEC SUCCES \n");
        	printf("\n\n\n\t\t\t\tVOTRE NOUVEAU SOLDE EST : %.2f",solde);
        	VERSER3:
	            printf("\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            	printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	              menu();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\nINVALIDE INPUT !!!!\a");
	                goto VERSER3;
	            }
    	}
        else if(cmp1==0){
            printf("LE COMPTE SOURCE N EXISTE PAS OU CIN/MOT DE PASS INCORRECT  !!!");
            VERSER1:
            printf("\n\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto VERSER;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !!!\a");
                goto VERSER1;
            }
        }
        else if(cmp2==0)
        {
			printf("LE COMPTE SIBLE N EXISTE PAS OU CIN   !!!");
            VERSER2:
            printf("\n\n\n\t\t\t [1] REESAYER  \n\t\t\t [2] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto VERSER;
            else if(menu_sortie==2)
               menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nINVALIDE INPUT !!!\a");
                goto VERSER2;
            }
        }

}
void supprimer1(){
    FILE *tmp;
    FILE *f;
	int cmp1,cmp2 ;
    infos personne ;
	char cinN[15];
    char passwordN[50];
	SUPP:
	cmp1=cmp2=0;
    tmp=fopen("tmpsup.dat","wb");
    f=fopen("projetD.dat","rb");
    printf("\n\n\t\t\t\tENTRER VOTRE CIN : ");
    scanf("%s",cinN);
    printf("\n\t\t\t\tMOT DE PASS  : ");
    scanf("%s",passwordN);


        while (fread(&personne,sizeof(personne),1,f )>0)
    	{
            if(strcmp(cinN,personne.cin)==0 )
            {
                cmp1=1;
                if(strcmp(passwordN,personne.password)==0)
                	cmp2=1;
            }
            else
				fwrite(&personne,sizeof(personne),1,tmp);
		}
		fclose(f);
		 remove("projetD.dat");
        fclose(tmp);

        rename("tmpsup.dat","projetD.dat");
			if(cmp1==1 && cmp2==1){
				SUPP3:
				system("cls");
				printf("\n\n\n\t\t\tCOMPTE SUPPRIMER AVEC SUCCES ");
	            printf("\n\n\n\t\t\t[1] Pour revenir au menu initial  \n\t\t\t[0] Pour sortir :");
	            printf("\n\t\t\tVOTRE CHOIX : ");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	                menu();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\nInvalide!\a");
	                goto SUPP3;
	            }
	        }

        else if(cmp1!=1){
            printf("\n\n\t\t\t\tCOMPTE N EXISTE PAS 	 !!!");
            SUPP1:
            printf("\n\n\n\t\t[1]: Pour resayez  \n\t\t[2]: Pour revenir au menu initial  \n\t\t[0]: Pour sortir  :");
            printf("\n\t\t\tVOTRE CHOIX : ");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto SUPP;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto SUPP1;
            }
        }
        else if(cmp2!=1){
            printf("\n\n\t\t\t\tCOMPTE N EXISTE PAS 	 !!!");
            SUPP2:
            printf("\n\n\n\t\t[1] Pour resayez  \n[2] Pour revenir au menu initial  \n[0] Pour sortir \n\t\tENTRER VOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto SUPP;
            else if(menu_sortie==2)
                menu();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\t\t\tInvalide!\a");
                goto SUPP2;
            }
        }

}
void supprimer2(){
    FILE *tmp;
    FILE *f;
	int cmp1,cmp2 ;
    infos personne ;
	char cinN[15];

	SUPP:
	cmp1=cmp2=0;
    tmp=fopen("tmpsupAA.dat","wb");
    f=fopen("projetD.dat","rb");
    printf("\n\n\t\t\t\tENTRER VOTRE CIN : ");
    scanf("%s",cinN);



        while (fread(&personne,sizeof(personne),1,f )>0)
    	{
            if(strcmp(cinN,personne.cin)==0 )
            {
                cmp1=1;

            }
            else
				fwrite(&personne,sizeof(personne),1,tmp);
		}
		fclose(f);
		 remove("projetD.dat");
        fclose(tmp);

        rename("tmpsupAA.dat","projetD.dat");

			if(cmp1==1){
				SUPP3:
				system("cls");
				printf("\n\n\n\t\t\tCOMPTE SUPPRIMER AVEC SUCCES ");
	            printf("\n\n\n\t\t\t[1] Pour revenir au menu initial  \n\t\t\t[0] Pour sortir \n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	                menuAdmin();
	            else if(menu_sortie==0)
	                sortie();
	            else
	            {
	                printf("\nInvalide!\a");
	                goto SUPP3;
	            }
	        }

        else if(cmp1!=1){
            printf("\n\n\t\t\t\tCOMPTE N EXISTE PAS 	 !!!");
            SUPP1:
            printf("\n\n\n\t\t[1] Pour resayez  \n\t\t[2] Pour revenir au menu initial  \n\t\t[0] Pour sortir \n\t\tENTRER VOTRE CHOIC :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto SUPP;
            else if(menu_sortie==2)
                menuAdmin();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\nInvalide!\a");
                goto SUPP1;
            }
        }


}
void firstrow(){
	int i ;
	printf("\n\t%c",201);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",187);
}
void lastrow(){
	int i ;
	printf("\n\t%c",200);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",188);
}
void midtext(){
	int i ;
	printf("\n\t%c",186);
}
void midrows(){
	int i ;
	printf("\n\t%c",204);
    for( i=0;i<70;i++)
    	printf("%c",205);
    	printf("%c",185);
}






void affichageListe(){


 FILE *f;

    infos personne;


	f=fopen("projetD.dat","rb");

    printf("\nN_compte         CIN          Nom         Prenom         DateNaissance         Telephone       Solde\n\n");
    while (fread(&personne,sizeof(personne),1,f )>0)
    {


//            	system("cls");
               printf("  %d    .        %s    .   %s    .   %s     .    %d/%d/%d     .    0%d      %.2f dh\n\n",personne.id,personne.cin,personne.nom,personne.prenom,personne.date_naissance.jour,personne.date_naissance.mois,personne.date_naissance.annee,personne.tel,personne.solde);


            }

fclose(f);

VERSER33:
	            printf("\n\n\n\n\t\t\t [1] REVENIR AU MENU INITIAL   \n\t\t\t [0] SORTIR \n");
            	printf("\n\n\t\t\tENTRER VOTRE CHOIX :");
	            scanf("%d",&menu_sortie);
	            system("cls");
	            if(menu_sortie==1)
	              menuAdmin();
	            else if(menu_sortie==0)
	                sortie();

	            else
	            {
	                printf("\nINVALIDE INPUT !!!!\a");
	                goto VERSER33;
	            }

}
void menu(){
    int choix,i ;

    choix:
    system("cls");
    printf("\n\n\t\t\t\t%c%c%c%c%c%c SYSTEME DE GESTION BANCAIRE %c%c%c%c%c%c",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
    printf("\n\n\n       \t\t\t\t%c%c%c%c%c%cMENU%c%c%c%c%c%c\n",5,5,5,5,5,5,5,5,5,5,5,5,5);
    firstrow();
    midtext();printf("\t\t[1] CREATION D'UN NOUVEAU COMPTE \t\t       %c ",186);
    midrows();
    midtext();printf("\t\t[2] MODIFICATION DES INFORMATIONS DU COMPTE\t       %c ",186);
    midrows();
    midtext();printf("\t\t[3] AFFICHER\t\t\t\t\t       %c",186);

    midrows();
    midtext();printf("\t\t[4] VOIR SOLDE\t\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[5] VERSER\t\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[6] SUPRESSION DU COMPTE\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[7] SORTIR\t\t\t\t\t       %c",186);
     midrows();
    midtext();printf("\t\t[8] MENU GENERALE\t\t\t\t       %c",186);
	lastrow();
	printf("\n\n\n\t\t ENTRER VOTRE CHOIX  :");
    scanf("%d",&choix );

    system("cls");
    switch(choix)
    {
        case 1:creation();
        break;
        case 2:modification();
        break;
        case 3:affichage();
        break;

        case 4:solde();
        break;
        case 5:verser();
        break;
        case 6:supprimer1();
        break;
        case 7:sortie();
        break;
         case 8:menugenenrale();
        break;
        default :
        	menu();
        break;


    }
}
void menuAdmin(){
system("cls");
 int choix ;


     printf("\n\n\t\t\t\t%c%c%c%c%c%c SYSTEME DE GESTION BANCAIRE %c%c%c%c%c%c",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
    printf("\n\n\n       \t\t\t\t%c%c%c%c%c%cMENU%c%c%c%c%c%c\n",5,5,5,5,5,5,5,5,5,5,5,5,5);
    firstrow();
    midtext();printf("\t\t[1] CREATION D'UN NOUVEAU COMPTE \t\t       %c ",186);
    midrows();
    midtext();printf("\t\t[2] MODIFICATION DES INFORMATIONS DU COMPTE\t       %c ",186);
    midrows();
    midtext();printf("\t\t[3] AFFICHER\t\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[4] TIRER L'ARGENT\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[5] VOIR SOLDE\t\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[6] VERSER\t\t\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[7] SUPRESSION DU COMPTE\t\t\t       %c",186);
        midrows();
    midtext();printf("\t\t[8] VOIR LES LISTES CLIENTS\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[9] MENUE GENERAL\t\t\t\t       %c",186);
     midrows();
    midtext();printf("\t\t[10] RECUPERER MOT DE PASS\t\t\t       %c",186);
    midrows();
    midtext();printf("\t\t[11]  Sortir\t\t\t\t\t       %c ",186);
	lastrow();
printf("\n\n\n\t\t ENTRER VOTRE CHOIX  :");
    scanf("%d",&choix );

    system("cls");
    switch(choix)
    {
        case 1:creation1();
        break;
        case 2:modification1();
        break;
        case 3:affichage2();
        break;
        case 4:tirer();
        break;
        case 5:solde1();
        break;
        case 6:verserclient();
        break;
        case 7:supprimer2();
        break;
        case 8:affichageListe();
        break;
        case 9:menugenenrale();
        break;
        case 10:recuperer();
        break;
        case 11:sortie();
        break;
        default : main();
        break;


    }}
void menuAdmin1(){
    system("cls");
    int idadmin;
    char passadmin [20];
    entrer:
    printf("\n\t\t\t\tID  : ");
    scanf("%d",&idadmin);
    printf("\n\t\t\t\tMOT DE PASS : ");
    scanf("%s",passadmin);
    FILE *pp;
    pp=fopen("myadmin.txt","r");
    int cmp = 0,cmp1=0;
    admin test ;
    while(fscanf(pp," %d   %s   \n",&test.id,test.password)==2){

        if (idadmin==test.id){
            cmp++;
           if (strcmp(passadmin,test.password)==0){

            cmp1++;
           }
        }


    }
    fclose(pp);
   if(cmp==0 ) {
   			system("cls");
   			printf("\n\t\t\tVOTRE ID EST INCORRECT !!") ;
   		revenir2:
            printf("\n\n\n\t\tEntrer :\n[1] Pour resayez  \n[2] Pour revenir au menu initial  \n[0] Pour sortir \n");
            printf("\n\t\t\tVOTRE choix : ");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto entrer ;
            else if(menu_sortie==2)
               menugenenrale();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\n\t\t\tINVALIDE!\a");
                goto revenir2;
            }

   }
   else if (cmp1==0){


    printf(" \n\t\t\tVOTRE MOT DE PASS EST INCORRECT !! ");
 revenir3:
            printf("\n\n\n\t\tEntrer :\n[1] Pour resayez  \n[2] Pour revenir au menu initial  \n[0] Pour sortir \n");
            printf("\n\t\t\tVOTRE CHOIX :");
            scanf("%d",&menu_sortie);
            system("cls");
            if (menu_sortie==1)
                goto entrer ;
            else if(menu_sortie==2)
                menugenenrale();
            else if(menu_sortie==0)
                sortie();
            else
            {
                printf("\n\n\t\t\t INVALIDE !\a");
                goto revenir3;
            }
   }
   else {

		menuAdmin();

   }

}
void menugenenrale(){

int choix;

    printf("\n\n\t\t\t\t%c%c%c%c%c%c SYSTEME DE GESTION BANCAIRE %c%c%c%c%c%c",4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4);
    printf("\n\n\n\t\t\t\t-----------MENU GENERALE-----------\n");
    printf("\n\n\t\t[1]:Menu Client\t\t\t\t\t[2]:Menu Admin\n");
    printf("\n\n\t\t\t\t    Entrer Votre choix :");
    scanf("%d",&choix);
        system("cls");
    switch(choix)
    {
        case 1: menu();
        break;
        case 2: menuAdmin1();
        break;
    }


}
int main (){

	menugenenrale();

return 0 ;
}
