#include <cstdio>
#define  FIN "algsort.in"
#define FOUT "algsort.out"
#define MAX 500005

class HeapSort {

      public:
      int heap[ MAX ], 
          size;

      //constructor of the class
      HeapSort() {

          size = 0;
      };

      //destructor of the class
      ~HeapSort() {
      };

      void swap(int a, int b) {

           int x = heap[ a ] ^ heap[ b ];

                   heap[ a ] = x ^ heap[ a ];

                   heap[ b ] = x ^ heap[ b ];
      };

      void insertHeap(int elem) {

           heap[ ++size ] = elem;

           up( size );
      };

      int removeHeap() {

          int ret = heap[ 1 ];

              swap(1, size--);

              down( 1 ); 

              return ret;
      };  

      private:
      void down(int p) {

           while(2 * p <= size) {

                 int c = 2 * p;

                 if(2 * p + 1 <= size && heap[2 * p + 1] < heap[ 2 * p ]) c++;

                 if(heap[ p ] <= heap[ c ]) break;

                 swap(p, c);

                 p = c;  
           }
      }; 

      void up(int c) {

           int p;
 
               p = c / 2;

               while( p ) {

                      if(heap[ p ] > heap[ c ]) {

                               swap(p, c);

                               c = p;

                               p = c / 2;

                      } else break;
               }
      };
};

void do_heapsort();

int main() {

    do_heapsort();

    return(0); 
};

void do_heapsort() {

    int i, 

        n,

        elem;

    HeapSort h;

    freopen(FIN, "r", stdin);

    scanf("%d", &n);

    for(i = 1; i <= n; i++) scanf("%d", &elem), h.insertHeap( elem );

    fclose( stdin ); 

    freopen(FOUT, "w", stdout);

    for(i = 1; i <= n; i++) printf("%d ", h.removeHeap(  ));

    fclose( stdout ); 
}