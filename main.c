#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Compte.h.c"
//Prototype
void ajouterCompte(Compte comptes[], int *compteur, int nbrComptes);
void depot(Compte comptes[], int compteur);
void retrait(Compte comptes[], int compteur);
void affichageCompte(Compte comptes[], int compteur);
void triAscendant(Compte comptes[], int compteur);
void affichageTri(Compte comptes[],int compteur);
void triDescendant(Compte comptes[], int compteur);
void rechercheParMontantAscendant(Compte comptes[], int compteur);
void rechercheParMontantDescendant(Compte comptes[], int compteur);
void rechercheParCIN(Compte comptes[], int compteur);
void fidelisation(Compte comptes[],int compteur);
//main
int main()
{
    int compteur=0;
    int nbrComptes;
    Compte comptes[100];
    int choix;
    int x=1;
    //system("cls");
    //introduire le Menu principale
    while(x)
    {
        printf("\n\t\tMenu\n");
        printf("Pour Ajouter un compte tapez 1.\n");
        printf("Pour Ajouter plusieurs comptes tapez 2.\n");
        printf("Pour Affichage des comptes tapez 3.\n");
        printf("Pour Operation tapez 4.\n");
        printf("Pour Fidelisation tapez 5.\n");
        printf("Pour Quitter le programme tapez 6.\n");
        do
        {
            scanf("%d", &choix);
        }
        while(choix > 6 || choix < 1);

        switch(choix)
        {
        case 1:
            system("cls");
            ajouterCompte(comptes, &compteur, 1);
            break;
        case 2:
            system("cls");
            printf("Saisire le nombre de compte :\n");
            scanf("%d",&nbrComptes);
            ajouterCompte(comptes, &compteur, nbrComptes);
            break;
        case 3:
            system("cls");
            printf("\n\t\t Affichage \n");
            printf("Pour affichage les comptes par ordre ascendant tapez 1.\n");
            printf("Pour affichage les comptes par ordre descendant tapez 2.\n");
            printf("Pour affichage les comptes par ordre ascendant tapez (affichage avec montant) 3.\n");
            printf("Pour affichage les comptes par ordre descendant tapez (affichage avec montant) 4.\n");
            printf("Pour Rechercher un compte par CIN tapez 5.\n");
            int c;

            scanf("%d",&c);
            switch(c)
            {
            case 1:
                system("cls");
                triAscendant(comptes,compteur);
                affichageTri(comptes,compteur);
                break;
            case 2:
                system("cls");
                triDescendant(comptes,compteur);
                affichageTri(comptes,compteur);
                break;
            case 3:
                system("cls");
                rechercheParMontantAscendant(comptes,compteur);
                break;
            case 4:
                system("cls");
                rechercheParMontantDescendant(comptes,compteur);
            case 5:
                rechercheParCIN(comptes, compteur);
            break;
            }
            break;

        case 4:
            system("cls");
            printf("\n\t\t Operation \n");
            printf("Retrait 1.\n");
            printf("Depot 2.\n");
            printf("\nTapez ici votre choix :");
            int c2;
            scanf("%d",&c2);
            switch (c2)
            {

            case 1 :
                system("cls");
                retrait(comptes, compteur);
                break;

            case 2 :
                system("cls");
                depot(comptes, compteur);
                break;
            }
            break;

        case 5:
            fidelisation(comptes,compteur);
            break;
        case 6 :
            system("cls");
            x=0;
            printf("\n\n\n\n\n\t\t\t\t\t\t\tBye Bye!");
            Sleep(3000);
            system("cls");
            break;
        }
    }
    return 0;
}
void ajouterCompte(Compte comptes[], int *compteur, int nbrComptes)
{
    system("cls");
    int i;
    for ( i = 0; i < nbrComptes; i++)
    {
        printf("Saisir Compte N*%d: \n",*compteur+1);
        printf("Entrer CIN : ");
        scanf("%s",comptes[*compteur].CIN);
        printf("Entrer Nom : ");
        scanf("%s",comptes[*compteur].Nom);
        printf("Entrer Prenom : ");
        scanf("%s",comptes[*compteur].Prenom);
        printf("Entrer Montants : ");
        scanf("%lf",&comptes[*compteur].Montant);
        (*compteur)++;
    }
}
void affichageCompte(Compte comptes[], int compteur)
{
    system("cls");
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
        return;
    }
    system("cls");
    int i;
    for ( i = 0; i < compteur; i++)
    {
        printf("Affichage Compte N*%d: \n",i+1);
        printf("CIN : %s\n",comptes[i].CIN);
        printf("Nom : %s\n",comptes[i].Nom);
        printf("Prenom : %s\n", comptes[i].Prenom);
        printf("Montants : %.2lf Dhs\n",comptes[i].Montant);
    }

}
void depot(Compte comptes[], int compteur)
{
    system("cls");
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
        return;
    }
    printf("Depot d'argent\n");
    int i;
    char CIN[10];
    double montant;
    printf("Saisir le CIN : ");
    scanf("%s", CIN);
    for ( i = 0; i < compteur; i++)
    {
        if(strcmp(comptes[i].CIN, CIN)==0)
        {
            printf("Saisir le Montant : ");
            scanf("%lf", &montant);
            if(montant<=0)
            {
                printf("Le montant doit etre superieur a zero!\n");
                return;
            }
            printf("Montant ajoute avec succes!\n");
            comptes[i].Montant+=montant;
            return;
        }
    }
    printf("\n\nCompte non trouve!\n\n\a");
}
void retrait(Compte comptes[], int compteur)
{
    system("cls");
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
        return;
    }
    printf("Retrait d'argent\n");
    int i;
    char CIN[10];
    double montant;
    printf("Saisir le CIN : ");
    scanf("%s", CIN);
    for ( i = 0; i < compteur; i++)
    {
        if(strcmp(comptes[i].CIN, CIN)==0)
        {
            printf("Saisir le Montant : ");
            scanf("%lf", &montant);
            if(comptes[i].Montant<0)
            {
                printf("Pas assez d'argent\a!\n");
                return;
            }
            printf("Montant retire avec succes!\n");
            comptes[i].Montant-=montant;
            return;
        }
    }
    printf("\n\nCompte non trouve!\n\n\a");
}
void rechercheParMontantAscendant(Compte comptes[], int compteur)
{
    system("cls");
    double montantRech;
    int i;
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");

    }
    else
    {
        triAscendant(comptes,compteur);
        printf("Entrer Montant : ");
        scanf("%lf",&montantRech);
        for (i=0; i < compteur; i++)
        {
            if(comptes[i].Montant > montantRech)
            {
                printf("Affichage Compte N*%d: \n",i+1);
                printf("CIN : %s\n",comptes[i].CIN);
                printf("Nom : %s\n",comptes[i].Nom);
                printf("Prenom : %s\n", comptes[i].Prenom);
                printf("Montants : %.2lf Dhs\n",comptes[i].Montant);
            }
        }
    }
}
void rechercheParMontantDescendant(Compte comptes[], int compteur)
{
    system("cls");
    double montantRech;
    int i;

    if(compteur<=0)
    {
        printf("Pas de comptes!\a");

    }
    else
    {
        triDescendant(comptes,compteur);
        printf("Entrer Montant : ");
        scanf("%lf",&montantRech);
        for (i=0; i < compteur; i++)
        {
            if(comptes[i].Montant < montantRech)
            {

                printf("CIN : %s\n",comptes[i].CIN);
                printf("Nom : %s\n",comptes[i].Nom);
                printf("Prenom : %s\n", comptes[i].Prenom);
                printf("Montants : %.2lf Dhs\n",comptes[i].Montant);

            }
        }
    }
}
void rechercheParCIN(Compte comptes[], int compteur)
{
    system("cls");
    printf("Recherche par CIN\n");
    char CIN[10];
    int i;
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
        return;
    }
    printf("Entrer CIN : ");
    scanf("%s", CIN);
    for (i=0; i < compteur; i++)
    {
        if(strcmp(comptes[i].CIN, CIN)==0)
        {
            printf("Compte trouve\n");
            printf("CIN : %s\n",comptes[i].CIN);
            printf("Nom : %s\n",comptes[i].Nom);
            printf("Prenom : %s\n",comptes[i].Prenom);
            printf("Montant : %.2lf DHS",comptes[i].Montant);
            return;
        }
    }
    printf("\n\nCompte non trouve!\n\n\a");
}
void triAscendant(Compte comptes[], int compteur)
{
    system("cls");
    int i, j;
    Compte tmp;
    for (i=0 ; i < compteur-1; i++)
    {
        for (j=0 ; j < compteur-i-1; j++)
        {
            if (comptes[j].Montant > comptes[j+1].Montant)
            {
                tmp = comptes[j];
                comptes[j] = comptes[j+1];
                comptes[j+1] = tmp;
            }
        }
    }
}
void affichageTri(Compte comptes[],int compteur)
{
    int i;
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
    }
    else
    {
        for ( i = 0; i < compteur; i++)
        {
            printf("Affichage Compte N*%d: \n",i+1);
            printf("CIN : %s\n",comptes[i].CIN);
            printf("Nom : %s\n",comptes[i].Nom);
            printf("Prenom : %s\n", comptes[i].Prenom);
            printf("Montants : %.2lf Dhs\n",comptes[i].Montant);
        }
    }
}
void triDescendant(Compte comptes[], int compteur)
{
    int i, j;
    Compte tmp;
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");
    }
    else
    {
        for (i=0 ; i < compteur-1; i++)
        {
            for (j=0 ; j < compteur-i-1; j++)
            {
                if (comptes[j].Montant < comptes[j+1].Montant)
                {
                    tmp = comptes[j];
                    comptes[j] = comptes[j+1];
                    comptes[j+1] = tmp;
                }
            }
        }
    }
}
void fidelisation(Compte comptes[],int compteur)
{
    system("cls");
    int m1,m2,m3;//montant a chercher
    int i,choix;
    if(compteur<=0)
    {
        printf("Pas de comptes!\a");

    }
    else
    {
        printf("Note !! = Cette option permet de augmenter les 3 plus grand Montant d'un pourcentage : 1,3%\n\n");
        m1= 0;      // initialiser les montants
        m2= 0;
        m3=0;
        for (i=0; i<compteur; i++)
        {
            if(m1 < comptes[i].Montant )
            {
                m3=m2;
                m2=m1;
                m1=comptes[i].Montant;
            }
            if(m2 < comptes[i].Montant && m1> comptes[i].Montant )
            {
                m3=m2;
                m2=comptes[i].Montant;
            }
            if(m3 < comptes[i].Montant && m2> comptes[i].Montant )
            {
                m3=comptes[i].Montant;
            }
        }
        // afficher les 3 grand valeur des montant existant
        printf("\nVoicie les 3 premiers premier  montant les plus grand dans la selection de compte : \n");
        for (i=0; i<compteur; i++)
        {
            if(comptes[i].Montant>=m3)
            {
                printf("CIN : %s\n",comptes[i].CIN);
                printf("Nom : %s\n",comptes[i].Nom);
                printf("Prenom : %s\n", comptes[i].Prenom);
                printf("Montants : %.2lf Dhs\n",comptes[i].Montant);
                printf("\t\n____________________________\n");
            }
        }
        // confirmation de l'operation
        printf("\nVous ete sur de comfirmer cette operation ??");
        printf("\n\nPour confirmer tapez 1 / Pour retourner au menu tapez 0\n");
        scanf("%d",&choix);
        system ("cls");
        //éxecution
        if(choix == 1)
        {
            for (i=0; i<compteur; i++)
            {
                if(comptes[i].Montant>=m3)
                {
                    comptes[i].Montant += comptes[i].Montant*0.013;
                    printf("\n\n\tOperation avec succe !!\a\n");
                    printf("CIN : %s\n",comptes[i].CIN);
                    printf("Nom : %s\n",comptes[i].Nom);
                    printf("Prenom : %s\n", comptes[i].Prenom);
                    printf("Montants : %.2lf Dhs\n",comptes[i].Montant);
                    printf("\t\n____________________________\n");
                }
            }
        }
    }
}


