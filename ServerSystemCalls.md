# Function List And Description #

## Server Registration ##
1.
```
u8int ServerRegDevice(char* name);//register itself as a device
```

This function registers the server as a device, the name parameter is used by applications and other servers to access the device. This returns false if the program is not a root application.

2.
```
u32int ServerReqNum();// return the number of requests to the server
```

3.
```
u8int ServerOpenLine();//opens the next requesting processes to communicate with
```

Function will enable the server to communicate with the next process that wants to use it. It returns false if there are no processes wanting to use it.

## Hardware Communication ##

1.

```
u8int ServerCaptPort(u16int port);//captures a port for communication with hardware
```