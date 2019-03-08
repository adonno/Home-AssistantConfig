// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("sonoff_viessmann");
  App.set_compilation_datetime(__DATE__ ", " __TIME__);
  LogComponent *logcomponent = App.init_log(115200, 512, UART_SELECTION_UART0);
  WiFiComponent *wificomponent = App.init_wifi();
  wificomponent->set_use_address("192.168.1.150");
  WiFiAP wifiap = WiFiAP();
  wifiap.set_ssid("Amores");
  wifiap.set_password("DoFi8414");
  wifiap.set_manual_ip(ManualIP{
      .static_ip = IPAddress(192, 168, 1, 150),
      .gateway = IPAddress(192, 168, 1, 1),
      .subnet = IPAddress(255, 255, 255, 0),
      .dns1 = IPAddress(192, 168, 1, 30),
      .dns2 = IPAddress(1, 0, 0, 1),
  });
  wificomponent->add_sta(wifiap);
  OTAComponent *otacomponent = App.init_ota();
  otacomponent->set_auth_password("sdfh514dfsh65");
  otacomponent->start_safe_mode();
  WebServer *webserver = App.init_web_server(80);
  api::APIServer *api_apiserver = App.init_api_server();
  api_apiserver->set_password("sdfh514dfsh65");
  time::HomeAssistantTime *homeassistant_time = App.make_homeassistant_time_component();
  UARTComponent *uartcomponent = App.init_uart(4800);
  uartcomponent->set_rx_pin(3);
  sensor::WiFiSignalSensor *sensor_wifisignalsensor = App.make_wifi_signal_sensor("esphome_viessmann_wifi_signal", 10000);
  sensor::UptimeSensor *sensor_uptimesensor = App.make_uptime_sensor("esphome_viessmann_uptime");
  text_sensor::VersionTextSensor *text_sensor_versiontextsensor = App.make_version_text_sensor("esphome_viessmann_esphome_version");
  homeassistant_time->set_timezone("CET-1CEST-2,M3.5.0/2,M10.4.0/3");
  sensor::CSE7766Component *sensor_cse7766component = App.make_cse7766(uartcomponent, 5000);
  sensor::CSE7766VoltageSensor *sensor_cse7766voltagesensor = sensor_cse7766component->make_voltage_sensor("viessmann_voltage");
  App.register_sensor(sensor_cse7766voltagesensor);
  sensor::CSE7766CurrentSensor *sensor_cse7766currentsensor = sensor_cse7766component->make_current_sensor("viessmann_current");
  App.register_sensor(sensor_cse7766currentsensor);
  sensor::CSE7766PowerSensor *power = sensor_cse7766component->make_power_sensor("viessmann_power");
  App.register_sensor(power);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
