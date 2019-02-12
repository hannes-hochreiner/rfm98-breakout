#include "rfm9x_g.h"

void _rfm9x_g_set_reset_pin();
void _rfm9x_g_reset_reset_pin();
void _rfm9x_g_delay(uint16_t millisec);
void _rfm9x_g_spi_transfer(uint8_t* const data, uint16_t length);
void _rfm9x_g_rx_callback();

static read_func _rx_callback = NULL;

const static rfm9x_t rfm98 = {
  .set_reset_pin = _rfm9x_g_set_reset_pin,
  .reset_reset_pin = _rfm9x_g_reset_reset_pin,
  .delay = _rfm9x_g_delay,
  .spi_transfer = _rfm9x_g_spi_transfer
};

void rfm9x_g_init() {
  wiringPiSetupGpio();
  wiringPiSPISetup(0, 8000000);
  pinMode(22, OUTPUT);

  RFM9X_Init(&rfm98);
  RFM9X_Reset(&rfm98);

  rfm9x_mode_t mode = RFM9X_MODE_LOW_FREQ_MODE | RFM9X_MODE_SLEEP;
  
  RFM9X_SetMode(&rfm98, &mode);
  mode = RFM9X_MODE_LORA | RFM9X_MODE_LOW_FREQ_MODE | RFM9X_MODE_SLEEP;
  RFM9X_SetMode(&rfm98, &mode);
  mode = RFM9X_MODE_LORA | RFM9X_MODE_LOW_FREQ_MODE | RFM9X_MODE_STANDBY;
  RFM9X_SetMode(&rfm98, &mode);

  rfm9x_conf1_t conf1 = RFM9X_CONF1_BW_125_KHZ | RFM9X_CONF1_CR_4_5 | RFM9X_CONF1_HEADER_EXPL;
  RFM9X_SetConf1(&rfm98, &conf1);
  rfm9x_conf2_t conf2 = RFM9X_CONF2_SF_128;
  RFM9X_SetConf2(&rfm98, &conf2);
  rfm9x_conf3_t conf3 = RFM9X_CONF3_AGC_AUTO_ON;
  RFM9X_SetConf3(&rfm98, &conf3);

  uint8_t power = 0x00;
  RFM9X_SetPower(&rfm98, &power);
}

void rfm9x_g_start_reception_mode() {
  rfm9x_mode_t mode = RFM9X_MODE_LORA | RFM9X_MODE_LOW_FREQ_MODE | RFM9X_MODE_RECEIVE_CONT;
  RFM9X_SetMode(&rfm98, &mode);
}

void rfm9x_g_get_message(read_func callback) {
  _rx_callback = callback;
  wiringPiISR(23, INT_EDGE_RISING, _rfm9x_g_rx_callback);
}

void rfm9x_g_get_flags(rfm9x_flags_t* const flags) {
  RFM9X_GetFlags(&rfm98, flags);
}

void rfm9x_g_reset_flags(const rfm9x_flags_t* const flags) {
  RFM9X_ResetFlags(&rfm98, flags);
}

void _rfm9x_g_rx_callback() {
  if (_rx_callback != NULL) {
    RFM9X_ReadMessage(&rfm98, _rx_callback);
  }

  rfm9x_flags_t flags = RFM9X_FLAG_ALL;
  RFM9X_ResetFlags(&rfm98, &flags);
}

void _rfm9x_g_set_reset_pin() {
  digitalWrite(22, HIGH);
}

void _rfm9x_g_reset_reset_pin() {
  digitalWrite(22, LOW);
}

void _rfm9x_g_delay(uint16_t millisec) {
  struct timespec req;

  req.tv_sec = 0;
  req.tv_nsec = (long)millisec * 1e6;
  nanosleep(&req, NULL);
}

void _rfm9x_g_spi_transfer(uint8_t* const data, uint16_t length) {
  wiringPiSPIDataRW(0, data, length);
}
