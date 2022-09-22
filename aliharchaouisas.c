#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

//projet de gestion de pharmacie realisé par ALI LHARCHAOUI

typedef struct produit produit;
struct produit{
	int code;
	char nom[50];
	int quantite;
	double prix;
	char date[100];
};

//AJOUTER
int ajouterP(produit p[1000],int n){
	int ns,i;
	printf("combien de produits voulez-vous ajouter  :");
	scanf("%d",&ns);
	for(i=n;i<n+ns;i++){
	 printf("donne le code de produit :");
	 scanf("%d",&p[i].code);
	 printf("donne le nom de produit :");
	 scanf("%s",p[i].nom);
	 printf("donne la quantite:");
	 scanf("%d",&p[i].quantite);
	 printf("donne le prix de produit(DH):");
	 scanf("%lf",&p[i].prix);
	 printf("\n********\n");
	}
	n+=ns;
return	n;

}
//AFFICHER
void afficher(produit p[1000],int n){
	int i;
	for(i = 0 ; i < n ; i++){
			printf("code : %d - nom : %s - quantite : %d - prix : %lf\n" , p[i].code , p[i].nom , p[i].quantite , p[i].prix);
			printf("\n *******\n");
		}
}
//RECHERCHE
//recherche_par_code
void recherche_par_code(produit a[1000],int n){
	int i=0,b;
	printf("enter the code");
	scanf("%d",&b);
	while(i<n){
		if(a[i].code==b){
			printf("nom  : %s \n",a[i].nom);
		    printf("code : %d \n",a[i].code);
			printf("prix : %f \n",a[i].prix);
			printf("quantite: %d \n",a[i].quantite);
			return;
		}
		i++;
	}
}
//recherche_par_quantite
void recherche_par_quantite(produit a[1000],int n){
	int i=0,b;
	printf("enter the quantite");
	 scanf("%d",&b);
	while(i<=n){
		if(a[i].quantite==b){
			printf("nom  : %s \n",a[i].nom);
		    printf("code : %d \n",a[i].code);
			printf("prix : %f \n",a[i].prix);
			printf("quantite: %d \n",a[i].quantite);
		}
		i++;
	}
}

//ACHETER PRODUIT
void acheterProduit(produit p[1000],produit p1[1000],int n,int* n2){
	int id,qte,i,t=0;
	double total,prixTTC;
	
	printf("entrer le code du produit:");
	scanf("%d",&id);printf("saisir la quantite");
		 scanf("%d",&qte);
	for(i=0;i<n;i++){
		if(p[i].code==id && p[i].quantite >=qte){
			t=1;
		  strcpy(p1[*n2].nom,p[i].nom);	
			p1[*n2].code=id;
		 	p1[*n2].quantite=qte;
			p[i].quantite-=qte;
			total=qte*p[i].prix*1.15;
			p1[*n2].prix=total;
			printf("le nom du produit : %s\n",p1[i].nom);
			printf("le code du produit : %d\n",p1[i].code);
			printf("qantite acheter : %d\n",qte);
		    printf("le total avec TTC: %lf\n",total);
		    *n2+=1;
		}
	}
		
	if(t=0){
			printf("not found ...");
		}
}


//LISTER LES PRODUIT
void triparselection(produit a[1000],int n){
	int i,j;
	produit c;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[j].prix>a[i].prix){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	
	}	
}

void triparnom(produit a[1000],int n){
	int i,j;
	produit c,*t=NULL;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcasecmp(a[i].nom,a[j].nom)<0){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	
	}	
}
//ETAT DU STOCK
void Etat_du_stock(produit a[1000],int n){
	int i=0;
	while(i<n){
		if(a[i].quantite<=3){
			printf("----------------------------------------------------------\n");
			printf("nom  : %s \n",a[i].nom);
		    printf("code : %d \n",a[i].code);
			printf("prix : %f \n",a[i].prix);
			printf("quantite: %d \n",a[i].quantite);
			
		}
		i++;
	}
}
//ALIMENTER DU STOCK
void alimenter_du_stock(produit a[1000],int n){
	int i=0,c,b,v;
	 printf("enter the code");
	 scanf("%d",&c);
	 printf("enter the quantite");
	 scanf("%d",&b);
	while(i<n){
		if(a[i].code==c){
		 a[i].quantite =a[i].quantite+b;
		 printf("le stock est bien augmenter");
		 return;
		}
		i++;
	}
	
	printf("le code n exite pas");
	
}
//SUPPRIMER
int supprimer(produit p[1000],int n){
	int idn;
	int i;
	printf("donne le code:");
	scanf("%d",&idn);
	for(i=0;i<n;i++){
       if(idn==p[i].code){
       	p[i]=p[n-1];
       	printf("produit supprimer");
	   }
	n--;	
	return n;
}
}
	
