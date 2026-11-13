#pragma once

#include <stdbool.h>
#include <stddef.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t nvs_if_init(void);

/* Integer */
esp_err_t nvs_if_write_i32(const char *key, int32_t value);
esp_err_t nvs_if_read_i32(const char *key, int32_t *value);

/* Unsigned 8-bit */
esp_err_t nvs_if_write_u8(const char *key, uint8_t value);
esp_err_t nvs_if_read_u8(const char *key, uint8_t *value);

/* String */
esp_err_t nvs_if_write_str(const char *key, const char *value);
esp_err_t nvs_if_read_str(const char *key, char *out_buf, size_t *buf_len);

/* Erase */
esp_err_t nvs_if_erase_key(const char *key);
esp_err_t nvs_if_erase_all(void);

#ifdef __cplusplus
}
#endif