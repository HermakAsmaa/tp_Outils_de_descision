#include "Graphe.hpp"

Graphe::Graphe(){
}

Graphe::Graphe(std::string cheminFichier){
  std::ifstream monflux(cheminFichier);
  if(monflux)
   {
     int nombres,nombre1,nombre2,arc,i(0);
     monflux >> nombres;
     std::cout << "Nombre de sommets :" << nombres << std::endl; 
     monflux >> nombres;
     std::cout << "Nombre d'arcs :" << nombres << std::endl; 
     while(i<nombres)
     {
      monflux >> nombre1;
      std::cout << "Sommet recuperer " << nombre1 << std::endl;
      this->add_Sommet(nombre1);
      monflux >> nombre2;
      std::cout << "Sommet recuperer " << nombre2 << std::endl;
      this->add_Sommet(nombre2);
      monflux >> arc;
      std::cout << "Arc recuperer " << arc << std::endl;
      this->add_Arc(nombre1,nombre2,arc);
      i++;
     }   
    }
  else
   {
     std::cout << "ERREUR:Impossible d'ouvrir le fishier en lecture" << std::endl;
    }
}

int Graphe::add_Sommet(int id){
  if(getSommetPosition(id)==-1){
   int pos=sommets.size();
   Sommet sommet(id);
   sommets.push_back(sommet);
   return pos;
   }
  else 
   return -1;
}

Sommet& Graphe::getSommet(int pos){
   assert(pos<sommets.size());
       return sommets[pos];
}

int Graphe::getSommetPosition(int id){
    for(int i=0;i<sommets.size();i++)
     {
       if(sommets[i].getId()==id)
         return i;
      }
     return -1;
}
void Graphe::remove_Sommet(int id){
   int pos=getSommetPosition(id);
   int arc_var;
  if(pos!=-1){
   for(int j=0;j<sommets[pos].nbrArcIn();j++)
      {
        arc_var=sommets[pos].getInArc(j);
        remove_Arc(arc_var);
       }
   for(int j=0;j<sommets[pos].nbrArcOut();j++)
      {
        arc_var=sommets[pos].getOutArc(j);
        remove_Arc(arc_var);
       }
  for(int i=pos;i<nbr_Sommets()-1;i++){
     sommets[i]=sommets[i+1];
   }
  sommets.pop_back();
 }
}

       
int Graphe::add_Arc(int idOrig,int idDest,int cout){
  int id=nbr_Arcs();
   Arc arc(id);
   arc.setIdOrig(idOrig);
   arc.setIdDest(idDest);
   arc.setCout(cout);
   arcs.push_back(arc);
   //ajouter l'arc dans les sommets origine et destination
   Sommet& s1=getSommet(getSommetPosition(idOrig));
   s1.AddOutArc(id);
   Sommet& s2=getSommet(getSommetPosition(idDest));
   s2.AddInArc(id);
   return id;
 
}
    
Arc& Graphe::getArc(int pos){
     assert(pos<arcs.size());
       return arcs[pos];
}

int Graphe::getArcPosition(int id){
     for(int i=0;i<arcs.size();i++)
     {
       if(arcs[i].getId()==id)
         return i;
      }
     return -1;
}

void Graphe::remove_Arc(int id){
  int pos=getArcPosition(id);
  if(pos!=-1){
     int idorig=getArc(id).getIdOrig();
     int iddest=getArc(id).getIdDest();
     for(int j=0;j<nbr_Sommets();j++)
      {
        if(sommets[j].getId()==idorig)
             sommets[j].removeOutArc(id);
        if(sommets[j].getId()==iddest)
             sommets[j].removeInArc(id);
       }
  for(int i=pos;i<nbr_Arcs()-1;i++){
     arcs[i]=arcs[i+1];
     arcs[i].setId(i+1);
   }
  arcs.pop_back();
 }
}
       
int Graphe::nbr_Sommets(){
    return sommets.size();
}
       
int Graphe::nbr_Arcs(){
    return arcs.size();
}
       
void Graphe::Afficher(){
    std::cout << "Les Sommets :" << std::endl;
    for(int i=0;i<sommets.size();i++){
      sommets[i].Afficher();
    }
    std::cout << "Les Arcs :" << std::endl;
    for(int i=0;i<arcs.size();i++){
      arcs[i].Afficher();
    }
}

