# MAC Protocols

Simulation of different Multiple Access Protocols using C++.

## Dependencies
The output is printedo on the terminal through emojis for a cleaner display. The emojis can be installed in terminal through emojione package

```
sudo apt install fonts-emojione
```

## Running the simulators

Go to the corresponding directory and run the make command to build and run the application simultaneously

```
make
```

## Output

#### Aloha
The devices can send frames randomly and continuously

![aloha](https://user-images.githubusercontent.com/21677583/117247237-89aceb00-ae5b-11eb-8690-1dab979b368f.png)

### Slotted Aloha
The devices can send frames randomly, however in divided time slots (here the time slot of 3 seconds is used)

![sllottedAloha](https://user-images.githubusercontent.com/21677583/117247252-8fa2cc00-ae5b-11eb-9cd9-b67f2d952256.png)

### p Persistent CSMA
The devices send frames after sensing the channel and with a probability of _p_. The probability is randomly chosen in the program for each device.

![pPersistent](https://user-images.githubusercontent.com/21677583/117247277-9a5d6100-ae5b-11eb-97e2-1b48cb04a68c.png)

### Non Persistent CSMA
The devices send frames after sensing the channel. If the channel is busy, it will run a timer and after that timer runs out, it senses the channel again. 

![nonPersistent](https://user-images.githubusercontent.com/21677583/117247297-a0534200-ae5b-11eb-931a-1eadaf9bd08e.png)
