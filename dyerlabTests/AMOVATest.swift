//
//  AMOVATest.swift
//  DLabGeneticsTests
//
//  Created by Rodney Dyer on 12/17/17.
//  Copyright © 2017 Rodney Dyer. All rights reserved.
//

import XCTest
@testable import dyerlab

class AMOVATest: XCTestCase {

    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }

    func testAMOVAMissing() {
        
        // Missing data
        XCTAssert( distAMOVA(loc1: Locus(), loc2: Locus()) == 0.0 )
        XCTAssert( distAMOVA(loc1: Locus(alleles: ["A","B"]), loc2: Locus()) == 0.0 )
        XCTAssert( distAMOVA(loc1: Locus(), loc2: Locus(alleles: ["A","B"])) == 0.0 )
        
        // Same Het
    }


}
