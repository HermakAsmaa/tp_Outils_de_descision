#include "Arc.hpp"
Arc::Arc(){
}

Arc::Arc(int Id){
  id=Id;
}

Arc::Arc(int Id,int IdOrig,int IdDest,int coutArg){
  id=Id;
  id_orig=IdOrig;
  id_dest=IdDest;
  cout=coutArg;
}

void Arc::setId(int idArg){
  id=idArg;
}
      
int Arc::getId(){
  return id;
}
       
void Arc::setIdOrig(int idOrig){
  id_orig=idOrig;
}
       
int Arc::getIdOrig(){
  return id_orig;
}
       
void Arc::setIdDest(int idDest){
  id_dest=idDest;
}
       
int Arc::getIdDest(){
   return id_dest;
}

void Arc::setCout(int coutArg){
   cout=coutArg;
}

int Arc::getCout(){
   return cout;
}

void Arc::Afficher(){
   std :: cout << "id= "<< id << " , orig=" << id_orig << " , dest=" << id_dest << " , cout=" << cout << std::endl ;  
}



