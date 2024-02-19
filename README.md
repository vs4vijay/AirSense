# AirSense


## Setup Development

```bash

pip install -U platformio

```

## Compile Firmware


```shell

pio run

```

- firmware will be at `.pio/build/*` directory

## Flash Firmware


### Option-I: Using esptool
- Install esptool.py - `pip install -U esptool`
```
python -m esptool write_flash -z 0 firmware.bin
```

---

## Development Notes

```bash


pio device list

```