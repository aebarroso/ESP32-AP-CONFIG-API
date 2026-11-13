#include "nvs_if.h"
#include "nvs_if_config.h"

#include "nvs.h"
#include "nvs_flash.h"
#include "esp_log.h"

static const char *TAG = "nvs_if";

static esp_err_t nvs_if_open_rw(nvs_handle_t *handle)
{
    if (handle == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    return nvs_open(NVS_IF_NAMESPACE, NVS_READWRITE, handle);
}

static esp_err_t nvs_if_open_ro(nvs_handle_t *handle)
{
    if (handle == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    return nvs_open(NVS_IF_NAMESPACE, NVS_READONLY, handle);
}

esp_err_t nvs_if_init(void)
{
    esp_err_t err = nvs_flash_init();

    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOGW(TAG, "NVS needs erase, erasing flash partition");
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }

    if (err == ESP_OK) {
        ESP_LOGI(TAG, "NVS initialized");
    }

    return err;
}

esp_err_t nvs_if_write_i32(const char *key, int32_t value)
{
    if (key == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_rw(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_set_i32(handle, key, value);
    if (err == ESP_OK) {
        err = nvs_commit(handle);
    }

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_read_i32(const char *key, int32_t *value)
{
    if (key == NULL || value == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_ro(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_get_i32(handle, key, value);

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_write_u8(const char *key, uint8_t value)
{
    if (key == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_rw(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_set_u8(handle, key, value);
    if (err == ESP_OK) {
        err = nvs_commit(handle);
    }

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_read_u8(const char *key, uint8_t *value)
{
    if (key == NULL || value == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_ro(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_get_u8(handle, key, value);

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_write_str(const char *key, const char *value)
{
    if (key == NULL || value == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_rw(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_set_str(handle, key, value);
    if (err == ESP_OK) {
        err = nvs_commit(handle);
    }

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_read_str(const char *key, char *out_buf, size_t *buf_len)
{
    if (key == NULL || buf_len == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_ro(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_get_str(handle, key, out_buf, buf_len);

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_erase_key(const char *key)
{
    if (key == NULL) {
        return ESP_ERR_INVALID_ARG;
    }

    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_rw(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_erase_key(handle, key);
    if (err == ESP_OK) {
        err = nvs_commit(handle);
    }

    nvs_close(handle);
    return err;
}

esp_err_t nvs_if_erase_all(void)
{
    nvs_handle_t handle;
    esp_err_t err = nvs_if_open_rw(&handle);
    if (err != ESP_OK) {
        return err;
    }

    err = nvs_erase_all(handle);
    if (err == ESP_OK) {
        err = nvs_commit(handle);
    }

    nvs_close(handle);
    return err;
}