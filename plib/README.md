# SMPS-MCAL-PLIB
SMPS Peripheral Driver Libraries for dsPIC33EP GS, dsPIC33CK and dsPIC33CH MP Digital Signal Controllers (DSC).

This library project provides generic peripheral libraries to be used with a microcontroller abstraction layer (MCAL) of a firmware project. These peripheral libraries provide a common API to initialize, monitor and control specific peripherals of a dedicated dsPIC DSC. The various functions provided provide data structures as virtual register sets, which will be loaded from and written to the IC registers. Thus, settings made for one IC can be easily migrated onto another IC, which might have significant differences in register names and locations. In addition, every write event will be verified by the library function returning a SUCCESS or FAILURE dependent on if the new register contents after a WRITE event matches the user-defined value.

### Please note:
The peripheral functions provided by this library may not cover all available configuration options. to provide maxmum flexibility, there are simplified, higher level functions for common use cases as well as lower-level, spcific functions. Low-level functions, however, may include settings which are only available on a specific chip family and the related function may not be fully generic.

