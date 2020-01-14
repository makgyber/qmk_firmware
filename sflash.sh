avrdude -p atmega32u4 -P /dev/ttyS0  -c arduino  -U flash:w:$1
