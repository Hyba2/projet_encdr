#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int code1;
    char nom[15];
    char adresse[16];
    char nationalite[15];
} fournisseur;

typedef struct {
    char nom[20];
    char code[20];
    char categorie[10];
    float prix;
    int quantitenstock;
    char disponibilite[30];
    fournisseur forns;
} produit;

void stockprod(produit *prod, int n) {
    FILE *fp;
    fp = fopen("stock.csv", "w");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    fprintf(fp, "Nom,Code,Categorie,Disponibilite,Prix,Quantite en stock,Code fournisseur,Nom fournisseur,Adresse fournisseur,Nationalite fournisseur\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", prod[i].nom, prod[i].code, prod[i].categorie,
               prod[i].disponibilite, prod[i].prix, prod[i].quantitenstock, prod[i].forns.code1,
               prod[i].forns.nom, prod[i].forns.adresse, prod[i].forns.nationalite);
    }

    fclose(fp);
}

void produitCategorieMoins(produit *prod, int n) {
    int minQuantite = -1;
    int i;
    char categorieMoins[20] = "";

    for (i = 0; i < n; i++) {
        if (minQuantite < 0 || prod[i].quantitenstock < minQuantite) {
            minQuantite = prod[i].quantitenstock;
            strcpy(categorieMoins, prod[i].categorie);
        }
    }

    FILE *fp;
    fp = fopen("categorie_moins.csv", "w");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    fprintf(fp, "Nom,Code,Categorie,Disponibilite,Prix,Quantite en stock,Code fournisseur,Nom fournisseur,Adresse fournisseur,Nationalite fournisseur\n");
    for (i = 0; i < n; i++) {
        if (strcmp(prod[i].categorie, categorieMoins) == 0) {
            fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", prod[i].nom, prod[i].code, prod[i].categorie,
                   prod[i].disponibilite, prod[i].prix, prod[i].quantitenstock, prod[i].forns.code1,
                   prod[i].forns.nom, prod[i].forns.adresse, prod[i].forns.nationalite);
        }
    }

    fclose(fp);
}

void produitFournisseur(produit *prod, int n, char fournisseurDonne[15]) {
    FILE *fp;
    fp = fopen("fournisseur.csv", "w");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    fprintf(fp, "Nom,Code,Categorie,Disponibilite,Prix,Quantite en stock,Code fournisseur,Nom fournisseur,Adresse fournisseur,Nationalite fournisseur\n");
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(prod[i].forns.nom, fournisseurDonne) == 0) {
            fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", prod[i].nom, prod[i].code, prod[i].categorie,
                   prod[i].disponibilite, prod[i].prix, prod[i].quantitenstock,
                   prod[i].forns.code1, prod[i].forns.nom, prod[i].forns.adresse,
                   prod[i].forns.nationalite);
        }
    }

    fclose(fp);
}

void produitCategorie(produit *prod, int n, char categorieDonnee[20]) {
    FILE *fp;
    fp = fopen("categorie.csv", "w");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    fprintf(fp, "Nom,Code,Categorie,Disponibilite,Prix,Quantite en stock,Code fournisseur,Nom fournisseur,Adresse fournisseur,Nationalite fournisseur\n");
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(prod[i].categorie, categorieDonnee) == 0) {
            fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", prod[i].nom, prod[i].code, prod[i].categorie,
                   prod[i].disponibilite, prod[i].prix, prod[i].quantitenstock,
                   prod[i].forns.code1, prod[i].forns.nom, prod[i].forns.adresse,
                   prod[i].forns.nationalite);
        }
    }

    fclose(fp);
}

void produitPrix(produit *prod, int n, float prixDonnee) {
    FILE *fp;
    fp = fopen("prix.csv", "w");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    fprintf(fp, "Nom,Code,Categorie,Disponibilite,Prix,Quantite en stock,Code fournisseur,Nom fournisseur,Adresse fournisseur,Nationalite fournisseur\n");
    int i;
    for (i = 0; i < n; i++) {
        if (prod[i].prix == prixDonnee) {
            fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", prod[i].nom, prod[i].code, prod[i].categorie,
                   prod[i].disponibilite, prod[i].prix, prod[i].quantitenstock,
                   prod[i].forns.code1, prod[i].forns.nom, prod[i].forns.adresse,
                   prod[i].forns.nationalite);
        }
    }

    fclose(fp);
}

