# endian
Endian is library for working with data endianity for every primityve data type from 2 up to 64 bytes. This library is possible to use everywhere on PC or embedded systems, because it uses only bit shifting for inversing byte order.

# Usage
For every dyta type is defined own function for inversing byte order:
- swap_endian_int16
- swap_endian_int32
- swap_endian_float
- swap_endian_int64
- swap_endian_double

Every function can be called separately, but in header file endian.h is defined generic macro which is able to choose right function automatically based on inserted data type:
```c
    int a = 0x000000FF;
    int b = swap_endian(a);
    
    printf("a = %x | b = %x\n", a, b);
```
Output of this code will be: 
```Bash
$ a = 0x000000FF, b = 0xFF000000
```

Usually complex data types consist from primitive data types, so change endian of complex data type can be done like this:
```c
    typedef struct
    {
        int    a;
        double b;
    }Data;

    Data 
    data_swap_endian(Data self)
    {
        return (Data) 
            {
                .a = swap_endian(self.a)
                , .b = swap_endian(self.b);
            };
    }

```

# Installation
Library has no dependency so it can be used directly copy-pased in source code or can be build and packed as static library. Library is possible to use on every platforms Linux, Mac, Windows embedded system.
For building and installation is prepared simple Makefile. In file dep.list are stored source code dependencies for building, so if this file is not in the same directory as Makefile, simple call command:
```Bash
    $ make dep
```
For building library simply call command:
```Bash
    $ make
```
For ensure of library correctnes is possible to call test by calling command:
```Bash
    $ make test
```
For installing library into system directories simply call command:
```Bash
    $ sudo make install
```
Under Windows with MSYS2 system installed is not sudo command and is necessary to change install directories:
```Bash
    $ make install INCLUDE_PATH=/mingw64/include/ LIB_PATH=/mingw64/lib/
```






