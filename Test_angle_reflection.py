import math
import numpy as np

def explanation():
    #degrees(): this method converts the value passed to it from radians to degrees
    #radians(): this method converts the value passed to it from degrees to radians
    #all trigonometric functions in Python assume that the input angle is in terms of radians!
    #pi/2 is 90 degrees, pi/3 is 60 degrees (perfect for us!)
    #the pi constant represents pi, which we use to work with degrees in trigonometric functions
    #here the trigonometric functions for 60 degrees:
    print(math.sin(math.pi/3))
    print(math.cos(math.pi/3))
    print(math.tan(math.pi/3))

    #now the inverses:
    print(math.asin(1)) #???? apparently only a value between -1 and 1. Do we need that?

    #square roots:
    print(math.sqrt(60))

    #square functions:
    print(math.pow(3,2))

def anglemath_general():
    side_a = 9
    side_b = 7

    #get side c:
    side_c = math.sqrt(pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b * (math.cos(math.pi/3))))
    print(side_c)

    #get the angle:
    angle_right = math.acos((pow(side_c, 2) + pow(side_a, 2) - pow(side_b, 2)) / (2 * side_c * side_a))
    #convert from rad to deg:
    print(np.rad2deg(angle_right))
    #otherwise it would look like this...
    print(angle_right)

    #for the other angle, depends on what side is longer. Only one of them needs to be calculated
    angle_left = math.acos((pow(side_c, 2) + pow(side_b,2) - pow(side_a, 2)) / (2 * side_c * side_b))
    print(np.rad2deg(angle_left))
    print(angle_left)

def angle_calculation_incoming():
    #this needs to be inputs from the sensor:
    side_a = float(input("Choose lenght of side a: "))
    side_b = float(input("Choose lenght of side b: "))

    if side_a > side_b:
        side_c = math.sqrt(pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b * (math.cos(math.pi / 3))))
        print(side_c)
        angle_left = math.acos((pow(side_c, 2) + pow(side_b, 2) - pow(side_a, 2)) / (2 * side_c * side_b))
        print(np.rad2deg(angle_left))
        print(angle_left)
    elif side_b > side_a:
        side_c = math.sqrt(pow(side_a, 2) + pow(side_b, 2) - (2 * side_a * side_b * (math.cos(math.pi / 3))))
        print(side_c)
        angle_right = math.acos((pow(side_c, 2) + pow(side_a, 2) - pow(side_b, 2)) / (2 * side_c * side_a))
        print(np.rad2deg(angle_right))
        print(angle_right)
    else:
        pass
        #Car needs to turn 180 degrees and drive straight into the other direction. No clue how to do that.

def angle_calculation_deflection():
    # ok bitches, we need to figure out the length that the sensor needs to measure until it drives forward.
    # we can do this. "Finding-complex-algorithms-please-someone-kill-me"-Round 2!!!

    #inputs:
    anglesum_triangle = 180 #makes sense to make this a global variable to avoid magic numbers

    angle_alpha = 120 #the top angle between sensor and side to the wall: 180-60 = 120
    #angle_deflect = 40 #that would be the angle that got calculated in the previous function.
    side_a = 42 #This is an estimation of the length of the robocar plus extra to the wall. Needs to be refined.

    angle_deflect = int(input("Angle of deflection: "))

    #calculate the missing angle:
    angle_beta = (anglesum_triangle - angle_alpha - angle_deflect)
    print(angle_beta)

    #calculate the length of the side that needs to be equal to the sensor measurement:
    side_b = (math.sin(angle_deflect/math.pi) * side_a) / (math.sin(angle_beta/math.pi))
    print(side_b)

def test_for_loop():
    times = int(input("Input: "))

    for x in range(times):
        print("Hej")

#Result is 5 centimeters off. Maybe that is enough.
while True:
    test_for_loop()

#15cm off
#1cm off
#the bigger the deflection angle, the bigger the mistake. Maybe we can just subtract something, depending on how big the outcome is.
#hashtag dirty fixes, bitches.

#10cm: 1cm too less
#20cm: 1cm too much
#25cm: minus value. Fuck.
#30cm:
#35cm:
#40cm:
#45cm:
#50cm:
#55cm:
#60cm:
#65cm:
#70cm:
#75cm:
#80cm:
#85cm:
