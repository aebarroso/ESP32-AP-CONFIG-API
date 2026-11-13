#include "wifi_ap_mgr.h"
#include "esp_log.h"

void app_main(void)
{
    ESP_ERROR_CHECK(wifi_ap_mgr_init());
}