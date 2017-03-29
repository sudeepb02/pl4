#Generate sine wave

import math
import Adafruit_BBIO.PWM as PWM


pin = "P8_13"

#initialize
inst = []
dc = []
PWM.start(pin, 0, 5000)

for n in range(0, 199):
	inst.append(1.5 + 1.5*math, sin((2*3.14*50*n)/10000))
while True:
	for n in range(0, 199):
		dc.append(inst[n]*100/3.3)
		PWM.set_duty_cycle(pin, dc[n])

PWM.stop(pin)
PWM.cleanup()
