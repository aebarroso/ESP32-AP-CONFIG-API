idf_component_register(SRCS "wifi_ap_mgr.c"
                       INCLUDE_DIRS "include"
                       REQUIRES esp_wifi esp_event nvs_flash)