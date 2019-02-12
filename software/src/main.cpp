#include "main.hpp"

void read(int16_t rssi, uint8_t* const data, uint16_t length);

static aes_ecb* aes_ptr;
static zmq::socket_t* publisher_ptr;

int main(int argc, char const *argv[])
{
  try {
    rfm9x_flags_t rfm_flags;
    rfm9x_flags_t rfm_all_flags = RFM9X_FLAG_ALL;
    args args(argc, argv);
    aes_ecb aes(args.get_key());
    aes_ptr = &aes;

    zmq::context_t context(1);
    zmq::socket_t publisher(context, ZMQ_PUB);

    publisher.bind("tcp://*:5555");
    publisher_ptr = &publisher;
    
    rfm9x_g_init();
    rfm9x_g_start_reception_mode();
    rfm9x_g_get_message(read);

    while (true) {
      struct timespec req;

      req.tv_sec = 1;
      req.tv_nsec = 0;
      nanosleep(&req, NULL);
    }
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}

void read(int16_t rssi, uint8_t* const data, uint16_t length) {
  std::cout << "rssi: " << rssi << " length: " << length << "\n";
  unsigned char decrypt_data[length];
  aes_ptr->decrypt(data, decrypt_data, length);
  
  if (decrypt_data[0] == 1) {
    message_0001_t* msg = (message_0001_t*)(decrypt_data);
  
    std::string msg_json = format_message_1(rssi, msg);
    std::cout << msg_json << "\n";
    zmq::message_t msg_zmq(msg_json.c_str(), msg_json.size());
    publisher_ptr->send(msg_zmq);
  } else if (decrypt_data[0] == 2) {
    message_0002_t* msg = (message_0002_t*)(decrypt_data);
 
    std::string msg_json = format_message_2(rssi, msg);
    std::cout << msg_json << "\n";
    zmq::message_t msg_zmq(msg_json.c_str(), msg_json.size());
    publisher_ptr->send(msg_zmq);
  } else {
    std::cout << "unknown message type received: " << decrypt_data[0] << "\n";
  }
}

std::string format_message_1(const int16_t& rssi, message_0001_t const *const msg) {
  json j;

  j["rssi"] = rssi;
  j["timestamp"] = get_timestamp();
  j["message"]["type"] = msg->type;
  j["message"]["mcu_id"] = mcu_id_to_hex(msg->mcu_id_1, msg->mcu_id_2, msg->mcu_id_3);
  j["message"]["message_index"] = msg->message_index;
  j["message"]["sensor_id"] = sensor_id_to_hex(msg->sensor_id);
  j["message"]["humidity"] = msg->humidity;
  j["message"]["temperature"] = msg->temperature;

  return j.dump();
}

std::string format_message_2(const int16_t& rssi, message_0002_t const *const msg) {
  json j;

  j["rssi"] = rssi;
  j["timestamp"] = get_timestamp();
  j["message"]["type"] = msg->type;
  j["message"]["mcu_id"] = mcu_id_to_hex(msg->mcu_id_1, msg->mcu_id_2, msg->mcu_id_3);
  j["message"]["message_index"] = msg->message_index;
  j["message"]["sensor_id"] = sensor_id_to_hex(msg->sensor_id);
  j["message"]["humidity"] = msg->humidity;
  j["message"]["temperature"] = msg->temperature;
  j["message"]["pressure"] = msg->pressure;

  return j.dump();
}

std::string get_timestamp() {
  time_t now;
  time(&now);
  char buf[sizeof("YYYY-MM-DDTHH:MM:SSZ")];
  strftime(buf, sizeof(buf), "%FT%TZ", gmtime(&now));

  return std::string(buf);
}

std::string sensor_id_to_hex(uint16_t sensor_id) {
  std::ostringstream os;

  os.width(4);
  os.fill('0');
  os << std::hex << std::uppercase << sensor_id;

  return os.str();
}

std::string mcu_id_to_hex(uint32_t mcu_id_1, uint32_t mcu_id_2, uint32_t mcu_id_3) {
  std::ostringstream os;

  os.width(8);
  os.fill('0');
  os << std::hex << std::uppercase << mcu_id_3 << "-" << mcu_id_2 << "-" << mcu_id_1;

  return os.str();
}
