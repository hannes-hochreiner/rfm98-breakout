#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>
#include <stdexcept>
#include "aes_ecb.hpp"
#include "message.h"
#include "args.hpp"
#include "zmq.hpp"
#include "json.hpp"

using json = nlohmann::json;

extern "C" {
#include "rfm9x_g.h"
}

#include <time.h>

std::string format_message_1(const int16_t& rssi, message_0001_t const *const msg);
std::string format_message_2(const int16_t& rssi, message_0002_t const *const msg);
std::string get_timestamp();
std::string sensor_id_to_hex(uint16_t sensor_id);
std::string mcu_id_to_hex(uint32_t mcu_id_1, uint32_t mcu_id_2, uint32_t mcu_id_3);

#endif
