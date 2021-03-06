/*
 * Copyright (c) 1992 Stanford University
 * Copyright (c) 1992 Silicon Graphics, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and 
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Stanford and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Stanford and Silicon Graphics.
 * 
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
 *
 * IN NO EVENT SHALL STANFORD OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF 
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
 * OF THIS SOFTWARE.
 */

#ifndef iv_xselection_h
#define iv_xselection_h

#include <InterViews/selection.h>
#include <IV-X11/Xlib.h>

class PopupWindow;

class SelectionManagerRep {
public:
#ifdef _DELTA_EXTENSIONS
#pragma __static_class
#endif
    XDisplay* xdisplay_;
    String* name_;
    XSelectionRequestEvent x_req_;
    PopupWindow* owner_;
    SelectionHandler* convert_;
    SelectionHandler* lose_;
    SelectionHandler* done_;
    SelectionHandler* ok_;
    SelectionHandler* fail_;

    SelectionManagerRep(Display*, const String&);
    ~SelectionManagerRep();

    void request(SelectionManager*, const XSelectionRequestEvent&);
    void notify(SelectionManager*, const XSelectionEvent&);
};

#endif
