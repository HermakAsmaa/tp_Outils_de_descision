#ifndef GRAPHE_H
#define GRAPHE_H


#include <iostream>
#include <vector>
#include <cassert>
#include "Arc.hpp"
#include "Sommet.hpp"
#include <string>
#include <fstream>

class Graphe{
   
   protected:
       std:: vector<Arc> arcs;
       std:: vector<Sommet> sommets;
   
   public:
       Graphe();
       Graphe(std::string cheminFichier);
       int add_Sommet(int id);
       int getSommetPosition(int id);
       Sommet& getSommet(int pos);
       void remove_Sommet(int id);
       int add_Arc(int idOrig,int idDest,int cout=0);
       //int add_Arc(int id,int idOrig,int idDest,int cout=0);
       int getArcPosition(int id);
       Arc& getArc(int pos);
       void remove_Arc(int id);
       int nbr_Sommets();
       int nbr_Arcs();
       void Afficher();
       void Dijkstra(int idRacine);
       void Bellman(int idRacine); 
       
};

#endif
