#ifndef __RFM9X_G_H__
#define __RFM9X_G_H__

#include "rfm9x_lora.h"
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <time.h>

void rfm9x_g_init();
void rfm9x_g_start_reception_mode();
void rfm9x_g_get_message(read_func callback);
void rfm9x_g_get_flags(rfm9x_flags_t* const flags);
void rfm9x_g_reset_flags(const rfm9x_flags_t* const flags);

#endif
