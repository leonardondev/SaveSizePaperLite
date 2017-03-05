#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>   
#include "bitmap_image.hpp"

using namespace std;

void recortar(unsigned int px, unsigned int py, std::string file_name){

     /*matriz bitmap*/
     bitmap_image image(file_name);
     
     /*conversão para gray*/
     image.convert_to_grayscale();

     unsigned int largura = image.width(); //390
     unsigned int altura = image.height(); //390
     
     /*teste de segurança*/
     if(largura%px!=0)exit(1);
     if(altura%py!=0)exit(1);

     unsigned int i, j, k, l, n = 0;
     bitmap_image recorte;//matriz bitmap
     std::stringstream numero;//sequencia de caracteres para nomear os arquivos
     
     /*RECORTANDO*/
     for(i=0;i<altura;i+=py)   {
          for(j=0;j<largura;j+=px)   {
               n++;//n-ésimo recorte
               if (!image.region(     j     ,     i     ,     px    ,     py     ,recorte)){
                    std::cout << "ERROR: figura " << n << std::endl;
               }
               
               /* Esvaziando stringstream */
               numero.str("");
               
               /*convertendo int em string*/
               numero << n;
               
               /*salvando recorte*/
               recorte.save_image("_recorte_" + numero.str() + ".bmp");

        }
     }
}


