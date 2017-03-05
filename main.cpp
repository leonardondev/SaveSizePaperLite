#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void recortar(unsigned int px, unsigned int py, std::string file_name);

int main(){
     unsigned int px;
     unsigned int py;
     
     cout << "insira px" << endl;
     cin >> px;
     cout << "insira py" << endl;
     cin >> py;
     
     /*nome do arquivo*/
     string nome_da_foto;
     cout << "\nEntre com o nome do arquivo" << endl;
     cin >> nome_da_foto;

recortar(px,py,nome_da_foto);

return 0;
}

