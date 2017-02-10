//include necessary external libraries
#include <stdlib.h>
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/bitmaps/boxes>
#include <pthread.h> 
#include <sys/sem.h>
#include <signal.h>
#include <math.h>
using namespace std;


//set configuration of ray tracer
#define ANTIALIAS 2
#define RECURSION 3
#define MAX_DISTANCE 100000

//include ray tracer libraries
#include "Server.cpp"

//executed program
int main(int argc, char *argv[]){

    //create window
    Pixmap icon_map;
    Display* display;
    char* display_name = getenv("DISPLAY");
    display = XOpenDisplay(display_name);
    if (display == NULL) {
        fprintf(stderr, "%s: cannot connect to X server '%s'\n",
             argv[0], display_name);
        exit (1);
    }
    int screen_num = DefaultScreen(display);
    int depth = DefaultDepth(display, screen_num);
    Window win;
    unsigned int win_width = DisplayWidth(display, screen_num);
    unsigned int win_height = DisplayHeight(display, screen_num);
    unsigned int win_x = 0;
    unsigned int win_y = 0;
    unsigned int win_border_width = 2;
    win = XCreateSimpleWindow(display,
                RootWindow(display, screen_num),
                win_x, win_y, win_width,
                win_height, win_border_width,
                BlackPixel(display, screen_num),
                WhitePixel(display, screen_num));
                
    //label the window
    XTextProperty winName;
    char* cWinName = (char *)"Hans' Ray Tracer";
    XStringListToTextProperty(&cWinName, 1, &winName);
    
    //set icon for window
    icon_map = XCreateBitmapFromData(display, win, boxes_bits,
                     boxes_width, boxes_height);
    char* icon_name = (char *)"Hans' Ray Tracer";
    XTextProperty iconName;
    XStringListToTextProperty(&icon_name, 1, &iconName);
    
    //set exit protocol for xwindows
    Atom wmDelete=XInternAtom(display, "WM_DELETE_WINDOW", True);
    XSetWMProtocols(display, win, &wmDelete, 1);
    
    //set window properties
    XWMHints *wm_hints;
    XClassHint *class_hints;
    XSizeHints *size_hints;
    if (!(size_hints = XAllocSizeHints())) {
        fprintf(stderr, "%s: failure allocating memory", argv[0]);
        exit(0);
    }
    if (!(wm_hints = XAllocWMHints())) {
        fprintf(stderr, "%s: failure allocating memory", argv[0]);
        exit(0);
    }
    if (!(class_hints = XAllocClassHint())) {
        fprintf(stderr, "%s: failure allocating memory", argv[0]);
        exit(0);
    }
    size_hints->flags = PPosition | PSize | PMinSize;
    size_hints->min_width = 50;
    size_hints->min_height = 50;
    wm_hints->initial_state = NormalState;
    wm_hints->input = True;
    wm_hints->icon_pixmap = icon_map;
    wm_hints->flags = StateHint | IconPixmapHint | InputHint;
    class_hints->res_name = argv[0];
    class_hints->res_class = (char *)"HansRayTracer";
    XSetWMProperties(display, win, &winName, &iconName,
            argv, argc, size_hints, wm_hints,
                 class_hints);
                 
    //create graphic context
    GC gc;
    XGCValues values;
    unsigned long valuemask = 0;
    gc = XCreateGC(display, win, valuemask, &values);
    if (gc < 0) {
        fprintf(stderr, "XCreateGC: \n");
    }    
    XSetBackground(display, gc, BlackPixel(display, screen_num));
    Visual* default_vis = DefaultVisual(display, screen_num);
    XImage *ximage;
    int width, height;
    width = DisplayWidth(display,screen_num);
    height = DisplayHeight(display,screen_num);

    //create a server with window properties
    Server* server = new Server(width, height);

    //calculate image of server
    server->ray_trace();

    //get image from server
    unsigned char* ray_image = server->get_image();

    //create Ximage from unsigned char* ray_image
    ximage = XCreateImage(display, default_vis, 24, ZPixmap, 0, 
                (char *)ray_image, width, height, 32, 0);

    //remove server
    delete server;

    //Create event handler
    XSelectInput(display, win, ExposureMask |
                 KeyPressMask |
                 StructureNotifyMask);
                 
    //show window
    XMapWindow(display, win);

    //flush Xserver
    XSync(display, False);
    
    //wait for event to stop execution
    XEvent event1;
    bool exit = false;
    int x, y;

    while(!exit){ 
        XNextEvent(display, &event1);
        switch(event1.type){
            case ConfigureNotify:
                //window size changed
                win_width = event1.xconfigure.width;
                win_height = event1.xconfigure.height;
            case Expose:
                //only draw for last expose event
                if(event1.xexpose.count > 0) break; 
                //redraw window here
                //redraw visible part of image to screen
                XPutImage(display, win, gc, ximage, 0, 0, 0, 0,
                      win_width, win_height); 
                //flush Xserver
                XSync(display, False);
        
                break;
            case KeyPress:
                //a key has been pressed
                x = event1.xkey.x;
                y = event1.xkey.y;
                win = event1.xkey.window;
                {
                    KeySym ksymbol = XKeycodeToKeysym(display,
                            event1.xkey.keycode, 0);
                    switch(ksymbol){
                        case XK_Q:
                        case XK_q:
                            //the q key was pressed so exit
                            exit = true;
                            break;
                        default:
                            break;
                    }
                }
                break;
            case ClientMessage:
                //window closed so exit
                exit = true;
                break;
            default:
                break;
        }
    }
    
    //Free memory on exit
    XDestroyImage(ximage);
    XFreePixmap(display, icon_map);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
    return 1;
}


