#ifndef __BLE_HANDLER_H
#define __BLE_HANDLER_H

enum BleCommandType
{
    BLE_OPEN,
    BLE_CLOSE,
    BLE_SET_MODE
};

class BLE_Handler
{
    struct BLECommand
    {
        BleCommandType type;
    };
};

#endif // __BLE_HANDLER_H