//
//  ResultsController.swift
//  dyerlab
//
//  Created by Rodney Dyer on 12/23/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Cocoa

class ResultsController: NSViewController {
    

    var html = String()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do view setup here.
    }
    
    func updateContent() {
        let header = "<html><body>"
        let footer = "</body></html>"
        
        let content = header + html + footer
        //webView!.loadHTMLString( content )
    }
    
    
}
