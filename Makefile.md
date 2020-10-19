# Makefile

Before issuing any command in a target rule set, there are certain special macros predefined −

- `$@` is the name of the file to be made.
- `$?` is the names of the changed dependents.

For example, we could use a rule as follows −

```
hello: main.cpp hello.cpp factorial.cpp
   $(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

hello: main.cpp hello.cpp factorial.cpp
   $(CC) $(CFLAGS) $@.cpp $(LDFLAGS) -o $@
```

In this example, $@ represents hello and $? or $@.cpp picks up all the changed source files.
There are two more special macros used in the implicit rules. They are −

- `$<` the name of the related file that caused the action.
- `$*` the prefix shared by target and dependent files.