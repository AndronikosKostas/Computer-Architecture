### Q1
```C
    parser.add_argument("--cpu", type=str, choices=list(cpu_types.keys()),
                        default="atomic",
                        help="CPU model to use")
    parser.add_argument("--cpu-freq", type=str, default="1GHz")
    parser.add_argument("--num-cores", type=int, default=1,
                        help="Number of CPU cores")
    parser.add_argument("--mem-type", default="DDR3_1600_8x8",
                        choices=ObjectList.mem_list.get_names(),
                        help = "type of memory to use")
    parser.add_argument("--mem-channels", type=int, default=2,
                        help = "number of memory channels")
    parser.add_argument("--mem-ranks", type=int, default=None,
                        help = "number of memory ranks per channel")
    parser.add_argument("--mem-size", action="store", type=str,
                        default="2GB",
                        help="Specify the physical memory size")
```

CPU Type : Atomic <br />
CPU Frequency : 1GHz <br />
Num of Cores : 1 <br />
Cash Memory : DDR3_1600_8x8 <br />
RAM Size : 2GB <br />

### Q2a
Line 59: clock = 1000, this means that the frequency is 1GHz
Line 66: cpu_type = MinorCPU
b.

### Q2b 
sim_seconds : seconds of the simulations <br />
sim_insts : number of instructions simulated <br />
host_inst_rate: The simulator instruction rate <br />

### Q2c 
number of commited instructions = 5027 (line 27 in stats.txt)

### Q2d
L2 accesses <br /> 
Instructions : 327 (line 840 in stats.txt) <br />
Data : 147 (line 841 in stats.txt) <br />
I would observe how many misses I have in L1

### Q3
The gem5 has two different CPU models, included in the in-order category of CPUs, the Minor and the Simple CPU.
#### Minor CPU 
Minor is an in-order processor model with a fixed pipeline but configurable data structures and execute behaviour. It is intended to be used to model processors with strict in-order execution behaviour and allows visualisation of an instruction’s position in the pipeline through the MinorTrace/minorview.py format/tool. The intention is to provide a framework for micro-architecturally correlating the model with a particular, chosen processor with similar capabilities.

#### Simple CPU 
The SimpleCPU is a purely functional, in-order model that is suited for cases where a detailed model is not necessary. This can include warm-up periods, client systems that are driving a host, or just testing to make sure a program works. []

#### BaseSimpleCPU 
The BaseSimpleCPU serves several purposes:

Holds architected state, stats common across the SimpleCPU models.
Defines functions for checking for interrupts, setting up a fetch request, handling pre-execute setup, handling post-execute actions, and advancing the PC to the next instruction. These functions are also common across the SimpleCPU models.
Implements the ExecContext interface.
The BaseSimpleCPU can not be run on its own. You must use one of the classes that inherits from BaseSimpleCPU, either AtomicSimpleCPU or TimingSimpleCPU.

#### AtomicSimpleCPU

The AtomicSimpleCPU is the version of SimpleCPU that uses atomic memory accesses (see Memory systems for details). It uses the latency estimates from the atomic accesses to estimate overall cache access time. The AtomicSimpleCPU is derived from BaseSimpleCPU, and implements functions to read and write memory, and also to tick, which defines what happens every CPU cycle. It defines the port that is used to hook up to memory, and connects the CPU to the cache.

#### TimingSimpleCPU

The TimingSimpleCPU is the version of SimpleCPU that uses timing memory accesses (see Memory systems for details). It stalls on cache accesses and waits for the memory system to respond prior to proceeding. Like the AtomicSimpleCPU, the TimingSimpleCPU is also derived from BaseSimpleCPU, and implements the same set of functions. It defines the port that is used to hook up to memory, and connects the CPU to the cache. It also defines the necessary functions for handling the response from memory to the accesses sent out.
### Q3c
An increase in the frequency we may see a decrease in simSeconds and hostSeconds because the total time of the process depends on the frequency that the CPU has. By changing the technology of the cash I also expect to see a decrease in the host time because another type of memory which has lower access time decreases the time that the CPU needs to take the data and store them on the caches.

### REVIEW
Overall, even I did not manage to run the gem5 on my laptop, I learned a lot of new things regarding the computer architecture, such as the basic for the CPUs, cashes and how to learn to search for all these new things. But to say the things how they are I spent much of my time to try and solve other type of problems such as download the linux (with vm, dual boot etc), run all the necessary instructions and eventually stopped by a different obstacle each time. Even from this painfull situation I also learned and practiced other skills, patience for instance...



### Bibliography 
[gem5.org](https://www.gem5.org/documentation/general_docs/cpu_models/minor_cpu)
