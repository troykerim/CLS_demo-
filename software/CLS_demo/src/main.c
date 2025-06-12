#include <stdio.h>
#include "PmodCLS.h"
#include "sleep.h"
#include "string.h"
#include "xil_cache.h"
#include "xil_printf.h"
#include "xparameters.h"

void DemoInitialize();
void DemoRun();
void DemoCleanup();
//void EnableCaches();
//void DisableCaches();

PmodCLS myDevice;

int main(void) {
   DemoInitialize();
   DemoRun();
   DemoCleanup();
   return 0;
}

void DemoInitialize() {
   //EnableCaches();
   CLS_begin(&myDevice, XPAR_PMODCLS_0_AXI_LITE_SPI_BASEADDR);
}

void DemoRun() {
   char szInfo1[32];
   char szInfo2[32];

   CLS_DisplayClear(&myDevice);
   strcpy(szInfo1, "  PmodCLS Demo");
   strcpy(szInfo2, "  Hello World!");
   CLS_WriteStringAtPos(&myDevice, 0, 0, szInfo1);
   CLS_WriteStringAtPos(&myDevice, 1, 0, szInfo2);

   usleep(500000);

   while (1) {
      CLS_DisplayClear(&myDevice);
      strcpy(szInfo1, "->PmodCLS Demo<- ");
      CLS_WriteStringAtPos(&myDevice, 0, 0, szInfo1);
      CLS_WriteStringAtPos(&myDevice, 1, 0, szInfo2);

      usleep(500000);

      CLS_DisplayClear(&myDevice);
      strcpy(szInfo1, "  PmodCLS Demo   ");
      CLS_WriteStringAtPos(&myDevice, 0, 0, szInfo1);
      CLS_WriteStringAtPos(&myDevice, 1, 0, szInfo2);

      usleep(500000);
   }
}

void DemoCleanup() {
   CLS_end(&myDevice);
   //DisableCaches();
}
