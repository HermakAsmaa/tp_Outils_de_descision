#include "Sommet.hpp"
#include <iostream>
#include<vector>


Sommet::Sommet(){
  id=0;
}

Sommet::Sommet(int idArg){
  id=idArg;
}

void Sommet::setId(int idArg){
  id=idArg;
}
      
int Sommet::getId(){
   return id;
}

/*
int Sommet::find_element(int elt,std::vector<int> vec){
  for(int i=0;i<vec.size();i++){
     if(vec[i]==elt)
        return i;
   }
   return -1;
}
*/
      
int Sommet::AddInArc(int idArg){
  int pos=findInArc(idArg);
  if(pos == -1){
     in_arcs.push_back(idArg);
         return (in_arcs.size()-1);
   }
  else
   {
     std::cout << "L'arc existe deja" << std::endl;
     return pos;
   }
}
      
int  Sommet::getInArc(int position){
   //assert--->if
  assert(position < in_arcs.size());
      return in_arcs[position];
}

void Sommet::removeInArc(int IdArc){
  int pos=findInArc(IdArc);
  if(pos!=-1){
  for(int i=pos;i<nbrArcIn()-1;i++){
     in_arcs[i]=in_arcs[i+1];
   }
  in_arcs.pop_back();
 }
}
int Sommet::findInArc(int IdArc){
   for(int i=0;i<in_arcs.size();i++){
    if(in_arcs[i]==IdArc)
      return i;
   }
   return -1;
  
}
      
int Sommet::AddOutArc(int idArg){
  int pos = findOutArc(idArg);
  if(pos == -1){
     out_arcs.push_back(idArg);
       return (out_arcs.size()-1);
   }
  else
   {
     return pos;
   }
}
      
int Sommet::getOutArc(int position){
   //assert--->if
    assert(position < out_arcs.size());
      return out_arcs[position];
    
}

void Sommet::removeOutArc(int IdArc){
  int pos=findOutArc(IdArc);
  if(pos!=-1){
  for(int i=pos;i<nbrArcOut()-1;i++){
     out_arcs[i]=out_arcs[i+1];
   }
  out_arcs.pop_back();
 }
}
int Sommet::findOutArc(int IdArc){
    for(int i=0;i<out_arcs.size();i++){
    if(out_arcs[i]==IdArc)
      return i;
   }
   return -1;
}

      
int Sommet::nbrArcIn(){
    return in_arcs.size();
}
      
int Sommet::nbrArcOut(){
    return out_arcs.size();
}
     
void Sommet::Afficher(){
  std :: cout << "id= "<< id << " in=[";
  for(int i=0;i<nbrArcIn();i++)
   {
      std :: cout << " "<< in_arcs[i];
    }
   std :: cout << " ] out[";
  for(int i=0;i<nbrArcOut();i++)
   {
      std :: cout << " "<< out_arcs[i];
    }
   std :: cout << " ]" << std::endl;
}






