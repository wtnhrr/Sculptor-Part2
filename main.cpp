#include <iostream>
#include <vector>
#include <fstream>
#include "sculptor.h"
#include "Leitor.h"
#include "figurageometrica.h"




using namespace std;

int main()
{
   Sculptor *wf;

   Leitor parser;

   vector<FiguraGeometrica*>figs;

   figs = parser.parse("C:/Users/queir/OneDrive/Documentos/Programação Avançada/PA - c++ - Part 2/test.txt");

   wf = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

   for(size_t i=0;i<figs.size();i++){
       cout << "draw/n";
       figs[i]->draw(*wf);
   }

   wf->writeOFF((char*) "zariman.off");
   
   for(size_t i=0;i<figs.size();i++){
       delete figs[i];
   }

   delete wf;
   
   return 0;
}