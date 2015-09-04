#include "small_serial.h"
#include "global.h"

#ifdef _UART
void putc(unsigned char byte )
{
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
	UCA0TXBUF = byte;
}

void putCMD(CMD c){
	putc(c.cmd);
	putc(c.val1);
	putc(c.val2);
}
#endif
