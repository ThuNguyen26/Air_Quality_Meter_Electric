#include "WiFi_Manager.h"

ERROR_CODE WIFI_init()
{
#ifdef USING_WIFI_CONFIG
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    int retry_counter = 0;
    while (WiFi.status() != WL_CONNECTED && retry_counter <= WIFI_MAX_CONNECT_TRIAL)
    {
        delay(1000);
        log_e("WiFi connecting.....!");
        retry_counter++;
    }
    if (WiFi.status() == wl_status_t::WL_CONNECTED)
    {
        log_e("WiFi connected!");
        log_e("IP: %s", WiFi.localIP().toString().c_str());
        connectionStatus_st.wifiStatus = status_et::CONNECTED;
        return ERROR_NONE;
    }
    else
    {
        log_e("WiFi initialized failed!");
        connectionStatus_st.wifiStatus = status_et::DISCONNECTED;
        return ERROR_WIFI_INIT_FAILED;
    }
#endif
}