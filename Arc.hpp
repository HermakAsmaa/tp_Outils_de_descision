#ifndef Arc_H
#define Arc_H

#include<iostream>

class Arc{

   protected:
      int id;
      int id_orig;
      int id_dest;
      int cout;
   public:
       Arc();
       Arc(int Id);
       Arc(int Id,int idOrig,int idDest,int coutArg);
       void setId(int idArg);
       int getId();
       void setIdOrig(int idOrig);
       int getIdOrig();
       void setIdDest(int idDest);
       int getIdDest();
       void setCout(int coutArg);
       int getCout();
       void Afficher();
     
};

#endif
