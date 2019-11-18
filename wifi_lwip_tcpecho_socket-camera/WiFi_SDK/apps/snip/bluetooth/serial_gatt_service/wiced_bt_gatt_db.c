/*
 * Copyright 2018, Cypress Semiconductor Corporation or a subsidiary of 
 * Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** This file has been automatically generated by the WICED Smart Ready Designer.
 * BLE device's GATT database and device configuration.
 *
 */

#include "wiced.h"
#include "wiced_bt_dev.h"
#include "wiced_bt_gatt_db.h"

#include "wiced_bt_uuid.h"
#include "wiced_bt_gatt.h"

/*************************************************************************************
** GATT server definitions
*************************************************************************************/

const uint8_t gatt_server_db[] = // Define GATT database
{
    /* Primary Service 'Generic Attribute' */
    PRIMARY_SERVICE_UUID16 (HDLS_GENERIC_ATTRIBUTE, UUID_SERVICE_GATT),

    /* Primary Service 'Generic Access' */
    PRIMARY_SERVICE_UUID16 (HDLS_GENERIC_ACCESS, UUID_SERVICE_GAP),

        /* Characteristic 'Device Name' */
        CHARACTERISTIC_UUID16 (HDLC_GENERIC_ACCESS_DEVICE_NAME, HDLC_GENERIC_ACCESS_DEVICE_NAME_VALUE,
            UUID_CHARACTERISTIC_DEVICE_NAME, LEGATTDB_CHAR_PROP_READ | LEGATTDB_PERM_AUTH_READABLE,
            LEGATTDB_PERM_READABLE),

        /* Characteristic 'Appearance' */
        CHARACTERISTIC_UUID16 (HDLC_GENERIC_ACCESS_APPEARANCE, HDLC_GENERIC_ACCESS_APPEARANCE_VALUE,
            UUID_CHARACTERISTIC_APPEARANCE, LEGATTDB_CHAR_PROP_READ | LEGATTDB_PERM_AUTH_READABLE,
            LEGATTDB_PERM_READABLE),

    /* Primary Service 'serial_gatt' */
    PRIMARY_SERVICE_UUID128 (HDLS_SERIAL_GATT, UUID_SERIAL_GATT_SERVICE),

        /* Characteristic 'serial_data' */
        CHARACTERISTIC_UUID128_WRITABLE (HDLC_SERIAL_GATT_SERIAL_DATA, HDLC_SERIAL_GATT_SERIAL_DATA_VALUE,
            UUID_SERIAL_GATT_SERIAL_DATA, LEGATTDB_CHAR_PROP_WRITE_NO_RESPONSE | LEGATTDB_CHAR_PROP_NOTIFY,
            LEGATTDB_PERM_VARIABLE_LENGTH | LEGATTDB_PERM_WRITE_CMD /*| LEGATTDB_PERM_AUTH_WRITABLE*/),

            /* Descriptor 'Client Characteristic Configuration' */
            CHAR_DESCRIPTOR_UUID16_WRITABLE (HDLD_SERIAL_GATT_SERIAL_DATA_CLIENT_CONFIGURATION,
                UUID_DESCRIPTOR_CLIENT_CHARACTERISTIC_CONFIGURATION,
                LEGATTDB_PERM_READABLE | LEGATTDB_PERM_WRITE_REQ | LEGATTDB_PERM_WRITE_CMD |
                /*LEGATTDB_PERM_AUTH_WRITABLE |*/ LEGATTDB_PERM_AUTH_READABLE),

    /* Primary Service 'Battery Service' */
    PRIMARY_SERVICE_UUID16 (HDLS_BATTERY_SERVICE, UUID_SERVICE_BATTERY),

        /* Characteristic 'Battery Level' */
        CHARACTERISTIC_UUID16 (HDLC_BATTERY_SERVICE_BATTERY_LEVEL, HDLC_BATTERY_SERVICE_BATTERY_LEVEL_VALUE,
            UUID_CHARACTERISTIC_BATTERY_LEVEL, LEGATTDB_CHAR_PROP_READ,
            LEGATTDB_PERM_READABLE),

    /* Primary Service 'Device Information' */
    PRIMARY_SERVICE_UUID16 (HDLS_DEVICE_INFORMATION, UUID_SERVICE_DEVICE_INFORMATION),

        /* Characteristic 'Manufacturer Name String' */
        CHARACTERISTIC_UUID16 (HDLC_DEVICE_INFORMATION_MANUFACTURER_NAME_STRING, HDLC_DEVICE_INFORMATION_MANUFACTURER_NAME_STRING_VALUE,
            UUID_CHARACTERISTIC_MANUFACTURER_NAME_STRING, LEGATTDB_CHAR_PROP_READ,
            LEGATTDB_PERM_READABLE),

        /* Characteristic 'Model Number String' */
        CHARACTERISTIC_UUID16 (HDLC_DEVICE_INFORMATION_MODEL_NUMBER_STRING, HDLC_DEVICE_INFORMATION_MODEL_NUMBER_STRING_VALUE,
            UUID_CHARACTERISTIC_MODEL_NUMBER_STRING, LEGATTDB_CHAR_PROP_READ,
            LEGATTDB_PERM_READABLE),

        /* Characteristic 'Firmware Revision String' */
        CHARACTERISTIC_UUID16 (HDLC_DEVICE_INFORMATION_FIRMWARE_REVISION_STRING, HDLC_DEVICE_INFORMATION_FIRMWARE_REVISION_STRING_VALUE,
            UUID_CHARACTERISTIC_FIRMWARE_REVISION_STRING, LEGATTDB_CHAR_PROP_READ,
            LEGATTDB_PERM_READABLE),

        /* Characteristic 'Software Revision String' */
        CHARACTERISTIC_UUID16 (HDLC_DEVICE_INFORMATION_SOFTWARE_REVISION_STRING, HDLC_DEVICE_INFORMATION_SOFTWARE_REVISION_STRING_VALUE,
            UUID_CHARACTERISTIC_SOFTWARE_REVISION_STRING, LEGATTDB_CHAR_PROP_READ,
            LEGATTDB_PERM_READABLE),
};

