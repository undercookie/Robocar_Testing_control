import serial

IDEAL_DISTANCE_MIN = int(150)
IDEAL_DISTANCE_MAX = int(160)

if __name__=='__main__':
    ser = serial.Serial('COM3', 115200, timeout=1)
    ser.flush()

while True:

    if ser.in_waiting > 0:
        distance = int(ser.readline().decode('utf_8').rstrip())
        if distance > IDEAL_DISTANCE_MAX:
            ser.write(str("I").encode('utf_8'))
        elif distance < IDEAL_DISTANCE_MIN:
            ser.write(str("E").encode('utf_8'))
        else:
            ser.write(str("F").encode('utf_8'))

