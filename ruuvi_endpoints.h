#ifndef RUUVI_ENDPOINTS_H
#define RUUVI_ENDPOINTS_H

#include <stdint.h>

#define RUUVI_ENDPOINT_SUCCESS 0
#define RUUVI_ENDPOINT_ERROR_INVALID_PARAM (1<<4)  //!< Invalid Parameter
#define RUUVI_ENDPOINT_ERROR_NULL          (1<<11) //!< Null Pointer

typedef int32_t ruuvi_endpoint_status_t;

/**
 *  Ruuvi Standard Message consists of 11 bytes: 3 are a header, 8 are payload.
 *  Header has destination, source and type.
 *  Payload format is determined by the type of a message. 
 */
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_INDEX   0
#define RUUVI_ENDPOINT_STANDARD_SOURCE_INDEX        1
#define RUUVI_ENDPOINT_STANDARD_TYPE_INDEX          2
#define RUUVI_ENDPOINT_STANDARD_PAYLOAD_START_INDEX 2
#define RUUVI_ENDPOINT_STANDARD_HEADER_LENGTH       3
#define RUUVI_ENDPOINT_STANDARD_PAYLOAD_LENGTH      8
#define RUUVI_ENDPOINT_STANDARD_MESSAGE_LENGTH    (RUUVI_ENDPOINT_STANDARD_HEADER_LENGTH + RUUVI_ENDPOINT_STANDARD_PAYLOAD_LENGTH)

/** @brief If endpoint is even, type of a message is considered a write. If it is odd, type is considered a read. */
#define RUUVI_ENDPOINT_STANDARD_TYPE_READ_BIT              (1<<0)
#define RUUVI_ENDPOINT_STANDARD_SENSOR_CONFIGURATION_WRITE (0x02)
#define RUUVI_ENDPOINT_STANDARD_SENSOR_CONFIGURATION_READ  (RUUVI_ENDPOINT_STANDARD_SENSOR_CONFIGURATION_WRITE | RUUVI_ENDPOINT_STANDARD_TYPE_READ_BIT)
#define RUUVI_ENDPOINT_STANDARD_SENSOR_OFFSET_WRITE        (0x04)
#define RUUVI_ENDPOINT_STANDARD_SENSOR_OFFSET_READ         (RUUVI_ENDPOINT_STANDARD_SENSOR_OFFSET_WRITE | RUUVI_ENDPOINT_STANDARD_TYPE_READ_BIT)
#define RUUVI_ENDPOINT_STANDARD_LOG_CONFIGURATION_WRITE    (0x06)
#define RUUVI_ENDPOINT_STANDARD_LOG_CONFIGURATION_READ     (RUUVI_ENDPOINT_STANDARD_LOG_CONFIGURATION_WRITE | RUUVI_ENDPOINT_STANDARD_TYPE_READ_BIT)
#define RUUVI_ENDPOINT_STANDARD_VALUE_WRITE                (0x08) //!< Sensor reads are acknowledged by setting type as value write
#define RUUVI_ENDPOINT_STANDARD_VALUE_READ                 (RUUVI_ENDPOINT_STANDARD_VALUE_WRITE | RUUVI_ENDPOINT_STANDARD_TYPE_READ_BIT)
#define RUUVI_ENDPOINT_STANDARD_TYPE_ERROR                 (0xFF) //!< internal error has occured

#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ACCELERATION   0x4A //!< XYZ acceleration combined
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ACCELERATION_X 0x40 //!< X acceleration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ACCELERATION_Y 0x41 //!< Y acceleration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ACCELERATION_Z 0x42 //!< Z acceleration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_GYRATION       0x4B //!< XYZ gyration combined
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_GYRATION_X     0x43 //!< X gyration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_GYRATION_Y     0x44 //!< Y gyration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_GYRATION_Z     0x45 //!< Z gyration
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ADC_BATTERY    0x20 //!< ADC battery vs GND
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_TEMPERATURE    0x30 //!< Temperature
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_HUMIDITY       0x31 //!< Humidity
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_PRESSURE       0x32 //!< Pressure
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_ENVIRONMENTAL  0x3A //!< Temperature, humidity, air pressure combined.
#define RUUVI_ENDPOINT_STANDARD_DESTINATION_RTC            0x21 //!< RTC value

#endif