// Length of the GATT database
const uint16_t gatt_server_db_len = sizeof(gatt_server_db);

const uint8_t gatt_server_db_device_name[] = {'S','e','r','i','a','l','G','a','t','t'};
const uint16_t gatt_server_db_device_name_len = sizeof(gatt_server_db_device_name);

const uint8_t gatt_server_db_appearance[] = { BIT16_TO_8(APPEARANCE_GENERIC_TAG) };
const uint16_t gatt_server_db_appearance_len = sizeof(gatt_server_db_appearance);

uint8_t battery_service_battery_level                                       =  0;
char device_information_manufacturer_name_string[]                       = {'C','y','p','r','e','s','s',0,0,0,0,0,0,0,0,0};
char device_information_model_number_string[]                            = {'B','L','E',0x2d,'1','0','1',0,0,0,0,0,0,0,0,0};
char device_information_firmware_revision_string[]                       = {'1',0x2e,'0',0x2e,'0'};
char device_information_software_revision_string[]                       = {'1',0x2e,'0',0x2e,'1'};
uint8_t service_serial_data_client_configuration[]                    = {BIT16_TO_8(GATT_CLIENT_CONFIG_NONE)};

/* GATT attribute lookup table                                */
/* (attributes externally referenced by GATT server database) */
attribute_t gatt_db_ext_attr_tbl[] =
{
    /* { attribute handle,                                                   len,                                                 attribute data } */
    {HDLC_GENERIC_ACCESS_DEVICE_NAME_VALUE,                                  5,                                                   (uint8_t *)gatt_server_db_device_name},
    {HDLC_GENERIC_ACCESS_APPEARANCE_VALUE,                                   2,                                                   (uint8_t *)gatt_server_db_appearance},
    {HDLC_BATTERY_SERVICE_BATTERY_LEVEL_VALUE,                               1,                                                   &battery_service_battery_level},
    {HDLC_DEVICE_INFORMATION_MANUFACTURER_NAME_STRING_VALUE,                 sizeof(device_information_manufacturer_name_string), device_information_manufacturer_name_string},
    {HDLC_DEVICE_INFORMATION_MODEL_NUMBER_STRING_VALUE,                      sizeof(device_information_model_number_string),      device_information_model_number_string},
    {HDLC_DEVICE_INFORMATION_FIRMWARE_REVISION_STRING_VALUE,                 sizeof(device_information_firmware_revision_string), device_information_firmware_revision_string},
    {HDLC_DEVICE_INFORMATION_SOFTWARE_REVISION_STRING_VALUE,                 sizeof(device_information_software_revision_string), device_information_software_revision_string},
};

const uint16_t gatt_db_ext_attr_tbl_size = ( sizeof ( gatt_db_ext_attr_tbl ) / sizeof ( attribute_t ) );
