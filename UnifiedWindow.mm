#include "UnifiedWindow.h"

#include <Cocoa/Cocoa.h>


void UnifiedWindow::HideTitleBar(long windowID) {

    NSView *nativeView = reinterpret_cast<NSView *>(windowID);
    NSWindow* nativeWindow = [nativeView window];

    [nativeWindow setStyleMask:
        [nativeWindow styleMask] | NSFullSizeContentViewWindowMask | NSWindowTitleHidden];

    [nativeWindow setTitlebarAppearsTransparent:YES];

}
