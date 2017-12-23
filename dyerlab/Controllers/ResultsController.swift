//
//  ResultsController.swift
//  dyerlab
//
//  Created by Rodney Dyer on 12/23/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import Cocoa
import WebKit

class ResultsController: NSViewController {
    
    var results = NSMutableAttributedString()
    let H1_attr = [ NSAttributedStringKey.font: NSFont(name: "Helvetica", size: 18)! ]
    let H2_attr = [ NSAttributedStringKey.font: NSFont(name: "Helvetica", size: 16)! ]
    let H3_attr = [ NSAttributedStringKey.font: NSFont(name: "Helvetica", size: 14)! ]
    let P_attr = [ NSAttributedStringKey.font: NSFont(name: "Helvetica", size: 11)! ]
    
    @IBOutlet var textView: NSTextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do view setup here.
        
        addHeader("Dyerlab")
        addSubSubHeader("Build: Experimental")
        addParagraph("""
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
""")
        
        textView.isEditable = false
        textView.isRichText = true
        textView.isSelectable = true
        textView.isGrammarCheckingEnabled = false
    }
    
    func setContent(_ val: NSMutableAttributedString  ) {
        self.results = val
    }
    
    func addHeader(_ val: String ) {
        let val = NSMutableAttributedString(string: val+"\n",
                                            attributes: H1_attr)
        textView.textStorage?.append(val)
    }
    func addSubHeader(_ val: String ) {
        let val = NSMutableAttributedString(string: val+"\n",
                                            attributes: H2_attr)
        textView.textStorage?.append(val)
    }
    func addSubSubHeader(_ val: String ) {
        let val = NSMutableAttributedString(string: val+"\n",
                                            attributes: H3_attr)
        textView.textStorage?.append(val)
    }
    func addParagraph(_ val: String ){
        let val = NSMutableAttributedString(string: val+"\n",
                                            attributes: P_attr)
        textView.textStorage?.append(val)
    }
    
    
}


extension NSMutableAttributedString {
    
}

