#include<iostream>
#include<vector>
#include"Sommet.hpp"
#include"Arc.hpp"
#include"Graphe.hpp"

int main(){
/*
Graphe graphe;
graphe.add_Sommet(1);
graphe.add_Sommet(2);
graphe.add_Sommet(3);
graphe.add_Sommet(4);
graphe.add_Sommet(5);
graphe.add_Sommet(6);

graphe.add_Arc(1,2,5);
graphe.add_Arc(1,4,7);
graphe.add_Arc(1,3,2);
graphe.add_Arc(3,4,3);
graphe.add_Arc(4,6,9);
graphe.add_Arc(2,5,2);
graphe.add_Arc(5,4,1);
graphe.add_Arc(6,5,11);
graphe.add_Arc(6,2,3);
*/
Graphe graphe("/home/asmaa/tp_Outils_de_descision/graphe.txt");
graphe.Afficher();
graphe.Dijkstra(1);
graphe.Bellman(1);

 return 0;

}