//Statistique
void totale_des_prix(produit p1[1000],int n2){
	int i;
	double s=0;
	for(i = 0 ; i <= n2 ; i++){
		 s+=p1[i].prix;
		} 
		printf("le totle des prix vendu est %lf ",s );
		printf("\n *********************\n");
}

void moyenne_des_prix(produit p[1000],int n2){
	int i;
	double s=0;
	for(i = 0 ; i <= n2 ; i++){
		 s+=p[i].prix;	
		} 
		printf("\n im here\n");
		printf("le totle des prix vendu est %lf ",s/n2 );
			printf("\n *******\n");
}

void min_des_prix(produit p[1000],int n2){
	int i;
	produit a=p[0];
	for(i = 1 ; i <= n2 ; i++){
		 if(a.prix>p[i].prix){
		 	a=p[i];
		 }
		} 
		printf("----------------------------------------------------------\n");
			printf("nom  : %s \n",a.nom);
		    printf("code : %d \n",a.code);
			printf("prix : %f \n",a.prix);
			printf("quantite: %d \n",a.quantite);
}

void max_des_prix(produit p[1000],int n2){
	int i;
	produit a=p[0];
	for(i = 1 ; i <= n2 ; i++){
		 if(a.prix<p[i].prix)
			a=p[i];
		} 
		printf("----------------------------------------------------------\n");
			printf("nom  : %s \n",a.nom);
		    printf("code : %d \n",a.code);
			printf("prix : %f \n",a.prix);
			printf("quantite: %d \n",a.quantite);
}


int main(){
    produit p[1000],p1[1000];
	int  n=0, c, c2, c5,n2=0, i=0,c9;
	produit produitsAchetee[1000];
	do{
	
	
 
		system("cls");
	printf("                      **********************MENU*****************************   \n");
 	printf("                      *                (1)-ajouter les produit              *   \n");
    printf("                      *                (2)-lister les produit               *   \n");
    printf("                      *                (3)-Acheter produit                  *   \n");
    printf("                      *                (4)-Affichage                        *   \n");
    printf("                      *                (5)-Recherche                        *   \n");
    printf("                      *                (6)-Etat du stock                    *   \n");
    printf("                      *                (7)-Alimenter du stock               *   \n");
    printf("                      *                (8)-Supprimer les produit            *   \n");
    printf("                      *                (9)-Statistique                      *   \n");
    printf("                      *                (0)-Quitter                          *   \n");
    printf("                      *******************************************************  \n");
    scanf("%d",&c);
    
    	switch(c){
	case 1:	 n=ajouterP(p,n);                                    system("PAUSE") ;   break;
	case 2:  
			 printf(" 1 trie  par prix \n");
	         printf(" 2 trie par nom \n");
	 		 scanf("%d",&c2);
	 		 switch(c2){
	 		 	case 1:triparselection(p,n);afficher(p,n);       system("PAUSE");    break;
	 		 	case 2:triparnom(p,n);afficher(p,n);             system("PAUSE");    break;
			 
		    }   break;
	case 3:	acheterProduit( p, p1, n,&n2);                      system("PAUSE");    break;
	case 4: afficher(p,n);                                       system("PAUSE");    break;
	case 5: printf(" 1 recherche par code \n");
	        printf("2 recherche par quantite \n");
	 		 scanf("%d",&c5);
	 		 switch(c5){
	 		 	case 1:recherche_par_code(p,n);                   system("PAUSE");   break;
	 		 	case 2:recherche_par_quantite(p,n);               system("PAUSE");   break;
			 
		    } break; 
	case 6: Etat_du_stock(p,n);                                   system("PAUSE");   break;
	case 7: alimenter_du_stock(p,n);afficher(p,n);                system("PAUSE");   break;
	case 8: n=supprimer(p,n);                                     system("PAUSE");   break;
	case 9:  
	        printf("1 pour le totale des prix \n");
	        printf("2 pour la moyenne des prix \n");
	        printf("3 pour la max des prix \n");
	        printf("4 pour le min des prix \n");
	 		 scanf("%d",&c9);
	 		 switch(c9){
	 		 	case 1:totale_des_prix(p1,n2);                    system("PAUSE");   break;
	 		 	case 2:moyenne_des_prix(p1,n2);                   system("PAUSE");   break;
	 		 	case 3:max_des_prix(p1,n2);    					  system("PAUSE");   break;
	 		 	case 4:min_des_prix(p1,n2);   					  system("PAUSE");   break;
			
		    }   break;
	case 0: i=1;                                                  system("PAUSE");   break;
	}

}while(i==0);

    return 0;
}
