# Work Experience

## jvm oom 

```
Before fix:

> jstat -gc 13540
 S0C    S1C    S0U    S1U      EC       EU        OC         OU       PC     PU    YGC     YGCT    FGC    FGCT     GCT
2176.0 2176.0  0.0   2176.0 17472.0  17472.0   43712.0    43712.0   12288.0 6613.6     69    0.458  941   148.422  148.880

> jmap -histo:live 13540 | more

 num     #instances         #bytes  class name
----------------------------------------------
   1:       1530738       36737712  java.lang.String
   2:       1530506       25476528  [C
   3:        304938        2439504  com.JavaFormat
   4:         16023        1889744  <constMethodKlass>
   5:         16023        1284880  <methodKlass>
   6:         26316        1014568  <symbolKlass>
   7:          1299         757920  <constantPoolKlass>
```


