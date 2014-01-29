//
#include "Utility.h"

//
//
//
qreal Utility::Round(qreal val, int step)
{  
   int tmp = int(val) + step /2;  

   tmp -= tmp % step;  

   return qreal(tmp);  
}