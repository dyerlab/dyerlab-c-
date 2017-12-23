//
//  MainWindowController.swift
//  dyerlab
//
//  Created by Rodney Dyer on 12/23/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Cocoa

class MainWindowController: NSWindowController {

    override func windowDidLoad() {
        super.windowDidLoad()
    
        // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
        self.windowFrameAutosaveName = NSWindow.FrameAutosaveName(rawValue: "position")
    }

}
