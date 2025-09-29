#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define TAILLE 50

// Définition de la structure Contact
typedef struct {
    char nom[TAILLE];
    char telephone[TAILLE];
    char email[TAILLE];
} Contact;

// Tableau global pour stocker les contacts
Contact contacts[MAX_CONTACTS];
int nb_contacts = 0;

// Fonction pour vider le buffer clavier
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour ajouter un contact
void ajouterContact() {
    if (nb_contacts >= MAX_CONTACTS) {
        printf("Carnet plein !\n");
        return;
    }

    printf("Nom : ");
    scanf(" %[^\n]", contacts[nb_contacts].nom);

    // Vérification du numéro (<= 10 caractères)
    do {
        printf("Téléphone (max 10 chiffres) : ");
        scanf(" %[^\n]", contacts[nb_contacts].telephone);

        if (strlen(contacts[nb_contacts].telephone) > 10) {
            printf("⚠ Erreur : le numéro ne doit pas dépasser 10 chiffres.\n");
        }
    } while (strlen(contacts[nb_contacts].telephone) > 10);

    printf("Email : ");
    scanf(" %[^\n]", contacts[nb_contacts].email);

    nb_contacts++;
    printf("✅ Contact ajouté avec succès !\n");
}

// Fonction pour afficher tous les contacts
void afficherContacts() {
    if (nb_contacts == 0) {
        printf("⚠ Aucun contact enregistré.\n");
        return;
    }
    printf("\n--- Liste des contacts ---\n");
    for (int i = 0; i < nb_contacts; i++) {
        printf("%d) Nom: %s | Téléphone: %s | Email: %s\n",
               i + 1, contacts[i].nom, contacts[i].telephone, contacts[i].email);
    }
    printf("---------------------------\n");
}

// Fonction pour rechercher un contact par nom
int rechercherContact(char nom[]) {
    for (int i = 0; i < nb_contacts; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            return i; // Retourne l'indice si trouvé
        }
    }
    return -1; // Non trouvé
}

// Fonction pour afficher un contact précis
void afficherUnContact() {
    char nom[TAILLE];
    printf("Entrez le nom du contact à rechercher : ");
    scanf(" %[^\n]", nom);

    int index = rechercherContact(nom);
    if (index != -1) {
        printf("Nom: %s | Téléphone: %s | Email: %s\n",
               contacts[index].nom, contacts[index].telephone, contacts[index].email);
    } else {
        printf(" Contact non trouvé.\n");
    }
}

// Fonction pour modifier un contact
void modifierContact() {
    char nom[TAILLE];
    printf("Entrez le nom du contact à modifier : ");
    scanf(" %[^\n]", nom);

    int index = rechercherContact(nom);
    if (index != -1) {
        // Vérification du numéro
        do {
            printf("Nouveau téléphone (max 10 chiffres) : ");
            scanf(" %[^\n]", contacts[index].telephone);

            if (strlen(contacts[index].telephone) > 10) {
                printf(" Erreur : le numéro ne doit pas dépasser 10 chiffres.\n");
            }
        } while (strlen(contacts[index].telephone) > 10);

        printf("Nouvel email : ");
        scanf(" %[^\n]", contacts[index].email);
        printf(" Contact modifié avec succès !\n");
    } else {
        printf("Contact non trouvé.\n");
    }
}

// Fonction pour supprimer un contact
void supprimerContact() {
    char nom[TAILLE];
    printf("Entrez le nom du contact à supprimer : ");
    scanf(" %[^\n]", nom);

    int index = rechercherContact(nom);
    if (index != -1) {
        for (int i = index; i < nb_contacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        nb_contacts--;
        printf(" Contact supprimé avec succès !\n");
    } else {
        printf("Contact non trouvé.\n");
    }
}

int main() {
    int choix;
    do {
        printf("\n===== MENU GESTION CONTACTS =====\n");
        printf("1. Ajouter un contact\n");
        printf("2. Afficher tous les contacts\n");
        printf("3. Rechercher un contact\n");
        printf("4. Modifier un contact\n");
        printf("5. Supprimer un contact\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        

        switch (choix) {
            case 1: ajouterContact(); break;
            case 2: afficherContacts(); break;
            case 3: afficherUnContact(); break;
            case 4: modifierContact(); break;
            case 5: supprimerContact(); break;
            case 0: printf(" Au revoir !\n"); break;
            default: printf(" Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