void Ajoutprod(produit **prod, int *n) {
    FILE *fp;
    fp = fopen("stock.csv", "a");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    produit m;
    printf("\nEntrer les informations du nouveau produit:\n");
    printf("Nom : ");
    scanf("%s", m.nom);
    printf("Code : ");
    scanf("%s", m.code);
    printf("disponibilite : ");
    scanf("%s", m.disponibilite);
    printf("Categorie : ");
    scanf("%s", m.categorie);
    printf("Prix : ");
    scanf("%f", &m.prix);
    printf("Quantite en stock : ");
    scanf("%d", &m.quantitenstock);
    printf("Code fournisseur : ");
    scanf("%d", &m.forns.code1);
    printf("Nom fournisseur : ");
    scanf("%s", m.forns.nom);
    printf("Adresse fournisseur : ");
    scanf("%s", m.forns.adresse);
    printf("Nationalite fournisseur : ");
    scanf("%s", m.forns.nationalite);

    fprintf(fp, "%s;%s;%s;%s;%.2f;%d;%d;%s;%s;%s\n", m.nom, m.code, m.categorie,
            m.disponibilite, m.prix, m.quantitenstock, m.forns.code1,
            m.forns.nom, m.forns.adresse, m.forns.nationalite);

    fclose(fp);
}

void Suppprod(produit **prod, int *n) {
    char codeDonnee[15];
    printf("\nEntrer le code du produit a supprimer : ");
    scanf("%s", codeDonnee);

    FILE *fp;
    fp = fopen("stock.csv", "r");

    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    FILE *temp;
    temp = fopen("temp.csv", "w");

    if (temp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char code[20];
        sscanf(line, "%*[^,],%19[^,],", code);
        if (strcmp(code, codeDonnee) != 0) {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("stock.csv");
    rename("temp.csv", "stock.csv");
}

int main() {
    int choix;
    do {
        printf("\nMenu principal : \n");
        printf("1. Afficher le stock de produit\n");
        printf("2. Afficher les produits de la categorie ayant le moins de produit\n");
        printf("3. Afficher les produits d'un fournisseur donne\n");
        printf("4. Afficher les produits d'une categorie donnee\n");
        printf("5. Afficher les produits ayant un prix donne\n");
        printf("6. Ajouter un produit\n");
        printf("7. Supprimer un produit\n");
        printf("8. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: {
                FILE *fp;
                fp = fopen("stock.csv", "r");
                if (fp == NULL) {
                    printf("Erreur lors de l'ouverture du fichier.");
                    exit(1);
                }
                char c;
                while ((c = getc(fp)) != EOF) {
                    putchar(c);
                }
                fclose(fp);
            }
                break;
            case 2: {
                FILE *fp;
                fp = fopen("stock.csv", "r");
                if (fp == NULL) {
                    printf("Erreur lors de l'ouverture du fichier.");
                    exit(1);
                }
                produit prod[100]; // Assuming maximum 100 products
                int i = 0;
                char line[256];
                while (fgets(line, sizeof(line), fp)) {
                    sscanf(line, "%[^,];%[^,];%[^,];%[^,];%f;%d;%d;%[^,];%[^,];%[^\n]", prod[i].nom, prod[i].code, prod[i].categorie,
                           prod[i].disponibilite, &prod[i].prix, &prod[i].quantitenstock, &prod[i].forns.code1,
                           prod[i].forns.nom, prod[i].forns.adresse, prod[i].forns.nationalite);
                    i++;
                }
                fclose(fp);
                produitCategorieMoins(prod, i);
            }
                break;
            case 3: {
                char fournisseurDonne[15];
                printf("Entrer le nom du fournisseur : ");
                scanf("%s", fournisseurDonne);
                produitFournisseur(NULL, 0, fournisseurDonne);
            }
                break;
            case 4: {
                char categorieDonnee[20];
                printf("Entrer le nom de la categorie : ");
                scanf("%s", categorieDonnee);
                produitCategorie(NULL, 0, categorieDonnee);
            }
                break;
            case 5: {
                float prixDonnee;
                printf("Entrer le prix : ");
                scanf("%f", &prixDonnee);
                produitPrix(NULL, 0, prixDonnee);
            }
                break;
            case 6:
                Ajoutprod(NULL, NULL);
                break;
            case 7:
                Suppprod(NULL, NULL);
                break;
            case 8:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 8);

    return 0;
}
