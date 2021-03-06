/**
 *  @author      Adrian Statescu <mergesortv@gmail.com>
 *  @description Quick Sort in Action.
 *  @License     MIT 
 */
#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 500005
#define FIN "algsort.in"
#define FOUT "algsort.out"

typedef unsigned int uint;

class Container {

      public:

      Container(uint _N): N( _N ), contor( 0 ) {}

      ~Container(){}

      void add_to_container(uint elem) {

           vec[ contor++ ] = elem;
      };

      void sorted() {

           _quicksort(0, N - 1);
      }; 

      friend std::ostream &operator << (std::ostream &stream, const Container &obj) {

             for(int i = 0; i < obj.N; i++) {
         
                 stream<<obj.vec[ i ]<<" "; 
             }  

             return stream; 
      };

      private:

      uint vec[ MAXN ],
           N, 
           contor;  

      void _quicksort(int lo, int hi) {

           int i = lo,

               j = hi,

               p = vec[ (lo + hi) >> 1 ];

               while( i <= j ) {

                     while( vec[ i ] < p ) i++; 

                     while( vec[ j ] > p ) j--; 

                     if(i <= j ) _swap(i, j), i++, j--;
               }

               if(lo < j) _quicksort(lo, j);   

               if(i < hi) _quicksort(i, hi);
      };

       void _swap(int i, int j) {

            int res = vec[ i ] ^ vec[ j ];

                vec[ i ] = res ^ vec[ i ];

                vec[ j ] = res ^ vec[ j ];
       }     
};

int main() {

    uint N, 

         elem;

     std::ifstream fin( FIN );

     std::ofstream fout( FOUT );

     fin>>N; 

     Container container( N );

     for(uint i = 0; i < N; ++i) fin>>elem,

                                 container.add_to_container( elem ); 

     container.sorted( );

     fout<<container; 

     fin.close();
     
    return(0);         
};