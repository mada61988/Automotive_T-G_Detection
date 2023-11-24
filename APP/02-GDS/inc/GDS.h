#ifndef EUF_APP_GDS_H
#define EUF_APP_GDS_H

//prototypes
void GDS_vidManager(void *pt);
void GDS_vidInit(void);

// STATE
#define GDS_stateIDLE            0
#define GDS_stateWRNG            1
#define GDS_stateEROR            2   

#define IDLE    "IDLE"
#define WRNG    "WRNG"
#define EROR    "EROR"
#endif
