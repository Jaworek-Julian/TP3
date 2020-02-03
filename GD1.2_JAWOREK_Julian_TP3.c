#include <stdlib.h>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
//-------------------------------------------------------------------
// Structure des tableaux
typedef struct objet_s
{
	char* nom;
	double prix;
} objet_t;
//-------------------------------------------------------------------
// Fonction pour retirer un emplacement
int objet_remove(objet_t* objets, int id, int size)
{
	if (id != size - 1)
		objets[id] = objets[size - 1];

	return size - 1;
}
//-------------------------------------------------------------------
// Fonction void pour trier un tableau
void objet_tri(objet_t* objets, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;
		for (int j = i; j < size; j++)
		{
			if (objets[j].prix < objets[minIndex].prix)
				minIndex = j;
		}

		if (minIndex != i)
		{
			objet_t tmp = objets[i];
			objets[i] = objets[minIndex];
			objets[minIndex] = tmp;
		}
	}
}
//-------------------------------------------------------------------
// Fonction void pour appeler un tableau
void appelInv(objet_t* cases, int size) {

	objet_tri(cases, size);

	for (int i = 0; i < size; i++)
	{
		printf("%s / %g pieces (%d)\n", cases[i].nom, cases[i].prix, i);
	}

}
//-------------------------------------------------------------------
int main()
{
	int invMarch = 3;
	int choix = 0;
	int compteur = 0;
	double argent = 100;
	int invPerso = 5;

	objet_t inventairePerso[10];
	inventairePerso[0].nom = "kebab";
	inventairePerso[0].prix = 6;
	inventairePerso[1].nom = "herbe de provence";
	inventairePerso[1].prix = 20;
	inventairePerso[2].nom = "epee rouillee";
	inventairePerso[2].prix = 10;
	inventairePerso[3].nom = "cheveux";
	inventairePerso[3].prix = 0.05;
	inventairePerso[4].nom = "tablette de chocolat";
	inventairePerso[4].prix = 5;

	objet_t inventaireMarchant[5];
	inventaireMarchant[0].nom = "potion de soin";
	inventaireMarchant[0].prix = 10;
	inventaireMarchant[1].nom = "potion de mana";
	inventaireMarchant[1].prix = 5.5;
	inventaireMarchant[2].nom = "bombe";
	inventaireMarchant[2].prix = 50;


	while (choix != 3)
	{

		printf("Vous avez:\n");

		appelInv(inventairePerso, invPerso);

		printf("ainsi que: %g pieces dans votre inventaire\nvoulez-vous vendre? (0), ajouter un article? (1), acheter un article (2) ou quitter (3)\n", argent);
		scanf("%d", &choix);

		//vente
		if (choix == 0)
		{
			printf("que voulez-vous vendre?\n");

			scanf("%d", &compteur);

			inventaireMarchant[invMarch] = inventairePerso[compteur];

			argent += inventairePerso[compteur].prix;

			invPerso = objet_remove(inventairePerso, compteur, invPerso);
			//-------------------------------------------------------------------
		}
		//ajout d'un objet
		else if (choix == 1)
		{
			invMarch++;
			double d = 0;
			char nom[32];
			printf("inserez le nom de la marchandise:\n");
			scanf("%s", &nom);
			scanf("%lf", &d);

			inventaireMarchant[invMarch - 1].nom = nom;
			inventaireMarchant[invMarch - 1].prix = d;

			appelInv(inventaireMarchant, invMarch);

		}
		//-------------------------------------------------------------------
		//achat
		else if (choix == 2)
		{
			appelInv(inventaireMarchant, invMarch);

			printf("que voulez-vous acheter?\n");
			scanf("%d", &compteur);

			if (argent < inventaireMarchant[compteur].prix)
			{
				printf("Vous n'avez pas assez d'argent!\n");
			}else
			{
				inventairePerso[invPerso] = inventaireMarchant[compteur];
				argent -= inventaireMarchant[compteur].prix;
				invPerso += 1;
				invMarch = objet_remove(inventaireMarchant, compteur, invMarch);
			}
		}
		//permet une meilleur lisibilitée
		printf("\n\n");
	//-------------------------------------------------------------------
	}
}