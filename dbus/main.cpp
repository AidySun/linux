#include <stdio.h>
#include <stdlib.h>
#include <systemd/sd-bus.h>

int main(int argc, char *argv[]) {
        sd_bus_error error = SD_BUS_ERROR_NULL;
        sd_bus_message *m = NULL;
        sd_bus *bus = NULL;
        const char *path;
        int r;

        const char *servicePath=":1.1599";
        const char *objectPath="/com/aidy/navigation/myipc"; //"/Models/Navigation/MyIPC/MyIPC";
        const char *interface="/com/aidy/navigation/myipc"; ///Models/Navigation/MyIPC/MyIPC";
        const char *method="funcWithoutReturnVal";

        /* Connect to the system bus */
        r = sd_bus_open_user(&bus);
        if (r < 0) {
                fprintf(stderr, "Failed to connect to system bus: %s\n", strerror(-r));
                goto finish;
        }
        // r = sd_bus_call_method(bus,
        //                        "org.freedesktop.systemd1",           /* service to contact */
        //                        "/org/freedesktop/systemd1",          /* object path */
        //                        "org.freedesktop.systemd1.Manager",   /* interface name */
        //                        "StartUnit",                          /* method name */
        //                        &error,                               /* object to return error in */
        //                        &m,                                   /* return message on success */
        //                        "ss",                                 /* input signature */
        //                        "cups.service",                       /* first argument */
        //                        "replace");                           /* second argument */
 
        /* Issue the method call and store the respons message in m */
        
        r = sd_bus_call_method(bus,
                               servicePath,           /* service to contact */
                               objectPath,          /* object path */
                               interface,   /* interface name */
                               method,                          /* method name */
                               &error,                               /* object to return error in */
                               &m,                                   /* return message on success */
                               NULL);                           /* second argument */
        if (r < 0) {
                fprintf(stderr, "Failed to issue method call: %s\n", error.message);
                goto finish;
        }

        /* Parse the response message */
        r = sd_bus_message_read(m, "o", &path);
        if (r < 0) {
                fprintf(stderr, "Failed to parse response message: %s\n", strerror(-r));
                goto finish;
        }

        printf("Queued service job as %s.\n", path);

finish:
        sd_bus_error_free(&error);
        sd_bus_message_unref(m);
        sd_bus_unref(bus);

        return r < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
