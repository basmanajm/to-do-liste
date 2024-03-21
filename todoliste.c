#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char *task;
int numtask=0;
char  tasks[10][25];     // 10 tasks et 25 caracteres au max pour chaq task
char newtask[10][20];   // Pour ajouter une nouvelle tache
int choix;             // selon le menu
int priorites[10];     //tableau qui  contiendra les priorités des taches marqués par l'utilisateur
int priorite;          //1: Haute, 2: Moyenne, 3: Basse, 4: Aucune
int taches_terminees[10];    // Tableau qui indique si la tache est terminee ou non

//definition des fonctions

void ajouter(){
    if(numtask>10) {
        printf("la liste  est pleine\n");
   }
   else{
    printf("Ajoutez la tache : \n");
    scanf("%s",&tasks[numtask]);
    do{
    printf("Entrez la priorite (1: Haute, 2: Moyenne, 3: Basse, 4: Aucune) : ");
     scanf("%d", &priorites[numtask]);
     }while(priorites[numtask]>4);
   numtask++;
   }
}

 void modifier(){
    if (numtask == 0) {
        printf("To-Do List est vide.\n");
    } else {
    printf("entrez le numero de tache que vous voulez modifier\n");
    scanf("%d",&numtask);
    printf("entrez la nouvelle tache\n");
    scanf("%s", &newtask);
    strcpy(tasks[numtask-1],*newtask);
    printf("Entrez la priorite (1: Haute, 2: Moyenne, 3: Basse, 4: Aucune) : ");
    scanf("%d", &priorites[numtask - 1]);
    printf("La tache %d vient d'etre modifiee en '%s' \n", numtask,newtask);
    }
}

void supprimer(){
    if (numtask == 0) {
        printf("To-Do List est vide.\n");
    } else {
    printf("entrez le numero de tache que vous voulez supprimer\n");
    scanf("%d",&numtask);
   
    if(numtask>=1 && numtask<10){
        for(int i=numtask-1 ;i<9; i++){
            strcpy(tasks[i],tasks[i+1]);
            priorites[i] = priorites[i + 1];
            taches_terminees[i] = taches_terminees[i + 1];
            
        }
        printf("La tache %d est supprimee.\n",numtask );
        numtask--;
    }else{printf("Ce numero n'est pas valide.\n") ;}
  }
}

void afficher(){
     if(numtask!=0){
        printf("Liste des taches :\n");
    for( int i=0; i<numtask; i++){
    printf("Tache num %d : %s    de priorite:%d  statut:%d \n ",i+1,tasks[i],priorites[i],taches_terminees[i]);
    }
     } else {
        printf("aucune tache n est enregistre!\n");
     }
}
void marquer(){
    int reponse;
    if (numtask == 0) {
        printf("To-Do List est vide.\n");
    } else {
        do{
        printf("La tache '%s' est-elle terminee ? (1: Oui, 0: Non) : ", tasks[numtask-1]);
        
        scanf("%d", &reponse);
        
        if (reponse == 1) {
            taches_terminees[numtask-1] = 1;
           printf("La tache '%s' est marquee comme terminee.\nbravo!\n", tasks[numtask - 1]);
        } else if (reponse == 0) {
            taches_terminees[numtask-1] = 0;
           printf("La tache '%s' est marquee comme non terminee.\ncourage!\n", tasks[numtask - 1]);
        } else {
            printf("Veuillez entrer une reponse valide (1 pour Oui, 0 pour Non).\n");
        }
        } while (!(reponse == 1 || reponse == 0));
    }  
}

void afficher_par_priorite(){
    if (numtask == 0) {
        printf("la liste est vide\n");
    }
    else{

    printf("\n--- To-Do List par priorite ---\n");
    for (int priorite = 1; priorite <= 4; priorite++) {
        printf("Priorite %d:\n", priorite);
        for (int i = 0; i < numtask; i++) {
            if (priorites[i] == priorite) {
                printf("  - %s\n", tasks[i]);
            }
        }
    }
    }
}


// Gestionnaire principal du programme.
int main(){
 while(true){
    
    printf("          TO DO LIST!\n\n");     //titre
    printf("Quelle tache vous voulez effectuer?\n 1.ajouter\n 2.modifier\n 3.supprimer\n 4.afficher la liste\n 5.afficher_par_priorite\n 6.marquer les taches terminees\n 7.quitter \n"); //menu
    int choix=0;
    scanf("%d",&choix); 
    getchar();
    switch (choix){
    case 1:          //ajout  d'une tache
       ajouter();
       marquer();
       printf("c est  ajoute a votre liste  de taches.\n");
        break;
   
    case 2:         //modification d'une tache
        modifier();
        marquer() ;
        break;

    case 3:         //suppression d'une tache
        supprimer();
        break;

    case  4:         //affichage des taches
      afficher();
      break;

    case 5:         //afficher par priorites
    afficher_par_priorite();
    break;

    case 6:        // marquer les taches
     if (numtask == 0) {
        printf("To-Do List est vide.\n");
    } else {
    printf("entrez l num de tache que vouz voulez marquez\n");
    scanf("%d",&numtask);
    marquer();
    break;

    case 7:             //sortir du programme
      printf("Au revoir!\n");
       return 0;


    default:
      printf("votre choix n est pas valide \n veuillez choisir de nouveau\n");
      break;
    }
 }
 }
 
 return 0;
}