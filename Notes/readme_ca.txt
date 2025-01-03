First Computer Arichitecture Lab report
Authors: Konstantinidis Paschalis, Tzouvaras Evangelos

Question 1
There are three different type of processors, which of one has different default settings. These settings are exported from the starter_se.py file. We run the "Hello world" program with the minor CPU as a CPU type and by running the command:

./build/ARM/gem5.opt configs/example/arm/starter_se.py --cpu="minor" "tests/test-progs/hello/bin/arm/linux/hello"

Minor CPU (Line 179)

Default frequency: 4GHz
Default cores: 1
Default memory type: DDR3_1600_8x8
Default memory storage: 2GB
Question 2
a. The same information about the CPU settings may be exported from the config.ini file.

Line 59: clock = 250, this means that the frequency is 4GHz
Line 36: cpus_count = 0
Line 1251:(memory settings) type: DRAMInterface
Line 66: cpu_type = MinorCPU
b.

sim_seconds: The number of seconds simulated (Second) (/hellostats.txt line 3)
sim_insts: The number of instructions simulated (Count) (/hellostats.txt line 10)
host_inst_rate: The simulator instruction rate (inst/sec) (/hellostats.txt line 12)
c. Commited instructions: 5028 - Number of instructions committed (from /hellostats.txt file on line 19)

d. L2 accesses: 479 - Number of demand (read+write) accesses (frmo /hellostats.txt file on line 426)

Another way to find the L2 accesses is by L1 misses because for every L1 cache miss (instruction or data cache) the processor will go to L2 cache to search the information.

Question 3
The gem5 simulator has to different models for in-order CPU simulations: the Minor CPU and the simple CPU.

MINOR CPU

Minor is an in-order processir model with a fixed pipeline but congigurable data stuctures and execute behaviour. It is intended to be used to model processors with strict in-order execution behaviour and allows visualisation of an instruction’s position in the pipeline through the MinorTrace/minorview.py format/tool. The intention is to provide a framework for micro-architecturally correlating the model with a particular, chosen processor with similar capabilities.The model isn’t currently capable of multithreading but there are THREAD comments in key places where stage data needs to be arrayed to support multithreading.

SIMPLE CPU

The simple CPU is an in-order model that it is used when the detailed model is not necessary and can support the new memory system. Simple CPU has three sub-categories: the BaseSimple CPU, the AtomicSimple CPU and the TimingSimple CPU models. The BaseSimple CPU has functions for checking interrupts and handling pre-execute and post-execute actions. Also can set up a fetch request. The BaseSimple CPU model cannot be run on its owm but is used within the other two Simple CPU models. The AtomicSimple CPU has the characteristic that uses atomic memory acesses. It estimates the overall cache access time and connects the CPU with the cache. It has functions to read-write the memory and to monitor the CPU in every cycle. Finally, the TimingSimple CPU model uses timing memory access. It stalls on cache accesses and waits for the memory system to respond prior to proceeding. It also implements the same functions as the AtomicSimple model.

a. The program in that that we wrote is a simple program that creates an array 20x20 dimanesion and fills it with some values.

MINOR CPU

simSeconds = 0.000033     # Number of seconds simulated (Seconds)
hostSeconds = 0.07     # Real time elapsed on the host (Seconds)
TIMINGSIMPLE CPU

simSeconds = 0.000047     # Number of seconds simulated (Seconds)
hostSeconds = 0.02     # Real time elapsed on the host (Seconds)
b.

c. We made two changes on the parameters and we observed the results. The first simulation has as a parameter the increament of the CPU frequency from 1GHz (default), to 4.2GHz. The second simulation has as parameters, frequency on 4.2GHz and another type of memory from DDR3_1600_8x8 (default) to DDR4_2400_8x8. The results are presented below:

MINOR CPU

simSeconds = 0.000033     # Number of seconds simulated (Seconds)
simTicks = 33014000     # Number of ticks simulated (Tick)
hostSeconds = 0.07     # Real time elapsed on the host (Seconds)
hostTickRate = 491339527     # The number of ticks simulated per host scd
hostInstRate = 274062     # Simulator instruction rate
system.cpu.cpi = 3.580112     # CPI: cycles per instruction
system.cpu.ipc = 0.279321     # IPC: instructions per cycle
MINOR CPU with frequency 4.2GHz

simSeconds = 0.000026     # Number of seconds simulated (Seconds)
simTicks = 26224982     # Number of ticks simulated (Tick)
hostSeconds = 0.09     # Real time elapsed on the host (Seconds)
hostTickRate = 300449464     # The number of ticks simulated per host scd
hostInstRate = 211017     # Simulator instruction rate
system.cpu.cpi = 5.974570     # CPI: cycles per instruction
system.cpu.ipc = 0.167376     # IPC: instructions per cycle
MINOR CPU with frequency 4.2GHz and DDR4_2400_8x8

hostSeconds = 0.07     # Real time elapsed on the host (Seconds)
hostTickRate = 367859704     # The number of ticks simulated per host scd
MINOR CPU - COMMENTS We can observe that by increasing the frequency of the CPU, the simulation seconds are decreased and the simulation Ticks too. That is an expected result because the total time of a process depends on the frequency of the processor. Also, the CPI parameter was increased and the IPC parameter was decreased due to the increament of the frequency. The disadvantage by icreasing the frequency is that the total host time was increased
The change on the memory type has only affect on the host time which was decreased. This is an expected result because another type of memory which has lower access time decreases the time that the CPU needs to take the data and store them on the caches. The final host time became the same as the default value and the simulation time is lower due to the increament on the CPU frequency.

TIMINGSIMPLE CPU

simSeconds = 0.000047     # Number of seconds simulated (Seconds)
simTicks = 46758000     # Number of ticks simulated (Tick)
hostSeconds = 0.02     # Real time elapsed on the host (Seconds)
hostTickRate = 875450639     # The number of ticks simulated per host scd
hostInstRate = 481882     # Simulator instruction rate
TIMINGSIMPLE CPU with frequency 4.2GHz

simSeconds = 0.000033     # Number of seconds simulated (Seconds)
simTicks = 33306910     # Number of ticks simulated (Tick)
hostSeconds = 0.04     # Real time elapsed on the host (Seconds)
hostTickRate = 2097298917     # The number of ticks simulated per host scd
hostInstRate = 821669     # Simulator instruction rate
TIMINGSIMPLE CPU with frequency 4.2GHz and DDR4_2400_8x8

hostSeconds = 0.03     # Real time elapsed on the host (Seconds)
hostTickRate = 1333387316     # The number of ticks simulated per host scd
TIMINGSIMPLE CPU - COMMENTS Same results as the minor CPU we can see by increasing the frequency on the timing simple CPU. The simulated seconds were decreased and the host time was increased. By changing also the type of memory, the host time was decreased because the access time on the memory is smaller now. By comparing the affect of the change on the memory on the two different models of CPU, another type of it has bigger affect on the minor CPU model. On the other side, the impact of the CPU frequency is bigger on the timing simple CPU which decreased the simulation time by 30%. On the minor CPU model the reduction is about 20%.