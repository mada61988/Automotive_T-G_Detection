#ifndef EUF_APP_TDS_H
#define EUF_APP_TDS_H

//Prototypes
void TDS_vidManager(void *pt);
void TDS_vidInit(void);
void TDS_vidGetCurrTemp();

//STATE
#define IDLE        0
#define WARNING        1
#define DANGER        2

// Temp Ranges
#define MAX_TEMP        105
#define WARNING_TEMP    100



#endif
