#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

Display *dis;
Window win;
int x11_fd;
fd_set in_fds;

struct timeval tv;
XEvent ev;

int main() {
    dis = XOpenDisplay(NULL);
    win = XCreateSimpleWindow(dis, RootWindow(dis, 0), 1, 1, 256, 256, \
        0, BlackPixel (dis, 0), BlackPixel(dis, 0));

    // You don't need all of these. Make the mask as you normally would.
    XSelectInput(dis, win, 
        ExposureMask | KeyPressMask | KeyReleaseMask | PointerMotionMask |
        ButtonPressMask | ButtonReleaseMask  | StructureNotifyMask 
        );

    XMapWindow(dis, win);
    XFlush(dis);

    // This returns the FD of the X11 display (or something like that)
    x11_fd = ConnectionNumber(dis);

    // Main loop

    
    while(1) {
        // Create a File Description Set containing x11_fd
        FD_ZERO(&in_fds);
        FD_SET(x11_fd, &in_fds);

        // Set our timer.  One second sounds good.
        tv.tv_usec = 0;
        tv.tv_sec = 1;

        // Wait for X Event or a Timer
        int num_ready_fds = select(x11_fd + 1, &in_fds, NULL, NULL, &tv);
        if (num_ready_fds > 0)
            printf("Event Received!\n");
        else if (num_ready_fds == 0)
            // Handle timer here
            printf("Timer Fired!\n");
        else
            printf("An error occured!\n");

        // Handle XEvents and flush the input 
        while(XPending(dis))
            XNextEvent(dis, &ev);
    }
    return(0);
}