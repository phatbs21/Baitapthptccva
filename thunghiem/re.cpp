#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>using namespace std;#define SO_THREAD     5void *wait(void *tid)
{
   int i;
     sleep(1);
   cout << "\nDang tam dung mot Thread " << endl;
   cout << "\nThread voi ID la : " << tid << "  ... dang thoat! " << endl;
   pthread_exit(NULL);
}int main ()
{
   int rc;
   int i;
   pthread_t threads[SO_THREAD];
   pthread_attr_t attr;
   void *status;   // khoi tao va thiet lap mot thread co the ket hop
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);   for( i=0; i < SO_THREAD; i++ ){
      cout << "\nmain() : dang tao thread! " << i << endl;
      rc = pthread_create(&threads[i], NULL, wait, (void *)i );
      if (rc){
         cout << "\nError: Khong the tao thread! " << rc << endl;
         exit(-1);
      }
   }   // giai phong thuoc tinh va doi thread khac
   pthread_attr_destroy(&attr);
   for( i=0; i < SO_THREAD; i++ ){
      rc = pthread_join(threads[i], &status);
      if (rc){
         cout << "\nError: khong the ket hop! " << rc << endl;
         exit(-1);
      }
      cout << "\nMain: ket huc thread id :" << i ;
      cout << "  va thoat voi trang thai:" << status << endl;
   }   cout << "\nMain: thoat chuong trinh!" << endl;
   pthread_exit(NULL);
}