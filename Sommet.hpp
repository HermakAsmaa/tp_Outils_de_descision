#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Sommet{

   protected:
      int id;
      std ::vector<int> in_arcs;
      std ::vector<int> out_arcs;
  
   public:
      Sommet();
      Sommet(int idArg);
      void setId(int idArg);
      int getId();
      int AddInArc(int idArg);
      int getInArc(int position);
      void removeInArc(int idArc);
      int findInArc(int IdArc);
      int AddOutArc(int idArg);
      int getOutArc(int position);
      void removeOutArc(int idArc);
      int findOutArc(int idArc);
      int nbrArcIn();
      int nbrArcOut();
      void Afficher();

};

#endif
