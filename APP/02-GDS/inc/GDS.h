#ifndef EUF_APP_GDS_H
#define EUF_APP_GDS_H

//prototypes
void GDM_vidManager(void *pt);
void GDM_vidInit(void);

// STATE
#define GDM_u8StateIDLE            (uint8)1
#define GDM_u8StateWRNG            (uint8)2
#define GDM_u8StateDNGR            (uint8)3   

#define IDLE    "IDLE"
#define WRNG    "WRNG"
#define EROR    "EROR"
#endif
