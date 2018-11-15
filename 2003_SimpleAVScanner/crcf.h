#ifndef ___crcf_h___
#define ___crcf_h___

extern void InitCrcTable(void);              // Initialize the CRC table
extern ULONG Reflect(ULONG , char);          // Reflection 
extern int Get_CRC(unsigned char*, ULONG);   // Returns CRC value

#endif