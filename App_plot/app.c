/*
*
*	Simple C code tried to do the plot with X11 lib but it is unfinished.
*	[+] TO-DO: Fix the plot display, Test real time
*/


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINES 100
#define MAX_TEMP 100

// Function to parse the temperature value from a line
double parseTemperature(const char *line) {
    double temp;
    if (sscanf(line, "Temp = %lf", &temp) == 1) {
        return temp;
    } else {
        return NAN; // Not a valid temperature value
    }
}

int main() {
    Display *display;
    Window window;
    XEvent event;
    GC gc;
    XGCValues values;
    int screen_width, screen_height;
    int x, y;

    // Initialize Xlib
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return 1;
    }

    screen_width = DisplayWidth(display, DefaultScreen(display));
    screen_height = DisplayHeight(display, DefaultScreen(display));

    // Create a window
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, screen_width, screen_height, 1, BlackPixel(display, DefaultScreen(display)), WhitePixel(display, DefaultScreen(display)));

    // Map the window on the screen
    XMapWindow(display, window);

    // Create a graphics context
    values.foreground = BlackPixel(display, DefaultScreen(display));
    values.line_width = 2;
    values.line_style = LineSolid;
    gc = XCreateGC(display, window, GCForeground | GCLineWidth | GCLineStyle, &values);

    // Open the text file for reading
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file for reading\n");
        return 1;
    }

    // Read temperature data from the file
    double temperatures[MAX_LINES];
    int numLines = 0;
    char line[MAX_TEMP];

    while (fgets(line, sizeof(line), file) != NULL && numLines < MAX_LINES) {
        double temp = parseTemperature(line);
        if (!isnan(temp)) {
            temperatures[numLines++] = temp;
        }
    }

    // Close the file
    fclose(file);

    // Draw the curve
    x = 50;
    for (int i = 0; i < numLines - 1; i++) {
        int y1 = screen_height - temperatures[i] * 5; // Scale the temperature for display
        int y2 = screen_height - temperatures[i + 1] * 5;
        XDrawLine(display, window, gc, x, y1, x + 10, y2); // Adjust x and line length as needed
        x += 10; // Adjust x increment as needed
    }

    // Main event loop
    while (1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress)
            break;
    }

    // Clean up and close the window
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0;
}

