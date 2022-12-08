# endian
Endian is library for working with data endianity for every primityve data type from 2 up to 64 bytes. This library is possible to use everywhere on PC or embedded systems, because it uses only bit shifting for inversing byte order.

# Ussage
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
```
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



