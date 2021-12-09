#include<iostream>
#include<omp.h>
#include<fstream>
#include<cstring>
using namespace std;



int main(){
  string ws[5] = {"aa","the","an","is","of"};
  for(int nt=1;nt<=8;nt*=2){
    cout<< "\n for threads " << nt << endl; 
    // double t = omp_get_wtime();
    #pragma omp parallel for num_threads(nt)
    for(int i=0;i<5;i++){
      double t = omp_get_wtime();
      int c = 0;
      fstream f;
      string w;
      f.open("words.txt"); //w1.txt w2.txt ...
      while(f >> w)
        if(strcmp(ws[i].c_str(),w.c_str())==0)
          c++;
        // cout<<"\n" << w << endl;
      cout<<"\n"<<ws[i]<<" "<<c<<" Time :" << omp_get_wtime()-t << endl;
    }
    
  }
  return 0;
}
