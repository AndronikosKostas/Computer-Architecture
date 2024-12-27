# ComputerArchitectureLab3
The objective of this lab is to be familiar with the McPAT simulator that produces results about the consuming power of a program

## Q1.1
### Dynamic Power
Circuits dissipate dynamic power when they
charge and discharge the capacitive loads to switch states.
Dynamic power is proportional to the total load capacitance,
the supply voltage, the voltage swing during switching, the
clock frequency, and the activity factor.

### Dynamic Leakage
Transistors in circuits leak, dissipating static power. Leakage
current depends on the width of the transistors and the
local state of the devices. There are two leakage mechanisms.
Subthreshold leakage occurs because a small current
passes between the source and drain of off-state transistors.
Gate leakage is the current leaking through the gate terminal,
and varies greatly with the state of the device.

### Running Different Programs in the same processor - Dynamic Power and Leakage
The dynamic power will be different because each program may need more hardware than others, so the dynamic power will be greater. Regarding dynamic leakage, we are expecting to see no difference, because its nature, which is static and depends on the width of the transistors.

## Q1.2
The WATT Ratings are reffering to the maximum power that a CPU can handle under full load, so it is not a valid metric to say which CPU will be more efficient. For instance, the CPU with the 50W peak consumption may be more efficienT if it can handle in a smart way the system / program and eventually it may needs 4W average power. On the other hand, the other processor may needs all the power that can handles cause its different architecture. McPAT cannot gives us straight ahead the answer to the problem. We will need, how each CPU performs under a specific load.


## Q1.3
We can compare the results from Xeon and ARM A9 processors by compraring EDAP (Energy-Delay-Area Product).

$$ EDAP = (Runtime \ Dynamic + Subthreshold \ Leakage + Gate \ Leakage) * runTime * Area $$

### XEON
$$ EDAP = ( 72.9199 + 35.1632 + 1.66871 ) * runTime * 410.507 = 45053.88626767 * runTime $$
### ARM
$$ EDAP = ( 2.96053 +   0.0523094 + 0.0563774 ) * runTime * 5.39698 = 16.564501685264002 * runTime $$

45053.88 / 16.54 = 2723.93 \
If we compare it to 50, it is 5 times greater. If the above division would be close to 50, we maybe could make a discussion around the fact that the XEON could be more efficient, but with the current data the answer is that the ARM is by far more energy efficient.


## Bibliography 
https://ieeexplore.ieee.org/document/5375438