void Graphe::Dijkstra(int idRacine){
    int j=0;
    int n=nbr_Sommets();
    //std::cout << "Le nombre de sommets: " << n << std::endl;
    int min=0;
    //std::cout << "Le minimum: " << min << std::endl;
    int pos=getSommetPosition(idRacine);
    //std::cout << "La position : " << pos << std::endl;
   if(pos!=-1)
   {  
     //std::cout << "je suis là la position different de -1" << std::endl; 
     int pere[n]={0};
     int m[n]={0};
     for(int i=0;i<n;i++){
        m[i]=1000;
      }
     int T[n]={0};
     pere[pos]=-1;
     m[pos]=0;
     T[pos]=1;
     Sommet s=getSommet(pos);
     for(int i=0;i<s.nbrArcOut();i++){
         Arc c=getArc(getArcPosition(s.getOutArc(i)));
         //std::cout << "l'arc est de cout " << c.getCout() << std::endl;
         pere[getSommetPosition(c.getIdDest())]=s.getId();
         //std::cout << "position: " << getSommetPosition(c.getIdDest()) << " pere:" << s.getId() << std::endl;
         m[getSommetPosition(c.getIdDest())]=c.getCout();
         //std::cout << "position: " << getSommetPosition(c.getIdDest()) << " pere" << c.getCout() << std::endl;
       }
     int min=0;
 while(min!=1000){  
    //std::cout << "le minimum est different de 1000" << std::endl;
     min=1000;
     for(int i=0;i<n;i++)
     {
        //std::cout << "le sommet:" << sommets[i].getId() << "T[i] : " << T[i] << "m[i] : " << m[i] << std::endl;
       if(T[i]==0 && m[i]<min){
         //std::cout << "le sommet choisi est :" << sommets[i].getId() << std::endl;
         pos=i;
         min=m[i];
        }
     }
     if(min!=1000){
        s=getSommet(pos);
        T[pos]=1;
        for(int i=0;i<s.nbrArcOut();i++){
         Arc c=getArc(getArcPosition(s.getOutArc(i)));
         int p=getSommetPosition(c.getIdDest());
         if(m[p]>(c.getCout()+m[pos]))
         {
           pere[p]=s.getId();
           m[p]=c.getCout()+m[pos];
         }
       }
      }
     }
   // 
   std::cout << "Les sommets :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << sommets[i].getId() << "  " ;
    }
     std::cout << std::endl; 
   std::cout << "Le tableau m :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << m[i] << "  " ;
    }
     std::cout << std::endl; 
   std::cout << "Le tableau pere :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << pere[i] << "  " ;
    }
     std::cout << std::endl; 
   //
   }
   else
   {
      std::cout << "Le noued du debut n'existe pas " << std::endl;
      //min=1000;
    }
}

void Graphe::Bellman(int idRacine){
   int n=nbr_Sommets();
   //int min=0;
   int pos=getSommetPosition(idRacine);
   if(pos!=-1)
   {
      int pere[nbr_Sommets()]={0};
      int m[nbr_Sommets()]={0};
      for(int i=0;i<n;i++){
        m[i]=1000;
      }
      int T[nbr_Sommets()]={0};
      bool stop=false;
      pere[pos]=-1;
      m[pos]=0;
      T[pos]=1;
      Sommet s=getSommet(pos);
      for(int i=0;i<s.nbrArcOut();i++){
         Arc c=getArc(getArcPosition(s.getOutArc(i)));
         pere[getSommetPosition(c.getIdDest())]=s.getId();
         m[getSommetPosition(c.getIdDest())]=c.getCout();
       }
       if(pos==n-1)
         pos=0;
       else
         pos++;
    while(stop==false){
      stop=true;
      //T={0};
      while(T[pos]==0){  
             //pos=j;
             //min=m[j] 
             s=getSommet(pos);
             T[pos]=1;
             
             for(int i=0;i<s.nbrArcOut();i++){
                Arc c=getArc(getArcPosition(s.getOutArc(i)));
                int p=getSommetPosition(c.getIdDest());
               if(m[p]>c.getCout()+m[pos])
               {
                  pere[p]=s.getId();
                  m[p]=c.getCout()+m[pos];
                  stop=false;
                }
               }
              if(pos==nbr_Sommets()-1)
                  pos=0;
              else
                  pos++;
       }
       for(int k=0;k<n;k++){
            T[k]=0;
         }
     }
     // 
   std::cout << "Les sommets :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << sommets[i].getId() << "  " ;
    }
     std::cout << std::endl; 
   std::cout << "Le tableau m :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << m[i] << "  " ;
    }
     std::cout << std::endl; 
   std::cout << "Le tableau pere :" << std::endl ;
   for(int i=0;i<n;i++){
     std::cout << pere[i] << "  " ;
    }
     std::cout << std::endl; 
   //
   }
   else
   {
      std::cout << "Le noued du debut n'existe pas " << std::endl;
      //min=1000;
    }
}


