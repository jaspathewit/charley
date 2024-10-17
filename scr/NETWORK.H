/* File contains structures and typedefs for the network structure   
  
(c) Mr J Hewitt 5-NOV-1994 */  
  
/* standard included files */  
  
/* project included files */   
#include "typedef.h"  
#include "nodes.h"  
#include "traffic.h"  
#include "links.h"  
#include "contivit.h"    
#include "routes.h"  
#include "rtlinks.h"  
#include "netparam.h"  
#include "pop.h"  
#include "net.h"  
  
/* defines */  
#define TRUE 1  
#define FALSE 0  
  
#define BUFFER_INC 200  
  
  
/* define character constants */  
#define RETURNC '\n'  
#define RETURNS "\n"              
#define PERIODC '.'  
#define EMPTYC '\0'  
  
/* macro to remove the return char at the end of the string */  
#define RMCR(str) (*(str+(strlen(str)-1))=EMPTYC)  
  
/* macro definition for determining if a string is terminated with */  
/* a return character */  
#define STRRET(str) (*(str+(strlen(str)-1))==RETURNC) 
