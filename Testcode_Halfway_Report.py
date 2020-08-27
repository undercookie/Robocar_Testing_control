import serial

if __name__=='__main__':
    ser = serial.Serial('COM3', 9600, timeout=1)
    ser.flush()


while True:
    print()
    print("Menu")
    print("--------------------")
    print("Turn left: L")
    print("Turn slighlty left: E")
    print("Turn slighlty right: I")
    print("Turn right: R")
    print("Move forward: F")
    print("Move backward: B")
    print("Halt the car: H")
    print("Start the car: S")
    print()

    command = input("Enter your choice: ").upper()

    ser.write(str(command).encode('utf_8'))
    print("Sending command " + str(command) + " to Arduino.")

